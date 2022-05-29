#pragma once

#define IGNORE_MOD_TAP_INTERRUPT
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO    // Disable old-style macro handling (to save space).
#define NO_ACTION_FUNCTION // Disable old-style function handling (to save space).

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)

#define LEADER_TIMEOUT 300
//#define LEADER_PER_KEY_TIMING

// only allow up to 8 layers to save firmware size (on introduction: 832 bytes)
#define LAYER_STATE_8BIT
