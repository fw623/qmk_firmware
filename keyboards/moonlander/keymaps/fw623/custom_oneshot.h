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
