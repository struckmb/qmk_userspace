#include "struckmb.h"

// ZWINGEND HIER LOKAL: Der draculad-spezifische Entfaltungs-Wrapper
#define DRACULAD_MAP(l_top, r_top, l_mid, r_mid, l_bot, r_bot, enc_l, enc_r, l_th, ex_l, ex_r, r_th) LAYOUT(l_top, r_top, l_mid, r_mid, l_bot, r_bot, enc_l, enc_r, ex_l, l_th, r_th, ex_r)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { //

    [_BASE] = DRACULAD_MAP(                                                     //
        BASE_L_TOP, BASE_R_TOP, BASE_L_MID, BASE_R_MID, BASE_L_BOT, BASE_R_BOT, //
        KC_MUTE, KC_MPLY, KC_BSPC, BASE_L_THUMBS, BASE_R_THUMBS, KC_MUTE),

    [_SYMB] = DRACULAD_MAP(                                                     //
        SYMB_L_TOP, SYMB_R_TOP, SYMB_L_MID, SYMB_R_MID, SYMB_L_BOT, SYMB_R_BOT, //
        KC_TRNS, KC_TRNS, KC_TRNS, SYMB_L_THUMBS, SYMB_R_THUMBS, KC_TRNS),

    [_NAVI] = DRACULAD_MAP(                                                     //
        NAVI_L_TOP, NAVI_R_TOP, NAVI_L_MID, NAVI_R_MID, NAVI_L_BOT, NAVI_R_BOT, //
        KC_TRNS, KC_TRNS, KC_TRNS, EMPTY__THUMBS, EMPTY__THUMBS, KC_TRNS)

};
