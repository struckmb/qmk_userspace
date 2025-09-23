#include "struckmb.h"
#include "keyOverride.c"

#define LAYOUT_split_3x6_3_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#ifdef QWERTY_ENABLE
    [LAYER_QWERTY] = LAYOUT_split_3x6_3_wrapper(_QWERTY_3x6_, _THUMBS_3_2_),
#endif // ifdef QWERTY_ENABLE
#ifdef NOTED_ENABLE
    [LAYER_NOTED] = LAYOUT_split_3x6_3_wrapper(_NOTED_3x6_, _THUMBS_3_2_),
#endif // ifdef NOTED_ENABLE
#ifdef BONE_ENABLE
    [LAYER_BONE] = LAYOUT_split_3x6_3_wrapper(_BONE_3x6_, _THUMBS_3_2_),
#endif // ifdef BONE_ENABLE
#ifdef NEO2_ENABLE
    [LAYER_NEO2] = LAYOUT_split_3x6_3_wrapper(_NEO2_3x6_, _THUMBS_3_2_),
#endif // ifdef BONE_ENABLE
#ifdef COLEMAK_DH_ENABLE
    [LAYER_COLEMAK_DH] = LAYOUT_split_3x6_3_wrapper(_COLEMAK_DH_3x6_, _THUMBS_3_2_),
#endif /* ifdef COLEMAK_DH_ENABLE */
#ifdef DVORAK_DE_ENABLE
    [LAYER_DVORAK_DE] = LAYOUT_split_3x6_3_wrapper(_DVORAK_DE_3x6_, _THUMBS_3_2_),
#endif /* ifdef DVORAK_DE_ENABLE */
#ifdef GAME_ENABLE
    [LAYER_GAME] = LAYOUT_split_3x6_3_wrapper(_GAME_3x6_, _GAME_L4_3_, _GAME_R4_2_),
#endif // GAME_ENABLE

    [LAYER_RAISE] = LAYOUT_split_3x6_3_wrapper(_RAISE_3x6_, _RAISE_L4_3_, _RAISE_R4_2_), //
    [LAYER_LOWER] = LAYOUT_split_3x6_3_wrapper(_LOWER_3x6_, _LOWER_L4_3_, _LOWER_R4_2_), //
    [LAYER_SYMBL] = LAYOUT_split_3x6_3_wrapper(_SYMBL_3x6_, _SYMBL_L4_3_, _SYMBL_R4_2_), //
#ifdef POINTING_DEVICE_ENABLE
    [LAYER_POINTER] = LAYOUT_split_3x6_3_wrapper(                             //
        _ADD_L_1_, KC_NO, KC_NO, S_D_MOD, DPI_MOD, KC_NO, _POINT_R1_6_,       //
        _ADD_L_2_, MS_BTN4, DRG_TOG, DRGSCRL, SNIPING, MS_BTN5, _POINT_R2_6_, //
        _POINT_L3_6_, S_C_TAB, SNIPING, DRGSCRL, DRG_TOG, C___TAB, _ADD_R_3_, //
        _POINT_L4_3_, _POINT_R4_2_),
#endif                                                                                  // ifdef POINTING_DEVICE_ENABLE
    [LAYER_ATTIC] = LAYOUT_split_3x6_3_wrapper(_ATTIC_3x6_, _ATTIC_L4_3_, _ATTIC_R4_2_) //
};

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE
