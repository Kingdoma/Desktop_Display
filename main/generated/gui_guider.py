# Copyright 2025 NXP
# NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
# accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
# activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
# comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
# terms, then you may not retain, install, activate or otherwise use the software.

import SDL
import utime as time
import usys as sys
import lvgl as lv
import lodepng as png
import ustruct
import fs_driver

lv.init()
SDL.init(w=480,h=320)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(480*320*4)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 480
disp_drv.ver_res = 320
disp_drv.register()

# Regsiter SDL mouse driver
indev_drv = lv.indev_drv_t()
indev_drv.init()
indev_drv.type = lv.INDEV_TYPE.POINTER
indev_drv.read_cb = SDL.mouse_read
indev_drv.register()

fs_drv = lv.fs_drv_t()
fs_driver.fs_register(fs_drv, 'Z')

# Below: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

COLOR_SIZE = lv.color_t.__SIZE__
COLOR_IS_SWAPPED = hasattr(lv.color_t().ch,'green_h')

class lodepng_error(RuntimeError):
    def __init__(self, err):
        if type(err) is int:
            super().__init__(png.error_text(err))
        else:
            super().__init__(err)

# Parse PNG file header
# Taken from https://github.com/shibukawa/imagesize_py/blob/ffef30c1a4715c5acf90e8945ceb77f4a2ed2d45/imagesize.py#L63-L85

def get_png_info(decoder, src, header):
    # Only handle variable image types

    if lv.img.src_get_type(src) != lv.img.SRC.VARIABLE:
        return lv.RES.INV

    data = lv.img_dsc_t.__cast__(src).data
    if data == None:
        return lv.RES.INV

    png_header = bytes(data.__dereference__(24))

    if png_header.startswith(b'\211PNG\r\n\032\n'):
        if png_header[12:16] == b'IHDR':
            start = 16
        # Maybe this is for an older PNG version.
        else:
            start = 8
        try:
            width, height = ustruct.unpack(">LL", png_header[start:start+8])
        except ustruct.error:
            return lv.RES.INV
    else:
        return lv.RES.INV

    header.always_zero = 0
    header.w = width
    header.h = height
    header.cf = lv.img.CF.TRUE_COLOR_ALPHA

    return lv.RES.OK

def convert_rgba8888_to_bgra8888(img_view):
    for i in range(0, len(img_view), lv.color_t.__SIZE__):
        ch = lv.color_t.__cast__(img_view[i:i]).ch
        ch.red, ch.blue = ch.blue, ch.red

# Read and parse PNG file

def open_png(decoder, dsc):
    img_dsc = lv.img_dsc_t.__cast__(dsc.src)
    png_data = img_dsc.data
    png_size = img_dsc.data_size
    png_decoded = png.C_Pointer()
    png_width = png.C_Pointer()
    png_height = png.C_Pointer()
    error = png.decode32(png_decoded, png_width, png_height, png_data, png_size)
    if error:
        raise lodepng_error(error)
    img_size = png_width.int_val * png_height.int_val * 4
    img_data = png_decoded.ptr_val
    img_view = img_data.__dereference__(img_size)

    if COLOR_SIZE == 4:
        convert_rgba8888_to_bgra8888(img_view)
    else:
        raise lodepng_error("Error: Color mode not supported yet!")

    dsc.img_data = img_data
    return lv.RES.OK

# Above: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

decoder = lv.img.decoder_create()
decoder.info_cb = get_png_info
decoder.open_cb = open_png

def anim_x_cb(obj, v):
    obj.set_x(v)

def anim_y_cb(obj, v):
    obj.set_y(v)

def anim_width_cb(obj, v):
    obj.set_width(v)

def anim_height_cb(obj, v):
    obj.set_height(v)

def anim_img_zoom_cb(obj, v):
    obj.set_zoom(v)

def anim_img_rotate_cb(obj, v):
    obj.set_angle(v)

global_font_cache = {}
def test_font(font_family, font_size):
    global global_font_cache
    if font_family + str(font_size) in global_font_cache:
        return global_font_cache[font_family + str(font_size)]
    if font_size % 2:
        candidates = [
            (font_family, font_size),
            (font_family, font_size-font_size%2),
            (font_family, font_size+font_size%2),
            ("montserrat", font_size-font_size%2),
            ("montserrat", font_size+font_size%2),
            ("montserrat", 16)
        ]
    else:
        candidates = [
            (font_family, font_size),
            ("montserrat", font_size),
            ("montserrat", 16)
        ]
    for (family, size) in candidates:
        try:
            if eval(f'lv.font_{family}_{size}'):
                global_font_cache[font_family + str(font_size)] = eval(f'lv.font_{family}_{size}')
                if family != font_family or size != font_size:
                    print(f'WARNING: lv.font_{family}_{size} is used!')
                return eval(f'lv.font_{family}_{size}')
        except AttributeError:
            try:
                load_font = lv.font_load(f"Z:MicroPython/lv_font_{family}_{size}.fnt")
                global_font_cache[font_family + str(font_size)] = load_font
                return load_font
            except:
                if family == font_family and size == font_size:
                    print(f'WARNING: lv.font_{family}_{size} is NOT supported!')

global_image_cache = {}
def load_image(file):
    global global_image_cache
    if file in global_image_cache:
        return global_image_cache[file]
    try:
        with open(file,'rb') as f:
            data = f.read()
    except:
        print(f'Could not open {file}')
        sys.exit()

    img = lv.img_dsc_t({
        'data_size': len(data),
        'data': data
    })
    global_image_cache[file] = img
    return img

def calendar_event_handler(e,obj):
    code = e.get_code()

    if code == lv.EVENT.VALUE_CHANGED:
        source = e.get_current_target()
        date = lv.calendar_date_t()
        if source.get_pressed_date(date) == lv.RES.OK:
            source.set_highlighted_dates([date], 1)

def spinbox_increment_event_cb(e, obj):
    code = e.get_code()
    if code == lv.EVENT.SHORT_CLICKED or code == lv.EVENT.LONG_PRESSED_REPEAT:
        obj.increment()
def spinbox_decrement_event_cb(e, obj):
    code = e.get_code()
    if code == lv.EVENT.SHORT_CLICKED or code == lv.EVENT.LONG_PRESSED_REPEAT:
        obj.decrement()

def digital_clock_cb(timer, obj, current_time, show_second, use_ampm):
    hour = int(current_time[0])
    minute = int(current_time[1])
    second = int(current_time[2])
    ampm = current_time[3]
    second = second + 1
    if second == 60:
        second = 0
        minute = minute + 1
        if minute == 60:
            minute = 0
            hour = hour + 1
            if use_ampm:
                if hour == 12:
                    if ampm == 'AM':
                        ampm = 'PM'
                    elif ampm == 'PM':
                        ampm = 'AM'
                if hour > 12:
                    hour = hour % 12
    hour = hour % 24
    if use_ampm:
        if show_second:
            obj.set_text("%d:%02d:%02d %s" %(hour, minute, second, ampm))
        else:
            obj.set_text("%d:%02d %s" %(hour, minute, ampm))
    else:
        if show_second:
            obj.set_text("%d:%02d:%02d" %(hour, minute, second))
        else:
            obj.set_text("%d:%02d" %(hour, minute))
    current_time[0] = hour
    current_time[1] = minute
    current_time[2] = second
    current_time[3] = ampm

def analog_clock_cb(timer, obj):
    datetime = time.localtime()
    hour = datetime[3]
    if hour >= 12: hour = hour - 12
    obj.set_time(hour, datetime[4], datetime[5])

def datetext_event_handler(e, obj):
    code = e.get_code()
    target = e.get_target()
    if code == lv.EVENT.FOCUSED:
        if obj is None:
            bg = lv.layer_top()
            bg.add_flag(lv.obj.FLAG.CLICKABLE)
            obj = lv.calendar(bg)
            scr = target.get_screen()
            scr_height = scr.get_height()
            scr_width = scr.get_width()
            obj.set_size(int(scr_width * 0.8), int(scr_height * 0.8))
            datestring = target.get_text()
            year = int(datestring.split('/')[0])
            month = int(datestring.split('/')[1])
            day = int(datestring.split('/')[2])
            obj.set_showed_date(year, month)
            highlighted_days=[lv.calendar_date_t({'year':year, 'month':month, 'day':day})]
            obj.set_highlighted_dates(highlighted_days, 1)
            obj.align(lv.ALIGN.CENTER, 0, 0)
            lv.calendar_header_arrow(obj)
            obj.add_event_cb(lambda e: datetext_calendar_event_handler(e, target), lv.EVENT.ALL, None)
            scr.update_layout()

def datetext_calendar_event_handler(e, obj):
    code = e.get_code()
    target = e.get_current_target()
    if code == lv.EVENT.VALUE_CHANGED:
        date = lv.calendar_date_t()
        if target.get_pressed_date(date) == lv.RES.OK:
            obj.set_text(f"{date.year}/{date.month}/{date.day}")
            bg = lv.layer_top()
            bg.clear_flag(lv.obj.FLAG.CLICKABLE)
            bg.set_style_bg_opa(lv.OPA.TRANSP, 0)
            target.delete()

# Create Home
Home = lv.obj()
Home.set_size(480, 320)
Home.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for Home, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home.set_style_bg_color(lv.color_hex(0xb9c6d2), lv.PART.MAIN|lv.STATE.DEFAULT)
Home.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_cont_time
Home_cont_time = lv.obj(Home)
Home_cont_time.set_pos(335, 31)
Home_cont_time.set_size(130, 121)
Home_cont_time.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for Home_cont_time, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_cont_time.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_time.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_time.set_style_bg_opa(181, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_time.set_style_bg_color(lv.color_hex(0x154870), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_time.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_time.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_time.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_time.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_time.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_time.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create Home_digital_clock_time
Home_digital_clock_time_time = [int(11), int(25), int(50), "AM"]
Home_digital_clock_time = lv.dclock(Home_cont_time, "11:25:50 AM")
Home_digital_clock_time_timer = lv.timer_create_basic()
Home_digital_clock_time_timer.set_period(1000)
Home_digital_clock_time_timer.set_cb(lambda src: digital_clock_cb(Home_digital_clock_time_timer, Home_digital_clock_time, Home_digital_clock_time_time, True, True ))
Home_digital_clock_time.set_pos(13, 59)
Home_digital_clock_time.set_size(98, 20)
# Set style for Home_digital_clock_time, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_digital_clock_time.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_digital_clock_time.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_digital_clock_time.set_style_text_font(test_font("montserratMedium", 17), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_digital_clock_time.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_digital_clock_time.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_digital_clock_time.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_digital_clock_time.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_digital_clock_time.set_style_pad_top(4, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_digital_clock_time.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_digital_clock_time.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_digital_clock_time.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_digital_clock_time.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_datetext_date
Home_datetext_date = lv.label(Home_cont_time)
Home_datetext_date.set_text("2025/10/14")
Home_datetext_date.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
Home_datetext_date.add_flag(lv.obj.FLAG.CLICKABLE)
Home_datetext_date_calendar = None
Home_datetext_date.add_event_cb(lambda e: datetext_event_handler(e, Home_datetext_date_calendar), lv.EVENT.ALL, None)
Home_datetext_date.set_pos(23, 27)
Home_datetext_date.set_size(81, 24)
# Set style for Home_datetext_date, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_datetext_date.set_style_text_color(lv.color_hex(0xe2e2e2), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_datetext_date.set_style_text_font(test_font("montserratMedium", 15), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_datetext_date.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_datetext_date.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_datetext_date.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_datetext_date.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_datetext_date.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_datetext_date.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_datetext_date.set_style_pad_top(7, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_datetext_date.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_datetext_date.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_datetext_date.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_time_title
Home_time_title = lv.label(Home_cont_time)
Home_time_title.set_text("Time")
Home_time_title.set_long_mode(lv.label.LONG.WRAP)
Home_time_title.set_width(lv.pct(100))
Home_time_title.set_pos(0, 0)
Home_time_title.set_size(130, 25)
# Set style for Home_time_title, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_time_title.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_time_title.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_time_title.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_time_title.set_style_text_font(test_font("montserratMedium", 15), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_time_title.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_time_title.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_time_title.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_time_title.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_time_title.set_style_bg_opa(59, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_time_title.set_style_bg_color(lv.color_hex(0x1e1e1e), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_time_title.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_time_title.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_time_title.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_time_title.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_time_title.set_style_pad_left(4, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_time_title.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_weekday
Home_weekday = lv.label(Home_cont_time)
Home_weekday.set_text("Tuesday")
Home_weekday.set_long_mode(lv.label.LONG.WRAP)
Home_weekday.set_width(lv.pct(100))
Home_weekday.set_pos(9, 87)
Home_weekday.set_size(103, 22)
# Set style for Home_weekday, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_weekday.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_weekday.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_weekday.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_weekday.set_style_text_font(test_font("montserratMedium", 17), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_weekday.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_weekday.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_weekday.set_style_text_line_space(5, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_weekday.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_weekday.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_weekday.set_style_pad_top(1, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_weekday.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_weekday.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_weekday.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_weekday.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_cont_net
Home_cont_net = lv.obj(Home)
Home_cont_net.set_pos(335, 164)
Home_cont_net.set_size(130, 144)
Home_cont_net.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for Home_cont_net, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_cont_net.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_net.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_net.set_style_bg_opa(181, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_net.set_style_bg_color(lv.color_hex(0x154870), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_net.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_net.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_net.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_net.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_net.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_net.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create Home_speed_info
Home_speed_info = lv.obj(Home_cont_net)
Home_speed_info.set_pos(4, 28)
Home_speed_info.set_size(120, 59)
Home_speed_info.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for Home_speed_info, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_speed_info.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_info.set_style_border_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_info.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_info.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_info.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_info.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_info.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_info.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_info.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_info.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_info.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create Home_download_icon
Home_download_icon = lv.img(Home_speed_info)
Home_download_icon.set_src("B:MicroPython/_download_alpha_13x13.bin")
Home_download_icon.add_flag(lv.obj.FLAG.CLICKABLE)
Home_download_icon.set_pivot(50,50)
Home_download_icon.set_angle(0)
Home_download_icon.set_pos(-2, 25)
Home_download_icon.set_size(13, 13)
# Set style for Home_download_icon, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_download_icon.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_download_icon.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_download_icon.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_upload_icon
Home_upload_icon = lv.img(Home_speed_info)
Home_upload_icon.set_src("B:MicroPython/_upload_alpha_13x13.bin")
Home_upload_icon.add_flag(lv.obj.FLAG.CLICKABLE)
Home_upload_icon.set_pivot(50,50)
Home_upload_icon.set_angle(0)
Home_upload_icon.set_pos(-2, 3)
Home_upload_icon.set_size(13, 13)
# Set style for Home_upload_icon, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_upload_icon.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_upload_icon.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_upload_icon.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_speed_label
Home_speed_label = lv.label(Home_speed_info)
Home_speed_label.set_text("Mbps\n")
Home_speed_label.set_long_mode(lv.label.LONG.WRAP)
Home_speed_label.set_width(lv.pct(100))
Home_speed_label.set_pos(81, 1)
Home_speed_label.set_size(41, 24)
# Set style for Home_speed_label, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_speed_label.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_label.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_label.set_style_text_color(lv.color_hex(0xe3e3e3), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_label.set_style_text_font(test_font("montserratMedium", 13), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_label.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_label.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_label.set_style_text_line_space(11, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_label.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_label.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_label.set_style_pad_top(1, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_label.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_label.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_label.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_speed_label.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_upload_data
Home_upload_data = lv.label(Home_speed_info)
Home_upload_data.set_text("2200.50")
Home_upload_data.set_long_mode(lv.label.LONG.WRAP)
Home_upload_data.set_width(lv.pct(100))
Home_upload_data.set_pos(10, 1)
Home_upload_data.set_size(67, 16)
# Set style for Home_upload_data, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_upload_data.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_upload_data.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_upload_data.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_upload_data.set_style_text_font(test_font("montserratMedium", 14), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_upload_data.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_upload_data.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_upload_data.set_style_text_line_space(5, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_upload_data.set_style_text_align(lv.TEXT_ALIGN.RIGHT, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_upload_data.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_upload_data.set_style_pad_top(1, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_upload_data.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_upload_data.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_upload_data.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_upload_data.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_download_data
Home_download_data = lv.label(Home_speed_info)
Home_download_data.set_text("1200.50")
Home_download_data.set_long_mode(lv.label.LONG.WRAP)
Home_download_data.set_width(lv.pct(100))
Home_download_data.set_pos(9, 24)
Home_download_data.set_size(68, 16)
# Set style for Home_download_data, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_download_data.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_download_data.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_download_data.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_download_data.set_style_text_font(test_font("montserratMedium", 14), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_download_data.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_download_data.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_download_data.set_style_text_line_space(5, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_download_data.set_style_text_align(lv.TEXT_ALIGN.RIGHT, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_download_data.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_download_data.set_style_pad_top(1, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_download_data.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_download_data.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_download_data.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_download_data.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_label_8
Home_label_8 = lv.label(Home_speed_info)
Home_label_8.set_text("Mbps\n")
Home_label_8.set_long_mode(lv.label.LONG.WRAP)
Home_label_8.set_width(lv.pct(100))
Home_label_8.set_pos(81, 24)
Home_label_8.set_size(41, 27)
# Set style for Home_label_8, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_label_8.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_8.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_8.set_style_text_color(lv.color_hex(0xe3e3e3), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_8.set_style_text_font(test_font("montserratMedium", 13), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_8.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_8.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_8.set_style_text_line_space(11, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_8.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_8.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_8.set_style_pad_top(1, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_8.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_8.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_8.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_8.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_ip_data
Home_ip_data = lv.label(Home_cont_net)
Home_ip_data.set_text("China")
Home_ip_data.set_long_mode(lv.label.LONG.WRAP)
Home_ip_data.set_width(lv.pct(100))
Home_ip_data.set_pos(44, 110)
Home_ip_data.set_size(81, 16)
# Set style for Home_ip_data, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_ip_data.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_data.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_data.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_data.set_style_text_font(test_font("montserratMedium", 15), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_data.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_data.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_data.set_style_text_line_space(5, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_data.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_data.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_data.set_style_pad_top(1, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_data.set_style_pad_right(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_data.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_data.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_data.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_ip_label
Home_ip_label = lv.label(Home_cont_net)
Home_ip_label.set_text("IPloc:")
Home_ip_label.set_long_mode(lv.label.LONG.WRAP)
Home_ip_label.set_width(lv.pct(100))
Home_ip_label.set_pos(7, 110)
Home_ip_label.set_size(41, 22)
# Set style for Home_ip_label, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_ip_label.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_label.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_label.set_style_text_color(lv.color_hex(0xe3e3e3), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_label.set_style_text_font(test_font("montserratMedium", 14), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_label.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_label.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_label.set_style_text_line_space(5, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_label.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_label.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_label.set_style_pad_top(1, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_label.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_label.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_label.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ip_label.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_ping_data
Home_ping_data = lv.label(Home_cont_net)
Home_ping_data.set_text("200")
Home_ping_data.set_long_mode(lv.label.LONG.WRAP)
Home_ping_data.set_width(lv.pct(100))
Home_ping_data.set_pos(47, 86)
Home_ping_data.set_size(38, 22)
# Set style for Home_ping_data, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_ping_data.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_data.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_data.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_data.set_style_text_font(test_font("montserratMedium", 14), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_data.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_data.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_data.set_style_text_line_space(5, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_data.set_style_text_align(lv.TEXT_ALIGN.RIGHT, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_data.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_data.set_style_pad_top(1, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_data.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_data.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_data.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_data.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_Ping_label
Home_Ping_label = lv.label(Home_cont_net)
Home_Ping_label.set_text("Ping:")
Home_Ping_label.set_long_mode(lv.label.LONG.WRAP)
Home_Ping_label.set_width(lv.pct(100))
Home_Ping_label.set_pos(7, 85)
Home_Ping_label.set_size(46, 22)
# Set style for Home_Ping_label, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_Ping_label.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_Ping_label.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_Ping_label.set_style_text_color(lv.color_hex(0xe3e3e3), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_Ping_label.set_style_text_font(test_font("montserratMedium", 15), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_Ping_label.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_Ping_label.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_Ping_label.set_style_text_line_space(5, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_Ping_label.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_Ping_label.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_Ping_label.set_style_pad_top(1, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_Ping_label.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_Ping_label.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_Ping_label.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_Ping_label.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_label_temp_tit
Home_label_temp_tit = lv.label(Home_cont_net)
Home_label_temp_tit.set_text("Network Monitor")
Home_label_temp_tit.set_long_mode(lv.label.LONG.WRAP)
Home_label_temp_tit.set_width(lv.pct(100))
Home_label_temp_tit.set_pos(0, 0)
Home_label_temp_tit.set_size(130, 26)
# Set style for Home_label_temp_tit, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_label_temp_tit.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_temp_tit.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_temp_tit.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_temp_tit.set_style_text_font(test_font("montserratMedium", 14), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_temp_tit.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_temp_tit.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_temp_tit.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_temp_tit.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_temp_tit.set_style_bg_opa(59, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_temp_tit.set_style_bg_color(lv.color_hex(0x1e1e1e), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_temp_tit.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_temp_tit.set_style_pad_top(8, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_temp_tit.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_temp_tit.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_temp_tit.set_style_pad_left(4, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_temp_tit.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_ping_unit
Home_ping_unit = lv.label(Home_cont_net)
Home_ping_unit.set_text("ms")
Home_ping_unit.set_long_mode(lv.label.LONG.WRAP)
Home_ping_unit.set_width(lv.pct(100))
Home_ping_unit.set_pos(87, 86)
Home_ping_unit.set_size(38, 22)
# Set style for Home_ping_unit, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_ping_unit.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_unit.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_unit.set_style_text_color(lv.color_hex(0xe3e3e3), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_unit.set_style_text_font(test_font("montserratMedium", 13), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_unit.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_unit.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_unit.set_style_text_line_space(5, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_unit.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_unit.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_unit.set_style_pad_top(1, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_unit.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_unit.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_unit.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_ping_unit.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_cont_electricity
Home_cont_electricity = lv.obj(Home)
Home_cont_electricity.set_pos(157, 52)
Home_cont_electricity.set_size(170, 247)
Home_cont_electricity.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for Home_cont_electricity, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_cont_electricity.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_electricity.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_electricity.set_style_bg_opa(181, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_electricity.set_style_bg_color(lv.color_hex(0x154870), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_electricity.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_electricity.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_electricity.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_electricity.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_electricity.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_electricity.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create Home_cont_total_normal
Home_cont_total_normal = lv.obj(Home_cont_electricity)
Home_cont_total_normal.set_pos(5, 35)
Home_cont_total_normal.set_size(135, 70)
Home_cont_total_normal.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for Home_cont_total_normal, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_cont_total_normal.set_style_border_width(1, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_total_normal.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_total_normal.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_total_normal.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_total_normal.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_total_normal.set_style_bg_opa(64, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_total_normal.set_style_bg_color(lv.color_hex(0x065c9b), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_total_normal.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_total_normal.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_total_normal.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_total_normal.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_total_normal.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_total_normal.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create Home_line_1
Home_line_1 = lv.line(Home_cont_total_normal)
Home_line_1_line_points = [{"x":0, "y":0},{"x":0, "y":53},]
Home_line_1.set_points(Home_line_1_line_points, 2)
Home_line_1.set_pos(64, 10)
Home_line_1.set_size(6, 52)
# Set style for Home_line_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_line_1.set_style_line_width(1, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_line_1.set_style_line_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_line_1.set_style_line_opa(173, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_line_1.set_style_line_rounded(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_label_total
Home_label_total = lv.label(Home_cont_total_normal)
Home_label_total.set_text("Total")
Home_label_total.set_long_mode(lv.label.LONG.WRAP)
Home_label_total.set_width(lv.pct(100))
Home_label_total.set_pos(5, 8)
Home_label_total.set_size(57, 12)
# Set style for Home_label_total, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_label_total.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total.set_style_text_color(lv.color_hex(0xe6f7ff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total.set_style_text_font(test_font("montserratMedium", 10), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_label_normal
Home_label_normal = lv.label(Home_cont_total_normal)
Home_label_normal.set_text("Normal")
Home_label_normal.set_long_mode(lv.label.LONG.WRAP)
Home_label_normal.set_width(lv.pct(100))
Home_label_normal.set_pos(74, 8)
Home_label_normal.set_size(57, 12)
# Set style for Home_label_normal, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_label_normal.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal.set_style_text_font(test_font("montserratMedium", 10), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_label_total_value
Home_label_total_value = lv.label(Home_cont_total_normal)
Home_label_total_value.set_text("20")
Home_label_total_value.set_long_mode(lv.label.LONG.WRAP)
Home_label_total_value.set_width(lv.pct(100))
Home_label_total_value.set_pos(9, 32)
Home_label_total_value.set_size(36, 27)
# Set style for Home_label_total_value, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_label_total_value.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_value.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_value.set_style_text_color(lv.color_hex(0x00bdff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_value.set_style_text_font(test_font("montserratMedium", 18), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_value.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_value.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_value.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_value.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_value.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_value.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_value.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_value.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_value.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_value.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_label_normal_value
Home_label_normal_value = lv.label(Home_cont_total_normal)
Home_label_normal_value.set_text("20")
Home_label_normal_value.set_long_mode(lv.label.LONG.WRAP)
Home_label_normal_value.set_width(lv.pct(100))
Home_label_normal_value.set_pos(79, 30)
Home_label_normal_value.set_size(38, 27)
# Set style for Home_label_normal_value, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_label_normal_value.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_value.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_value.set_style_text_color(lv.color_hex(0x00ff6a), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_value.set_style_text_font(test_font("montserratMedium", 18), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_value.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_value.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_value.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_value.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_value.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_value.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_value.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_value.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_value.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_value.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_label_total_num
Home_label_total_num = lv.label(Home_cont_total_normal)
Home_label_total_num.set_text("Num")
Home_label_total_num.set_long_mode(lv.label.LONG.WRAP)
Home_label_total_num.set_width(lv.pct(100))
Home_label_total_num.set_pos(33, 44)
Home_label_total_num.set_size(22, 10)
# Set style for Home_label_total_num, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_label_total_num.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_num.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_num.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_num.set_style_text_font(test_font("montserratMedium", 10), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_num.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_num.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_num.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_num.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_num.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_num.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_num.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_num.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_num.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_total_num.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_label_normal_num
Home_label_normal_num = lv.label(Home_cont_total_normal)
Home_label_normal_num.set_text("Num")
Home_label_normal_num.set_long_mode(lv.label.LONG.WRAP)
Home_label_normal_num.set_width(lv.pct(100))
Home_label_normal_num.set_pos(108, 44)
Home_label_normal_num.set_size(22, 10)
# Set style for Home_label_normal_num, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_label_normal_num.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_num.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_num.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_num.set_style_text_font(test_font("montserratMedium", 10), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_num.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_num.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_num.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_num.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_num.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_num.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_num.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_num.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_num.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_normal_num.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_label_ele_monitor_title
Home_label_ele_monitor_title = lv.label(Home_cont_electricity)
Home_label_ele_monitor_title.set_text("Electricity Monitor")
Home_label_ele_monitor_title.set_long_mode(lv.label.LONG.WRAP)
Home_label_ele_monitor_title.set_width(lv.pct(100))
Home_label_ele_monitor_title.set_pos(0, 0)
Home_label_ele_monitor_title.set_size(170, 26)
# Set style for Home_label_ele_monitor_title, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_label_ele_monitor_title.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_ele_monitor_title.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_ele_monitor_title.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_ele_monitor_title.set_style_text_font(test_font("montserratMedium", 10), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_ele_monitor_title.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_ele_monitor_title.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_ele_monitor_title.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_ele_monitor_title.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_ele_monitor_title.set_style_bg_opa(59, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_ele_monitor_title.set_style_bg_color(lv.color_hex(0x1e1e1e), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_ele_monitor_title.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_ele_monitor_title.set_style_pad_top(10, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_ele_monitor_title.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_ele_monitor_title.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_ele_monitor_title.set_style_pad_left(10, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_ele_monitor_title.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_cont_3
Home_cont_3 = lv.obj(Home)
Home_cont_3.set_pos(13, 57)
Home_cont_3.set_size(130, 61)
Home_cont_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for Home_cont_3, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_cont_3.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_3.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_3.set_style_bg_opa(181, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_3.set_style_bg_color(lv.color_hex(0x154870), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_3.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_3.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_3.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_3.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_3.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_3.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create Home_digital_clock_2
Home_digital_clock_2_time = [int(11), int(25), int(50), "AM"]
Home_digital_clock_2 = lv.dclock(Home_cont_3, "11:25:50 AM")
Home_digital_clock_2_timer = lv.timer_create_basic()
Home_digital_clock_2_timer.set_period(1000)
Home_digital_clock_2_timer.set_cb(lambda src: digital_clock_cb(Home_digital_clock_2_timer, Home_digital_clock_2, Home_digital_clock_2_time, True, True ))
Home_digital_clock_2.set_pos(71, 31)
Home_digital_clock_2.set_size(58, 20)
# Set style for Home_digital_clock_2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_digital_clock_2.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_digital_clock_2.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_digital_clock_2.set_style_text_font(test_font("montserratMedium", 10), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_digital_clock_2.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_digital_clock_2.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_digital_clock_2.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_digital_clock_2.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_digital_clock_2.set_style_pad_top(7, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_digital_clock_2.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_digital_clock_2.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_digital_clock_2.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_digital_clock_2.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_datetext_2
Home_datetext_2 = lv.label(Home_cont_3)
Home_datetext_2.set_text("2025/10/14")
Home_datetext_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
Home_datetext_2.add_flag(lv.obj.FLAG.CLICKABLE)
Home_datetext_2_calendar = None
Home_datetext_2.add_event_cb(lambda e: datetext_event_handler(e, Home_datetext_2_calendar), lv.EVENT.ALL, None)
Home_datetext_2.set_pos(6, 31)
Home_datetext_2.set_size(58, 24)
# Set style for Home_datetext_2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_datetext_2.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_datetext_2.set_style_text_font(test_font("montserratMedium", 10), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_datetext_2.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_datetext_2.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_datetext_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_datetext_2.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_datetext_2.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_datetext_2.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_datetext_2.set_style_pad_top(7, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_datetext_2.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_datetext_2.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_datetext_2.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_label_5
Home_label_5 = lv.label(Home_cont_3)
Home_label_5.set_text("Time")
Home_label_5.set_long_mode(lv.label.LONG.WRAP)
Home_label_5.set_width(lv.pct(100))
Home_label_5.set_pos(0, 0)
Home_label_5.set_size(130, 25)
# Set style for Home_label_5, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_label_5.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_5.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_5.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_5.set_style_text_font(test_font("montserratMedium", 10), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_5.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_5.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_5.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_5.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_5.set_style_bg_opa(59, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_5.set_style_bg_color(lv.color_hex(0x1e1e1e), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_5.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_5.set_style_pad_top(9, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_5.set_style_pad_right(10, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_5.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_5.set_style_pad_left(10, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_5.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_cont_4
Home_cont_4 = lv.obj(Home)
Home_cont_4.set_pos(13, 130)
Home_cont_4.set_size(130, 169)
Home_cont_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for Home_cont_4, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_cont_4.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_4.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_4.set_style_bg_opa(181, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_4.set_style_bg_color(lv.color_hex(0x154870), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_4.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_4.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_4.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_4.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_4.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_4.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create Home_label_7
Home_label_7 = lv.label(Home_cont_4)
Home_label_7.set_text("Network Monitor")
Home_label_7.set_long_mode(lv.label.LONG.WRAP)
Home_label_7.set_width(lv.pct(100))
Home_label_7.set_pos(0, 0)
Home_label_7.set_size(130, 26)
# Set style for Home_label_7, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_label_7.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_7.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_7.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_7.set_style_text_font(test_font("montserratMedium", 10), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_7.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_7.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_7.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_7.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_7.set_style_bg_opa(59, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_7.set_style_bg_color(lv.color_hex(0x1e1e1e), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_7.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_7.set_style_pad_top(10, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_7.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_7.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_7.set_style_pad_left(10, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_7.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_label_6
Home_label_6 = lv.label(Home_cont_4)
Home_label_6.set_text("Up:\nDown:")
Home_label_6.set_long_mode(lv.label.LONG.WRAP)
Home_label_6.set_width(lv.pct(100))
Home_label_6.set_pos(24, 34)
Home_label_6.set_size(59, 33)
# Set style for Home_label_6, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_label_6.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_6.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_6.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_6.set_style_text_font(test_font("montserratMedium", 10), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_6.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_6.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_6.set_style_text_line_space(5, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_6.set_style_text_align(lv.TEXT_ALIGN.LEFT, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_6.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_6.set_style_pad_top(1, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_6.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_6.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_6.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_6.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_img_6
Home_img_6 = lv.img(Home_cont_4)
Home_img_6.set_src("B:MicroPython/_upload_alpha_12x12.bin")
Home_img_6.add_flag(lv.obj.FLAG.CLICKABLE)
Home_img_6.set_pivot(50,50)
Home_img_6.set_angle(0)
Home_img_6.set_pos(5, 33)
Home_img_6.set_size(12, 12)
# Set style for Home_img_6, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_img_6.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_img_6.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_img_6.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_img_5
Home_img_5 = lv.img(Home_cont_4)
Home_img_5.set_src("B:MicroPython/_download_alpha_12x12.bin")
Home_img_5.add_flag(lv.obj.FLAG.CLICKABLE)
Home_img_5.set_pivot(50,50)
Home_img_5.set_angle(0)
Home_img_5.set_pos(5, 48)
Home_img_5.set_size(12, 12)
# Set style for Home_img_5, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_img_5.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_img_5.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_img_5.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_label_home_title
Home_label_home_title = lv.label(Home)
Home_label_home_title.set_text("Monitoring")
Home_label_home_title.set_long_mode(lv.label.LONG.WRAP)
Home_label_home_title.set_width(lv.pct(100))
Home_label_home_title.set_pos(123, 11)
Home_label_home_title.set_size(210, 20)
# Set style for Home_label_home_title, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_label_home_title.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_home_title.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_home_title.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_home_title.set_style_text_font(test_font("montserratMedium", 17), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_home_title.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_home_title.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_home_title.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_home_title.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_home_title.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_home_title.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_home_title.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_home_title.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_home_title.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_home_title.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_btn_menu
Home_btn_menu = lv.btn(Home)
Home_btn_menu_label = lv.label(Home_btn_menu)
Home_btn_menu_label.set_text(""+lv.SYMBOL.RIGHT+"  ")
Home_btn_menu_label.set_long_mode(lv.label.LONG.WRAP)
Home_btn_menu_label.set_width(lv.pct(100))
Home_btn_menu_label.align(lv.ALIGN.CENTER, 0, 0)
Home_btn_menu.set_style_pad_all(0, lv.STATE.DEFAULT)
Home_btn_menu.set_pos(0, 130)
Home_btn_menu.set_size(27, 56)
# Set style for Home_btn_menu, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_btn_menu.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_menu.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_menu.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_menu.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_menu.set_style_bg_img_src("B:MicroPython/_home_bak_27x56.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_menu.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_menu.set_style_bg_img_recolor_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_menu.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_menu.set_style_text_font(test_font("montserratMedium", 18), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_menu.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_menu.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_cont_menu
Home_cont_menu = lv.obj(Home)
Home_cont_menu.set_pos(0, 0)
Home_cont_menu.set_size(480, 320)
Home_cont_menu.add_flag(lv.obj.FLAG.HIDDEN)
Home_cont_menu.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for Home_cont_menu, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_cont_menu.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_menu.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_menu.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_menu.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_menu.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_menu.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_menu.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_menu.set_style_bg_img_src("B:MicroPython/_menu_bak_480x320.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_menu.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_menu.set_style_bg_img_recolor_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_cont_menu.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create Home_img_tick
Home_img_tick = lv.img(Home_cont_menu)
Home_img_tick.set_src("B:MicroPython/_menu_bal_alpha_192x192.bin")
Home_img_tick.add_flag(lv.obj.FLAG.CLICKABLE)
Home_img_tick.set_pivot(50,50)
Home_img_tick.set_angle(0)
Home_img_tick.set_pos(-96, 53)
Home_img_tick.set_size(192, 192)
# Set style for Home_img_tick, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_img_tick.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_img_tick.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_img_tick.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_btn_phone
Home_btn_phone = lv.btn(Home_cont_menu)
Home_btn_phone_label = lv.label(Home_btn_phone)
Home_btn_phone_label.set_text("")
Home_btn_phone_label.set_long_mode(lv.label.LONG.WRAP)
Home_btn_phone_label.set_width(lv.pct(100))
Home_btn_phone_label.align(lv.ALIGN.CENTER, 0, 0)
Home_btn_phone.set_style_pad_all(0, lv.STATE.DEFAULT)
Home_btn_phone.set_pos(8, 1)
Home_btn_phone.set_size(54, 54)
# Set style for Home_btn_phone, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_btn_phone.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_phone.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_phone.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_phone.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_phone.set_style_bg_img_src("B:MicroPython/_menu_air_54x54.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_phone.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_phone.set_style_bg_img_recolor_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_phone.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_phone.set_style_text_font(test_font("montserratMedium", 10), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_phone.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_phone.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_btn_warning
Home_btn_warning = lv.btn(Home_cont_menu)
Home_btn_warning_label = lv.label(Home_btn_warning)
Home_btn_warning_label.set_text("")
Home_btn_warning_label.set_long_mode(lv.label.LONG.WRAP)
Home_btn_warning_label.set_width(lv.pct(100))
Home_btn_warning_label.align(lv.ALIGN.CENTER, 0, 0)
Home_btn_warning.set_style_pad_all(0, lv.STATE.DEFAULT)
Home_btn_warning.set_pos(56, 26)
Home_btn_warning.set_size(54, 54)
# Set style for Home_btn_warning, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_btn_warning.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_warning.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_warning.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_warning.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_warning.set_style_bg_img_src("B:MicroPython/_menu_anfang_54x54.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_warning.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_warning.set_style_bg_img_recolor_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_warning.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_warning.set_style_text_font(test_font("montserratMedium", 10), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_warning.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_warning.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_btn_power
Home_btn_power = lv.btn(Home_cont_menu)
Home_btn_power_label = lv.label(Home_btn_power)
Home_btn_power_label.set_text("")
Home_btn_power_label.set_long_mode(lv.label.LONG.WRAP)
Home_btn_power_label.set_width(lv.pct(100))
Home_btn_power_label.align(lv.ALIGN.CENTER, 0, 0)
Home_btn_power.set_style_pad_all(0, lv.STATE.DEFAULT)
Home_btn_power.set_pos(84, 75)
Home_btn_power.set_size(54, 54)
# Set style for Home_btn_power, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_btn_power.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_power.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_power.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_power.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_power.set_style_bg_img_src("B:MicroPython/_menu_elevator_54x54.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_power.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_power.set_style_bg_img_recolor_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_power.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_power.set_style_text_font(test_font("montserratMedium", 10), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_power.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_power.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_btn_temp
Home_btn_temp = lv.btn(Home_cont_menu)
Home_btn_temp_label = lv.label(Home_btn_temp)
Home_btn_temp_label.set_text("")
Home_btn_temp_label.set_long_mode(lv.label.LONG.WRAP)
Home_btn_temp_label.set_width(lv.pct(100))
Home_btn_temp_label.align(lv.ALIGN.CENTER, 0, 0)
Home_btn_temp.set_style_pad_all(0, lv.STATE.DEFAULT)
Home_btn_temp.set_pos(96, 132)
Home_btn_temp.set_size(54, 54)
# Set style for Home_btn_temp, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_btn_temp.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_temp.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_temp.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_temp.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_temp.set_style_bg_img_src("B:MicroPython/_menu_tem_54x54.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_temp.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_temp.set_style_bg_img_recolor(lv.color_hex(0xe5ff00), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_temp.set_style_bg_img_recolor_opa(216, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_temp.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_temp.set_style_text_font(test_font("montserratMedium", 10), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_temp.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_temp.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_btn_link
Home_btn_link = lv.btn(Home_cont_menu)
Home_btn_link_label = lv.label(Home_btn_link)
Home_btn_link_label.set_text("")
Home_btn_link_label.set_long_mode(lv.label.LONG.WRAP)
Home_btn_link_label.set_width(lv.pct(100))
Home_btn_link_label.align(lv.ALIGN.CENTER, 0, 0)
Home_btn_link.set_style_pad_all(0, lv.STATE.DEFAULT)
Home_btn_link.set_pos(8, 254)
Home_btn_link.set_size(54, 54)
# Set style for Home_btn_link, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_btn_link.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_link.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_link.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_link.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_link.set_style_bg_img_src("B:MicroPython/_menu_xiaofang_54x54.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_link.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_link.set_style_bg_img_recolor_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_link.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_link.set_style_text_font(test_font("montserratMedium", 10), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_link.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_link.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_btn_safe
Home_btn_safe = lv.btn(Home_cont_menu)
Home_btn_safe_label = lv.label(Home_btn_safe)
Home_btn_safe_label.set_text("")
Home_btn_safe_label.set_long_mode(lv.label.LONG.WRAP)
Home_btn_safe_label.set_width(lv.pct(100))
Home_btn_safe_label.align(lv.ALIGN.CENTER, 0, 0)
Home_btn_safe.set_style_pad_all(0, lv.STATE.DEFAULT)
Home_btn_safe.set_pos(56, 231)
Home_btn_safe.set_size(54, 54)
# Set style for Home_btn_safe, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_btn_safe.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_safe.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_safe.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_safe.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_safe.set_style_bg_img_src("B:MicroPython/_menu_electricity_54x54.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_safe.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_safe.set_style_bg_img_recolor_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_safe.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_safe.set_style_text_font(test_font("montserratMedium", 10), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_safe.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_safe.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_btn_light
Home_btn_light = lv.btn(Home_cont_menu)
Home_btn_light_label = lv.label(Home_btn_light)
Home_btn_light_label.set_text("")
Home_btn_light_label.set_long_mode(lv.label.LONG.WRAP)
Home_btn_light_label.set_width(lv.pct(100))
Home_btn_light_label.align(lv.ALIGN.CENTER, 0, 0)
Home_btn_light.set_style_pad_all(0, lv.STATE.DEFAULT)
Home_btn_light.set_pos(84, 184)
Home_btn_light.set_size(54, 54)
# Set style for Home_btn_light, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_btn_light.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_light.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_light.set_style_radius(3, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_light.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_light.set_style_bg_img_src("B:MicroPython/_menu_light_54x54.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_light.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_light.set_style_bg_img_recolor_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_light.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_light.set_style_text_font(test_font("montserratMedium", 10), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_light.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_btn_light.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create Home_label_monitor
Home_label_monitor = lv.label(Home_cont_menu)
Home_label_monitor.set_text("Monitoring")
Home_label_monitor.set_long_mode(lv.label.LONG.WRAP)
Home_label_monitor.set_width(lv.pct(100))
Home_label_monitor.set_pos(4, 152)
Home_label_monitor.set_size(72, 28)
# Set style for Home_label_monitor, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
Home_label_monitor.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_monitor.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_monitor.set_style_text_color(lv.color_hex(0xbbff00), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_monitor.set_style_text_font(test_font("montserratMedium", 10), lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_monitor.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_monitor.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_monitor.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_monitor.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_monitor.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_monitor.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_monitor.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_monitor.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_monitor.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
Home_label_monitor.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

Home.update_layout()

def Home_btn_menu_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.CLICKED):
        pass
        Home_cont_menu.clear_flag(lv.obj.FLAG.HIDDEN)
        
Home_btn_menu.add_event_cb(lambda e: Home_btn_menu_event_handler(e), lv.EVENT.ALL, None)

def Home_cont_menu_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.CLICKED):
        pass
        Home_cont_menu.add_flag(lv.obj.FLAG.HIDDEN)
        
Home_cont_menu.add_event_cb(lambda e: Home_cont_menu_event_handler(e), lv.EVENT.ALL, None)

def Home_btn_phone_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.CLICKED):
        pass
Home_btn_phone.add_event_cb(lambda e: Home_btn_phone_event_handler(e), lv.EVENT.ALL, None)

def Home_btn_warning_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.CLICKED):
        pass
Home_btn_warning.add_event_cb(lambda e: Home_btn_warning_event_handler(e), lv.EVENT.ALL, None)

def Home_btn_power_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.CLICKED):
        pass
Home_btn_power.add_event_cb(lambda e: Home_btn_power_event_handler(e), lv.EVENT.ALL, None)

def Home_btn_temp_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.CLICKED):
        pass
Home_btn_temp.add_event_cb(lambda e: Home_btn_temp_event_handler(e), lv.EVENT.ALL, None)

def Home_btn_link_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.CLICKED):
        pass
Home_btn_link.add_event_cb(lambda e: Home_btn_link_event_handler(e), lv.EVENT.ALL, None)

def Home_btn_safe_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.CLICKED):
        pass
Home_btn_safe.add_event_cb(lambda e: Home_btn_safe_event_handler(e), lv.EVENT.ALL, None)

def Home_btn_light_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.CLICKED):
        pass
Home_btn_light.add_event_cb(lambda e: Home_btn_light_event_handler(e), lv.EVENT.ALL, None)

# content from custom.py

# Load the default screen
lv.scr_load(Home)

while SDL.check():
    time.sleep_ms(5)

