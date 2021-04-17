/* Copyright 2021 fw623 (https://github.com/fw623/)
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

#include "custom_lock.h"
#include "layout.h"

static bool    locked_matrix[MATRIX_ROWS][MATRIX_COLS];  // keyboard matrix indicating whether key was locked
static uint8_t locked_layer;                             // highest active layer at time of locking

// lock all currently pressed keys; release all still locked but not pressed keys
static void activate_custom_lock(void) {
    bool    any_key_pressed = false;  // non-`ST_LOCK`-key pressed
    uint8_t current_layer   = 0;
    for (uint8_t l = MY_MAX_LAYER; l >= 0; l--) {
        if (IS_LAYER_ON(l)) {
            current_layer = l;
            break;
        }
    }

    for (uint8_t c = 0; c < MATRIX_COLS; c++) {
        for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
            // simulate release if it is still locked but should no longer be
            keypos_t sim_keypos = {.col = c, .row = r};
            if (matrix_is_on(r, c) && keymap_key_to_keycode(current_layer, sim_keypos) != ST_LOCK) {
                any_key_pressed = true;
                break;
            }
        }
    }

    if (any_key_pressed) {  // any key pressed -> just add that
        for (uint8_t c = 0; c < MATRIX_COLS; c++) {
            for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
                locked_matrix[r][c] = matrix_is_on(r, c) || locked_matrix[r][c];
            }
        }
    } else {  // no key pressed -> release all locked keys and reset lock status
        for (uint8_t c = 0; c < MATRIX_COLS; c++) {
            for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
                // simulate release if it is still locked but should no longer be
                if (locked_matrix[r][c] && !matrix_is_on(r, c)) {
                    keypos_t sim_keypos  = {.col = c, .row = r};
                    uint16_t sim_keycode = keymap_key_to_keycode(locked_layer, sim_keypos);
                    unregister_code16(sim_keycode);
                }

                locked_matrix[r][c] = matrix_is_on(r, c);
            }
        }
    }

    // save layer that's ON when locking
    locked_layer = current_layer;
}

bool handle_custom_lock(uint16_t keycode, keyrecord_t *record) {
    // swallow release of locked key; release before first press while locked
    if (keycode != ST_LOCK && locked_matrix[record->event.key.row][record->event.key.col]) {
        if (record->event.pressed) {
            unregister_code16(keycode);
            locked_matrix[record->event.key.row][record->event.key.col] = false;
        } else {
            return false;
        }
    }

    if (keycode == ST_LOCK && record->event.pressed) {
        activate_custom_lock();
    }

    return true;
}
