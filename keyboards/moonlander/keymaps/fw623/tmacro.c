#include "tmacro.h"

typedef struct tmacro_t {
    uint16_t keycode;
    uint16_t delay;
    bool pressed;
} tmacro_t;

bool tmacro_recording = false;
bool tmacro_playing = false;
uint16_t tmacro_index = 0;
uint16_t tmacro_size = 0;
tmacro_t tmacro[TMACRO_SIZE_MAX];
uint16_t tmacro_timer = 0;
uint16_t tmacro_record_timer = 0;

uint16_t tmacro_next_index(void) {
    return (tmacro_index + 1) % tmacro_size;
}

bool handle_tmacro(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
    case TM_REC:
        if (record->event.pressed) {
            tmacro_recording = true;
            tmacro_playing = false;
            tmacro_size = 0;
            tmacro_record_timer = timer_read();
        } else {
            tmacro_recording = false;
            tmacro_playing = false;
        }
        return false;

    case TM_PLAY:
        if (record->event.pressed && !tmacro_recording) {
            tmacro_playing = !tmacro_playing;
            if (tmacro_playing) {
                tmacro_index = 0;
                tmacro_timer = timer_read();
            }
            if (!tmacro_playing) {
                // release all potentially pressed keys
                for (int i = 0; i < tmacro_size; i++) {
                    if (tmacro[i].pressed) {
                        unregister_code16(tmacro[i].keycode);
                    }
                }
            }
        }
        return false;
    }

    if (tmacro_recording) {
        if (tmacro_size <= TMACRO_SIZE_MAX){
            tmacro[tmacro_size].keycode = keycode;
            tmacro[tmacro_size].delay = timer_elapsed(tmacro_record_timer);
            tmacro[tmacro_size].pressed = record->event.pressed;

            tmacro_size++;
        }
        return true;
    }

    return true;
}



void handle_tmacro_timer(void) {
    if (tmacro_playing && timer_elapsed(tmacro_timer) >= tmacro[tmacro_index].delay) {
        if (tmacro_index == tmacro_size - 1) {
            tmacro_timer = timer_read();
        }

        UN_REGISTER_CODE16(tmacro[tmacro_index].pressed, tmacro[tmacro_index].keycode);
        tmacro_index = tmacro_next_index();
    }
}
