#pragma once

#include QMK_KEYBOARD_H

#define DEFAULT 0
#define QWERTZ 1
#define L1 2
#define L2 3
#define L3 4  // NUM
#define L4 5  // NUM SPECIAL
#define L5 6  // F1-12..

enum custom_keycodes {
    EMAIL = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record);
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record);
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record);
void matrix_scan_user(void);
