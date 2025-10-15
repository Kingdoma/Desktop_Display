file(GLOB_RECURSE GUI_GUIDER_SOURCES
    "generated/*.c"
    "custom/*.c")

idf_component_register(
    SRCS
        "main.c"
        "gui_guider_support.c"
        "display_driver.c"
        "tinyusb_cdc.c"
        "metrics.c"
        ${GUI_GUIDER_SOURCES}
    INCLUDE_DIRS
        "."
        "custom"
        "generated"
        "generated/images"
        "generated/guider_fonts"
        "generated/guider_customer_fonts")

target_compile_definitions(${COMPONENT_LIB} PRIVATE LV_LVGL_H_INCLUDE_SIMPLE=1)
target_compile_options(${COMPONENT_LIB} PRIVATE -include "${CMAKE_CURRENT_SOURCE_DIR}/gui_guider_support.h")
