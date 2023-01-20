/* Copyright 2023 fw623 (https://github.com/fw623/)
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


#include "quickrepeat.h"

/*
 * this is a WIP attempt at repeatedly holding a key for a period and then releasing
 */

bool quickrepeat_enabled = false;
bool quickrepeat_active = false;
uint16_t quickrepeat_period_base = 100; // in ms
uint16_t quickrepeat_period = 100; // in ms
/* uint16_t quickrepeat_on_duration = 1; // in ms */
uint16_t quickrepeat_stepsize = 5; // in ms
uint16_t quickrepeat_periodstart = 0;
uint16_t quickrepeat_keycode = KC_NO;
uint16_t quickrepeat_last_keycode = KC_NO;

void quickrepeat_on(void) {
    if (quickrepeat_active) return;
    quickrepeat_active = true;

    register_code16(quickrepeat_keycode);
}

void quickrepeat_off(void) {
    if (!quickrepeat_active) return;
    quickrepeat_active = false;

    unregister_code16(quickrepeat_keycode);
}

bool handle_quickrepeat (uint16_t keycode, keyrecord_t *record) {
    if (keycode < SAFE_RANGE) {
        quickrepeat_last_keycode = keycode;
    }

    switch (keycode) {
    case ST_TOG:
        if (record->event.pressed) {
            quickrepeat_enabled = !quickrepeat_enabled;
            if (!quickrepeat_enabled) {
                quickrepeat_off();
            } else {
                quickrepeat_keycode = quickrepeat_last_keycode;
            }
        }
        quickrepeat_periodstart = timer_read();
        return false;
    case ST_RST:
        /* quickrepeat_on_duration = quickrepeat_period; */
        quickrepeat_period = quickrepeat_period_base;
        quickrepeat_periodstart = timer_read();
        return false;
    case ST_INC:
        if (quickrepeat_period - quickrepeat_stepsize > 0)
            quickrepeat_period -= quickrepeat_stepsize;
        /* if (quickrepeat_on_duration + quickrepeat_stepsize <= quickrepeat_period) { */
        /*     quickrepeat_on_duration += quickrepeat_stepsize; */
        /* } */
        return false;
    case ST_DEC:
        quickrepeat_period += quickrepeat_stepsize;
        /* if (quickrepeat_on_duration - quickrepeat_stepsize >= 0) { */
        /*     quickrepeat_on_duration -= quickrepeat_stepsize; */
        /* } */
        return false;
    }

    return true;
}

void handle_quickrepeat_timer(void) {
    if (quickrepeat_enabled) {
        uint16_t since_periodstart = timer_elapsed(quickrepeat_periodstart);
        if (since_periodstart >= quickrepeat_period) {
            /* if (quickrepeat_on_duration > 0) */
            quickrepeat_on();
            quickrepeat_periodstart = timer_read();
            /* } else if (since_periodstart >= quickrepeat_on_duration) { */
        } else if (since_periodstart >= quickrepeat_period/2) {
            /* if (quickrepeat_on_duration < quickrepeat_period) */
            quickrepeat_off();
        }
    }
}
