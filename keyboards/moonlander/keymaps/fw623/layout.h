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

#define MO_USER(layer) { if (record->event.pressed) { layer_on(L_SHCUT); } else { layer_off(L_SHCUT); } }

/* ========== LAYER definitions ========== */
enum layer {
  L_LOWER,
  L_UPPER,
  L_SHCUT,
  L_NAV,
  L_NUM,
  L_FN,
  L_SYMBOL,
  L_MOUSE,
  // L_GREEK_L,
  // L_GREEK_U,
  // L_MATH, // maybe latex instead of math
  L_QWERTZ,
  L_GAMING,
  L_CUBING,
  // L_KEYVAL,
};
#define MY_MAX_LAYER L_CUBING

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
  ST_C_X,  // Ctrl+X on press, holds Ctrl until released
  ST_M_X,  // Alt+X on press, holds Alt until released
  ST_LOCK, // lock currently pressed keys until either `ST_LOCK` is hit again, or locked key is pressed
};

#define TG_GAME TG(L_GAMING)
#define TG_QWTZ TG(L_QWERTZ)
#define TG_CUBE TG(L_CUBING)
#define TT_NAV  TT(L_NAV)
#define CTL_ENT LCTL_T(KC_ENTER)
#define CTL_ESC LCTL_T(KC_ESCAPE)
#define ALT_ESC LALT_T(KC_ESCAPE)
#define ALT_ENT LALT_T(KC_ENTER)
#define NUMCAPS LT(L_NUM, KC_CAPS)
#define MO_FN   MO(L_FN)
#define FN_SPC  LT(L_FN, KC_SPC)

extern const uint16_t PROGMEM keymaps[MY_MAX_LAYER + 1][MATRIX_ROWS][MATRIX_COLS];

/* ========== LED definitions ========== */
#define ooooooo {  0,  0,  0} // LED off
#define BLUE    {154,255,255}
#define YELLOW  { 35,255,255}
#define FLESH   {249,228,255}
#define CYAN    {105,255,255}
#define PINK    {205,255,255}
#define PINK_RGB 209,  0,255

extern const uint8_t PROGMEM ledmap[MY_MAX_LAYER + 1][DRIVER_LED_TOTAL][3];
