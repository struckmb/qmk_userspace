/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
// #include QMK_KEYBOARD_H
//
// enum charybdis_keymap_layers {
//     LAYER_BASE = 0,
//     LAYER_LOWER,
//     LAYER_RAISE,
// };
//
// #define LOWER MO(LAYER_LOWER)
// #define RAISE MO(LAYER_RAISE)
//
// // clang-format off
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//   [LAYER_BASE] = LAYOUT(
//   // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
//        KC_LGUI,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_RGUI,
//   // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
//        KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_RCTL,
//   // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
//        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
//   // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
//                                   KC_BSPC,  KC_SPC,   LOWER,      RAISE,  KC_ENT
//   //                            ╰───────────────────────────╯ ╰──────────────────╯
//   ),
//
//   [LAYER_LOWER] = LAYOUT(
//   // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
//        XXXXXXX, RM_TOGG, KC_MNXT, KC_MPLY, KC_MPRV, XXXXXXX,    KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC, XXXXXXX,
//   // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
//        XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    KC_PPLS,    KC_4,    KC_5,    KC_6, KC_PMNS, XXXXXXX,
//   // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
//        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,  QK_BOOT,    KC_PAST,    KC_1,    KC_2,    KC_3, KC_PSLS, XXXXXXX,
//   // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
//                                   XXXXXXX, XXXXXXX, _______,    XXXXXXX, _______
//   //                            ╰───────────────────────────╯ ╰──────────────────╯
//   ),
//
//   [LAYER_RAISE] = LAYOUT(
//   // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
//        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_VOLU, KC_MUTE, KC_VOLD, XXXXXXX, XXXXXXX,
//   // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
//        XXXXXXX, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
//   // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
//        XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,    QK_BOOT, EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
//                                   _______, _______, XXXXXXX,    _______, XXXXXXX
//   //                            ╰───────────────────────────╯ ╰──────────────────╯
//   ),
// };
// // clang-format on

#include "struckmb.h"
#include "keyOverride.c"

#define LAYOUT_split_3x6_3_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#ifdef QWERTY_ENABLE
    [LAYER_QWERTY] = LAYOUT_split_3x6_3_wrapper(_QWERTY_3x6_, _THUMBS_3_2_),
#endif // ifdef QWERTY_ENABLE
#ifdef NEO2_ENABLE
    [LAYER_BONE] = LAYOUT_split_3x6_3_wrapper(_NEO2_3x6_, _THUMBS_3_2_),
#endif // ifdef BONE_ENABLE
#ifdef BONE_ENABLE
    [LAYER_BONE] = LAYOUT_split_3x6_3_wrapper(_BONE_3x6_, _THUMBS_3_2_),
#endif // ifdef BONE_ENABLE
#ifdef NOTED_ENABLE
    [LAYER_NOTED] = LAYOUT_split_3x6_3_wrapper(_NOTED_3x6_, _THUMBS_3_2_),
#endif // ifdef NOTED_ENABLE
#ifdef DVORAK_DE_ENABLE
    [LAYER_DVORAK_DE] = LAYOUT_split_3x6_3_wrapper(_DVORAK_DE_3x6_, _THUMBS_3_2_),
#endif /* ifdef DVORAK_DE_ENABLE */
#ifdef COLEMAK_DH_ENABLE
    [LAYER_COLEMAK_DH] = LAYOUT_split_3x6_3_wrapper(_COLEMAK_DH_3x6_, _THUMBS_3_2_),
#endif /* ifdef COLEMAK_DH_ENABLE */
#ifdef MOUSEKEY_ENABLE
    // [LAYER_POINTER] = LAYOUT_split_3x6_3_wrapper(_POINT_3x6_, _PL4_3_, _PR4_2_),
    [LAYER_POINTER] = LAYOUT_split_3x6_3_wrapper(                          //
        _ADD_L_1_, KC_WH_D, S_D_RMOD, DPI_RMOD, DPI_MOD, S_D_MOD, _POINT_R1_6_, //
        _ADD_L_2_, KC_BTN4, DRG_TOG, DRGSCRL, SNIPING, KC_BTN5, _POINT_R2_6_,   //
        _POINT_L3_6_, KC_NO, SNIPING, DRGSCRL, DRG_TOG, C___TAB, _ADD_R_3_,     //
        _POINT_L4_3_, _POINT_R4_2_),
#endif /* ifdef MOUSEKEY_ENABLE */

    [LAYER_SYMBL] = LAYOUT_split_3x6_3_wrapper(_SYMBL_3x6_, _SYMBL_L4_3_, _SYMBL_R4_2_), //
    [LAYER_LOWER] = LAYOUT_split_3x6_3_wrapper(_LOWER_3x6_, _LOWER_L4_3_, _LOWER_R4_2_), //
    [LAYER_RAISE] = LAYOUT_split_3x6_3_wrapper(_RAISE_3x6_, _RAISE_L4_3_, _RAISE_R4_2_), //
    [LAYER_ATTIC] = LAYOUT_split_3x6_3_wrapper(_ATTIC_3x6_, _ATTIC_L4_3_, _ATTIC_R4_2_), //
};

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE
