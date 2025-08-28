#pragma once
#include QMK_KEYBOARD_H
#include "keymap_german_extended.h"

#ifndef QWERTY_ENABLE
#  ifndef BONE_ENABLE
#    ifndef NOTED_ENABLE
#      ifndef COLEMAK_DH_ENABLE
#        fail // at least one base layer has to be enabled!
#      endif // !COLEMAK_DH_ENABLE
#    endif // !NOTED_ENABLE
#  endif // !BONE_ENABLE
#endif // !QWERTY_ENABLE

/// Enumeration of layers
enum userspace_layers {
// base layers
#ifdef QWERTY_ENABLE
    LAYER_QWERTY,
#endif // QWERTY_ENABLE
#ifdef BONE_ENABLE
    LAYER_BONE,
#endif /* ifdef BONE_ENABLE */
#ifdef NOTED_ENABLE
    LAYER_NOTED,
#endif /* ifdef NOTED_ENABLE */
#ifdef COLEMAK_DH_ENABLE
    LAYER_COLEMAK_DH,
#endif /* ifdef COLEMAK_DH_ENABLE */
#ifdef GAME_ENABLE
    LAYER_GAME,
#endif /* ifdef GAME_ENABLE */
#ifdef ASETNIOP_ENABLE
    LAYER_ASETNIOP,
#endif /* ifdef ASETNIOP_ENABLE */
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
    LAYER_SYMBL,
    LAYER_LOWER,
    LAYER_RAISE,
#ifdef MOUSEKEY_ENABLE
    LAYER_POINTER,
#endif // MOUSEKEY_ENABLE
    LAYER_ATTIC,
    LAYER_X
};

// Custom macro keycode ranges
enum userspace_custom_keycodes {
    // Safe stuff
    BS_SAFE = SAFE_RANGE,
    DL_PREV,
    DL_NEXT,
    NO_MODS,
#ifdef ARTSENIO_ENABLE
    /* AR_START, AR_END, // Dummy key codes for combo definitions */
    AR_A,
    AR_S,
    AR_E,
    AR_O,
#endif // ARTSENIO_ENABLE
#ifdef ASETNIOP_ENABLE
/* AS_START, AS_END, // Dummy key codes for combo definitions */
#endif // ASETNIOP_ENABLE
#ifdef X__ENCODER_ENABLE
    // Encoder button(s)
    BS_ENC0,
    BS_ENC1,
#endif // X__ENCODER_ENABLE
       // use for keymap specific codes
    KEYMAP_SAFE_RANGE
};

// Fallbacks to first base layer
#ifndef QWERTY_ENABLE
#    define LAYER_QWERTY 0
#endif // ifndef QWERTY_ENABLE
#ifndef BONE_ENABLE
#    define LAYER_BONE 0
#endif // ifndef BONE_ENABLE
#ifndef NOTED_ENABLE
#    define LAYER_NOTED 0
#endif // ifndef NOTED_ENABLE
#ifndef COLEMAK_DH_ENABLE
#    define LAYER_COLEMAK_DH 0
#endif // ifndef COLEMAK_DH_ENABLE
#ifndef GAME_ENABLE
#    define LAYER_GAME 0
#endif /* ifndef GAME_ENABLE */
#ifndef ARTSENIO_ENABLE
#    define LAYER_ARTSENIO 0
#else // artsenio specific layer keys
#    define AR_A LT(L_ARTS_PAR, DE_A)
#    define AR_E LT(L_ARTS_SYM, DE_E)
#    define AR_S LT(L_ARTS_NUM, DE_S)
#    define AR_O DE_O
#endif /* ifndef ARTSENIO_ENABLE */
#ifndef ASETNIOP_ENABLE
#    define LAYER_ASETNIOP 0
#endif /* ifndef ASETNIOP_ENABLE */
// sticky layers (withstands reset):
#define DL_QWER PDF(LAYER_QWERTY)
#define DL_BONE PDF(LAYER_BONE)
#define DL_NOTE PDF(LAYER_NOTED)
#define DL_CODH PDF(LAYER_COLEMAK_DH)
// non-sticky layers (return to saved after reset):
#define DL_GAME DF(LAYER_GAME)
#define DL_ARTS DF(LAYER_ARTSENIO)
#define DL_ASET DF(LAYER_ASETNIOP)

// layer switching shortcuts
#define LOW_TAB LT(LAYER_LOWER, KC_TAB)
#define RSE_BSP LT(LAYER_RAISE, KC_BSPC)
#define ATT(kc) LT(LAYER_ATTIC, kc)
#define SY_L(kc) LT(LAYER_SYMBL, kc)
#define SY_R(kc) LT(LAYER_SYMBL, kc)
#ifdef MOUSEKEY_ENABLE
#    define MS(kc) LT(LAYER_POINTER, kc)
#else
#    define MS(kc) kc
#endif
#define LX(kc) LT(LAYER_X, kc)

// one shot modifier shortcuts
#define OSM_ALT OSM(MOD_LALT)
#define OSM_AGR OSM(MOD_RALT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_MEH OSM(MOD_MEH)
#define OSM_SFT OSM(MOD_LSFT)

// // first and last column for 6 column keyboards:
#define SFT_ENT LSFT_T(KC_ENT)
#define SFT_SPC RSFT_T(KC_SPC)
#define C___TAB C(KC_TAB)
#define S_C_TAB S(C(KC_TAB))

#define HRML(k1, k2, k3, k4) LGUI_T(k1), LALT_T(k2), LSFT_T(k3), LCTL_T(k4)
#define HRMR(k1, k2, k3, k4) RCTL_T(k1), RSFT_T(k2), LALT_T(k3), RGUI_T(k4)

// /// // /* KEYMAPS */ // /// //

/* first and last column base layer keys for 6x3 keyboards */
// Base layers
#define _BASE_L_1_ LALT_T(KC_BSPC)
#define _BASE_L_2_ SY_L(KC_ESC)
#define _BASE_L_3_ LGUI_T(KC_APP)
// R1 and R2 depend on layout
#define _BASE_R_1_(kc) LALT_T(kc)
#define _BASE_R_2_(kc) SY_R(kc)
#define _BASE_R_3_(kc) RGUI_T(kc)
// Additional layers
#define _ADD_L_1_ KC_LALT
#define _ADD_L_2_ _BASE_L_2_
#define _ADD_L_3_ KC_LGUI
// R1 and R2 depend on layout
#define _ADD_R_1_ KC_LALT
#define _ADD_R_2_ KC_RCTL
#define _ADD_R_3_ KC_RGUI
// thumbs
#define _0L4_2_ SFT_ENT, LOW_TAB
#define _0L4_3_ KC_ESC, _0L4_2_
#define _0R4_2_ RSE_BSP, SFT_SPC
#define _0R4_3_ _0R4_2_, QK_REP

/* THUMBS for base layers */
#define _THUMBS_3_2_ _0L4_3_, _0R4_2_
#define _THUMBS_3_3_ _0L4_3_, _0R4_3_

#ifdef QWERTY_ENABLE
/* QWERTY layout */
#    define __QL1_1_ DE_Q
#    define __QL1_4_ DE_W, DE_E, DE_R, DE_T
#    define __QR1_4_ DE_Z, DE_U, DE_I, DE_O
#    define __QR1_1_ DE_P
#    define __QL2_4_ HRML(DE_A, DE_S, DE_D, DE_F)
#    define __QL2_1_ DE_G
#    define __QR2_1_ DE_H
#    define __QR2_4_ HRMR(DE_J, DE_K, DE_L, DE_ODIA)

#    define _QL1_5_ LX(__QL1_1_), __QL1_4_
#    define _QL2_5_ __QL2_4_, SY_L(__QL2_1_)
#    define _QL3_5_ MS(DE_Y), DE_X, DE_C, DE_V, DE_B
#    define _QR1_5_ __QR1_4_, __QR1_1_
#    define _QR2_5_ SY_R(__QR2_1_), __QR2_4_
#    define _QR3_5_ DE_N, DE_M, DE_COMM, DE_DOT, MS(DE_SS)
//
#    define _QL1_6_ _BASE_L_1_, __QL1_1_, __QL1_4_
#    define _QL2_6_ _BASE_L_2_, __QL2_4_, __QL2_1_
#    define _QL3_6_ _BASE_L_3_, _QL3_5_
#    define _QR1_6_ _QR1_5_, _BASE_R_1_(DE_UDIA)
#    define _QR2_6_ __QR2_1_, __QR2_4_, _BASE_R_2_(DE_ADIA)
#    define _QR3_6_ _QR3_5_, _BASE_R_3_(KC_ENT)
//
#    define _QWERTY_3x5_ _QL1_5_, _QR1_5_, _QL2_5_, _QR2_5_, _QL3_5_, _QR3_5_
#    define _QWERTY_3x6_ _QL1_6_, _QR1_6_, _QL2_6_, _QR2_6_, _QL3_6_, _QR3_6_
#    define _QWERTY_L_X_ _QL1_5_, DE_Z, DE_UDIA, DE_I, DE_O, DE_P, _QL2_5_, __QR2_4_, DE_ADIA, _QL3_5_, _QR3_5_
#endif // QWERTY_ENABLE

#ifdef BONE_ENABLE
/* BONE layout */
#    define __HRM__BL2_4_ HRML(DE_C, DE_T, DE_I, DE_E)
#    define __HRM__BR2_4_ HRMR(DE_N, DE_R, DE_S, DE_G)
#    define _BL1_5_ DE_J, DE_D, DE_U, DE_A, DE_X
#    define _BL2_5_ __HRM__BL2_4_, SY_L(DE_O)
#    define _BL3_5_ MS(DE_F), DE_V, DE_UDIA, DE_ADIA, DE_ODIA
#    define _BR1_5_ DE_P, DE_H, DE_L, DE_M, DE_W
#    define _BR2_5_ SY_R(DE_B), __HRM__BR2_4_
#    define _BR3_5_ DE_Y, DE_Z, DE_COMM, DE_DOT, MS(DE_K)
//
#    define _BL1_6_ _BASE_L_1_, _BL1_5_
#    define _BL2_6_ _BASE_L_2_, __HRM__BL2_4_, DE_O
#    define _BL3_6_ _BASE_L_3_, _BL3_5_
#    define _BR1_6_ _BR1_5_, _BASE_R_1_(DE_SS)
#    define _BR2_6_ DE_B, __HRM__BR2_4_, _BASE_R_2_(DE_Q)
#    define _BR3_6_ _BR3_5_, _BASE_R_3_(KC_ENT)
//
#    define _BONE_3x5_ _BL1_5_, _BR1_5_, _BL2_5_, _BR2_5_, _BL3_5_, _BR3_5_
#    define _BONE_3x6_ _BL1_6_, _BR1_6_, _BL2_6_, _BR2_6_, _BL3_6_, _BR3_6_
#endif // BONE_ENABLE

#ifdef NOTED_ENABLE
/* NOTED layout */
#    define __HRM__NL2_4_ HRML(DE_C, DE_S, DE_I, DE_E)
#    define __HRM__NR2_4_ HRMR(DE_T, DE_N, DE_R, DE_H)
#    define _NL1_5_ DE_Z, DE_Y, DE_U, DE_A, DE_Q
#    define _NL2_5_ __HRM__NL2_4_, SY_L(DE_O)
#    define _NL3_5_ MS(DE_V), DE_X, DE_UDIA, DE_ADIA, DE_ODIA
#    define _NR1_5_ DE_P, DE_B, DE_M, DE_L, DE_F
#    define _NR2_5_ SY_R(DE_D), __HRM__NR2_4_
#    define _NR3_5_ DE_W, DE_G, DE_COMM, DE_DOT, MS(DE_K)
//
#    define _NL1_6_ _BASE_L_1_, _NL1_5_
#    define _NL2_6_ _BASE_L_2_, __HRM__NL2_4_, DE_O
#    define _NL3_6_ _BASE_L_3_, _NL3_5_
#    define _NR1_6_ _NR1_5_, _BASE_R_1_(DE_J)
#    define _NR2_6_ DE_D, __HRM__NR2_4_, _BASE_R_2_(DE_SS)
#    define _NR3_6_ _NR3_5_, _BASE_R_3_(KC_ENT)
//
#    define _NOTED_3x5_ _NL1_5_, _NR1_5_, _NL2_5_, _NR2_5_, _NL3_5_, _NR3_5_
#    define _NOTED_3x6_ _NL1_6_, _NR1_6_, _NL2_6_, _NR2_6_, _NL3_6_, _NR3_6_
#endif // NOTED_ENABLE

#ifdef COLEMAK_DH_ENABLE
/* Colemak Mod-DH layout (german adaption) */
#    define __HRM__CL2_4_ HRML(DE_A, DE_R, DE_S, DE_T)
#    define __HRM__CR2_4_ HRMR(DE_N, DE_E, DE_I, DE_O)
#    define _CL1_5_ DE_Q, DE_W, DE_F, DE_P, DE_B
#    define _CR1_5_ DE_J, DE_L, DE_U, DE_Y, DE_ODIA
#    define _CL2_5_ __HRM__CL2_4_, SY_L(DE_G)
#    define _CR2_5_ SY_R(DE_M), __HRM__CR2_4_
#    define _CL3_5_ MS(DE_Z), DE_X, DE_C, DE_D, DE_V
#    define _CR3_5_ DE_K, DE_H, DE_COMM, DE_DOT, MS(DE_SS)
//
#    define _CL1_6_ _BASE_L_1_, _CL1_5_
#    define _CR1_6_ _CR1_5_, _BASE_R_1_(DE_UDIA)
#    define _CL2_6_ _BASE_L_2_, __HRM__CL2_4_, DE_G
#    define _CR2_6_ DE_M, __HRM__CR2_4_, _BASE_R_2_(DE_ADIA)
#    define _CL3_6_ _BASE_L_3_, _CL3_5_
#    define _CR3_6_ _CR3_5_, _BASE_R_3_(KC_ENT)
//
#    define _COLEMAK_DH_3x5_ _CL1_5_, _CR1_5_, _CL2_5_, _CR2_5_, _CL3_5_, _CR3_5_
#    define _COLEMAK_DH_3x6_ _CL1_6_, _CR1_6_, _CL2_6_, _CR2_6_, _CL3_6_, _CR3_6_
#endif // COLEMAK_DH_ENABLE

#ifdef GAME_ENABLE
/* GAME layout
 *  q │ w │ e │ r │ t         6 │ 7 │ 8 │ 9 │ 0
 * ───┼───┼───┼───┼───       ───┼───┼───┼───┼───
 *  a │ s │ d │ f │ g         ← │ ↓ │ ↑ │ → │Tab
 * ───┼───┼───┼───┼───       ───┼───┼───┼───┼───
 *  y │ x │ c │ v │ b         1 │ 2 │ 3 │ 4 │ 5
 *          ┌───┬───┬───┐ ┌───┬───┬───┐
 *          │Esc│Sft│Ctl│ │Spc│Ent│Alt│
 *          └───┴───┴───┘ └───┴───┴───┘
 *            *                     *
 */
#    define _GL1_5_ _QL1_5_
#    define _GL2_5_ _QL2_5_
#    define _GL3_5_ _QL3_5_
#    define _GR1_5_ KC_6, KC_7, KC_8, KC_9, KC_0
#    define _GR2_5_ KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TAB
#    define _GR3_5_ KC_1, KC_2, KC_3, KC_4, KC_5
//
#    define _GL1_6_ KC_NO, _GL1_5_
#    define _GL2_6_ KC_NO, _GL2_5_
#    define _GL3_6_ KC_NO, _GL3_5_
#    define _GR1_6_ _GR1_5_, KC_NO
#    define _GR2_6_ _GR2_5_, KC_NO
#    define _GR3_6_ _GR3_5_, KC_NO
//
#    define _GL4_2_ KC_LSFT, KC_LCTL
#    define _GL4_3_ KC_ESC, _GL4_2_
#    define _GR4_2_ KC_SPC, KC_ENT
#    define _GR4_3_ _GR4_2_, KC_LALT
#endif // GAME_ENABLE

/* Symbols layer */
#define _SL1_5_ DE_AT, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC
#define _SL2_5_ DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR
#define _SL3_5_ DE_HASH, DE_DLR, DE_PIPE, DE_TILD, DE_ACUT
#define _SR1_5_ DE_EXLM, DE_LABK, DE_RABK, DE_EQL, DE_AMPR
#define _SR2_5_ DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN
#define _SR3_5_ DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN
//
#define _SL1_6_ _ADD_L_1_, _SL1_5_
#define _SL2_6_ _ADD_L_2_, _SL2_5_
#define _SL3_6_ _ADD_L_3_, _SL3_5_
#define _SR1_6_ _SR1_5_, _ADD_R_1_
#define _SR2_6_ _SR2_5_, DE_SECT
#define _SR3_6_ _SR3_5_, _ADD_R_3_
//
#ifdef DYNAMIC_TAPPING_TERM_ENABLE
#    define _SL4_2_ DE_SECT, DT_DOWN
#    define _SL4_3_ DT_PRNT, _SL4_2_
#    define _SR4_2_ DT_UP, SFT_SPC
#else
#    define _SL4_2_ DE_SECT, G(DE_CIRC)
#    define _SL4_3_ DE_DEG, _SL4_2_
#    define _SR4_2_ KC_RALT, SFT_SPC
#endif // DYNAMIC_TAPPING_TERM_ENABLE
#define _SR4_3_ _SR4_2_, CW_TOGG
//
#define _SYMBL_3x5_ _SL1_5_, _SR1_5_, _SL2_5_, _SR2_5_, _SL3_5_, _SR3_5_
#define _SYMBL_3x6_ _SL1_6_, _SR1_6_, _SL2_6_, _SR2_6_, _SL3_6_, _SR3_6_

/* Lower: Numbers and function keys */
#define _LL1_5_ KC_F1, KC_F2, KC_F3, KC_F4, DE_PND
#define _LL2_5_ KC_F5, KC_F6, KC_F7, KC_F8, DE_EURO
#define _LL3_5_ KC_F9, KC_F10, KC_F11, KC_F12, DE_CENT
#define _LR1_5_ DE_SLSH, DE_7, DE_8, DE_9, DE_MINS
#define _LR2_5_ DE_PLUS, DE_4, DE_5, DE_6, DE_DOT
#define _LR3_5_ DE_0, DE_1, DE_2, DE_3, DE_COMM
//
#define _LL1_6_ _ADD_L_1_, _LL1_5_
#define _LL2_6_ _ADD_L_2_, _LL2_5_
#define _LL3_6_ _ADD_L_3_, _LL3_5_
#define _LR1_6_ _LR1_5_, _ADD_R_1_
#define _LR2_6_ _LR2_5_, _ADD_R_2_
#define _LR3_6_ _LR3_5_, _ADD_R_3_
//
#define _LL4_2_ KC_LSFT, KC_TRNS
#define _LL4_3_ DE_YEN, _LL4_2_
#define _LR4_2_ ATT(KC_BSPC), SFT_SPC
#define _LR4_3_ _LR4_2_, DE_DLR
//
#define _LOWER_3x5_ _LL1_5_, _LR1_5_, _LL2_5_, _LR2_5_, _LL3_5_, _LR3_5_
#define _LOWER_3x6_ _LL1_6_, _LR1_6_, _LL2_6_, _LR2_6_, _LL3_6_, _LR3_6_

/* Raise: Control + Navigation layer */
#define _RL1_5_ KC_PGUP, KC_BSPC, KC_UP, KC_DEL, KC_PGDN
#define _RL2_5_ KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END
#define _RL3_5_ KC_UNDO, KC_CUT, KC_COPY, KC_PSTE, KC_AGAIN
#define _RR1_5_ KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_EJCT
#define _RR2_5_ OSM_MEH, OSM_CTL, OSM_SFT, OSM_ALT, OSM_GUI
#define _RR3_5_ KC_PSCR, KC_NO, KC_INSERT, OSM_AGR, CW_TOGG
//
#define _RL1_6_ _ADD_L_1_, _RL1_5_
#define _RL2_6_ _ADD_L_2_, _RL2_5_
#define _RL3_6_ _ADD_L_3_, _RL3_5_
#define _RR1_6_ _RR1_5_, _ADD_R_1_
#define _RR2_6_ _RR2_5_, _ADD_R_2_
#define _RR3_6_ _RR3_5_, _ADD_R_3_
//
#define _RL4_2_ LSFT_T(KC_VOLD), ATT(KC_MUTE)
#define _RL4_3_ KC_MPRV, _RL4_2_
#define _RR4_2_ KC_TRNS, RSFT_T(KC_VOLU)
#define _RR4_3_ _RR4_2_, KC_MNXT
//
#define _RAISE_3x5_ _RL1_5_, _RR1_5_, _RL2_5_, _RR2_5_, _RL3_5_, _RR3_5_
#define _RAISE_3x6_ _RL1_6_, _RR1_6_, _RL2_6_, _RR2_6_, _RL3_6_, _RR3_6_

#ifdef MOUSEKEY_ENABLE
/* Pointer layer */
#    define _PL1_5_ KC_WH_D, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U
#    define _PL2_5_ KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5
#    define _PL3_5_ S_C_TAB, KC_CUT, KC_COPY, KC_PSTE, XXXXXXX
#    define _PR1_5_ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#    define _PR2_5_ OSM_MEH, OSM_CTL, OSM_SFT, OSM_ALT, OSM_GUI
#    define _PR3_5_ KC_ACL0, KC_ACL1, KC_ACL2, OSM_AGR, C___TAB
//
#    define _PL1_6_ _ADD_L_1_, _PL1_5_
#    define _PL2_6_ _ADD_L_2_, _PL2_5_
#    define _PL3_6_ _ADD_L_3_, _PL3_5_
#    define _PR1_6_ _PR1_5_, _ADD_R_1_
#    define _PR2_6_ _PR2_5_, _ADD_R_2_
#    define _PR3_6_ _PR3_5_, _ADD_R_3_
//
#    define _PL4_2_ KC_BTN1, KC_BTN2
#    define _PL4_3_ XXXXXXX, _PL4_2_
#    define _PR4_2_ KC_BTN3, KC_BTN1
#    define _PR4_3_ _PR4_2_, XXXXXXX
//
#    define _POINT_3x5_ _PL1_5_, _PR1_5_, _PL2_5_, _PR2_5_, _PL3_5_, _PR3_5_
#    define _POINT_3x6_ _PL1_6_, _PR1_6_, _PL2_6_, _PR2_6_, _PL3_6_, _PR3_6_
#endif // MOUSEKEY_ENABLE

/* Attic: Adjustments and missing stuff */
#define _AL1_5_ QK_BOOT, EE_CLR, DL_ASET, DL_ARTS, KC_APP
#define _AL2_5_ DL_GAME, DL_PREV, DL_NEXT, DL_QWER, NO_MODS
#define _AL3_5_ RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD
#define _AR1_5_ DE_IEXL, DE_LSAQ, DE_LDAQ, DE_RDAQ, DE_RSAQ
#define _AR2_5_ DE_IQUE, DE_MDOT, DE_SLQU, DE_LSQU, DE_RSQU
#define _AR3_5_ DE_NDSH, DE_MDSH, DE_DLQU, DE_LDQU, DE_RDQU
//
#define _AL1_6_ QK_BOOT, _AL1_5_
#define _AL2_6_ KC_NO, _AL2_5_
#define _AL3_6_ EE_CLR, _AL3_5_
#define _AR1_6_ _AR1_5_, QK_BOOT
#define _AR2_6_ _AR2_5_, DE_ELLP
#define _AR3_6_ _AR3_5_, EE_CLR
//
#define _AL4_2_ LSFT_T(KC_BRID), KC_TRNS
#define _AL4_3_ KC_LSFT, _AL4_2_
#define _AR4_2_ KC_TRNS, RSFT_T(KC_BRIU)
#define _AR4_3_ _AR4_2_, KC_NO
//
#define _ATTIC_3x5_ _AL1_5_, _AR1_5_, _AL2_5_, _AR2_5_, _AL3_5_, _AR3_5_
#define _ATTIC_3x6_ _AL1_6_, _AR1_6_, _AL2_6_, _AR2_6_, _AL3_6_, _AR3_6_
