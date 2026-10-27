#include "struckmb.h"

#define CANTOR_MAP(...) LAYOUT_split_3x6_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_NOTED] = CANTOR_MAP(
        NOTED_L6_TOP, NOTED_R6_TOP,
        NOTED_L6_MID, NOTED_R6_MID,
        NOTED_L6_BOT, NOTED_R6_BOT,
        LT(_NAVI, KC_ESC), LGUI_T(KC_ENT), LT(_NAVI, KC_TAB),
        KC_TRNS, KC_SPC, LT(_NAVI, KC_TAB)
    ),
    [_QWERT] = CANTOR_MAP(
        QWERT_L6_TOP, QWERT_R6_TOP,
        QWERT_L6_MID, QWERT_R6_MID,
        QWERT_L6_BOT, QWERT_R6_BOT,
        LT(_NAVI, KC_ESC), LGUI_T(KC_ENT), LT(_NAVI, KC_TAB),
        KC_TRNS, KC_SPC, LT(_NAVI, KC_TAB)
    ),
    [_SYMB] = CANTOR_MAP(
        SYMB_L6_TOP, SYMB_R6_TOP,
        SYMB_L6_MID, SYMB_R6_MID,
        SYMB_L6_BOT, SYMB_R6_BOT,
        DE_AT, KC_ENT, G(DE_CIRC),
        KC_TRNS, KC_SPC, KC_RALT
    ),
    [_NAVI] = CANTOR_MAP(
        KC_NO, NAVI_L_TOP, NAVI_R_TOP, KC_NO,
        KC_NO, NAVI_L_MID, NAVI_R_MID, KC_NO,
        KC_NO, NAVI_L_BOT, NAVI_R_BOT, KC_NO,
        TG(_NAVI), DE_COMM, KC_TRNS,
        KC_TRNS, DE_0, DE_DOT
    ),
    [_FUNC] = CANTOR_MAP(
        KC_NO, FUNC_L_TOP, FUNC_R_TOP, KC_NO,
        KC_NO, FUNC_L_MID, FUNC_R_MID, KC_NO,
        KC_NO, FUNC_L_BOT, FUNC_R_BOT, KC_NO,
        TG(_NAVI), KC_TRNS, KC_TRNS,
        KC_TRNS, DE_SLNG, LY_TOGG
    ),
};
