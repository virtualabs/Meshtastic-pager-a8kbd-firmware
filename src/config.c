#include "CH58x_common.h"
#include "config.h"

/**
 * @brief Global array defining the keyboard matrix rows' GPIOs.
 */
const kbd_gpio_t g_kbd_rows[KBD_ROW_NUMBER] = {
    {GPIO_PortB, GPIO_Pin_19},      /* Row 0 */
    {GPIO_PortB, GPIO_Pin_18},      /* Row 1 */
    {GPIO_PortB, GPIO_Pin_17},      /* Row 2 */
    {GPIO_PortB, GPIO_Pin_16},      /* Row 3 */
    {GPIO_PortB, GPIO_Pin_15},      /* Row 4 */
    {GPIO_PortB, GPIO_Pin_14},      /* Row 5 */
    {GPIO_PortB, GPIO_Pin_13},      /* Row 6 */
    {GPIO_PortB, GPIO_Pin_12},      /* Row 7 */
};

/**
 * @brief Global array defining the keyboard matrix columns' GPIOs.
 */
const kbd_gpio_t g_kbd_cols[KBD_COL_NUMBER] = {
    {GPIO_PortB, GPIO_Pin_0},      /* Col.  0 */
    {GPIO_PortB, GPIO_Pin_1},      /* Col.  1 */
    {GPIO_PortB, GPIO_Pin_2},      /* Col.  2 */
    {GPIO_PortB, GPIO_Pin_3},      /* Col.  3 */
    {GPIO_PortB, GPIO_Pin_4},      /* Col.  4 */
    {GPIO_PortB, GPIO_Pin_5},      /* Col.  5 */
    {GPIO_PortB, GPIO_Pin_6},      /* Col.  6 */
    {GPIO_PortB, GPIO_Pin_7},      /* Col.  7 */
    {GPIO_PortB, GPIO_Pin_8},      /* Col.  8 */
    {GPIO_PortB, GPIO_Pin_9},      /* Col.  9 */
    {GPIO_PortA, GPIO_Pin_9},      /* Col. 10 */
    {GPIO_PortA, GPIO_Pin_8},      /* Col. 11 */
};

/**
 * @brief LEDs definitions
 */
const kbd_gpio_t g_led_chg = { KBD_LED_CHG_PORT, KBD_LED_CHG_PIN};
const kbd_gpio_t g_led_wlan = { KBD_LED_WLAN_PORT, KBD_LED_WLAN_PIN };
const kbd_gpio_t g_led_bl_red = { KBD_BL_RED_PORT, KBD_BL_RED_PIN };
const kbd_gpio_t g_led_bl_green = { KBD_BL_GREEN_PORT, KBD_BL_GREEN_PIN };
const kbd_gpio_t g_led_bl_blue = { KBD_BL_BLUE_PORT, KBD_BL_BLUE_PIN };