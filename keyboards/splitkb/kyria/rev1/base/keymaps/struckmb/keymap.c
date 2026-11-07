#include "struckmb.h"

#define KYRIA_MAP(...) LAYOUT(__VA_ARGS__)

#define KYRIA_THUMBS(l, r) KC_TRNS, l, KC_TRNS, KC_TRNS, r, KC_TRNS

#define KYRIA_BASE_EXTRAS(l, r) l, DE_LBRC, KC_CAPS, MO(_NUMS), DE_RBRC, r
#define KYRIA_FUNC_EXTRAS(l, r) l, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, r

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_NOTED] = KYRIA_MAP(                              //
        NOTED_L6_TOP, NOTED_R6_TOP,                    //
        NOTED_L6_MID, NOTED_R6_MID,                    //
        KYRIA_BASE_EXTRAS(NOTED_L6_BOT, NOTED_R6_BOT), //
        KYRIA_THUMBS(BASE_L3_TMB, BASE_R3_TMB)),

    [_QWERT] = KYRIA_MAP(                              //
        QWERT_L6_TOP, QWERT_R6_TOP,                    //
        QWERT_L6_MID, QWERT_R6_MID,                    //
        KYRIA_BASE_EXTRAS(QWERT_L6_BOT, QWERT_R6_BOT), //
        KYRIA_THUMBS(BASE_L3_TMB, BASE_R3_TMB)),

    [_SYMB] = KYRIA_MAP(                             //
        SYMB_L6_TOP, SYMB_R6_TOP,                    //
        SYMB_L6_MID, SYMB_R6_MID,                    //
        KYRIA_FUNC_EXTRAS(SYMB_L6_BOT, SYMB_R6_BOT), //
        KYRIA_THUMBS(SYMB_L3_TMB, SYMB_R3_TMB)),

    [_NAVI] = KYRIA_MAP(                             //
        NAVI_L6_TOP, NAVI_R6_TOP,                    //
        NAVI_L6_MID, NAVI_R6_MID,                    //
        KYRIA_FUNC_EXTRAS(NAVI_L6_BOT, NAVI_R6_BOT), //
        KYRIA_THUMBS(NAVI_L3_TMB, NAVI_R3_TMB)),

    [_NUMS] = KYRIA_MAP(                             //
        NUMS_L6_TOP, NUMS_R6_TOP,                    //
        NUMS_L6_MID, NUMS_R6_MID,                    //
        KYRIA_FUNC_EXTRAS(NUMS_L6_BOT, NUMS_R6_BOT), //
        KYRIA_THUMBS(NUMS_L3_TMB, NUMS_R3_TMB))};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        tap_code(clockwise ? KC_VOLU : KC_VOLD);
    } else if (index == 1) {
        tap_code(clockwise ? KC_PGDN : KC_PGUP);
    }
    return false;
}
#endif
