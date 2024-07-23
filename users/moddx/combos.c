#include "combos.h"
#include "layer.h"

enum combo_events {
  //XV_ESC,
  VL_GUI,
  //LC_TAB,
  WK_SFT,
  XQ_CLEAR,
  LEFT_CLICK,
  RIGHT_CLICK,
  MIDDLE_CLICK,
  TOGGLE_SCROLL,
  COMBO_LENGTH,
};
uint16_t COMBO_LEN = COMBO_LENGTH;

//const uint16_t PROGMEM escape_combo[] = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM gui_combo[] = {KC_V, KC_L, COMBO_END};
//const uint16_t PROGMEM tab_combo[] = {KC_L, KC_C, COMBO_END};
const uint16_t PROGMEM sft_combo[] = {KC_W, KC_K, COMBO_END};
const uint16_t PROGMEM clear_mods_combo[] = {KC_X, KC_Q, COMBO_END};

// MOUSE
const uint16_t PROGMEM left_click_combo[] = {QK_LEAD, KC_P, COMBO_END};
const uint16_t PROGMEM right_click_combo[] = {LT(_L4, KC_I), KC_V, COMBO_END};
const uint16_t PROGMEM middle_click_combo[] = {LT(_L5, KC_A), KC_L, COMBO_END};
const uint16_t PROGMEM toggle_scroll_combo[] = {KC_C, KC_W, COMBO_END};

/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */
combo_t key_combos[] = {
  //[XV_ESC] = COMBO_ACTION(escape_combo),
  [VL_GUI] = COMBO_ACTION(gui_combo),
  //[LC_TAB] = COMBO_ACTION(tab_combo),
  [WK_SFT] = COMBO_ACTION(sft_combo),
  [XQ_CLEAR] = COMBO_ACTION(clear_mods_combo),
  [LEFT_CLICK] = COMBO_ACTION(left_click_combo),
  [RIGHT_CLICK] = COMBO_ACTION(right_click_combo),
  [MIDDLE_CLICK] = COMBO_ACTION(middle_click_combo),
  [TOGGLE_SCROLL] = COMBO_ACTION(toggle_scroll_combo),
};


void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    // case XV_ESC:
    //   if (pressed) {
    //     tap_code(KC_ESC);
    //   }
    //   break;
    case VL_GUI:
      if (pressed) {
        if (get_oneshot_mods() & MOD_MASK_GUI) {
            clear_oneshot_mods();
            tap_code(KC_LGUI);
        } else {
            set_oneshot_mods(MOD_MASK_GUI);
        }
      }
      break;
    case LEFT_CLICK:
      if (pressed) {
        tap_code(KC_BTN1);
      }
      break;
    case RIGHT_CLICK:
      if (pressed) {
        tap_code(KC_BTN2);
      }
      break;
    case MIDDLE_CLICK:
      if (pressed) {
        tap_code(KC_BTN3);
      }
      break;
    case TOGGLE_SCROLL:
      if (pressed) {
        //tap_code(DRGSCRL);
      }
      break;
    // case LC_TAB:
    //   if (pressed) {
    //     tap_code(KC_TAB);
    //   }
    //   break;
    case WK_SFT:
      if (pressed) {
        set_oneshot_mods(MOD_LSFT);
      }
      break;
    case XQ_CLEAR:
      if (pressed) {
        clear_oneshot_mods();
        reset_oneshot_layer();
        layer_clear();
      }
      break;
  }
}
