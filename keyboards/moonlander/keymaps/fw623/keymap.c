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

#include "action_layer.h"
#include "quantum.h"
#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "config.h"
#include "moonlander.h"
#include "layout.h"
#include "custom_oneshot.h"
#include "multihold.h"
#include "custom_lock.h"
#include "tmacro.h"
#include "quickrepeat.h"

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

/* ========== LED stuff ========== */
void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

/* set layer color on both "piano keys" */
static void set_layer_lock_color(bool *other_active, uint8_t r, uint8_t g, uint8_t b) {
    if (!(*other_active)) { rgb_matrix_set_color(35, r, g, b); }
    rgb_matrix_set_color(71, r, g, b);

    *other_active = true;
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

    bool other_active = false;

    // custom oneshot layers locked
    for (int i = 0; i < NUM_COSM; i++) {
        if (custom_oneshots[i].locked) {
            RGB rgb = custom_oneshots[i].rgb;
            set_layer_lock_color(&other_active, rgb.r, rgb.g, rgb.b);
        }
    }

    // tap toggle layers
    if (IS_LAYER_ON(L_NUM) && !matrix_is_on(4, 3)) { set_layer_lock_color(&other_active, RGB_L_NUM); }
    if (IS_LAYER_ON(L_FN) && !matrix_is_on(4, 3)) { set_layer_lock_color(&other_active, RGB_L_FN); }
    if (IS_LAYER_ON(L_NAV) && !matrix_is_on(10, 4)) { set_layer_lock_color(&other_active, RGB_L_NAV); }

    // caps lock
    if (!IS_LAYER_ON(L_GAMING) && host_keyboard_led_state().caps_lock) {
        set_layer_lock_color(&other_active, RGB_CAPS);
    }
}

void rgb_matrix_indicators_user(void) {
    /* if (g_suspend_state || keyboard_config.disable_layer_led) { return; } */
    if (keyboard_config.disable_layer_led) { return; } // TODO: figure out why `g_suspend_state` is no longer defined

    uint8_t layer = biton32(layer_state);
    if (L_LOWER <= layer && layer <= MY_MAX_LAYER) {
        set_layer_color(layer);
    } else {
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) { rgb_matrix_set_color_all(0, 0, 0); }
    }
}

/* ========== LAYOUT custom stuff ========== */
static void repeat(keyrecord_t *record, uint8_t code, int times) {
    if (record->event.pressed) {
        for (int i = 0; i < times - 1; i++) { tap_code(code); }
        register_code(code);
    } else {
        unregister_code(code);
    }
}

void layer_on_state(layer_state_t *state, uint8_t layer) {
    *state = (*state) | ((layer_state_t)1 << layer);
}
void layer_off_state(layer_state_t *state, uint8_t layer) {
    *state = (*state) & ~((layer_state_t)1 << layer);
}

/* ========== LAYOUT predefined stuff ========== */
void matrix_scan_user(void) {
    timeout_cosms(); // custom oneshot modifiers
    /* handle_quickrepeat_timer(); */
    handle_tmacro_timer();
}

static bool TGL_W_is_active = false, TGL_LSFT_is_active = false;
static bool hash_is_pressed = false;
static bool reenable_number_layer = false;
static uint16_t last_keycode = KC_NO, current_keycode = KC_NO;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    last_keycode = current_keycode;
    current_keycode = keycode;

    if ((last_keycode == SYM_UNDS || last_keycode == NUM_SLSH) && !IS_LAYER_ON(L_UPPER)) {
        unregister_code(KC_LSFT);
    }
    if ((last_keycode == KC_COMM) && IS_LAYER_ON(L_UPPER)) {
        register_code(KC_LSFT);
    }
    /* if (last_keycode == SFT_SPC && IS_LAYER_ON(L_LCTL)) { */
    /*     register_code(KC_LCTL); */
    /* } */

    if (!handle_custom_lock(keycode, record)) { return false; }
    if (!handle_cosms(keycode, record)) { return false; }
    if (!handle_multiholds(keycode, record)) { return false; }
    if (!handle_tmacro(keycode, record)) { return false; }
    /* if (!handle_quickrepeat(keycode, record)) { return false; } */


    /* if (keycode == SFT_MINS && last_keycode == CZ_SPC) { */
    /*     return false; */
    /* } */

    switch (keycode) {
    case SFT_SPC:
    case SFT_MINS:
    case LSFT_RA:
    case LSFT_LA:
    case LSFT_DA:
    case LSFT_UA:
        LAYER_ON_OFF(record->event.pressed, L_UPPER);
        break;
    }

    switch (keycode) {
    case CTL_ESC:
        LAYER_ON_OFF(record->event.pressed, L_LCTL);
        break;
        /* case SFT_SPC: */
        /*     if (IS_LAYER_ON(L_LCTL)) { */
        /*         // disable CTL for space tap */
        /*         REGISTER_OR_UNREGISTER_CODE(!record->event.pressed, KC_LCTL); */
        /*     } */
        /*     break; */
    case SYM_UNDS:
    case NUM_SLSH:
        // NOTE: we must register shift manually because it doesn't work automatically for TAP part
        if (!IS_LAYER_ON(L_UPPER)) {
            REGISTER_OR_UNREGISTER_CODE(record->event.pressed, KC_LSFT);
        }
        break;
    case KC_COMM:
        // NOTE: we must unregister shift temporarily
        if (IS_LAYER_ON(L_UPPER)) {
            REGISTER_OR_UNREGISTER_CODE(!record->event.pressed, KC_LSFT);
        }
        break;
    case DE_HASH:
        hash_is_pressed = record->event.pressed;
        break;
    case DE_COLN:
        if (hash_is_pressed && record->event.pressed) {
            // NOTE: we'll later also send a release of DE_COLN, but that shouldn't matter
            tap_code16(DE_QUOT);
            return false;
        }
        break;
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
    case KC_RSFT:
        LAYER_ON_OFF(record->event.pressed, L_UPPER);
        // we need to call this here to get layer LEDs activated (for whatever reason)
        return process_action_kb(record);
    case RGB_SLD:
        if (record->event.pressed) { rgblight_mode(1); }
        return false;
    case TGL_W:
        if (record->event.pressed) {
            TGL_W_is_active = !TGL_W_is_active;
            REGISTER_OR_UNREGISTER_CODE(TGL_W_is_active, KC_W);
        }
        break;
    case TGL_S:
        if (TGL_W_is_active) {
            TGL_W_is_active = false;
            unregister_code(KC_W);
        }
        REGISTER_OR_UNREGISTER_CODE(record->event.pressed, KC_S);
        break;
    case TGL_LSFT:
        if (record->event.pressed) {
            TGL_LSFT_is_active = !TGL_LSFT_is_active;
            REGISTER_OR_UNREGISTER_CODE(TGL_LSFT_is_active, KC_LSFT);
        }
        break;
    case CZ_NUM:
        if (record->event.pressed) {
            if (IS_LAYER_ON(L_NUM)) {
                reenable_number_layer = true;
                layer_off(L_NUM);
            } else {
                reenable_number_layer = false;
                layer_on(L_CZ);
            }
        } else {
            if (last_keycode == CZ_NUM) {
                if (reenable_number_layer) {
                    layer_off(L_NUM);
                } else {
                    layer_off(L_CZ);
                    layer_on(L_NUM);
                }
            } else {
                if (reenable_number_layer) {
                    layer_on(L_NUM);
                } else {
                    layer_off(L_CZ);
                }
            }
        }
        break;
    }

    return true;
}


static layer_state_t last_layer_state = 0;
static bool reenable_gaming_toggle_layer = false;

/* calling `tap_code` inside `layer_state_set_user` seems to cause the keyboard to hang */
/* calling `layer_on` etc inside `layer_state_set_user` does not actually apply the changes */
layer_state_t layer_state_set_user(layer_state_t state) {
    if (IS_LAYER_ON_STATE(state ^ last_layer_state, L_GAMING)) {
        if (host_keyboard_led_state().caps_lock) {
            unregister_code(KC_LOCKING_CAPS_LOCK);
        }

        if (IS_LAYER_ON_STATE(state, L_GAMING) && reenable_gaming_toggle_layer) {
            layer_on_state(&state, L_GAMING_TOGGLE);
        }
        if (IS_LAYER_OFF_STATE(state, L_GAMING)) {
            reenable_gaming_toggle_layer = IS_LAYER_ON_STATE(state, L_GAMING_TOGGLE);
            layer_off_state(&state, L_GAMING_TOGGLE);
        }
    }

    if (IS_LAYER_ON_STATE(state ^ last_layer_state, L_GAMING_TOGGLE)) {
        if (IS_LAYER_OFF_STATE(state, L_GAMING_TOGGLE)) {
            if (TGL_W_is_active) {
                TGL_W_is_active = false;
                unregister_code(KC_W);
            }
            if (TGL_LSFT_is_active) {
                TGL_LSFT_is_active = false;
                unregister_code(KC_LSFT);
            }
        }
    }

    last_layer_state = state;
    return state;
}
