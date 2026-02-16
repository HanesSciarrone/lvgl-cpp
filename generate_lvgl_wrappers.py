import logging
import os

from scripts import widget_wrapper as widgets
from scripts import core_wrapper as core

# Adjust to your LVGL repository
INCLUDE = "lvgl"# where to write generated headers

# ----------------------------------- Globals ----------------------------------

# Parse the full lvgl.h umbrella header
script_path = os.path.abspath(__file__)
script_directory = os.path.dirname(script_path)
lvgl_root = os.path.join(script_directory, INCLUDE)
header_file = script_directory + "/lvgl/lvgl.h"
# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------


def main():
    # Configure the logger to show messages from INFO level and above
    logging.basicConfig(level=logging.INFO, format="%(levelname)s - %(message)s")

    widgets.generate_widgets_wrapper(header_file, script_directory, lvgl_root)
    core.generate_core_wrapper(header_file, script_directory, lvgl_root)



if __name__ == "__main__":
    main()
