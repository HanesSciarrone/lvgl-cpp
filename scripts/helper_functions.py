import os
import re

import clang.cindex
from clang.cindex import TokenKind
from clang.cindex import TypeKind


def normalize_type(t):
    """Normalize type spelling for comparisons: remove extra spaces before '*' but leave everything else unchanged"""
    return re.sub(r"\s+\*", "*", t)


def declaration_in_file(cursor, header):
    if cursor.location.file is None:
        return False
    try:
        return os.path.samefile(cursor.location.file.name, header)
    except FileNotFoundError:
        return False


def is_lv_function(cursor):
    return (
        cursor.kind == clang.cindex.CursorKind.FUNCTION_DECL
        and cursor.spelling.startswith("lv_")
    )


# Classify function like: lv_btn_set_text -> method "lv_set_text"
def classify_function(name):
    m = re.match(r"^lv_[^_]+_(.+)$", name)
    if not m:
        return None
    method = "lv_" + m.group(1)
    return method


# Mantain the language variable type in Clang AST
def format_type(arg):
    tokens = list(arg.get_tokens())

    if not tokens:
        return None

    parts = []
    for token in tokens:
        if token.spelling == arg.spelling:
            break
        parts.append(token.spelling)

    return " ".join(parts).strip()

# Return the type of the return value of the function.
# The use of token is because the clang AST isn't able to
# parse bool type for example.
def return_type_format(function_cursor):
    tokens = list(function_cursor.get_tokens())
    result = []

    for token in tokens:
        # Stop when we reach the function name
        if token.kind == TokenKind.IDENTIFIER and token.spelling == function_cursor.spelling:
            break
        result.append(token.spelling)

    return " ".join(result).strip()

def is_creation_function(name, cursor):
    # match name ending in _create and first parameter lv_obj_t*
    if not name.endswith("_create"):
        return False

    # First parameter is lv_obj_t*
    args = list(cursor.get_arguments())

    if len(args) >= 1:
        t = normalize_type(args[0].type.spelling)

        if t == "lv_obj_t*" or t == "const lv_obj_t*":
            return True

    return False

def build_cpp_method(cursor, method, c_function_name):
    """Return a C++ method string for this cursor.
    method_name: short method like 'lv_set_text'
    c_fn_name: full C function name like 'lv_btn_set_text'
    """
    # Build C++ argument list
    args_cpp = []
    call_args = []
    first_is_obj = False
    variadic_fn = False
    arg_name = ""

    for i, arg in enumerate(cursor.get_arguments()):
        arg_type = arg.type
        arg_name = arg.spelling or f"a{i}"

        # Detect the 'obj' parameter
        if i == 0 and normalize_type(arg_type.spelling).endswith("lv_obj_t*"):
            first_is_obj = True
            continue

        # --- FIX: handle array parameters ---
        elem_type = format_type(arg)
        if arg_type.kind in (TypeKind.CONSTANTARRAY, TypeKind.INCOMPLETEARRAY):
            arg_cpp = f"{elem_type} {arg_name}[]"
        else:
            arg_cpp = f"{elem_type} {arg_name}"

        args_cpp.append(arg_cpp)
        call_args.append(arg_name)

    if (cursor.type.is_function_variadic()):
        variadic_fn = True
        args_cpp.append("Args&&... args")
        call_args.append("std::forward<Args>(args)...")

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
    ret = return_type_format(cursor)

    # Generate wrapper method
    if ret == "void":
        body = f"\n        {call};\n"
    else:
        body = f"\n        return {call};\n"

    method_cpp = ""

    if (variadic_fn):
        method_cpp  =  "    template<typename... Args>\n"

    method_cpp += f"    {ret} {method}({', '.join(args_cpp)}) \n    {{ {body}    }}\n\n"
    return method_cpp
