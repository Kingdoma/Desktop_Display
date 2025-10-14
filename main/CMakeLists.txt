file(GLOB_RECURSE GUI_GUIDER_SOURCES
    "generated/*.c"
    "custom/*.c")

idf_component_register(
    SRCS
        "main.c"
        ${GUI_GUIDER_SOURCES}
    INCLUDE_DIRS
        "."
        "custom"
        "generated"
        "generated/images"
        "generated/guider_fonts"
        "generated/guider_customer_fonts")

target_compile_definitions(${COMPONENT_LIB} PRIVATE LV_LVGL_H_INCLUDE_SIMPLE=1)
