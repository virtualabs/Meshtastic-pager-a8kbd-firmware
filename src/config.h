#ifndef __INC_KEYBD_CONFIG_H
#define __INC_KEYBD_CONFIG_H

#define GPIO_PortA  0
#define GPIO_PortB  1

#define KBD_ROW_NUMBER  8
#define KBD_COL_NUMBER  12
#define KBD_MAX_PRESSED 3

#define KBD_LED_CHG_PORT    GPIO_PortB
#define KBD_LED_CHG_PIN     GPIO_Pin_20
#define KBD_LED_WLAN_PORT   GPIO_PortB
#define KBD_LED_WLAN_PIN    GPIO_Pin_21
#define KBD_BL_RED_PORT     GPIO_PortB
#define KBD_BL_RED_PIN      GPIO_Pin_23
#define KBD_BL_GREEN_PORT   GPIO_PortA
#define KBD_BL_GREEN_PIN    GPIO_Pin_11
#define KBD_BL_BLUE_PORT    GPIO_PortA
#define KBD_BL_BLUE_PIN     GPIO_Pin_10

#define PWM_FREQ            1000


typedef enum {
    GPIO_INPUT_FLOATING = GPIO_ModeIN_Floating,
    GPIO_INPUT_PULLUP,
    GPIO_INPUT_PULLDOWN
} gpio_input_t;

/**
 * @brief Keyboard GPIO definition structure for row and column. 
 */
typedef struct {
    int port;
    int pin;
} kbd_gpio_t;

/**
 * @brief Global array defining the keyboard matrix rows' GPIOs.
 */
extern const kbd_gpio_t g_kbd_rows[KBD_ROW_NUMBER];

/**
 * @brief Global array defining the keyboard matrix columns' GPIOs.
 */
extern const kbd_gpio_t g_kbd_cols[KBD_COL_NUMBER];

/**
 * @brief LEDs definitions
 */
extern const kbd_gpio_t g_led_chg;
extern const kbd_gpio_t g_led_wlan;
extern const kbd_gpio_t g_led_bl_red;
extern const kbd_gpio_t g_led_bl_green;
extern const kbd_gpio_t g_led_bl_blue;

#endif /* __INC_KEYBD_CONFIG_H */