#ifndef DISPLAY_CONFIG_H
#define DISPLAY_CONFIG_H

#include "driver/gpio.h"
#include "driver/i2c.h"

/* Display resolution and buffer configuration */
#define EXAMPLE_LCD_H_RES              (480)
#define EXAMPLE_LCD_V_RES              (320)
#define EXAMPLE_LCD_BIT_PER_PIXEL      (16)
#define EXAMPLE_LCD_DATA_WIDTH         (8)
#define EXAMPLE_LCD_BUFFER_LINES       (50)
#define EXAMPLE_LCD_MIRROR_X           false
#define EXAMPLE_LCD_MIRROR_Y           false

/* Touch controller configuration */
#define EXAMPLE_TOUCH_I2C_PORT         (I2C_NUM_0)
#define EXAMPLE_TOUCH_I2C_SCL          (GPIO_NUM_1)
#define EXAMPLE_TOUCH_I2C_SDA          (GPIO_NUM_2)
#define EXAMPLE_TOUCH_I2C_CLK_HZ       (400000)
#define EXAMPLE_TOUCH_RST              (GPIO_NUM_NC)
#define EXAMPLE_TOUCH_INT              (GPIO_NUM_NC)
#define EXAMPLE_TOUCH_SWAP_XY          false
#define EXAMPLE_TOUCH_MIRROR_X         false
#define EXAMPLE_TOUCH_MIRROR_Y         false
#define EXAMPLE_TOUCH_PHYS_WIDTH       (320)
#define EXAMPLE_TOUCH_PHYS_HEIGHT      (480)

/* ST7796 panel GPIO assignments */
#define EXAMPLE_PIN_NUM_LCD_CS         (GPIO_NUM_17)
#define EXAMPLE_PIN_NUM_LCD_DC         (GPIO_NUM_46)
#define EXAMPLE_PIN_NUM_LCD_WR         (GPIO_NUM_3)
#define EXAMPLE_PIN_NUM_LCD_DATA0      (GPIO_NUM_9)
#define EXAMPLE_PIN_NUM_LCD_DATA1      (GPIO_NUM_12)
#define EXAMPLE_PIN_NUM_LCD_DATA2      (GPIO_NUM_11)
#define EXAMPLE_PIN_NUM_LCD_DATA3      (GPIO_NUM_14)
#define EXAMPLE_PIN_NUM_LCD_DATA4      (GPIO_NUM_13)
#define EXAMPLE_PIN_NUM_LCD_DATA5      (GPIO_NUM_47)
#define EXAMPLE_PIN_NUM_LCD_DATA6      (GPIO_NUM_21)
#define EXAMPLE_PIN_NUM_LCD_DATA7      (GPIO_NUM_45)
#define EXAMPLE_PIN_NUM_LCD_DATA8      (GPIO_NUM_NC)
#define EXAMPLE_PIN_NUM_LCD_DATA9      (GPIO_NUM_NC)
#define EXAMPLE_PIN_NUM_LCD_DATA10     (GPIO_NUM_NC)
#define EXAMPLE_PIN_NUM_LCD_DATA11     (GPIO_NUM_NC)
#define EXAMPLE_PIN_NUM_LCD_DATA12     (GPIO_NUM_NC)
#define EXAMPLE_PIN_NUM_LCD_DATA13     (GPIO_NUM_NC)
#define EXAMPLE_PIN_NUM_LCD_DATA14     (GPIO_NUM_NC)
#define EXAMPLE_PIN_NUM_LCD_DATA15     (GPIO_NUM_NC)
#define EXAMPLE_PIN_NUM_LCD_RST        (GPIO_NUM_NC)  
#define EXAMPLE_PIN_NUM_BK_LIGHT       (GPIO_NUM_48)
#define EXAMPLE_BK_LIGHT_ON_LEVEL      (1)                         

#endif /* DISPLAY_CONFIG_H */
