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

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "config.h"
#include "moonlander.h"
#include "layout.h"
#include "custom_oneshot.h"

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;
static uint16_t prev_keycode = KC_NO, curr_keycode = KC_NO;

/* ========== LED stuff ========== */
void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
  if (!IS_LAYER_ON(L_GAMING) && host_keyboard_led_state().caps_lock) {
    rgb_matrix_set_color(19, PINK_RGB);
    rgb_matrix_set_color(35, PINK_RGB);
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }

  uint8_t layer = biton32(layer_state);
  if (L_LOWER <= layer && layer <= MY_MAX_LAYER) {
    set_layer_color(layer);
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) { rgb_matrix_set_color_all(0, 0, 0); }
  }
}

/* ========== LAYOUT stuff ========== */
static void repeat(keyrecord_t *record, uint8_t code, int times) {
  if (record->event.pressed) {
    for (int i = 0; i < times - 1; i++) { tap_code(code); }
    register_code(code);
  } else {
    unregister_code(code);
  }
}

void matrix_scan_user(void) {
  // handle timeout for Custom One Shot Modifiers (Layers)
  for (int i = 0; i < NUM_COSM; i++) { timeout_cosm(custom_oneshots + i); }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  prev_keycode = curr_keycode;
  curr_keycode = keycode;

  // handle Custom One Shot Modifiers (Layers)
  for (int i = 0; i < NUM_COSM; i++) {
    if (!handle_cosm(custom_oneshots + i, keycode, record)) { return false; }
  }

  switch (keycode) {
    case ST_CIRC:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_GRAVE) SS_TAP(X_SPACE));
      }
      break;
    case ST_GRVE:
      if (record->event.pressed) {
        tap_code16(DE_GRV);
        tap_code(KC_SPC);
      }
      break;
    case ST_RPTU:
      repeat(record, KC_UP, 8);
      break;
    case ST_RPTD:
      repeat(record, KC_DOWN, 8);
      break;
    case ST_RPTL:
      repeat(record, KC_LEFT, 12);
      break;
    case ST_RPTR:
      repeat(record, KC_RIGHT, 12);
      break;
    /* case CTL_ENT:
    case KC_LALT:
    case KC_LGUI:
      if (!IS_LAYER_ON(L_EMACS)) { MO_USER(L_SHCUT); }
      // we need to call this here to get layer LEDs activated (for whatever reason)
      return process_action_kb(record); */
    case KC_RSFT:
      MO_USER(L_UPPER);
      // we need to call this here to get layer LEDs activated (for whatever reason)
      return process_action_kb(record);
    case TG(L_GAMING):
      // unset CAPS on L_GAMING toggle
      if (!record->event.pressed && host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
      }
      return true;
    /* case TG_EMAC:
      if (record->event.pressed) {
        layer_off(L_SHCUT);
      }
      // we need to call this here to get layer LEDs activated (for whatever reason)
      return process_action_kb(record); */
    case ST_C_X:
      if (record->event.pressed) {
        register_code(KC_LCTRL);
        tap_code(KC_X);
      } else {
        unregister_code(KC_LCTRL);
      }
      return false;
    case ST_M_X:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_X);
      } else {
        unregister_code(KC_LALT);
      }
      return false;
    case RGB_SLD:
      if (record->event.pressed) { rgblight_mode(1); }
      return false;
  }
  return true;
}
