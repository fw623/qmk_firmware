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
#define NUMCAPS LCTL_T(KC_ESC)
#define CTL_ESC LT(L_NUM, KC_CAPS)

const uint16_t PROGMEM keymaps[MY_MAX_LAYER][MATRIX_ROWS][MATRIX_COLS];

/* ========== LED definitions ========== */
#define ooooooo {  0,  0,  0} // LED off
#define BLUE    {154,255,255}
#define YELLOW  { 35,255,255}
#define FLESH   {249,228,255}
#define CYAN    {105,255,255}
#define PINK    {205,255,255}
#define PINK_RGB 209,  0,255

const uint8_t PROGMEM ledmap[MY_MAX_LAYER][DRIVER_LED_TOTAL][3];
