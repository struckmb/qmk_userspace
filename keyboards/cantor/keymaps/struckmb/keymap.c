// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include "struckmb.h"
#include "keyOverride.c"

#define LAYOUT_split_3x6_3_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#ifdef QWERTY_ENABLE
    [LAYER_QWERTY] = LAYOUT_split_3x6_3_wrapper(_QWERTY_3x6_, _THUMBS_3_3_),
#endif // ifdef QWERTY_ENABLE
#ifdef NOTED_ENABLE
    [LAYER_NOTED] = LAYOUT_split_3x6_3_wrapper(_NOTED_3x6_, _THUMBS_3_3_),
#endif // ifdef NOTED_ENABLE
#ifdef COLEMAK_DH_ENABLE
    [LAYER_COLEMAK_DH] = LAYOUT_split_3x6_3_wrapper(_COLEMAK_DH_3x6_, _THUMBS_3_3_),
#endif /* ifdef COLEMAK_DH_ENABLE */
#ifdef MOUSEKEY_ENABLE
    [LAYER_POINTER] = LAYOUT_split_3x6_3_wrapper(_POINT_3x6_, _POINT_L4_3_, _POINT_R4_3_),
#endif /* ifdef MOUSEKEY_ENABLE */

    [LAYER_SYMBL] = LAYOUT_split_3x6_3_wrapper(_SYMBL_3x6_, _SYMBL_L4_3_, _SYMBL_R4_3_), //
    [LAYER_LOWER] = LAYOUT_split_3x6_3_wrapper(_LOWER_3x6_, _LOWER_L4_3_, _LOWER_R4_3_), //
    [LAYER_RAISE] = LAYOUT_split_3x6_3_wrapper(_RAISE_3x6_, _RAISE_L4_3_, _RAISE_R4_3_), //
    [LAYER_ATTIC] = LAYOUT_split_3x6_3_wrapper(_ATTIC_3x6_, _ATTIC_L4_3_, _ATTIC_R4_3_), //
};
