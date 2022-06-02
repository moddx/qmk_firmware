#include "combos.h"

enum combo_events {
  VL_GUI,
  GF_GUI,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM gui_combo[] = {KC_V, KC_L, COMBO_END};
const uint16_t PROGMEM nogui_combo[] = {KC_G, KC_F, COMBO_END};

/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */
combo_t key_combos[] = {
  [VL_GUI] = COMBO_ACTION(gui_combo),
  [GF_GUI] = COMBO_ACTION(nogui_combo),
};


void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case VL_GUI:
      if (pressed) {
        register_mods(MOD_MASK_GUI);
      }
      break;
    case GF_GUI:
      if (pressed) {
        unregister_mods(MOD_MASK_GUI);
      }
      break;
  }
}
