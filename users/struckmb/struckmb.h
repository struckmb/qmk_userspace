#pragma once
#include QMK_KEYBOARD_H
#include "keymap_german_extended.h"

// Oled screen
#ifdef OLED_ENABLE
#    include "bs-oled.h"
#endif // OLED_ENABLE

/// Enumeration of layers
enum userspace_layers {
// base layers
#ifdef QWERTY_ENABLE
    LAYER_QWERTY,
#endif // QWERTY_ENABLE
#ifdef NOTED_ENABLE
    LAYER_NOTED,
#endif // NOTED_ENABLE
#ifdef BONE_ENABLE
    LAYER_BONE,
#endif // BONE_ENABLE
#ifdef NEO2_ENABLE
    LAYER_NEO2,
#endif // NEO2_ENABLE
#ifdef COLEMAK_DH_ENABLE
    LAYER_COLEMAK_DH,
#endif // COLEMAK_DH_ENABLE
#ifdef DVORAK_DE_ENABLE
    LAYER_DVORAK_DE,
#endif // DVORAK_DE_ENABLE
#ifdef GAME_ENABLE
    LAYER_GAME,
#endif // GAME_ENABLE
#ifdef ASETNIOP_ENABLE
    LAYER_ASETNIOP,
#endif // ASETNIOP_ENABLE
#ifdef ARTSENIO_ENABLE
    // ARTSENIO layers
    LAYER_ARTSENIO,
    L_ARTS_NUM,
    L_ARTS_SYM,
    L_ARTS_PAR,
    L_ARTS_NAV,
    L_ARTS_MSE,
#endif /* ifdef ARTSENIO_ENABLE */
    // standard layers
    LAYER_RAISE,
    LAYER_LOWER,
    LAYER_SYMBL,
#ifdef MOUSEKEY_ENABLE
    LAYER_POINTER,
#endif // MOUSEKEY_ENABLE
    LAYER_ATTIC
};

#ifdef ARTSENIO_ENABLE
// artsenio specific layer keys
#    define AR_A LT(L_ARTS_PAR, DE_A)
#    define AR_E LT(L_ARTS_SYM, DE_E)
#    define AR_S LT(L_ARTS_NUM, DE_S)
#    define AR_O DE_O
#endif /* ifndef ARTSENIO_ENABLE */

// layer keys
#define DL_BASE PDF(0)
// // non-sticky layers (return to saved after reset):
#ifndef GAME_ENABLE
#    define LAYER_GAME 0
#endif /* ifndef GAME_ENABLE */
#define DL_GAME DF(LAYER_GAME)
#ifndef ARTSENIO_ENABLE
#    define LAYER_ARTSENIO 0
#endif // ifndef ARTSENIO_ENABLE
#define DL_ARTS DF(LAYER_ARTSENIO)
#ifndef ASETNIOP_ENABLE
#    define LAYER_ASETNIOP 0
#endif /* ifndef ASETNIOP_ENABLE */
#define DL_ASET DF(LAYER_ASETNIOP)

// find highest base layer or fail
#ifdef DVORAK_DE_ENABLE
#    define LAYER_MAX LAYER_DVORAK_DE
#else
#    ifdef COLEMAK_DH_ENABLE
#        define LAYER_MAX LAYER_COLEMAK_DH
#    else
#        ifdef NEO2_ENABLE
#            define LAYER_MAX LAYER_NEO2
#        else
#            ifdef BONE_ENABLE
#                define LAYER_MAX LAYER_BONE
#            else
#                ifdef NOTED_ENABLE
#                    define LAYER_MAX LAYER_NOTED
#                else
#                    ifdef QWERTY_ENABLE
#                        define LAYER_MAX LAYER_QWERTY
#                    else
#                        fail // at least one base layer has to be enabled!
#                    endif    // QWERTY_ENABLE
#                endif        // NOTED_ENABLE
#            endif            // BONE_ENABLE
#        endif                // NEO2_ENABLE
#    endif                    // COLEMAK_DH_ENABLE
#endif                        // DVORAK_DE_ENABLE

// Custom macro keycode ranges
enum userspace_custom_keycodes {
    // Safe stuff
    BS_SAFE = SAFE_RANGE,
    DL_PREV,
    DL_NEXT,
    SEL_ALL,
    CP_UNDO,
    CP_REDO,
    NO_MODS,
    // #ifdef ARTSENIO_ENABLE
    //     /* AR_START, AR_END, // Dummy key codes for combo definitions */
    //     AR_A,
    //     AR_S,
    //     AR_E,
    //     AR_O,
    // #endif // ARTSENIO_ENABLE
    // #ifdef ASETNIOP_ENABLE
    //     /* AS_START, AS_END, // Dummy key codes for combo definitions */
    // #endif // ASETNIOP_ENABLE
    // #ifdef X__ENCODER_ENABLE
    //     // Encoder button(s)
    //     BS_ENC0,
    //     BS_ENC1,
    // #endif // X__ENCODER_ENABLE
    // use for keymap specific codes
    KEYMAP_SAFE_RANGE
};

// layer switching shortcuts
#define RSE_ESC LT(LAYER_RAISE, KC_ESC)
#define RSE_DOT LT(LAYER_RAISE, KC_DOT)
#define LOW_TAB LT(LAYER_LOWER, KC_TAB)
#define LOW_ESC LT(LAYER_LOWER, KC_ESC)
#define SYM(kc) LT(LAYER_SYMBL, kc)
#define ATT(kc) LT(LAYER_ATTIC, kc)
#ifdef MOUSEKEY_ENABLE
#    define MS(kc) LT(LAYER_POINTER, kc)
#else
#    define MS(kc) kc
#endif
// some specials
#define GUI_ENT LGUI_T(KC_ENT)
#define SFT_SPC RSFT_T(KC_SPC)
#define C___TAB C(KC_TAB)
#define S_C_TAB S(C(KC_TAB))
#define CP_CUT S(KC_DEL)
#define CP_COPY C(KC_INS)
#define CP_PSTE S(KC_INS)

// home row mod wrappers
#define HRML(k1, k2, k3, k4) LGUI_T(k1), LALT_T(k2), LSFT_T(k3), LCTL_T(k4)
#define HRMR(k1, k2, k3, k4) RCTL_T(k1), RSFT_T(k2), LALT_T(k3), RGUI_T(k4)

// /// // /* KEYMAPS */ // /// //

/* standard first and last column keys on base layers for 6x3 keyboards */
// Base layers
#define _BASE_L_1_ LALT_T(KC_BSPC)
#define _BASE_L_2_ SYM(KC_ESC)
#define _BASE_L_3_ KC_LGUI
// in R1 and R2 kc depends on layout
#define _BASE_R_1_(kc) LALT_T(kc)
#define _BASE_R_2_(kc) SYM(kc)
#define _BASE_R_3_ RCTL_T(KC_APP)
// Additional layers
#define _ADD_L_1_ KC_BSPC
#define _ADD_L_2_ KC_ESC
#define _ADD_L_3_ KC_LGUI
#define _ADD_R_1_ KC_LALT
#define _ADD_R_2_ KC_NO
#define _ADD_R_3_ KC_RCTL

/* THUMBS for base layers */
#define _0L4_2_ GUI_ENT, LOW_TAB
#define _0R4_2_ RSE_DOT, KC_SPC
#define _0R4_2R KC_SPC, RSE_DOT

#define _0L4_3_ RSE_ESC, _0L4_2_
#define _0R4_3_ _0R4_2_, LOW_ESC

#define _THUMBS_3_2_ _0L4_3_, _0R4_2_
#define _THUMBS_3_3_ _0L4_3_, _0R4_3_

#ifdef QWERTY_ENABLE
/* QWERTY layout */
#    define __HRML_QWER HRML(DE_A, DE_S, DE_D, DE_F)
#    define __HRMR_QWER HRMR(DE_J, DE_K, DE_L, DE_ODIA)
#    define __REPL_QWER(kc1, kc2) DE_N, DE_M, kc1, kc2, MS(DE_SS)
//
#    define _QWER_L1_5_ DE_Q, DE_W, DE_E, DE_R, DE_T
#    define _QWER_L2_5_ __HRML_QWER, SYM(DE_G)
#    define _QWER_L3_5_ MS(DE_Y), DE_X, DE_C, DE_V, DE_B
#    define _QWER_R1_5_ DE_Z, DE_U, DE_I, DE_O, DE_P
#    define _QWER_R2_5_ SYM(DE_H), __HRMR_QWER
#    define _QWER_R3_5_ __REPL_QWER(DE_ADIA, DE_UDIA)
//
#    define _QWER_L1_6_ _BASE_L_1_, _QWER_L1_5_
#    define _QWER_L2_6_ _BASE_L_2_, __HRML_QWER, DE_G
#    define _QWER_L3_6_ _BASE_L_3_, _QWER_L3_5_
#    define _QWER_R1_6_ _QWER_R1_5_, _BASE_R_1_(DE_UDIA)
#    define _QWER_R2_6_ DE_H, __HRMR_QWER, _BASE_R_2_(DE_ADIA)
#    define _QWER_R3_6_ __REPL_QWER(DE_COMM, DE_DOT), _BASE_R_3_
//
#    define _QWERTY_3x5_ _QWER_L1_5_, _QWER_R1_5_, _QWER_L2_5_, _QWER_R2_5_, _QWER_L3_5_, _QWER_R3_5_
#    define _QWERTY_3x6_ _QWER_L1_6_, _QWER_R1_6_, _QWER_L2_6_, _QWER_R2_6_, _QWER_L3_6_, _QWER_R3_6_
#endif // QWERTY_ENABLE

#ifdef NOTED_ENABLE
/* NOTED layout */
#    define __HRML_NOTED HRML(DE_C, DE_S, DE_I, DE_E)
#    define __HRMR_NOTED HRMR(DE_T, DE_N, DE_R, DE_H)
#    define __REPL_NOTED(kc1, kc2) DE_W, DE_G, kc1, kc2, MS(DE_K)
//
#    define _NOTED_L1_5_ DE_Z, DE_Y, DE_U, DE_A, DE_Q
#    define _NOTED_L2_5_ __HRML_NOTED, SYM(DE_O)
#    define _NOTED_L3_5_ MS(DE_V), DE_X, DE_UDIA, DE_ADIA, DE_ODIA
#    define _NOTED_R1_5_ DE_P, DE_B, DE_M, DE_L, DE_F
#    define _NOTED_R2_5_ SYM(DE_D), __HRMR_NOTED
#    define _NOTED_R3_5_ __REPL_NOTED(DE_J, DE_SS)
//
#    define _NOTED_L1_6_ _BASE_L_1_, _NOTED_L1_5_
#    define _NOTED_L2_6_ _BASE_L_2_, __HRML_NOTED, DE_O
#    define _NOTED_L3_6_ _BASE_L_3_, _NOTED_L3_5_
#    define _NOTED_R1_6_ _NOTED_R1_5_, _BASE_R_1_(DE_J)
#    define _NOTED_R2_6_ DE_D, __HRMR_NOTED, _BASE_R_2_(DE_SS)
#    define _NOTED_R3_6_ __REPL_NOTED(DE_COMM, DE_DOT), _BASE_R_3_
//
#    define _NOTED_3x5_ _NOTED_L1_5_, _NOTED_R1_5_, _NOTED_L2_5_, _NOTED_R2_5_, _NOTED_L3_5_, _NOTED_R3_5_
#    define _NOTED_3x6_ _NOTED_L1_6_, _NOTED_R1_6_, _NOTED_L2_6_, _NOTED_R2_6_, _NOTED_L3_6_, _NOTED_R3_6_
#endif // NOTED_ENABLE

#ifdef BONE_ENABLE
/* BONE layout */
#    define __HRML_BONE HRML(DE_C, DE_T, DE_I, DE_E)
#    define __HRMR_BONE HRMR(DE_N, DE_R, DE_S, DE_G)
#    define __REPL_BONE(kc1, kc2) DE_Y, DE_Z, kc1, kc2, MS(DE_K)
//
#    define _BONE_L1_5_ DE_J, DE_D, DE_U, DE_A, DE_X
#    define _BONE_L2_5_ __HRML_BONE, SYM(DE_O)
#    define _BONE_L3_5_ MS(DE_F), DE_V, DE_UDIA, DE_ADIA, DE_ODIA
#    define _BONE_R1_5_ DE_P, DE_H, DE_L, DE_M, DE_W
#    define _BONE_R2_5_ SYM(DE_B), __HRMR_BONE
#    define _BONE_R3_5_ __REPL_BONE(DE_Q, DE_SS)
//
#    define _BONE_L1_6_ _BASE_L_1_, _BONE_L1_5_
#    define _BONE_L2_6_ _BASE_L_2_, __HRML_BONE, DE_O
#    define _BONE_L3_6_ _BASE_L_3_, _BONE_L3_5_
#    define _BONE_R1_6_ _BONE_R1_5_, _BASE_R_1_(DE_SS)
#    define _BONE_R2_6_ DE_B, __HRMR_BONE, _BASE_R_2_(DE_Q)
#    define _BONE_R3_6_ __REPL_BONE(DE_COMM, DE_DOT), _BASE_R_3_
//
#    define _BONE_3x5_ _BONE_L1_5_, _BONE_R1_5_, _BONE_L2_5_, _BONE_R2_5_, _BONE_L3_5_, _BONE_R3_5_
#    define _BONE_3x6_ _BONE_L1_6_, _BONE_R1_6_, _BONE_L2_6_, _BONE_R2_6_, _BONE_L3_6_, _BONE_R3_6_
#endif // BONE_ENABLE

#ifdef NEO2_ENABLE
/* NEO2 layout */
#    define __HRML_NEO2 HRML(DE_U, DE_I, DE_A, DE_E)
#    define __HRMR_NEO2 HRMR(DE_N, DE_R, DE_T, DE_D)
#    define __REPL_NEO2(kc1, kc2) DE_B, DE_M, kc1, kc2, MS(DE_J)
//
#    define _NEO2_L1_5_ DE_X, DE_V, DE_L, DE_C, DE_W
#    define _NEO2_L2_5_ __HRML_NEO2, SYM(DE_O)
#    define _NEO2_L3_5_ MS(DE_UDIA), DE_ODIA, DE_ADIA, DE_P, DE_Z
#    define _NEO2_R1_5_ DE_K, DE_H, DE_G, DE_F, DE_Q
#    define _NEO2_R2_5_ SYM(DE_S), __HRMR_NEO2
#    define _NEO2_R3_5_ __REPL_NEO2(DE_Y, DE_SS)
//
#    define _NEO2_L1_6_ _BASE_L_1_, _NEO2_L1_5_
#    define _NEO2_L2_6_ _BASE_L_2_, __HRML_NEO2, DE_O
#    define _NEO2_L3_6_ _BASE_L_3_, _NEO2_L3_5_
#    define _NEO2_R1_6_ _NEO2_R1_5_, _BASE_R_1_(DE_SS)
#    define _NEO2_R2_6_ DE_B, __HRMR_NEO2, _BASE_R_2_(DE_Y)
#    define _NEO2_R3_6_ __REPL_NEO2(DE_COMM, DE_DOT), _BASE_R_3_
//
#    define _NEO2_3x5_ _NEO2_L1_5_, _NEO2_R1_5_, _NEO2_L2_5_, _NEO2_R2_5_, _NEO2_L3_5_, _NEO2_R3_5_
#    define _NEO2_3x6_ _NEO2_L1_6_, _NEO2_R1_6_, _NEO2_L2_6_, _NEO2_R2_6_, _NEO2_L3_6_, _NEO2_R3_6_
#endif // NEO2_ENABLE

#ifdef COLEMAK_DH_ENABLE
/* Colemak Mod-DH layout (german adaption) */
#    define __HRML_COLEMAK_DH HRML(DE_A, DE_R, DE_S, DE_T)
#    define __HRMR_COLEMAK_DH HRMR(DE_N, DE_E, DE_I, DE_O)
#    define __REPL_COLEMAK_DH(kc1, kc2) DE_K, DE_H, kc1, kc2, MS(DE_SS)
//
#    define _COLEMAK_DH_L1_5_ DE_Q, DE_W, DE_F, DE_P, DE_B
#    define _COLEMAK_DH_L2_5_ __HRML_COLEMAK_DH, SYM(DE_G)
#    define _COLEMAK_DH_L3_5_ MS(DE_Z), DE_X, DE_C, DE_D, DE_V
#    define _COLEMAK_DH_R1_5_ DE_J, DE_L, DE_U, DE_Y, DE_ODIA
#    define _COLEMAK_DH_R2_5_ SYM(DE_M), __HRMR_COLEMAK_DH
#    define _COLEMAK_DH_R3_5_ __REPL_COLEMAK_DH(DE_ADIA, DE_UDIA)
//
#    define _COLEMAK_DH_L1_6_ _BASE_L_1_, _COLEMAK_DH_L1_5_
#    define _COLEMAK_DH_L2_6_ _BASE_L_2_, __HRML_COLEMAK_DH, DE_G
#    define _COLEMAK_DH_L3_6_ _BASE_L_3_, _COLEMAK_DH_L3_5_
#    define _COLEMAK_DH_R1_6_ _COLEMAK_DH_R1_5_, _BASE_R_1_(DE_UDIA)
#    define _COLEMAK_DH_R2_6_ DE_M, __HRMR_COLEMAK_DH, _BASE_R_2_(DE_ADIA)
#    define _COLEMAK_DH_R3_6_ __REPL_COLEMAK_DH(DE_COMM, DE_DOT), _BASE_R_3_
//
#    define _COLEMAK_DH_3x5_ _COLEMAK_DH_L1_5_, _COLEMAK_DH_R1_5_, _COLEMAK_DH_L2_5_, _COLEMAK_DH_R2_5_, _COLEMAK_DH_L3_5_, _COLEMAK_DH_R3_5_
#    define _COLEMAK_DH_3x6_ _COLEMAK_DH_L1_6_, _COLEMAK_DH_R1_6_, _COLEMAK_DH_L2_6_, _COLEMAK_DH_R2_6_, _COLEMAK_DH_L3_6_, _COLEMAK_DH_R3_6_
#endif // COLEMAK_DH_ENABLE

#ifdef DVORAK_DE_ENABLE
/* Dvorak layout (german adaption, 3x6 only) */
#    define __HRML_DVORAK_DE HRML(DE_A, DE_O, DE_E, DE_I)
#    define __HRMR_DVORAK_DE HRMR(DE_D, DE_R, DE_N, DE_S)
#    define __REPL_DVORAK_DE(kc1, kc2) DE_UDIA, kc1, kc2, DE_P, DE_Y
//
#    define _DVORAK_DE_L1_5_ __REPL_DVORAK_DE(DE_SS, DE_L)
#    define _DVORAK_DE_L2_5_ __HRML_DVORAK_DE, SYM(DE_U)
#    define _DVORAK_DE_L3_5_ MS(DE_ODIA), DE_Q, DE_J, DE_K, DE_X
#    define _DVORAK_DE_R1_5_ DE_F, DE_G, DE_C, DE_T, DE_Z
#    define _DVORAK_DE_R2_5_ SYM(DE_H), __HRMR_DVORAK_DE
#    define _DVORAK_DE_R3_5_ DE_B, DE_M, DE_W, DE_V, MS(DE_ADIA)
//
#    define _DVORAK_DE_L1_6_ _BASE_L_1_, __REPL_DVORAK_DE(DE_COMM, DE_DOT)
#    define _DVORAK_DE_L2_6_ _BASE_L_2_, __HRML_DVORAK_DE, DE_U
#    define _DVORAK_DE_L3_6_ DE_ADIA, _DVORAK_DE_L3_5_
#    define _DVORAK_DE_R1_6_ _DVORAK_DE_R1_5_, _BASE_R_1_(DE_SS)
#    define _DVORAK_DE_R2_6_ DE_H, __HRMR_DVORAK_DE, _BASE_R_2_(DE_L)
#    define _DVORAK_DE_R3_6_ _DVORAK_DE_R3_5_, _BASE_R_3_
//
#    define _DVORAK_DE_3x6_ _DVORAK_DE_L1_6_, _DVORAK_DE_R1_6_, _DVORAK_DE_L2_6_, _DVORAK_DE_R2_6_, _DVORAK_DE_L3_6_, _DVORAK_DE_R3_6_
#    define _DVORAK_DE_3x5_ _DVORAK_DE_L1_5_, _DVORAK_DE_R1_5_, _DVORAK_DE_L2_5_, _DVORAK_DE_R2_5_, _DVORAK_DE_L3_5_, _DVORAK_DE_R3_5_
#endif // DVORAK_DE_ENABLE

#ifdef GAME_ENABLE
// GAME layout
#    define _GAME_L1_5_ DE_Q, DE_W, DE_E, DE_R, DE_T
#    define _GAME_L2_5_ DE_A, DE_S, DE_D, DE_F, DE_G
#    define _GAME_L3_5_ DE_Y, DE_X, DE_C, DE_V, DE_B
#    define _GAME_R1_5_ KC_6, KC_7, KC_8, KC_9, KC_ESC
#    define _GAME_R2_5_ KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_5
#    define _GAME_R3_5_ DE_0, KC_1, KC_2, KC_3, KC_4
//
#    define _GAME_L1_6_ KC_TAB, _GAME_L1_5_
#    define _GAME_L2_6_ KC_LCTL, _GAME_L2_5_
#    define _GAME_L3_6_ KC_LSFT, _GAME_L3_5_
#    define _GAME_R1_6_ KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC
#    define _GAME_R2_6_ _GAME_R2_5_, KC_ENT
#    define _GAME_R3_6_ _GAME_R3_5_, KC_RSFT
//
#    define _GAME_L4_2_ KC_ENT, KC_TAB
#    define _GAME_R4_2_ KC_LSFT, KC_SPC
#    define _GAME_L4_3_ KC_LCTL, _GAME_L4_2_
#    define _GAME_R4_3_ _GAME_R4_2_, KC_LALT
//
#    define _GAME_3x6_ _GAME_L1_6_, _GAME_R1_6_, _GAME_L2_6_, _GAME_R2_6_, _GAME_L3_6_, _GAME_R3_6_
#endif // GAME_ENABLE

/* Raise: Control + Navigation layer */
#define _RAISE_L1_5_ KC_PGUP, KC_BSPC, KC_UP, KC_DEL, KC_PGDN
#define _RAISE_L2_5_ KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END
#define _RAISE_L3_5_ CP_UNDO, CP_CUT, CP_COPY, CP_PSTE, SEL_ALL
#define _RAISE_R1_5_ KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_EJCT
#define _RAISE_R2_5_ OS_MEH, OS_LCTL, OS_LSFT, OS_LALT, OS_LGUI
#define _RAISE_R3_5_ KC_PSCR, KC_INS, CW_TOGG, OS_RALT, CP_REDO
//
#define _RAISE_L1_6_ _ADD_L_1_, _RAISE_L1_5_
#define _RAISE_L2_6_ KC_INS, _RAISE_L2_5_
#define _RAISE_L3_6_ _ADD_L_3_, _RAISE_L3_5_
#define _RAISE_R1_6_ _RAISE_R1_5_, KC_PAUS
#define _RAISE_R2_6_ _RAISE_R2_5_, KC_SCRL
#define _RAISE_R3_6_ _RAISE_R3_5_, KC_TRNS
//
#define _RAISE_L4_2_ LSFT_T(KC_VOLD), ATT(KC_MUTE)
#define _RAISE_R4_2_ KC_TRNS, RSFT_T(KC_VOLU)
#define _RAISE_R4R2_ RSFT_T(KC_VOLU), KC_TRNS
#define _RAISE_L4_3_ KC_MPRV, _RAISE_L4_2_
#define _RAISE_R4_3_ _RAISE_R4_2_, KC_MNXT
//
#define _RAISE_3x5_ _RAISE_L1_5_, _RAISE_R1_5_, _RAISE_L2_5_, _RAISE_R2_5_, _RAISE_L3_5_, _RAISE_R3_5_
#define _RAISE_3x6_ _RAISE_L1_6_, _RAISE_R1_6_, _RAISE_L2_6_, _RAISE_R2_6_, _RAISE_L3_6_, _RAISE_R3_6_

/* Lower: Numbers and function keys */
#define _LOWER_L1_5_ KC_F1, KC_F2, KC_F3, KC_F4, DE_PND
#define _LOWER_L2_5_ HRML(KC_F5, KC_F6, KC_F7, KC_F8), DE_EURO
#define _LOWER_L3_5_ KC_F9, KC_F10, KC_F11, KC_F12, DE_CENT
#define _LOWER_R1_5_ DE_SLSH, DE_7, DE_8, DE_9, DE_PLUS
#define _LOWER_R2_5_ DE_DOT, HRMR(DE_4, DE_5, DE_6, DE_MINS)
#define _LOWER_R3_5_ DE_COLN, DE_1, DE_2, DE_3, DE_COMM
//
#define _LOWER_L1_6_ _ADD_L_1_, _LOWER_L1_5_
#define _LOWER_L2_6_ DE_YEN, _LOWER_L2_5_
#define _LOWER_L3_6_ KC_TRNS, _LOWER_L3_5_
#define _LOWER_R1_6_ _LOWER_R1_5_, DE_DLR
#define _LOWER_R2_6_ _LOWER_R2_5_, DE_HASH
#define _LOWER_R3_6_ _LOWER_R3_5_, KC_TRNS
//
#define _LOWER_L4_2_ DE_YEN, KC_TRNS
#define _LOWER_R4_2_ ATT(KC_APP), DE_0
#define _LOWER_R4R2_ DE_0, ATT(KC_APP)
#define _LOWER_L4_3_ DE_DLR, _LOWER_L4_2_
#define _LOWER_R4_3_ _LOWER_R4_2_, DE_DLR
//
#define _LOWER_3x5_ _LOWER_L1_5_, _LOWER_R1_5_, _LOWER_L2_5_, _LOWER_R2_5_, _LOWER_L3_5_, _LOWER_R3_5_
#define _LOWER_3x6_ _LOWER_L1_6_, _LOWER_R1_6_, _LOWER_L2_6_, _LOWER_R2_6_, _LOWER_L3_6_, _LOWER_R3_6_

/* Symbols layer */
#define _SYMBL_L1_5_ DE_AT, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC
#define _SYMBL_L2_5_ DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR
#define _SYMBL_L3_5_ DE_HASH, DE_DLR, DE_PIPE, DE_TILD, DE_ACUT
#define _SYMBL_R1_5_ DE_EXLM, DE_LABK, DE_RABK, DE_EQL, DE_AMPR
#define _SYMBL_R2_5_ DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN
#define _SYMBL_R3_5_ DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN
//
#define _SYMBL_L1_6_ _ADD_L_1_, _SYMBL_L1_5_
#define _SYMBL_L2_6_ _ADD_L_2_, _SYMBL_L2_5_
#define _SYMBL_L3_6_ _ADD_L_3_, _SYMBL_L3_5_
#define _SYMBL_R1_6_ _SYMBL_R1_5_, DE_SLNG
#define _SYMBL_R2_6_ _SYMBL_R2_5_, DE_SECT
#define _SYMBL_R3_6_ _SYMBL_R3_5_, DE_ELLP
//
#define _SYMBL_L4_2_ DE_SECT, G(DE_CIRC)
#define _SYMBL_R4_2_ DE_ELLP, KC_SPC
#define _SYMBL_R4R2_ KC_SPC, DE_ELLP
#define _SYMBL_L4_3_ DE_DEG, _SYMBL_L4_2_
#define _SYMBL_R4_3_ _SYMBL_R4_2_, DE_SLNG
//
#define _SYMBL_3x5_ _SYMBL_L1_5_, _SYMBL_R1_5_, _SYMBL_L2_5_, _SYMBL_R2_5_, _SYMBL_L3_5_, _SYMBL_R3_5_
#define _SYMBL_3x6_ _SYMBL_L1_6_, _SYMBL_R1_6_, _SYMBL_L2_6_, _SYMBL_R2_6_, _SYMBL_L3_6_, _SYMBL_R3_6_

#ifdef MOUSEKEY_ENABLE
/* Pointer layer */
#    define _POINT_L1_5_ MS_WHLD, MS_WHLL, MS_UP, MS_WHLR, MS_WHLU
#    define _POINT_L2_5_ MS_BTN4, MS_LEFT, MS_DOWN, MS_RGHT, MS_BTN5
#    define _POINT_L3_5_ S_C_TAB, CP_CUT, CP_COPY, CP_PSTE, SEL_ALL
#    define _POINT_R1_5_ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#    define _POINT_R2_5_ _RAISE_R2_5_
#    define _POINT_R3_5_ MS_ACL0, MS_ACL1, MS_ACL2, OS_RALT, C___TAB
//
#    define _POINT_L1_6_ XXXXXXX, _POINT_L1_5_
#    define _POINT_L2_6_ XXXXXXX, _POINT_L2_5_
#    define _POINT_L3_6_ XXXXXXX, _POINT_L3_5_
#    define _POINT_R1_6_ _POINT_R1_5_, XXXXXXX
#    define _POINT_R2_6_ _POINT_R2_5_, XXXXXXX
#    define _POINT_R3_6_ _POINT_R3_5_, XXXXXXX
//
#    define _POINT_L4_2_ MS_BTN1, MS_BTN2
#    define _POINT_R4_2_ MS_BTN3, MS_BTN1
#    define _POINT_R4R2_ MS_BTN1, MS_BTN3
#    define _POINT_L4_3_ XXXXXXX, _POINT_L4_2_
#    define _POINT_R4_3_ _POINT_R4_2_, XXXXXXX
//
#    define _POINT_3x5_ _POINT_L1_5_, _POINT_R1_5_, _POINT_L2_5_, _POINT_R2_5_, _POINT_L3_5_, _POINT_R3_5_
#    define _POINT_3x6_ _POINT_L1_6_, _POINT_R1_6_, _POINT_L2_6_, _POINT_R2_6_, _POINT_L3_6_, _POINT_R3_6_
#endif // MOUSEKEY_ENABLE

/* Attic: Adjustments and missing stuff */
#define _ATTIC_L1_5_ QK_BOOT, DL_ARTS, DL_ASET, DL_GAME, NO_MODS
#define _ATTIC_L2_5_ EE_CLR, DL_PREV, DL_NEXT, DL_BASE, UG_TOGG
#define _ATTIC_L3_5_ UG_SPDU, UG_SATU, UG_HUEU, UG_VALU, UG_NEXT
#define _ATTIC_R1_5_ DE_IEXL, DE_LSAQ, DE_LDAQ, DE_RDAQ, DE_RSAQ
#define _ATTIC_R2_5_ DE_IQUE, DE_MDOT, DE_SLQU, DE_LSQU, DE_RSQU
#define _ATTIC_R3_5_ DE_NDSH, DE_MDSH, DE_DLQU, DE_LDQU, DE_RDQU
//
#define _ATTIC_L1_6_ QK_BOOT, _ATTIC_L1_5_
#define _ATTIC_L2_6_ EE_CLR, _ATTIC_L2_5_
#define _ATTIC_L3_6_ QK_RBT, _ATTIC_L3_5_
#define _ATTIC_R1_6_ _ATTIC_R1_5_, QK_BOOT
#define _ATTIC_R2_6_ _ATTIC_R2_5_, EE_CLR
#define _ATTIC_R3_6_ _ATTIC_R3_5_, KC_PWR
//
#define _ATTIC_L4_2_ LSFT_T(KC_BRID), KC_TRNS
#define _ATTIC_L4_3_ KC_LSFT, _ATTIC_L4_2_
#define _ATTIC_R4_2_ KC_TRNS, RSFT_T(KC_BRIU)
#define _ATTIC_R4_3_ _ATTIC_R4_2_, KC_RSFT
//
#define _ATTIC_3x5_ _ATTIC_L1_5_, _ATTIC_R1_5_, _ATTIC_L2_5_, _ATTIC_R2_5_, _ATTIC_L3_5_, _ATTIC_R3_5_
#define _ATTIC_3x6_ _ATTIC_L1_6_, _ATTIC_R1_6_, _ATTIC_L2_6_, _ATTIC_R2_6_, _ATTIC_L3_6_, _ATTIC_R3_6_
