#include "struckmb.h"

#define CHARYBDIS_MAP(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_NOTED] = CHARYBDIS_MAP(       //
        NOTED_L6_TOP, NOTED_R6_TOP, //
        NOTED_L6_MID, NOTED_R6_MID, //
        NOTED_L6_BOT, NOTED_R6_BOT, //
        BASE_L3_TMB, BASE_R_THUMBS),

    [_QWERT] = CHARYBDIS_MAP(       //
        QWERT_L6_TOP, QWERT_R6_TOP, //
        QWERT_L6_MID, QWERT_R6_MID, //
        QWERT_L6_BOT, QWERT_R6_BOT, //
        BASE_L3_TMB, BASE_R_THUMBS),

    [_SYMB] = CHARYBDIS_MAP(      //
        SYMB_L6_TOP, SYMB_R6_TOP, //
        SYMB_L6_MID, SYMB_R6_MID, //
        SYMB_L6_BOT, SYMB_R6_BOT, //
        SYMB_L3_TMB, SYMB_R_THUMBS),

    [_NAVI] = CHARYBDIS_MAP(      //
        NAVI_L6_TOP, NAVI_R6_TOP, //
        NAVI_L6_MID, NAVI_R6_MID, //
        NAVI_L6_BOT, NAVI_R6_BOT, //
        NAVI_L3_TMB, NAVI_R_THUMBS),

    [_NUMS] = CHARYBDIS_MAP(      //
        NUMS_L6_TOP, NUMS_R6_TOP, //
        NUMS_L6_MID, NUMS_R6_MID, //
        NUMS_L6_BOT, NUMS_R6_BOT, //
        NUMS_L3_TMB, NUMS_R_THUMBS)

#ifdef POINTING_DEVICE_ENABLE
#    define EMPTY_ROW KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
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
