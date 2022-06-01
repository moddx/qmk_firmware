#pragma once

#include QMK_KEYBOARD_H

enum combo_events {
  VL_GUI,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;


void process_combo_event(uint16_t combo_index, bool pressed);
