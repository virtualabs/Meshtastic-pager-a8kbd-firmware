#ifndef __INC_KEYMAP_H
#define __INC_KEYMAP_H

#include "config.h"

/* Modifiers */
#define KEY_MOD_CTRL        0x01
#define KEY_MOD_SHIFT       0x02
#define KEY_MOD_LALT        0x04
#define KEY_MOD_META        0x08
#define KEY_MOD_RALT        0x10

/* HID key scan codes */
#define KEY_NONE 0x00 // No key pressed
#define KEY_ERR_OVF 0x01 //  Keyboard Error Roll Over - used for all slots if too many keys are pressed ("Phantom key")
#define KEY_A 0x04 // Keyboard a and A
#define KEY_B 0x05 // Keyboard b and B
#define KEY_C 0x06 // Keyboard c and C
#define KEY_D 0x07 // Keyboard d and D
#define KEY_E 0x08 // Keyboard e and E
#define KEY_F 0x09 // Keyboard f and F
#define KEY_G 0x0a // Keyboard g and G
#define KEY_H 0x0b // Keyboard h and H
#define KEY_I 0x0c // Keyboard i and I
#define KEY_J 0x0d // Keyboard j and J
#define KEY_K 0x0e // Keyboard k and K
#define KEY_L 0x0f // Keyboard l and L
#define KEY_M 0x10 // Keyboard m and M
#define KEY_N 0x11 // Keyboard n and N
#define KEY_O 0x12 // Keyboard o and O
#define KEY_P 0x13 // Keyboard p and P
#define KEY_Q 0x14 // Keyboard q and Q
#define KEY_R 0x15 // Keyboard r and R
#define KEY_S 0x16 // Keyboard s and S
#define KEY_T 0x17 // Keyboard t and T
#define KEY_U 0x18 // Keyboard u and U
#define KEY_V 0x19 // Keyboard v and V
#define KEY_W 0x1a // Keyboard w and W
#define KEY_X 0x1b // Keyboard x and X
#define KEY_Y 0x1c // Keyboard y and Y
#define KEY_Z 0x1d // Keyboard z and Z

#define KEY_1 0x1e // Keyboard 1 and !
#define KEY_2 0x1f // Keyboard 2 and @
#define KEY_3 0x20 // Keyboard 3 and #
#define KEY_4 0x21 // Keyboard 4 and $
#define KEY_5 0x22 // Keyboard 5 and %
#define KEY_6 0x23 // Keyboard 6 and ^
#define KEY_7 0x24 // Keyboard 7 and &
#define KEY_8 0x25 // Keyboard 8 and *
#define KEY_9 0x26 // Keyboard 9 and (
#define KEY_0 0x27 // Keyboard 0 and )

#define KEY_ENTER 0x28 // Keyboard Return (ENTER)
#define KEY_ESC 0x29 // Keyboard ESCAPE
#define KEY_BACKSPACE 0x2a // Keyboard DELETE (Backspace)
#define KEY_TAB 0x2b // Keyboard Tab
#define KEY_SPACE 0x2c // Keyboard Spacebar
#define KEY_MINUS 0x2d // Keyboard - and _
#define KEY_EQUAL 0x2e // Keyboard = and +
#define KEY_LEFTBRACE 0x2f // Keyboard [ and {
#define KEY_RIGHTBRACE 0x30 // Keyboard ] and }
#define KEY_BACKSLASH 0x31 // Keyboard \ and |
#define KEY_HASHTILDE 0x32 // Keyboard Non-US # and ~
#define KEY_SEMICOLON 0x33 // Keyboard ; and :
#define KEY_APOSTROPHE 0x34 // Keyboard ' and "
#define KEY_GRAVE 0x35 // Keyboard ` and ~
#define KEY_COMMA 0x36 // Keyboard , and <
#define KEY_DOT 0x37 // Keyboard . and >
#define KEY_SLASH 0x38 // Keyboard / and ?
#define KEY_CAPSLOCK 0x39 // Keyboard Caps Lock

#define KEY_F1 0x3a // Keyboard F1
#define KEY_F2 0x3b // Keyboard F2
#define KEY_F3 0x3c // Keyboard F3
#define KEY_F4 0x3d // Keyboard F4
#define KEY_F5 0x3e // Keyboard F5
#define KEY_F6 0x3f // Keyboard F6
#define KEY_F7 0x40 // Keyboard F7
#define KEY_F8 0x41 // Keyboard F8
#define KEY_F9 0x42 // Keyboard F9
#define KEY_F10 0x43 // Keyboard F10
#define KEY_F11 0x44 // Keyboard F11
#define KEY_F12 0x45 // Keyboard F12

#define KEY_SYSRQ 0x46 // Keyboard Print Screen
#define KEY_SCROLLLOCK 0x47 // Keyboard Scroll Lock
#define KEY_PAUSE 0x48 // Keyboard Pause
#define KEY_INSERT 0x49 // Keyboard Insert
#define KEY_HOME 0x4a // Keyboard Home
#define KEY_PAGEUP 0x4b // Keyboard Page Up
#define KEY_DELETE 0x4c // Keyboard Delete Forward
#define KEY_END 0x4d // Keyboard End
#define KEY_PAGEDOWN 0x4e // Keyboard Page Down
#define KEY_RIGHT 0x4f // Keyboard Right Arrow
#define KEY_LEFT 0x50 // Keyboard Left Arrow
#define KEY_DOWN 0x51 // Keyboard Down Arrow
#define KEY_UP 0x52 // Keyboard Up Arrow
#define KEY_POWER 0x66 // Keyboard Power
#define KEY_OPEN 0x74 // Keyboard Execute
#define KEY_HELP 0x75 // Keyboard Help
#define KEY_PROPS 0x76 // Keyboard Menu
#define KEY_FRONT 0x77 // Keyboard Select
#define KEY_STOP 0x78 // Keyboard Stop
#define KEY_AGAIN 0x79 // Keyboard Again
#define KEY_UNDO 0x7a // Keyboard Undo
#define KEY_CUT 0x7b // Keyboard Cut
#define KEY_COPY 0x7c // Keyboard Copy
#define KEY_PASTE 0x7d // Keyboard Paste
#define KEY_FIND 0x7e // Keyboard Find
#define KEY_MUTE 0x7f // Keyboard Mute
#define KEY_VOLUMEUP 0x80 // Keyboard Volume Up
#define KEY_VOLUMEDOWN 0x81 // Keyboard Volume Down
#define KEY_MAIL 0xb4 // E-mail
#define KEY_LEFTCTRL 0xe0 // Keyboard Left Control
#define KEY_LEFTSHIFT 0xe1 // Keyboard Left Shift
#define KEY_LEFTALT 0xe2 // Keyboard Left Alt
#define KEY_LEFTMETA 0xe3 // Keyboard Left GUI
#define KEY_RIGHTALT 0xe6 // Keyboard Right Alt

#define KEY_MEDIA_PLAYPAUSE 0xe8
#define KEY_MEDIA_STOPCD 0xe9
#define KEY_MEDIA_PREVIOUSSONG 0xea
#define KEY_MEDIA_NEXTSONG 0xeb
#define KEY_MEDIA_VOLUMEUP 0xed
#define KEY_MEDIA_VOLUMEDOWN 0xee
#define KEY_MEDIA_MUTE 0xef
#define KEY_MEDIA_WWW 0xf0
#define KEY_MEDIA_BACK 0xf1
#define KEY_MEDIA_FORWARD 0xf2
#define KEY_MEDIA_STOP 0xf3
#define KEY_MEDIA_FIND 0xf4
#define KEY_MEDIA_SCROLLUP 0xf5
#define KEY_MEDIA_SCROLLDOWN 0xf6
#define KEY_MEDIA_EDIT 0xf7
#define KEY_MEDIA_SLEEP 0xf8
#define KEY_MEDIA_COFFEE 0xf9
#define KEY_MEDIA_REFRESH 0xfa
#define KEY_MEDIA_CALC 0xfb
#define KEY_FUNC 0xfc

#define REPORT_MAGIC 0xa5

typedef struct {
    uint8_t key;
    uint16_t fn_mod_key;
} key_info_t;

const key_info_t g_keymap[KBD_ROW_NUMBER][KBD_COL_NUMBER] = {
    
    /***** Row 0 (from bottom) *****/
    {
        { KEY_NONE, KEY_NONE },                 /* Mouse right button*/
        { KEY_NONE, KEY_NONE },                 /* Function key */
        { KEY_NONE, KEY_NONE },                 /* Control key */
        { KEY_MINUS, KEY_NONE },                /* '_' */
        { KEY_EQUAL, KEY_NONE },                /* '=' */
        { KEY_NONE, KEY_NONE },                 /* ALT */
        { KEY_SPACE, KEY_NONE },                /* space */
        { KEY_NONE, KEY_NONE },                 /* ALT GR */
        { KEY_NONE, KEY_NONE },                 /* WIN */
        { KEY_LEFTBRACE, KEY_NONE },            /* '[' */
        { KEY_RIGHTBRACE, KEY_NONE },           /* ']' */
        { KEY_SLASH, KEY_NONE },                /* '/' */
    },

    /***** Row 1 (from bottom) *****/
    {
        { KEY_NONE, KEY_NONE },                 /* SHIFT */
        { KEY_Z, KEY_NONE },                    /* 'Z' */
        { KEY_X, KEY_NONE },                    /* 'X' */
        { KEY_C, KEY_NONE },                    /* 'C' */
        { KEY_V, KEY_NONE },                    /* 'V' */
        { KEY_B, KEY_NONE },                    /* 'B' */
        { KEY_N, KEY_NONE },                    /* 'N' */
        { KEY_M, KEY_NONE },                    /* 'M' */
        { KEY_COMMA, KEY_NONE },                /* ',' */
        { KEY_DOT, KEY_NONE },                  /* '.' */
        { KEY_SEMICOLON, KEY_NONE },            /* ';' */
        { KEY_APOSTROPHE, KEY_NONE },           /* '\'' */
    },

    /***** Row 2 (from bottom) *****/
    {
        { KEY_CAPSLOCK, KEY_NONE },                /* CAPS */
        { KEY_A, KEY_NONE },                 /* 'A' */
        { KEY_S, KEY_NONE },                 /* 'S' */
        { KEY_D, KEY_NONE },                 /* 'D' */
        { KEY_F, KEY_NONE },                 /* 'F' */
        { KEY_G, KEY_NONE },                 /* 'G' */
        { KEY_H, KEY_NONE },                 /* 'H' */
        { KEY_J, KEY_NONE },                 /* 'J' */
        { KEY_K, KEY_NONE },                 /* 'K' */
        { KEY_L, KEY_NONE },                 /* 'L' */
        { KEY_ENTER, ((KEY_MOD_CTRL | KEY_MOD_LALT) << 8) | KEY_DELETE },  /* ENTER / CTL+ALT+DEL */
        { KEY_END, KEY_PAGEDOWN },               /* END */
    },

    /***** Row 3 (from bottom) *****/
    {
        { KEY_TAB, KEY_NONE },               /* TAB */
        { KEY_Q, KEY_NONE },                 /* 'Q' */
        { KEY_W, KEY_NONE },                 /* 'W' */
        { KEY_E, KEY_NONE },                 /* 'E' */
        { KEY_R, KEY_NONE },                 /* 'R' */
        { KEY_T, KEY_NONE },                 /* 'T' */
        { KEY_Y, KEY_NONE },                 /* 'Y' */
        { KEY_U, KEY_NONE },                 /* 'U' */
        { KEY_I, KEY_NONE },                 /* 'I' */
        { KEY_O, KEY_NONE },                 /* 'O' */
        { KEY_P, KEY_NONE },                 /* 'P' */
        { KEY_BACKSLASH, KEY_NONE },         /* '\\' */
    },

    /***** Row 4 (from bottom) *****/
    {
        { KEY_GRAVE, KEY_NONE },             /* '`' */
        { KEY_1, KEY_NONE },                 /* '1' */
        { KEY_2, KEY_NONE },                 /* '2' */
        { KEY_3, KEY_NONE },                 /* '3' */
        { KEY_4, KEY_NONE },                 /* '4' */
        { KEY_5, KEY_NONE },                 /* '5' */
        { KEY_6, KEY_NONE },                 /* '6' */
        { KEY_7, KEY_NONE },                 /* '7' */
        { KEY_8, KEY_NONE },                 /* '8' */
        { KEY_9, KEY_NONE },                 /* '9' */
        { KEY_0, KEY_NONE },                 /* '0' */
        { KEY_BACKSPACE, KEY_NONE },         /* BACKSPACE */
    },

    /***** Row 5 (from bottom) *****/
    {
        { KEY_ESC, KEY_NONE },        /* ESC */
        { KEY_F1, KEY_NONE },         /* F1 */
        { KEY_F2, KEY_NONE },         /* F2 */
        { KEY_F3, KEY_NONE },         /* F3 */
        { KEY_F4, KEY_NONE },         /* F4 */
        { KEY_F5, KEY_NONE },         /* F5 */
        { KEY_F6, KEY_NONE },         /* F6 */
        { KEY_F7, KEY_SYSRQ },        /* F7 / PrintScr */
        { KEY_F8, KEY_NONE },         /* F8 */
        { KEY_F9, KEY_F11 },          /* F9 */
        { KEY_F10, KEY_F12 },         /* F10 */
        { KEY_DELETE, KEY_NONE },     /* DEL */
    },

    /***** Row 6 (vertical function buttons) *****/
    {
        { KEY_NONE, KEY_NONE },             /* Mouse left click */
        { KEY_MEDIA_VOLUMEUP, KEY_NONE },   /* VOLUME UP */
        { KEY_MEDIA_BACK, KEY_NONE },       /* REWIND */
        { KEY_MEDIA_PLAYPAUSE, KEY_NONE},   /* PLAY/PAUSE */
        { KEY_MEDIA_FORWARD, KEY_NONE },    /* FORWARD */
        { KEY_MEDIA_VOLUMEDOWN, KEY_NONE }, /* VOLUME DOWN */
        { KEY_UP, KEY_NONE },               /* UP */
        { KEY_LEFT,  KEY_NONE },            /* LEFT */
        { KEY_OPEN, KEY_NONE },             /* OK */
        { KEY_RIGHT, KEY_NONE },            /* RIGHT */
        { KEY_DOWN, KEY_NONE },             /* DOWN */
        { KEY_HOME, KEY_PAGEUP },           /* HOME/PAGEUP */
    },

    /***** Row 7 (vertical function buttons) *****/
    {
        { KEY_POWER, KEY_NONE},             /* POWER */
        { KEY_MEDIA_STOPCD, KEY_NONE },     /* PLAY */
        { KEY_MEDIA_MUTE, KEY_NONE },       /* MUTE */
        { KEY_MAIL, KEY_NONE },             /* MAIL */
        { KEY_MEDIA_FIND, KEY_NONE },       /* SEARCH */
        { KEY_FRONT, KEY_NONE },             /* HOME */
        { KEY_MEDIA_WWW, KEY_NONE },        /* WEB */
        { KEY_MEDIA_SCROLLUP, KEY_NONE},    /* SCROLL */
    },
};

#endif /* __INC_KEYMAP_H */