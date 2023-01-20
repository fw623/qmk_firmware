/* Copyright 2020 fw623 (https://github.com/fw623/)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "keymap_german.h"
#include "moonlander.h"

#define LAYER_ON_OFF(on, layer) { if (on) { layer_on(layer); } else { layer_off(layer); } }
#define REGISTER_OR_UNREGISTER_CODE(register, code) { if (register) { register_code(code); } else { unregister_code(code); } }
#define REGISTER_OR_UNREGISTER_CODE16(register, code) { if (register) { register_code16(code); } else { unregister_code16(code); } }

/* ========== LAYER definitions ========== */
enum layer {
    L_LOWER,
    L_UPPER,
    L_NUM,
    L_NUM2,
    L_CZ,
    L_FN,
    L_SYMBOL,
    L_SYMBOL2,
    L_LCTL,
    L_MOUSE,
    L_QWERTZ,
    L_GAMING,
    L_GAMING_TOGGLE, // toggle handling for gaming
    L_NAV,
};
#define MY_MAX_LAYER L_NAV

/* ========== LAYOUT definitions ========== */
enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
    ST_IGN,  // ignored
    ST_CIRC, // circumflex (not dead)
    ST_GRVE, // grave accent (not dead)
    ST_RPTU, // repeat UP
    ST_RPTD, // repeat DOWN
    ST_RPTL, // repeat LEFT
    ST_RPTR, // repeat RIGHT
    ST_SFT,  // custom oneshot shift
    ST_SYMB, // custom oneshot symbol layer
    ST_NUM,  // custom oneshot number layer
    ST_FN,   // custom oneshot function key layer
    ST_LOCK, // lock currently pressed keys until either `ST_LOCK` is hit again, or locked key is pressed
    ST_TOG,
    ST_INC,
    ST_DEC,
    ST_RST,
    TM_REC,  // record a timed macro while held
    TM_PLAY, // toggle repeated playing of most recently recorded timed macro
    TGL_W,    // toggle W
    TGL_S,    // normal S but also release toggled W
    TGL_LSFT, // toggle LSHIFT
};

#define ZC_ECAR UC(0x011b) // ě
#define ZC_SCAR UC(0x0161) // š
#define ZC_CCAR UC(0x010d) // č
#define ZC_RCAR UC(0x0159) // ř
#define ZC_ZCAR UC(0x017e) // ž
#define ZC_NCAR UC(0x0148) // ň
#define ZC_DCAR UC(0x010f) // ď
#define ZC_TCAR UC(0x0165) // ť
#define ZC_YACU UC(0x00fd) // ý
#define ZC_AACU UC(0x00e1) // á
#define ZC_IACU UC(0x00ed) // í
#define ZC_EACU UC(0x00e9) // é
#define ZC_UACU UC(0x00fa) // ú
#define ZC_OACU UC(0x00f3) // ó
#define ZC_URNG UC(0x016f) // ů

#define TG_GAME TG(L_GAMING)
#define TG_QWTZ TG(L_QWERTZ)
#define TT_NAV  TT(L_NAV)
#define TT_NUM  TT(L_NUM)
#define TT_FN   TT(L_FN)
#define MO_FN   MO(L_FN)
#define TT_GAME TT(L_GAMING)
#define TG_TGL  TG(L_GAMING_TOGGLE)

#define CTL_ENT LCTL_T(KC_ENTER)
#define CTL_ESC LCTL_T(KC_ESCAPE)
#define ALT_ESC LALT_T(KC_ESCAPE)
#define ALT_ENT LALT_T(KC_ENTER)
#define GUI_ESC LGUI_T(KC_ESCAPE)
#define GUI_ENT LGUI_T(KC_ENTER)
#define SFT_MINS LSFT_T(DE_MINS)
/* #define SFT_SPC LSFT_T(KC_SPC) // NOTE: this disables CTL for tap */
#define SFT_SPC LSFT_T(KC_SPC)
#define LSFT_RA LSFT_T(KC_RIGHT)
#define LSFT_LA LSFT_T(KC_LEFT)
#define LSFT_DA LSFT_T(KC_DOWN)
#define LSFT_UA LSFT_T(KC_UP)

#define SYM_UNDS LT(L_SYMBOL, DE_UNDS)
#define NUM_SLSH LT(L_NUM, DE_SLSH)
#define NUMCAPS LT(L_NUM, KC_CAPS)
#define FN_SPC  LT(L_FN, KC_SPC)
#define CZ_SPC  LT(L_CZ, KC_SPC)


extern const uint16_t PROGMEM keymaps[MY_MAX_LAYER + 1][MATRIX_ROWS][MATRIX_COLS];

/* ========== LED definitions ========== */
#define ooooooo {  0,  0,  0} // LED off
#define BLUE    {154,255,255}
#define YELLOW  { 35,255,255}
#define FLESH   {249,228,255}
#define CYAN    {105,255,255}
#define PINK    {205,255,255}
#define PINK_RGB 209,  0,255

// Layer colors
#define RGB_L_SFT  255, 255,   0 // red
#define RGB_L_SYMB 255, 255, 255 // white
#define RGB_L_NUM    0, 255,   0 // green
#define RGB_L_FN     0, 255, 255 // cyan
#define RGB_L_NAV  255,   0,   0 // red
#define RGB_CAPS   PINK_RGB

extern const uint8_t PROGMEM ledmap[MY_MAX_LAYER + 1][DRIVER_LED_TOTAL][3];
