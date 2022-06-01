#include "moddx.h"

#include "keymap_german.h"
#include "sendstring_german.h"
#include "tapdances.h"

// Tap Dance definitions
enum td_keycodes {
    TD_X_TAB,
    TD_S_SS,
    TD_L_MODS,
    TD_L_CSA_MODS,
    TD_L1_L2,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for X, twice for TAB
    //[TD_X_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_TAB),
    // triple tap s -> ß
    //[TD_S_SS] = ACTION_TAP_DANCE_FN_ADVANCED(stap_each, stap_finished, stap_reset),
    [TD_L_MODS] = ACTION_TAP_DANCE_FN_ADVANCED(lmods_each, lmods_finished, lmods_reset),
    [TD_L_CSA_MODS] = ACTION_TAP_DANCE_FN_ADVANCED(l_csa_mods_each, l_csa_mods_finished, l_csa_mods_reset),
    [TD_L1_L2] = ACTION_TAP_DANCE_FN_ADVANCED(l1_l2_each, l1_l2_finished, l1_l2_reset),
};

//
// OVERRIDES
//
// Dot/Comma on L3
const key_override_t ctrl_dot_override = ko_make_with_layers(MOD_MASK_CTRL, KC_DOT, KC_COMM, (1 << L3));
const key_override_t shift_dot_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_COMM, (1 << L3));
// Media Key on L1
const key_override_t play_next_override = ko_make_with_layers(MOD_MASK_CTRL, KC_MPLY, KC_MNXT, (1 << L1));
const key_override_t play_prev_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_MPLY, KC_MPRV, (1 << L1));

// L4
// ß
const key_override_t excl_quest_override = ko_make_with_layers(MOD_MASK_SHIFT, LSFT(KC_1), S(DE_SS), (1 << L4));
// '
const key_override_t apos_single_override = ko_make_with_layers(MOD_MASK_SHIFT, LSFT(KC_2), S(DE_HASH), (1 << L4));
// `
const key_override_t apos_backtick_override = ko_make_with_layers(MOD_MASK_ALT, LSFT(KC_2), DE_GRV, (1 << L4));
// ´
const key_override_t apos_tick_override = ko_make_with_layers(MOD_MASK_ALT, LSFT(KC_3), DE_ACUT, (1 << L4));
// ^
const key_override_t circ_override = ko_make_with_layers(MOD_MASK_ALT, LSFT(KC_7), DE_CIRC, (1 << L4));
// °
const key_override_t deg_override = ko_make_with_layers(MOD_MASK_ALT, LSFT(KC_9), DE_DEG, (1 << L4));
// backslash
const key_override_t sls_bsls_override = ko_make_with_layers(MOD_MASK_SHIFT, LSFT(KC_7), DE_BSLS, (1 << L4));

const key_override_t **key_overrides = (const key_override_t *[]){
    &ctrl_dot_override,
    &shift_dot_override,
    &play_next_override,
    &play_prev_override,
    // L4
    &excl_quest_override,
    &apos_single_override,
    &apos_backtick_override,
    &apos_tick_override,
    &circ_override,
    &deg_override,
    &sls_bsls_override,
    NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Default, L0
	[DEFAULT] = LAYOUT_split_3x5_3(
		KC_X,         KC_V,         KC_L,         KC_C,         KC_W,           KC_K,   KC_H,   KC_G,    KC_F,    KC_Q,
		LALT_T(KC_U), LT(L4, KC_I), LT(L5, KC_A), LT(L3, KC_E), KC_O,           KC_S,   KC_N,   KC_R,    KC_T,    KC_D,
		LSFT_T(DE_Y), DE_Y,         KC_LEAD,      KC_P,         DE_Z,           KC_B,   KC_M,   KC_COMM, KC_DOT,  RSFT_T(KC_J),
		                            TD(TD_L_MODS), KC_LCTL, TD(TD_L1_L2),       KC_SPC, MO(L2), U_NP
    ),

    [QWERTZ] = LAYOUT_split_3x5_3(
		KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,           KC_Z,   KC_U,   KC_I,    KC_O,    KC_P,
		LALT_T(KC_A), LT(L4, KC_S), LT(L5, KC_D), LT(L3, KC_F), KC_G,           KC_H,   KC_J,   KC_K,    KC_L,    KC_LEAD,
		LSFT_T(DE_Y), DE_X,         KC_C,         KC_V,         DE_B,           KC_N,   KC_M,   KC_COMM, KC_DOT,  RSFT_T(DE_MINS),
		                            TD(TD_L_MODS), KC_LCTL, TD(TD_L1_L2),       KC_SPC, MO(L2), U_NP
    ),

    // L1
	[L1] = LAYOUT_split_3x5_3(
        KC_TAB,  KC_ESC,     KC_ENT,     LCTL(DE_Z), KC_INS,        DM_REC1, DE_HASH,      DE_LCBR, DE_RCBR, KC_MPLY,
		KC_LCTL, S(DE_SS),   LCTL(KC_S), KC_HOME,    KC_END,        KC_LEFT, KC_DOWN,      KC_UP,   KC_RGHT, DE_LPRN,
		KC_LSFT, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO,         KC_DEL,  KC_BSPC,      DE_LBRC, DE_RBRC, DE_RPRN,
		                     KC_TRNS,    KC_LALT,    KC_TRNS,       KC_LALT, OSM(MOD_MEH), U_NP
    ),

	// L2
	[L2] = LAYOUT_split_3x5_3(
		EMAIL,          DE_BSLS,     DE_EQL,  DE_AMPR, DE_TILD,       DM_PLY1, LSFT(KC_F3), DE_ASTR, KC_F3,   DE_PLUS,
		LCTL_T(DE_AT),  DE_LABK,     DE_RABK, DE_MINS, DE_PIPE,       MC_SWLE, KC_PGDN,     KC_PGUP, MC_SWRI, KC_TRNS,
		LSFT_T(KC_APP), LALT(KC_F4), KC_NO,   KC_NO,   KC_NO,         DE_SS,   DE_UDIA,     DE_ODIA, DE_ADIA, KC_RSFT,
		                             KC_TRNS, KC_CAPS, KC_TRNS,       KC_TRNS, KC_TRNS,     U_NP
    ),

	// L3 NUM
	[L3] = LAYOUT_split_3x5_3(
		TG(QWERTZ),    KC_TRNS,       EH_RGHT,       EH_LEFT,       QK_BOOT,              DE_SLSH, KC_7,   KC_8,    KC_9,  DE_PLUS,
		OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL), KC_TRNS,       EEP_RST,              DE_ASTR, KC_4,   KC_5,    KC_6,  DE_MINS,
		OSM(MOD_LSFT), KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,              KC_BSPC, KC_1,   KC_2,    KC_3,  KC_RSFT,
                                      OSM(MOD_LGUI), OSM(MOD_LCTL), KC_TRNS,              KC_0,    KC_DOT, U_NP
    ),

    // L4 NUM SYMS
	[L4] = LAYOUT_split_3x5_3(
		KC_TRNS,       KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,              KC_NO,      LSFT(KC_7),  LSFT(KC_8),  LSFT(KC_9), KC_NO,
		OSM(MOD_LALT), KC_TRNS,  OSM(MOD_LCTL), MO(L5),        KC_TRNS,              KC_NO,      LSFT(KC_4),  LSFT(KC_5),  LSFT(KC_6), KC_NO,
		OSM(MOD_LSFT), KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,              KC_BSPC,    LSFT(KC_1),  LSFT(KC_2),  LSFT(KC_3), KC_NO,
		                         OSM(MOD_LGUI), OSM(MOD_LCTL), KC_TRNS,              LSFT(KC_0), KC_DOT, U_NP
    ),

	// L5 F-Keys
	[L5] = LAYOUT_split_3x5_3(
		KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,
		OSM(MOD_LALT), OSM(MOD_LSFT), KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS, KC_F4,   KC_F5,   KC_F6,   KC_F11,
		OSM(MOD_LSFT), KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F12,
		                              OSM(MOD_LGUI), OSM(MOD_LCTL), KC_TRNS,          KC_TRNS, KC_TRNS, U_NP
    )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    //if (!process_caps_word(keycode, record)) { return false; }

    switch (keycode) {
    case EMAIL:
        if (record->event.pressed) {
            // when keycode EMAIL is pressed
            SEND_STRING("matt@tuxship.org");
        } else {
            // when keycode EMAIL is released
        }
        break;
    case LSFT_T(DE_Z):
        if (record->tap.count && record->event.pressed) {
            tap_code16(LCTL(DE_Z));  // Send CTRL+Z on tap
            return false;        // Return false to ignore further processing of key
        }
        break;
    case LCTL_T(DE_AT):
        if (record->tap.count && record->event.pressed) {
            tap_code16(DE_AT);  // Send @ on tap
            return false;       // Return false to ignore further processing of key
        }
        break;
    }

    return true;
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(DE_Y):
        case RSFT_T(KC_J):
            // Immediately select the hold action when another key is pressed.
            return false;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_S) {
      tap_code16(DE_SS);
    }

    SEQ_ONE_KEY(KC_Q) {
      tap_code16(S(DE_SS));
    }

    SEQ_ONE_KEY(KC_E) {
      tap_code16(DE_EURO);
    }

    SEQ_ONE_KEY(KC_P) {
      tap_code16(C(S(A(KC_Q))));
    }

    SEQ_ONE_KEY(KC_N) {
      SEND_STRING("lapjenkt01.dvka.de:8000");
      tap_code(KC_ENTER);
    }
  }
}
