#pragma once

#include QMK_KEYBOARD_H
#include "keymap_german.h"

// Key Tap enumerator
typedef enum {
  TD_NONE,
  TD_UNKNOWN,
  TD_SINGLE_TAP,
  TD_SINGLE_HOLD,
  TD_DOUBLE_TAP,
  TD_DOUBLE_HOLD,
  TD_DOUBLE_SINGLE_TAP, // Send two single taps
  TD_TRIPLE_TAP,
  TD_TRIPLE_HOLD
} td_state_t;

// Keep track of key presses for Modifier
typedef struct {
  bool is_press_action;
  td_state_t state;
} td_tap_t;

td_state_t cur_dance (qk_tap_dance_state_t *state);

void stap_each(qk_tap_dance_state_t *state, void *user_data);
void stap_finished (qk_tap_dance_state_t *state, void *user_data);
void stap_reset (qk_tap_dance_state_t *state, void *user_data);

void ctrl_tab_each(qk_tap_dance_state_t *state, void *user_data);
void ctrl_tab_finished (qk_tap_dance_state_t *state, void *user_data);
void ctrl_tab_reset (qk_tap_dance_state_t *state, void *user_data);

void lmods_each(qk_tap_dance_state_t *state, void *user_data);
void lmods_finished (qk_tap_dance_state_t *state, void *user_data);
void lmods_reset (qk_tap_dance_state_t *state, void *user_data);

void l_csa_mods_each(qk_tap_dance_state_t *state, void *user_data);
void l_csa_mods_finished (qk_tap_dance_state_t *state, void *user_data);
void l_csa_mods_reset (qk_tap_dance_state_t *state, void *user_data);

void l1_l2_each(qk_tap_dance_state_t *state, void *user_data);
void l1_l2_finished (qk_tap_dance_state_t *state, void *user_data);
void l1_l2_reset (qk_tap_dance_state_t *state, void *user_data);
