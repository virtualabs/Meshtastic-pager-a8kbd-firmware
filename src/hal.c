/**
 * Hardware Abstraction Layer
 */
#include "CH58x_common.h"
#include "hal.h"

/**
 * @brief Configure GPIO as output with default level.
 * 
 * @param p_gpio 
 * @param level 
 * @return int 
 */

int gpio_config_output(const kbd_gpio_t *p_gpio, int level)
{
    switch(p_gpio->port)
    {
        case GPIO_PortA:
            {
                /* Configure GPIO as output. */
                GPIOA_ModeCfg(p_gpio->pin, GPIO_ModeOut_PP_5mA);

                /* Configure GPIO level. */
                if (level == 0)
                {
                    GPIOA_ResetBits(p_gpio->pin);
                }
                else
                {
                    GPIOA_SetBits(p_gpio->pin);
                }
            }
            break;

        case GPIO_PortB:
            {
                /* Configure GPIO as output. */
                GPIOB_ModeCfg(p_gpio->pin, GPIO_ModeOut_PP_5mA);

                /* Configure GPIO level. */
                if (level == 0)
                {
                    GPIOB_ResetBits(p_gpio->pin);
                }
                else
                {
                    GPIOB_SetBits(p_gpio->pin);
                }
            }
            break;

        default:
            /* Error: bad port number. */
            return -1;
    }

    /* Success. */
    return 0;
}


/**
 * @brief Configure GPIO input with optional pull-up/pull-down/floating
 * 
 * @param p_gpio 
 * @param input_type 
 * @return int 
 */

int gpio_config_input(const kbd_gpio_t *p_gpio, gpio_input_t input_type)
{
    switch(p_gpio->port)
    {
        case GPIO_PortA:
            {
                /* Configure GPIO as input. */
                GPIOA_ModeCfg(p_gpio->pin, (GPIOModeTypeDef)input_type);
            }
            break;

        case GPIO_PortB:
            {
                /* Configure GPIO as input. */
                GPIOB_ModeCfg(p_gpio->pin, (GPIOModeTypeDef)input_type);
            }
            break;

        default:
            /* Error: bad port number. */
            return -1;
    }

    /* Success. */
    return 0;
}


/**
 * @brief Set/Reset a GPIO
 * 
 * @param port 
 * @param pin 
 * @param level 
 */

void gpio_output_set(int port, int pin, int level)
{
    if (port == GPIO_PortA)
    {
        if (!level)
            GPIOA_ResetBits(pin);
        else 
            GPIOA_SetBits(pin);
    }
    else
    {
        if (!level)
            GPIOB_ResetBits(pin);
        else 
            GPIOB_SetBits(pin);       
    }
}


/**
 * @brief Initialize our keyboard GPIOs for key matrix and LEDs.
 */

void kbd_gpio_init(void)
{
    int i;

    /* Initialize all the required GPIOs for rows (output, default low). */
    for (i=0; i < KBD_ROW_NUMBER; i++)
    {
        gpio_config_output(&g_kbd_rows[i], 0);
    }

    /* Initialize all the required GPIOs for columns (input, pull-down). */
    for (i=0; i < KBD_COL_NUMBER; i++)
    {
        gpio_config_input(&g_kbd_cols[i],GPIO_INPUT_PULLDOWN );
    }
    
    /* Initialize our LEDS. */
    gpio_config_output(&g_led_chg, 0);
    gpio_config_output(&g_led_wlan, 0);

    /* Configure RGB LEDs as PWM outputs. */

    /* Red LED */
    gpio_config_output(&g_led_bl_red, 0);
    GPIOPinRemap(ENABLE, RB_PIN_TMR0);
    TMR0_PWMInit(High_Level, PWM_Times_1);
    TMR0_PWMCycleCfg(FREQ_SYS / PWM_FREQ);
    TMR0_PWMActDataWidth(0);
    TMR0_PWMEnable();
    TMR0_Enable();

    /* Green LED */
    gpio_config_output(&g_led_bl_green, 0);
    TMR1_PWMInit(High_Level, PWM_Times_1);
    TMR1_PWMCycleCfg(FREQ_SYS / PWM_FREQ);
    TMR1_PWMActDataWidth(0);
    TMR1_PWMEnable();
    TMR1_Enable();

    /* Blue LED */
    gpio_config_output(&g_led_bl_blue, 0);
    TMR2_PWMInit(High_Level, PWM_Times_1);
    TMR2_PWMCycleCfg(FREQ_SYS / PWM_FREQ);
    TMR2_PWMActDataWidth(0);
    TMR2_PWMEnable();
    TMR2_Enable();
}

/**
 * @brief Set keyboard row for key state reading.
 * 
 * @param i 
 * @return int 
 */

int kbd_row_set(int i)
{
    int j;

    if ((i < 0) || (i >= KBD_ROW_NUMBER))
    {
        return -1;
    }

    for (j=0; j < KBD_ROW_NUMBER; j++)
    {
        if (g_kbd_rows[j].port == GPIO_PortA)
        {
            if (j == i)
            {
                GPIOA_SetBits(g_kbd_rows[j].pin);
            }
            else
            {
                GPIOA_ResetBits(g_kbd_rows[j].pin);
            }
        }
        else
        {
            if (j == i)
            {
                GPIOB_SetBits(g_kbd_rows[j].pin);
            }
            else
            {
                GPIOB_ResetBits(g_kbd_rows[j].pin);
            }
        }
    }

    /* Success. */
    return 0;
}

uint16_t kbd_cols_read(void)
{
    uint16_t cols, temp;
    cols = GPIOB_ReadPort() & 0x03ff;
    temp = GPIOA_ReadPort();
    cols |= (temp & (1 << 9)) << 1;
    cols |= (temp & (1 << 8)) << 3;

    /* Return columns' state. */
    return cols;
}

/**
 * @brief Set/reset keyboard charge status LED
 * 
 * @param level 
 */

void kbd_set_led_charge(int level)
{
    gpio_output_set(g_led_chg.port, g_led_chg.pin, level);
}

/**
 * @brief Set/reset keyboard wlan status LED
 * 
 * @param level 
 */

void kbd_set_led_wlan(int level)
{
    gpio_output_set(g_led_wlan.port, g_led_wlan.pin, level);
}


/**
 * @brief Set red RGB LED duty cycle
 * 
 * @param level duty cycle to set (0 - 100)
 */
void kbd_set_red_duty(uint8_t level)
{
    /* Sanity check. */
    if (level > 100)
        level = 100;

    TMR0_Disable();
    TMR0_PWMActDataWidth(level * (FREQ_SYS / (100 * PWM_FREQ)));
    TMR0_Enable();
}

/**
 * @brief Set blue RGB LED duty cycle
 * 
 * @param level duty cycle to set (0 - 100)
 */
void kbd_set_blue_duty(uint8_t level)
{
    /* Sanity check. */
    if (level > 100)
        level = 100;

    TMR2_Disable();
    TMR2_PWMActDataWidth(level * (FREQ_SYS / (100 * PWM_FREQ)));
    TMR2_Enable();
}

/**
 * @brief Set green RGB LED duty cycle
 * 
 * @param level duty cycle to set (0 - 100)
 */
void kbd_set_green_duty(uint8_t level)
{
    /* Sanity check. */
    if (level > 100)
        level = 100;

    TMR1_Disable();
    TMR1_PWMActDataWidth(level * (FREQ_SYS / (100 * PWM_FREQ)));
    TMR1_Enable();
}
