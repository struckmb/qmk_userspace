#include "struckmb.h"

// draculad specific wrapper
#define DRACULAD_MAP(l_top, r_top, l_mid, r_mid, l_bot, r_bot, enc_l, enc_r, l_th, ex_l, ex_r, r_th) LAYOUT(l_top, r_top, l_mid, r_mid, l_bot, r_bot, enc_l, enc_r, l_th, ex_l, ex_r, r_th)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { //

    [_BASE] = DRACULAD_MAP(                                                     //
        BASE_L_TOP, BASE_R_TOP, BASE_L_MID, BASE_R_MID, BASE_L_BOT, BASE_R_BOT, //
        KC_MUTE, KC_MPLY, BASE_L_THUMBS, KC_TAB, KC_TRNS, BASE_R_THUMBS),

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

#ifdef XXX_OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return is_keyboard_left() ? OLED_ROTATION_270 : OLED_ROTATION_90;
    } else {
        return is_keyboard_left() ? OLED_ROTATION_180 : OLED_ROTATION_0;
    }
}

#endif // OLED_ENABLE
