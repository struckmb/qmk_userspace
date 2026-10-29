#include "struckmb.h"

#define CHARYBDIS_ROW(left, right) KC_NO, left, right, KC_NO
#define CHARYBDIS_MAP(...) LAYOUT(__VA_ARGS__)

#define EMPTY_ROW KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_NOTED] = CHARYBDIS_MAP(       //
        NOTED_L6_TOP, NOTED_R6_TOP, //
        NOTED_L6_MID, NOTED_R6_MID, //
        NOTED_L6_BOT, NOTED_R6_BOT, //
        BASE_LA_THUMB, BASE_L_THUMBS, BASE_R_THUMBS),

    [_QWERT] = CHARYBDIS_MAP(       //
        QWERT_L6_TOP, QWERT_R6_TOP, //
        QWERT_L6_MID, QWERT_R6_MID, //
        QWERT_L6_BOT, QWERT_R6_BOT, //
        BASE_LA_THUMB, BASE_L_THUMBS, BASE_R_THUMBS),

    [_SYMB] = CHARYBDIS_MAP(      //
        SYMB_L6_TOP, SYMB_R6_TOP, //
        SYMB_L6_MID, SYMB_R6_MID, //
        SYMB_L6_BOT, SYMB_R6_BOT, //
        SYMB_L_THUMBS, SYMB_ML_THUMB, SYMB_R_THUMBS),

    [_NAVI] = CHARYBDIS_MAP(                   //
        CHARYBDIS_ROW(NAVI_L_TOP, NAVI_R_TOP), //
        CHARYBDIS_ROW(NAVI_L_MID, NAVI_R_MID), //
        CHARYBDIS_ROW(NAVI_L_BOT, NAVI_R_BOT), //
        NAVI_L_THUMBS, KC_TRNS, NAVI_R_THUMBS),

    [_FUNC] = CHARYBDIS_MAP(                   //
        CHARYBDIS_ROW(FUNC_L_TOP, FUNC_R_TOP), //
        CHARYBDIS_ROW(FUNC_L_MID, FUNC_R_MID), //
        CHARYBDIS_ROW(FUNC_L_BOT, FUNC_R_BOT), //
        FUNC_L_THUMBS, KC_TRNS, FUNC_R_THUMBS)

#ifdef POINTING_DEVICE_ENABLE
        ,
    [_PNTR] = CHARYBDIS_MAP(                                //
        KC_NO, KC_NO, KC_NO, S_D_MOD, DPI_MOD, KC_NO,       //
        EMPTY_ROW,                                          //
        KC_NO, MS_BTN4, DRG_TOG, DRGSCRL, SNIPING, MS_BTN5, //
        OS_MEH, OS_LCTL, OS_LSFT, OS_LALT, OS_LGUI, KC_NO,  //
        EMPTY_ROW,                                          //
        KC_NO, SNIPING, DRGSCRL, DRG_TOG, KC_NO, KC_RCTL,   //
        KC_NO, MS_BTN1, MS_BTN2, MS_BTN1, MS_BTN3)};

#    define CHARYBDIS_AUTO_SNIPING_ON_LAYER _PNTR
#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#else
};
#endif // POINTING_DEVICE_ENABLE
