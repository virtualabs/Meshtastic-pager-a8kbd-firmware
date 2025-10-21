/********************************** (C) COPYRIGHT *******************************
 * File Name          : Main.c
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2020/08/06
 * Description        : 串口1收发演示
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

#include "CH58x_common.h"
#include "hal.h"
#include "keymap.h"

#define RX_BUF_SIZE 16

typedef enum {
    IDLE,
    RXBUF,
    COMPLETE
} rx_state_t;

rx_state_t g_rx_state = IDLE;
uint8_t g_rx_buf[RX_BUF_SIZE], rx_buf_idx=0;


void send_report(uint8_t modifiers, uint8_t *p_keys)
{
    /* First byte: magic */
    UART0_SendByte(REPORT_MAGIC);

    /* Second byte: modifiers. */
    UART0_SendByte(modifiers);

    /* Remaining bytes: scan codes. */
    for (int i=0; i < KBD_MAX_PRESSED; i++)
    {
        UART0_SendByte(p_keys[i]);
    }
}

void send_pong(void)
{
    /* Send PONG */
    UART0_SendByte(0xA7);
    for (int i=0; i<4; i++)
        UART0_SendByte(0x00);
}

/**
 * @brief Main routine
 * 
 * @return int 
 */

int main()
{
    uint16_t cols[KBD_ROW_NUMBER], keys;
    uint16_t prev_cols[KBD_ROW_NUMBER];
    uint8_t pressed_keys[KBD_MAX_PRESSED];
    uint8_t updated = 0;
    uint8_t key=0, modifiers=0, func=0;
    int key_idx;

    SetSysClock(CLK_SOURCE_PLL_60MHz);

    /* Configure UART */
    GPIOPinRemap(ENABLE, RB_PIN_UART0);
    GPIOA_SetBits(GPIO_Pin_14);
    GPIOA_ModeCfg(GPIO_Pin_14, GPIO_ModeOut_PP_5mA);
    GPIOA_ModeCfg(GPIO_Pin_15, GPIO_ModeIN_PU);
    UART0_DefInit();

    /* Enable interrupts for UART0. */
    PFIC_EnableIRQ(UART0_IRQn);
    UART0_INTCfg(ENABLE, RB_IER_THR_EMPTY | RB_IER_RECV_RDY);

    /* Configure our keyboard GPIOs. */
    kbd_gpio_init();

    kbd_set_led_charge(1);
    kbd_set_led_wlan(1);
    DelayMs(1000);
    kbd_set_led_charge(0);
    kbd_set_led_wlan(0);

    /* Initialize our keyboard state structures. */
    memset(prev_cols, 0, sizeof(prev_cols));
    memset(cols, 0, sizeof(cols));

    while(1)
    {
        /* Read our keyboard state. */
        updated = 0;
        for (int r=0; r < KBD_ROW_NUMBER; r++)
        {
            /* read row. */
            kbd_row_set(r);
            cols[r] = kbd_cols_read();

            if (cols[r] != prev_cols[r])
            {
                /* Debounce. */
                DelayMs(10);
                cols[r] = kbd_cols_read();

                /* Extract FUNC key state. */
                if (r == 0) {
                    func = (cols[0] & (1 << 1));
                    cols[r] &= 0xfffd;
                }

                if (cols[r] != prev_cols[r]) {
                    updated++;
                }
            }
        }

        /* Keyboard state updated ? */
        if (updated > 0)
        {
            /* Modifier: CTRL */
            if (cols[0] & ( 1 << 2)) {
                modifiers |= KEY_MOD_CTRL;
            } else {
                modifiers &= ~(KEY_MOD_CTRL);
            }

            /* Modifier: SHIFT */
            if (cols[1] & ( 1 << 0)) {
                modifiers |= KEY_MOD_SHIFT;
            } else {
                modifiers &= ~(KEY_MOD_SHIFT);
            }

            /* Modifier: LALT */
            if (cols[0] & ( 1 << 5)) {
                modifiers |= KEY_MOD_LALT;
            } else {
                modifiers &= ~(KEY_MOD_LALT);
            }

            /* Modifier: RALT */
            if (cols[0] & ( 1 << 7)) {
                modifiers |= KEY_MOD_RALT;
            } else {
                modifiers &= ~(KEY_MOD_RALT);
            }

            /* Modifier: META */
            if (cols[0] & ( 1 << 8)) {
                modifiers |= KEY_MOD_META;
            } else {
                modifiers &= ~(KEY_MOD_META);
            }

            /* List pressed keys */
            key_idx = 0;
            memset(pressed_keys, 0, KBD_MAX_PRESSED);
            for (int r=0; (r < KBD_ROW_NUMBER) && (key_idx <= KBD_MAX_PRESSED); r++)
            {
                for (int c=0; c < KBD_COL_NUMBER; c++)
                {
                    if (cols[r] & (1 << c))
                    {
                        if (func == 0) {
                            /* Func key not pressed, send normal key code. */
                            if (g_keymap[r][c].key != KEY_NONE)
                                pressed_keys[key_idx++] = g_keymap[r][c].key;
                        } else {               
                            /* Special case: FN + ENTER -> CTRL+ALT+DEL */
                            if (g_keymap[r][c].fn_mod_key & 0xFF00) {
                                pressed_keys[0] = g_keymap[r][c].fn_mod_key & 0xff;
                                modifiers = g_keymap[r][c].fn_mod_key >> 8;
                                key_idx = 1;
                            } else {
                                /* Other FUNC+KEY scan code. */
                                pressed_keys[key_idx++] = g_keymap[r][c].fn_mod_key & 0xff;
                            }
                        }
                    }

                    if (key_idx > KBD_MAX_PRESSED)
                        break;
                }
            }

            /* Error: too many keys pressed, send overflow. */
            if (key_idx >= KBD_MAX_PRESSED)
            {
                pressed_keys[0] = KEY_ERR_OVF;
                key_idx = 1;
            }

            /* Send report. */
            send_report(modifiers, pressed_keys);

            /* Update prev_cols. */
            memcpy(prev_cols, cols, sizeof(cols));
        }

        /* Process RX data. */
        if (g_rx_state == COMPLETE)
        {
            switch (g_rx_buf[0])
            {
                case 0xA6:
                    {
                        /* Set the LEDs accordingly. */
                        kbd_set_led_charge(g_rx_buf[1] & 1);
                        kbd_set_led_wlan((g_rx_buf[1] >> 1) & 1);

                        /* Set the RGB LEDs duty cycle. */
                        kbd_set_red_duty(g_rx_buf[2]);
                        kbd_set_green_duty(g_rx_buf[3]);
                        kbd_set_blue_duty(g_rx_buf[4]);
                    }
                    break;

                case 0xA7:
                    { 
                        send_pong();
                    }
                    break;

                default:
                    break;
            }

            /* Shift data in RX buffer */
            if (rx_buf_idx > 5)
            {
                for (int i = 5; i < rx_buf_idx; i++)
                {
                    g_rx_buf[i-5] = g_rx_buf[i];
                }
                rx_buf_idx -= 5;
            }

            /* Command processed. */
            g_rx_state = IDLE;
            rx_buf_idx = 0;
        }
    }
}

/*********************************************************************
 * @fn      UART0_IRQHandler
 *
 * @brief   UART0中断函数
 *
 * @return  none
 */
__INTERRUPT
__HIGH_CODE
void UART0_IRQHandler(void)
{
    int i;
    volatile uint8_t byte;

    switch(UART0_GetITFlag())
    {
        case UART_II_LINE_STAT: // Status error
        {
            UART0_GetLinSTA();
            break;
        }

        case UART_II_RECV_TOUT:
        case UART_II_RECV_RDY:
        {
            while ((rx_buf_idx < RX_BUF_SIZE) && (R8_UART0_LSR & 1))
            {
                /* Read byte from FIFO. */
                byte = UART0_RecvByte();

                if ((g_rx_state == IDLE) && ((byte == 0xA6) || (byte == 0xA7)))
                {
                    rx_buf_idx = 0;
                    g_rx_buf[rx_buf_idx++] = byte;
                    g_rx_state = RXBUF;
                }
                else
                {
                    /* Store receive byte in RX buffer, if possible. */
                    if (rx_buf_idx < RX_BUF_SIZE)
                    {
                        g_rx_buf[rx_buf_idx++] = byte;
                    }

                    if ((rx_buf_idx == 5) && (g_rx_state == RXBUF))
                    {
                        g_rx_state = COMPLETE;
                    }   
                }
            }
        }
        break;

        case UART_II_THR_EMPTY: // FIFO is empty
            break;

        case UART_II_MODEM_CHG: // Only UART0
            break;

        default:
            break;
    }
}