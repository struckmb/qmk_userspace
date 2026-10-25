#include "struckmb.h"

// draculad specific wrapper
#define DRACULAD_MAP(l_top, r_top, l_mid, r_mid, l_bot, r_bot, enc_l, enc_r, l_th, ex_l, ex_r, r_th) LAYOUT(l_top, r_top, l_mid, r_mid, l_bot, r_bot, enc_l, enc_r, l_th, ex_l, ex_r, r_th)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { //

    [_NOTED] = DRACULAD_MAP(                                                          //
        NOTED_L_TOP, NOTED_R_TOP, NOTED_L_MID, NOTED_R_MID, NOTED_L_BOT, NOTED_R_BOT, //
        KC_MUTE, KC_MPLY, BASE_L_THUMBS, BASE_ML_THUMB, KC_TRNS, BASE_R_THUMBS),

    [_QWERTZ] = DRACULAD_MAP(                                                               //
        QWERTZ_L_TOP, QWERTZ_R_TOP, QWERTZ_L_MID, QWERTZ_R_MID, QWERTZ_L_BOT, QWERTZ_R_BOT, //
        KC_MUTE, KC_MPLY, BASE_L_THUMBS, BASE_ML_THUMB, KC_TRNS, BASE_R_THUMBS),

    [_SYMB] = DRACULAD_MAP(                                                     //
        SYMB_L_TOP, SYMB_R_TOP, SYMB_L_MID, SYMB_R_MID, SYMB_L_BOT, SYMB_R_BOT, //
        KC_TRNS, KC_TRNS, SYMB_L_THUMBS, KC_TRNS, KC_TRNS, SYMB_R_THUMBS),

    [_NAVI] = DRACULAD_MAP(                                                     //
        NAVI_L_TOP, NAVI_R_TOP, NAVI_L_MID, NAVI_R_MID, NAVI_L_BOT, NAVI_R_BOT, //
        KC_TRNS, KC_TRNS, NAVI_L_THUMBS, KC_TRNS, KC_TRNS, NAVI_R_THUMBS),

    [_FUNC] = DRACULAD_MAP(                                                     //
        FUNC_L_TOP, FUNC_R_TOP, FUNC_L_MID, FUNC_R_MID, FUNC_L_BOT, FUNC_R_BOT, //
        KC_TRNS, KC_TRNS, FUNC_L_THUMBS, KC_TRNS, KC_TRNS, FUNC_R_THUMBS)

};
