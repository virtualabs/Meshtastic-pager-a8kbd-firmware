#ifndef __INC_HAL_H
#define __INC_HAL_H

#include "config.h"

/* GPIO configuration and level set/reset. */
int gpio_config_output(const kbd_gpio_t *p_gpio, int level);
int gpio_config_input(const kbd_gpio_t *p_gpio, gpio_input_t input_type);
void gpio_output_set(int port, int pin, int level);

/* Keyboard functions. */
void kbd_gpio_init(void);
int kbd_row_set(int i);
uint16_t kbd_cols_read(void);

/* LED control. */
void kbd_set_led_charge(int level);
void kbd_set_led_wlan(int level);

/* RGB lighting control. */
void kbd_set_red_duty(uint8_t level);
void kbd_set_green_duty(uint8_t level);
void kbd_set_blue_duty(uint8_t level);

#endif /* __INC_HAL_H */