#include "struckmb.h"

#define KYRIA_MAP(...) LAYOUT(__VA_ARGS__)

#define KYRIA_BASE_THUMBS KC_TRNS, BASE_LA_THUMB, BASE_L_THUMBS, KC_TRNS, KC_TRNS, KC_TRNS, BASE_R_THUMBS, KC_TRNS

#define KYRIA_SYMB_THUMBS KC_TRNS, SYMB_L_THUMBS, SYMB_ML_THUMB, KC_TRNS, KC_TRNS, KC_TRNS, SYMB_R_THUMBS, KC_TRNS

#define KYRIA_NAVI_THUMBS KC_TRNS, NAVI_L_THUMBS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NAVI_R_THUMBS, KC_TRNS

#define KYRIA_FUNC_THUMBS KC_TRNS, FUNC_L_THUMBS, KC_TRNS, KC_TRNS, KC_TRNS, FUNC_R_THUMBS, KC_TRNS, KC_TRNS

#define KYRIA_BASE_EXTRAS DE_LBRC, KC_CAPS, MO(_FUNC), DE_RBRC
#define KYRIA_TRANSPARENT_EXTRAS KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define KYRIA_ROW(left, right) KC_NO, left, right, KC_NO
#define KYRIA_XROW(left, right) KC_NO, left, KYRIA_TRANSPARENT_EXTRAS, right, KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_NOTED] = KYRIA_MAP(                              //
        NOTED_L6_TOP, NOTED_R6_TOP,                    //
        NOTED_L6_MID, NOTED_R6_MID,                    //
        NOTED_L6_BOT, KYRIA_BASE_EXTRAS, NOTED_R6_BOT, //
        KYRIA_BASE_THUMBS),

    [_QWERT] = KYRIA_MAP(                              //
        QWERT_L6_TOP, QWERT_R6_TOP,                    //
        QWERT_L6_MID, QWERT_R6_MID,                    //
        QWERT_L6_BOT, KYRIA_BASE_EXTRAS, QWERT_R6_BOT, //
        KYRIA_BASE_THUMBS),

    [_SYMB] = KYRIA_MAP(                                    //
        SYMB_L6_TOP, SYMB_R6_TOP,                           //
        SYMB_L6_MID, SYMB_R6_MID,                           //
        SYMB_L6_BOT, KYRIA_TRANSPARENT_EXTRAS, SYMB_R6_BOT, //
        KYRIA_SYMB_THUMBS),

    [_NAVI] = KYRIA_MAP(                    //
        KYRIA_ROW(NAVI_L_TOP, NAVI_R_TOP),  //
        KYRIA_ROW(NAVI_L_MID, NAVI_R_MID),  //
        KYRIA_XROW(NAVI_L_BOT, NAVI_R_BOT), //
        KYRIA_NAVI_THUMBS),

    [_FUNC] = KYRIA_MAP(                    //
        KYRIA_ROW(FUNC_L_TOP, FUNC_R_TOP),  //
        KYRIA_ROW(FUNC_L_MID, FUNC_R_MID),  //
        KYRIA_XROW(FUNC_L_BOT, FUNC_R_BOT), //
        KYRIA_FUNC_THUMBS)};

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
