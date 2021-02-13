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

bool is_cosm_key (uint16_t keycode) {
  for (int i = 0; i < NUM_COSM; i++) {
    if (custom_oneshots[i].trigger == keycode) { return true; }
  }
  return false;
}

void timeout_cosm (cosm_t *cosm) {
  if (cosm->oneshot_active && timer_elapsed(cosm->released_at) > COSM_TIMEOUT) {
    cosm->oneshot_active = false;
  }
}

void timeout_cosms (void) {
  for (int i = 0; i < NUM_COSM; i++) {
    timeout_cosm(custom_oneshots + i);
  }
}

#define SET_COSM { cosm->active = true; \
                   if (cosm->layer >= 0) { layer_on(cosm->layer); }	\
                   if (cosm->keycode != KC_NO) { register_code(cosm->keycode); } }

#define UNSET_COSM { cosm->active = false; \
                     if (cosm->layer >= 0) { layer_off(cosm->layer); }			\
                     if (cosm->keycode != KC_NO) { unregister_code(cosm->keycode); } }


bool handle_cosm (cosm_t *cosm, uint16_t keycode, keyrecord_t *record) {
  if (keycode == cosm->trigger) { // cosm key
    if (record->event.pressed) { // pressed
      cosm->pressed = true;
      cosm->interrupted = false;
      cosm->oneshot_active = false;
      cosm->locked = false;

	SET_COSM;
    } else { // released
      cosm->pressed = false;
      cosm->released_at = timer_read();
      
      if (cosm->interrupted) { // interrupted ==> reset unset layer and keycode
	UNSET_COSM;
      } else { // not interrupted ==> activate oneshot behaviour
	cosm->oneshot_active = true;
      }
    }

    return false;

    
  } else { // other key
    if (record->event.pressed) {
      if (cosm->pressed) {
	cosm->interrupted = true;
      } else if (cosm->oneshot_active) {
	cosm->oneshot_active = false;
      } else {
        if (cosm->active) { UNSET_COSM; }
      }
    }

    return true;
  }
}

bool handle_cosms (uint16_t keycode, keyrecord_t *record) {
  for (int i = 0; i < NUM_COSM; i++) {
    if (!handle_cosm(custom_oneshots + i, keycode, record)) { return false; }
  }
  return true;
}

