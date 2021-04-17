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

#pragma once

#include "stdbool.h"
#include "stdint.h"
#include "layout.h"

typedef struct multihold_key_t {
    const uint16_t keycode;
    const int      release_during_multihold;  // ignored iff == KC_NO
    bool           pressed;
} multihold_key_t;

#define MULTIHOLDS_LEN 2
typedef struct multihold_t {
    uint16_t        layer;
    const uint8_t   keys_len;
    multihold_key_t keys[MULTIHOLDS_LEN];  // keycodes assumed to be unique
} multihold_t;

bool handle_multiholds(uint16_t keycode, keyrecord_t *record);
