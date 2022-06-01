#pragma once

#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "layer.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record);
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record);
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record);
void matrix_scan_user(void);
