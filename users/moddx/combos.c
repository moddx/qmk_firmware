#include "combos.h"

enum combo_events {
  XV_ESC,
  VL_GUI,
  LC_TAB,
  HG_SFT,
  GF_ALT,
  DOTJ_WOWEE,
  CLEAR_MODS,
  COMBO_LENGTH,
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM escape_combo[] = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM gui_combo[] = {KC_V, KC_L, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_L, KC_C, COMBO_END};
const uint16_t PROGMEM sft_combo[] = {KC_H, KC_G, COMBO_END};
const uint16_t PROGMEM alt_combo[] = {KC_G, KC_F, COMBO_END};
const uint16_t PROGMEM clear_mods_combo[] = {KC_F, KC_Q, COMBO_END};
const uint16_t PROGMEM wowee_combo[] = {KC_DOT,  RSFT_T(KC_J), COMBO_END};

/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */
combo_t key_combos[] = {
  [XV_ESC] = COMBO_ACTION(escape_combo),
  [VL_GUI] = COMBO_ACTION(gui_combo),
  [LC_TAB] = COMBO_ACTION(tab_combo),
  [HG_SFT] = COMBO_ACTION(sft_combo),
  [GF_ALT] = COMBO_ACTION(alt_combo),
  [CLEAR_MODS] = COMBO_ACTION(clear_mods_combo),
  [DOTJ_WOWEE] = COMBO_ACTION(wowee_combo),
};


void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case XV_ESC:
      if (pressed) {
        tap_code(KC_ESC);
      }
      break;
    case VL_GUI:
      if (pressed) {
        set_oneshot_mods(MOD_MASK_GUI);
      }
      break;
    case LC_TAB:
      if (pressed) {
        tap_code(KC_TAB);
      }
      break;
    case HG_SFT:
      if (pressed) {
        set_oneshot_mods(MOD_LSFT);
      }
      break;
    case GF_ALT:
      if (pressed) {
        set_oneshot_mods(MOD_LALT);
      }
      break;
    case DOTJ_WOWEE:
      if (pressed) {
        SEND_STRING(":wowee:");
      }
      break;
    case CLEAR_MODS:
      if (pressed) {
        clear_oneshot_mods();
      }
      break;
  }
}
