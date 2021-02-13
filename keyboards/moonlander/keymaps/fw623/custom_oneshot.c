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

cosm_t custom_oneshots[NUM_COSM] = {
  { ST_SFT,  L_UPPER,  KC_RSFT, false, 0, false, false, false, false },
  { ST_SYMB, L_SYMBOL, KC_NO,   false, 0, false, false, false, false },
  { ST_NUM,  L_NUM,    KC_NO,   false, 0, false, false, false, false },
};

static bool is_cosm_key (uint16_t keycode) {
  for (int i = 0; i < NUM_COSM; i++) {
    if (custom_oneshots[i].trigger == keycode) { return true; }
  }
  return false;
}

static void timeout_cosm (cosm_t *cosm) {
  if (cosm->oneshot_active && timer_elapsed(cosm->released_at) > COSM_TIMEOUT) {
    cosm->oneshot_active = false;
  }
}

void timeout_cosms (void) {
  for (int i = 0; i < NUM_COSM; i++) {
    timeout_cosm(custom_oneshots + i);
  }
}

static inline void set_cosm (cosm_t *cosm) {
  cosm->active = true;
  if (cosm->layer >= 0) { layer_on(cosm->layer); }
  if (cosm->keycode != KC_NO) { register_code(cosm->keycode); }
}

static inline void unset_cosm (cosm_t *cosm) {
  cosm->active = false;
  if (cosm->layer >= 0) { layer_off(cosm->layer); }
  if (cosm->keycode != KC_NO) { unregister_code(cosm->keycode); }
}

static void handle_current_cosm_key (cosm_t *cosm, keyrecord_t *record) {
  if (record->event.pressed) { // pressed
    if (cosm->oneshot_active && timer_elapsed(cosm->released_at) <= COSM_LOCK_TIMEOUT) {
      cosm->locked = !cosm->locked; // toggle lock status if doubletapped without interrupt
    } else {
      cosm->pressed = true;
      cosm->interrupted = false;
      cosm->oneshot_active = false;
      
      if (!cosm->locked) { set_cosm(cosm); } else { unset_cosm(cosm); }
    }
    
  } else { // released
    cosm->pressed = false;
    cosm->released_at = timer_read();
    
    if (cosm->interrupted) { // interrupted ==> reset unset layer and keycode
      if (!cosm->locked) { unset_cosm(cosm); } else { set_cosm(cosm); }
    } else { // not interrupted ==> activate oneshot behaviour
      cosm->oneshot_active = true;
    }
  }
}

static void handle_noncosm_key (cosm_t *cosm, keyrecord_t *record) {
  if (record->event.pressed) {
    if (cosm->pressed) { // currently pressed ==> interrupted
      cosm->interrupted = true;
    } else if (cosm->oneshot_active) { // currently oneshot active ==> oneshot inactive
      cosm->oneshot_active = false;
    } else { // neither pressed nor oneshot active ==> unset
      if (!cosm->locked) {
	if (cosm->active) { unset_cosm(cosm);; }
      } else {
	if (!cosm->active) { set_cosm(cosm);; }
      }
    }
  }  
}

static bool handle_cosm (cosm_t *cosm, uint16_t keycode, keyrecord_t *record) {
  if (keycode == cosm->trigger) { // cosm key
    handle_current_cosm_key(cosm, record);
    return false;
  } else if (!is_cosm_key(keycode)) {  // other key (non-cosm)
    handle_noncosm_key(cosm, record);
  }
  return true;
}

bool handle_cosms (uint16_t keycode, keyrecord_t *record) {
  for (int i = 0; i < NUM_COSM; i++) {
    if (!handle_cosm(custom_oneshots + i, keycode, record)) { return false; }
  }
  return true;
}

