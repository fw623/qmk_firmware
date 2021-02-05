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

#include "custom_oneshot.h"
#include "layout.h"
#include "config.h"

// TODO: proper handling of lockmode

cosm_t custom_oneshots[NUM_COSM] = {
  { ST_SFT,  L_UPPER,  KC_RSFT, 0, false, false, false, false },
  { ST_SYMB, L_SYMBOL, KC_NO,   0, false, false, false, false },
  { ST_NUM,  L_NUM,    KC_NO,   0, false, false, false, false },
};

void reset_cosm (cosm_t *cosm) {
  if (cosm->keycode != KC_NO) { unregister_code(cosm->keycode); }
  if (cosm->layer >= 0) { layer_off(cosm->layer); }
  cosm->active = false;
}

void set_cosm (cosm_t *cosm) {
  if (cosm->layer >= 0) { layer_on(cosm->layer); }
  if (cosm->keycode != KC_NO) { register_code(cosm->keycode); }
  cosm->interrupted = false;
  cosm->active = true;

  // reset others
  for (int i = 0; i < NUM_COSM; i++) {
    if (custom_oneshots + i != cosm) { reset_cosm(custom_oneshots + i); }
  }
}

void timeout_cosm (cosm_t *cosm) {
  if (cosm->active && !cosm->pressed && !cosm->locked && timer_elapsed(cosm->released_at) > ONESHOT_TIMEOUT) {
    reset_cosm(cosm);
  }
}

bool handle_cosm (cosm_t *cosm, uint16_t keycode, keyrecord_t *record) {
  if (cosm->active && record->event.pressed && keycode != cosm->trigger && !cosm->locked) {
    // handle interrupts
    if (!cosm->pressed && cosm->interrupted) { reset_cosm(cosm); }
    cosm->interrupted = true;
  } else if (keycode == cosm->trigger) {
    // handle this key
    cosm->pressed = record->event.pressed;
    if (record->event.pressed) {
      if (cosm->active && !cosm->interrupted) {
        cosm->locked = !cosm->locked;
      } else {
        set_cosm(cosm);
      }
    } else {
      cosm->released_at = timer_read();
      if (cosm->interrupted) { reset_cosm(cosm); }
    }
    return false;
  }

  return true;
}
