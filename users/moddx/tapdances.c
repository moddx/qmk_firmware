#include "tapdances.h"
#include "moddx.h"

td_state_t cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
    // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
    else
      return TD_SINGLE_HOLD;
  } else if (state->count == 2) {
    // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
    // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
    // keystrokes of the key, and not the 'double tap' action/macro.
    if (state->interrupted)
      return TD_DOUBLE_SINGLE_TAP;
    else if (state->pressed)
      return TD_DOUBLE_HOLD;
    else
      return TD_DOUBLE_TAP;
  }

  // Assumes no one is trying to type the same letter three times (at least not quickly).
  // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)
      return TD_TRIPLE_TAP;
    else
      return TD_TRIPLE_HOLD;
  }

  return TD_UNKNOWN;
}

//
// Left Thumb mods
//

static td_tap_t lmods_state = { .is_press_action = true, .state = TD_NONE };

void lmods_each(qk_tap_dance_state_t *state, void *user_data) {
}

void lmods_finished(qk_tap_dance_state_t *state, void *user_data) {
    lmods_state.state = cur_dance(state);
    switch (lmods_state.state) {
        case TD_SINGLE_TAP:
            set_oneshot_mods(MOD_MASK_SHIFT); break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_MASK_SHIFT); break;
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_LSFT); tap_code(KC_LSFT);
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            register_mods(MOD_MASK_GUI); break;
        default:  break;
    }
}

void lmods_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (lmods_state.state) {
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_MASK_SHIFT); break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            unregister_mods(MOD_MASK_GUI); break;
        default: break;
    }
    lmods_state.state = TD_NONE;
}


//
// Layer 1 + 2
//

static td_tap_t l1_l2_state = { .is_press_action = true, .state = TD_NONE };

void l1_l2_each(qk_tap_dance_state_t *state, void *user_data) {
}

void l1_l2_finished(qk_tap_dance_state_t *state, void *user_data) {
    l1_l2_state.state = cur_dance(state);
    switch (l1_l2_state.state) {
        case TD_SINGLE_TAP:
        case TD_DOUBLE_SINGLE_TAP:
        case TD_SINGLE_HOLD:
            layer_on(L1); break;

        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
        case TD_TRIPLE_TAP:
        case TD_TRIPLE_HOLD:
            layer_on(L2); break;
        default:  break;
    }
}

void l1_l2_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (l1_l2_state.state) {
        case TD_SINGLE_TAP:
        case TD_DOUBLE_SINGLE_TAP:
        case TD_SINGLE_HOLD:
            layer_off(L1); break;

        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
        case TD_TRIPLE_TAP:
        case TD_TRIPLE_HOLD:
            layer_off(L2); break;
        default: break;
    }
    l1_l2_state.state = TD_NONE;
}
