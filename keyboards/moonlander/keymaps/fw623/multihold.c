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

#include "multihold.h"

static multihold_t multiholds[MULTIHOLDS_LEN] = {
    {.layer = L_NUM2, .keys_len = 2, .keys = {{CTL_ESC, KC_NO, false}, {GUI_ENT, KC_LGUI, false}}},
    {.layer = L_SYMBOL2, .keys_len = 2, .keys = {{ALT_ENT, KC_NO, false}, {GUI_ESC, KC_LGUI, false}}},
};

bool handle_multiholds(uint16_t keycode, keyrecord_t *record) {
    bool mh_exit = false;
    for (int i = 0; i < MULTIHOLDS_LEN; i++) {
        multihold_t *    mh               = multiholds + i;
        multihold_key_t *key              = NULL;
        bool             were_all_pressed = true, are_all_pressed = true;
        for (int j = 0; j < mh->keys_len; j++) {
            if (!mh->keys[j].pressed) {
                were_all_pressed = false;
            }
            if (mh->keys[j].keycode == keycode) {
                mh->keys[j].pressed = record->event.pressed;
                key                 = mh->keys + j;
            }
            if (!mh->keys[j].pressed) {
                are_all_pressed = false;
            }
        }

        if (!were_all_pressed && are_all_pressed) {
            for (int j = 0; j < mh->keys_len; j++) {
                if (mh->keys[j].release_during_multihold != KC_NO) {
                    unregister_code16(mh->keys[j].release_during_multihold);
                }
            }
            layer_on(mh->layer);
        } else if (were_all_pressed && !are_all_pressed) {
            layer_off(mh->layer);
            for (int j = 0; j < mh->keys_len; j++) {
                if (mh->keys[j].release_during_multihold != KC_NO && mh->keys[j].pressed) {
                    register_code16(mh->keys[j].release_during_multihold);
                }
            }
        }

        mh_exit = mh_exit || ((were_all_pressed != are_all_pressed) && key->release_during_multihold != KC_NO);
    }

    return !mh_exit;
}
