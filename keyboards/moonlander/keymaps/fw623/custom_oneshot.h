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

#include "quantum.h"

// Custom One Shot Modifier (or Layer)
typedef struct cosm_t {
  const uint16_t trigger;
  const int layer; // ignored iff < 0
  const uint16_t keycode; // ignored iff == KC_NO
  uint16_t released_at;
  bool active;
  bool pressed;
  bool interrupted;
} cosm_t;

#define NUM_COSM 2
extern cosm_t custom_oneshots[NUM_COSM];

bool handle_cosm (cosm_t *cosm, uint16_t keycode, keyrecord_t *record);
void set_cosm (cosm_t *cosm);
void reset_cosm (cosm_t *cosm);
void timeout_cosm (cosm_t *cosm);
