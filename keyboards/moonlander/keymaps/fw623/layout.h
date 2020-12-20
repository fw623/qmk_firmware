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

#define REGISTER_TAP(keycode) { register_code(keycode); unregister_code(keycode); }
#define REGISTER_TAP16(keycode) { register_code16(keycode); unregister_code16(keycode); }
#define MO_USER(layer) { if (record->event.pressed) { layer_on(L_SHCUT); } else { layer_off(L_SHCUT); } }

/* ========== LAYER definitions ========== */
enum layer {
  L_LOWER,
  L_FN,
  L_UPPER,
  L_SHCUT,
  L_NAV,
  L_SYMBOL,
  L_NUM,
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
  ST_CIRC,
  ST_GRVE,
  ST_RPTU,
  ST_RPTD,
  ST_RPTL,
  ST_RPTR,
  ST_SFT,
  ST_SYMB,
};

#define TG_GAME TG(L_GAMING)
#define TG_QWTZ TG(L_QWERTZ)
#define TG_CUBE TG(L_CUBING)
#define TT_NAV  TT(L_NAV)
#define CTL_ESC LCTL_T(KC_ESC)
#define NUMCAPS LT(L_NUM, KC_CAPS)

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
