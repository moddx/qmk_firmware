#pragma once

#include QMK_KEYBOARD_H

enum custom_keycodes {
    #ifdef CHARYBDIS_SAFE_RANGE
    START_RANGE = CHARYBDIS_SAFE_RANGE,
    #else
    START_RANGE = SAFE_RANGE,
    DPI_MOD,
    DPI_RMOD,
    DRGSCRL,
    SNIPING,
    #endif
    EMAIL,
    MC_SWLE,
    MC_SWRI,
    TG_MAC, TG_WIN, TG_LIN,
    KC_ACCEL,
    KEYCODES_RANGE
};
