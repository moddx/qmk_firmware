#include "combos.h"

const uint16_t PROGMEM gui_combo[] = {KC_V, KC_L, COMBO_END};

/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */
combo_t key_combos[] = {
  [VL_GUI] = COMBO_ACTION(gui_combo),
};


void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case VL_GUI:
      if (pressed) {
        tap_code(KC_LGUI);
      }
      break;
  }
}
