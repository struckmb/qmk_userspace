#include "struckmb.h"

#define CANTOR_MAP(...) LAYOUT_split_3x6_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_NOTED] = CANTOR_MAP(          //
        NOTED_L6_TOP, NOTED_R6_TOP, //
        NOTED_L6_MID, NOTED_R6_MID, //
        NOTED_L6_BOT, NOTED_R6_BOT, //
        BASE_LA_THUMB, BASE_L_THUMBS, BASE_R_THUMBS, BASE_RA_THUMB),

    [_QWERT] = CANTOR_MAP(          //
        QWERT_L6_TOP, QWERT_R6_TOP, //
        QWERT_L6_MID, QWERT_R6_MID, //
        QWERT_L6_BOT, QWERT_R6_BOT, //
        BASE_LA_THUMB, BASE_L_THUMBS, BASE_R_THUMBS, BASE_RA_THUMB),

    [_SYMB] = CANTOR_MAP(         //
        SYMB_L6_TOP, SYMB_R6_TOP, //
        SYMB_L6_MID, SYMB_R6_MID, //
        SYMB_L6_BOT, SYMB_R6_BOT, //
        SYMB_L_THUMBS, SYMB_ML_THUMB, KC_TRNS, SYMB_R_THUMBS),

    [_NAVI] = CANTOR_MAP(               //
        KC_NO, NAVI_L_TOP, NAVI_R6_TOP, //
        KC_NO, NAVI_L_MID, NAVI_R6_MID, //
        KC_NO, NAVI_L_BOT, NAVI_R6_BOT, //
        NAVI_L_THUMBS, KC_TRNS, KC_TRNS, NAVI_R_THUMBS),

    [_FUNC] = CANTOR_MAP(                     //
        KC_NO, FUNC_L_TOP, FUNC_R_TOP, KC_NO, //
        KC_NO, FUNC_L_MID, FUNC_R_MID, KC_NO, //
        KC_NO, FUNC_L_BOT, FUNC_R_BOT, KC_NO, //
        FUNC_L_THUMBS, KC_TRNS, KC_TRNS, FUNC_R_THUMBS),
};
