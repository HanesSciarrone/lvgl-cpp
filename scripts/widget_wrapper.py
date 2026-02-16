import logging
import os
import re
import sys

import clang.cindex
from clang.cindex import TypeKind

from scripts import helper_functions as helper

# Adjust to your LVGL repository
INCLUDE = "lvgl"

# Pick the C++ output file
OUT_DIR = "wrappers/widgets"  # where the widgets headers wrapper will be generated

# ----------------------------------- Globals -----------------------------------

# Configure libclang path if needed:
# clang.cindex.Config.set_library_file("/usr/lib/llvm-17/lib/libclang.so")

index = clang.cindex.Index.create()

# Regex to match #include directives, capturing the header name
# Handles both <header.h> and "header.h" formats
include_pattern = re.compile(r'#include\s*(<[^>]+>|"[^"]+")')

included_headers = []  # Header files included for the widgets in the lvgl library

# -------------------------------------------------------------------------------


# ------------------------------ Private functions ------------------------------
def _build_method(cursor, method, c_function_name):
    """Return a C++ method string for this cursor.
    method_name: short method like 'set_text'
    c_fn_name: full C function name like 'lv_btn_set_text'
    """
    # Build C++ argument list
    args_cpp = []
    call_args = []
    first_is_obj = False

    for i, arg in enumerate(cursor.get_arguments()):
        arg_type = arg.type
        arg_name = arg.spelling or f"a{i}"

        # Detect the 'obj' parameter
        if i == 0 and helper.normalize_type(arg_type.spelling).endswith("lv_obj_t*"):
            first_is_obj = True
            continue

        # --- FIX: handle array parameters ---
        if arg_type.kind in (TypeKind.CONSTANTARRAY, TypeKind.INCOMPLETEARRAY):
            elem = helper.format_type(arg)  # (arg_type.element_type)
            arg_cpp = f"{elem} {arg_name}[]"
        else:
            arg_cpp = f"{helper.format_type(arg)} {arg_name}"

        args_cpp.append(arg_cpp)
        call_args.append(arg_name)

    # Build the call expression
    if first_is_obj:
        call = (
            f"{c_function_name}(obj, {', '.join(call_args)})"
            if call_args
            else f"{c_function_name}(obj)"
        )
    else:
        call = (
            f"{c_function_name}({', '.join(call_args)})"
            if call_args
            else f"{c_function_name}()"
        )

    # Return type
    ret = helper.return_type_format(cursor)

    # Generate wrapper method
    if ret == "void":
        body = f"\n{{\n    {call};\n}}\n\n"
    else:
        body = f"\n{{\n    return {call};\n}}\n\n"

    method_cpp = f"    {ret} {method}({', '.join(args_cpp)}) {body}\n"
    return method_cpp


def _parse_widgets_headers(header_file):
    try:
        with open(header_file, "r") as f:
            for line in f:
                match = include_pattern.search(line)
                if match:
                    # Extract the header name, removing angle brackets or quotes
                    header_name = match.group(1).strip('<>"')
                    if header_name.find("widgets") != -1:
                        included_headers.append(header_name)
    except FileNotFoundError:
        logging.debug(f"Error: File not found at {header_file}")
        sys.exit(2)
    except Exception as e:
        logging.debug(f"An error occurred: {e}")
        sys.exit(3)


# -------------------------------------------------------------------------------


def generate_widgets_wrapper(header_file, script_directory, lvgl_root):
    _parse_widgets_headers(header_file)
    # prepare output dir
    os.makedirs(os.path.join(script_directory, OUT_DIR), exist_ok=True)

    for inc in included_headers:
        logging.info(f"Processing include: {inc}")

        # Full path to header in the lvgl tree if it looks like a project include
        include_path = os.path.join(lvgl_root, "src", inc)

        if not os.path.isfile(include_path):
            include_path = os.path.join(lvgl_root, inc)

        if not os.path.isfile(include_path):
            logging.debug(
                f"Header file not found in repo, skipping (or it's system header): {include_path}"
            )
            continue

        # parse with include paths and language
        args = [
            "-x",
            "c",
            "-std=c11",
            f"-I{os.path.join(lvgl_root, 'src')}",
        ]
        tu = index.parse(include_path, args=args)

        if not tu:
            logging.debug("Parse failed (tu is falsy); skipping")
            continue

        # print diagnostics if any (very useful)
        if len(tu.diagnostics) > 0:
            logging.debug("Diagnostics:")
            for d in tu.diagnostics:
                logging.debug(f"  - {d}")

        if tu.cursor is None:
            logging.debug("tu.cursor is None, parse failed; check args/includes")
            continue

        base = os.path.basename(include_path)  # get the name of file
        name, extension = os.path.splitext(base)  # strip the extention
        class_name = "".join(
            [p.capitalize() for p in name.split("_")]
        )  # strip the '_' character of the class name
        output_header = os.path.join(script_directory, OUT_DIR, f"{name}.hpp")
        logging.info(f"Generating {output_header}, class {class_name}")
        wrappers = {class_name: {"methods": [], "create": None}}

        # Get the class name and the methods of the class
        for cursor in tu.cursor.get_children():
            if not helper.declaration_in_file(cursor, include_path):
                continue

            if not helper.is_lv_function(cursor):
                continue

            c_function_name = cursor.spelling
            method_name = helper.classify_function(c_function_name)

            if method_name is None:
                method_name = c_function_name

            # detect create function
            if helper.is_creation_function(c_function_name, cursor):
                wrappers[class_name]["create"] = c_function_name
                continue

            # build method wrapper
            try:
                method_cpp = helper.build_cpp_method(cursor, method_name, c_function_name)
                wrappers[class_name]["methods"].append(method_cpp)
            except Exception as e:
                logging.warning(f"Failed to build method for {c_function_name}: {e}")

        # Check if the file exists before attempting to delete it
        if os.path.exists(output_header):
            os.remove(output_header)
            logging.debug(f"File '{output_header}' deleted successfully.")
        else:
            logging.debug(f"File '{output_header}' does not exist.")

        # Generate the wrapper code
        with open(output_header, "w") as f:
            guard = f"{name.upper()}_HPP"

            f.write(f"#ifndef {guard}\n")
            f.write(f"#define {guard}\n\n")
            f.write("#pragma once\n\n")

            f.write("#include <utility> // Required for std::forward if it is used\n\n")

            f.write('extern "C" {\n')

            # include only the original include (project relative)
            f.write(f'#include "{os.path.relpath(include_path, script_directory)}"\n')

            f.write("}\n\n")
            f.write("namespace lvgl {\n\n")

            f.write(f"class {class_name} {{\npublic:\n")

            # constructor(s) & methods
            cls = wrappers[class_name]
            create_function = cls["create"]

            if create_function:
                f.write(
                    f"    explicit {class_name}(lv_obj_t* parent) : obj({create_function}(parent)) {{}}\n\n"
                )
            else:
                f.write(
                    f"    explicit {class_name}(lv_obj_t* parent) : obj(parent) {{}}\n\n"
                )

            for method in cls["methods"]:
                f.write(method)

            f.write("\n    lv_obj_t* lv_get_obj() const { return obj; }\n")
            f.write("\nprivate:\n")
            f.write("    lv_obj_t* obj;\n")
            f.write("};\n\n")

            f.write("} // namespace lvglcpp\n")
            f.write(f"#endif /* {guard} */")

        logging.info(f"Done writing {output_header}")
