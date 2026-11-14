#pragma once

#ifdef COMBO_ENABLE
#    ifndef QWERTY_DISABLED
#        define COMBO_COUNT 6
#    else
#        define COMBO_COUNT 4
#    endif // QWERTY_DISABLED
#endif     // COMBO_ENABLE

#include QMK_KEYBOARD_H
#include "keymap_german_extended.h"

#define MC_NXTW G(DE_CIRC) // MAC: next window
enum custom_keycodes { LY_TOGG = SAFE_RANGE, TC_MDOT, TS_SRQU, TA_LSQU, TG_RSQU, SZ_COMBO };
enum custom_layers {
    _NOTED = 0,
#ifndef QWERTY_DISABLED
    _QWERT,
#endif
    _SYMB,
    _NAVI,
    _NUMS
#ifdef POINTING_DEVICE_ENABLE
    ,
    _PNTR
#endif // POINTING_DEVICE_ENABLE
};

#ifdef POINTING_DEVICE_ENABLE
#    define PTR(kc) LT(_PNTR, kc)
#else
#    define PTR(kc) kc
#endif // POINTING_DEVICE_ENABLE
#ifdef COMBO_ENABLE
#    define _BASE_CENTER_(kc) LT(_SYMB, kc)
#else
#    define _BASE_CENTER_(kc) kc
#endif

#define KC_2NO KC_NO, KC_NO
#define _BASE_L_TOP_ LALT_T(KC_BSPC)
#define _BASE_L_MID_ LT(_SYMB, KC_ESC)
#define _BASE_L_BOT_ KC_LSFT
#define _BASE_R_TOP_(kc) LALT_T(kc)
#define _BASE_R_MID_(kc) LT(_SYMB, kc)
#define _BASE_R_BOT_ RCTL_T(KC_APP)

// ==================================================================================
// DIE BASIS-EBENEN (3x5/6 ANORDNUNG)
// ==================================================================================

/* --- NOTED LAYER --- */
#define NOTED_L_TOP DE_Z, DE_Y, DE_U, DE_A, DE_Q
#define NOTED_L_MID LGUI_T(DE_C), LALT_T(DE_S), LSFT_T(DE_I), LCTL_T(DE_E), _BASE_CENTER_(DE_O)
#define NOTED_L_BOT PTR(DE_V), DE_X, DE_UDIA, DE_ADIA, DE_ODIA
#define NOTED_R_TOP DE_P, DE_B, DE_M, DE_L, DE_F
#define NOTED_R_MID _BASE_CENTER_(DE_D), RCTL_T(DE_T), RSFT_T(DE_N), LALT_T(DE_R), RGUI_T(DE_H)
#define NOTED_R_BOT DE_W, DE_G, DE_COMM, DE_DOT, PTR(DE_K)
#define NOTED_L6_TOP _BASE_L_TOP_, NOTED_L_TOP
#define NOTED_L6_MID _BASE_L_MID_, NOTED_L_MID
#define NOTED_L6_BOT _BASE_L_BOT_, NOTED_L_BOT
#define NOTED_R6_TOP NOTED_R_TOP, _BASE_R_TOP_(DE_J)
#define NOTED_R6_MID NOTED_R_MID, _BASE_R_MID_(DE_SS)
#define NOTED_R6_BOT NOTED_R_BOT, _BASE_R_BOT_

#ifndef QWERTY_DISABLED
/* --- QWERT LAYER --- */
#    define QWERT_L_TOP DE_Q, DE_W, DE_E, DE_R, DE_T
#    define QWERT_L_MID LGUI_T(DE_A), LALT_T(DE_S), LSFT_T(DE_D), LCTL_T(DE_F), _BASE_CENTER_(DE_G)
#    define QWERT_L_BOT PTR(DE_Y), DE_X, DE_C, DE_V, DE_B
#    define QWERT_R_TOP DE_Z, DE_U, DE_I, DE_O, DE_P
#    define QWERT_R_MID _BASE_CENTER_(DE_H), RCTL_T(DE_J), RSFT_T(DE_K), LALT_T(DE_L), RGUI_T(DE_ODIA)
#    define QWERT_R_BOT DE_N, DE_M, DE_COMM, DE_DOT, PTR(DE_SS)
#    define QWERT_L6_TOP _BASE_L_TOP_, QWERT_L_TOP
#    define QWERT_L6_MID _BASE_L_MID_, QWERT_L_MID
#    define QWERT_L6_BOT _BASE_L_BOT_, QWERT_L_BOT
#    define QWERT_R6_TOP QWERT_R_TOP, _BASE_R_TOP_(DE_UDIA)
#    define QWERT_R6_MID QWERT_R_MID, _BASE_R_MID_(DE_ADIA)
#    define QWERT_R6_BOT QWERT_R_BOT, _BASE_R_BOT_
#endif

// ==================================================================================
// DIE GLOBALEN DAUMEN-BAUSTEINE
// ==================================================================================
#define BASE_L3_TMB LT(_NAVI, KC_ESC), LGUI_T(KC_ENT), LT(_NUMS, KC_TAB)
#define BASE_RI_TMB KC_SPC, LT(_NAVI, KC_BSPC)
#define BASE_R2_TMB LT(_NAVI, KC_BSPC), KC_SPC
#define BASE_RA_TMB LT(_NUMS, KC_DEL)
#define BASE_R3_TMB BASE_R2_TMB, BASE_RA_TMB

// ==================================================================================
// ZUSÄTZLICHE EBENEN
// ==================================================================================
#define _ADD_L_TOP KC_BSPC
#define _ADD_L_MID KC_ESC
#define _ADD_L_BOT KC_LSFT

/* --- SYMBOL LAYER --- */
#define SYMB_L_TOP DE_ELLP, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC
#define SYMB_L_MID DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR
#define SYMB_L_BOT DE_HASH, DE_DLR, DE_PIPE, DE_TILD, DE_GRV
#define SYMB_R_TOP DE_EXLM, DE_LABK, DE_RABK, DE_EQL, DE_AMPR
#define SYMB_R_MID DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN
#define SYMB_R_BOT DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN
#define SYMB_L6_TOP _ADD_L_TOP, SYMB_L_TOP
#define SYMB_L6_MID _ADD_L_MID, SYMB_L_MID
#define SYMB_L6_BOT _ADD_L_BOT, SYMB_L_BOT
#define SYMB_R6_TOP SYMB_R_TOP, DE_SLNG
#define SYMB_R6_MID SYMB_R_MID, DE_AT
#define SYMB_R6_BOT SYMB_R_BOT, DE_SECT
// Thumbs
#define SYMB_L3_TMB KC_ESC, KC_ENT, MC_NXTW
#define SYMB_RI_TMB KC_SPC, DE_AT
#define SYMB_R2_TMB DE_AT, KC_SPC
#define SYMB_RA_TMB DE_SECT
#define SYMB_R3_TMB SYMB_R2_TMB, SYMB_RA_TMB

/* --- NAVIGATION LAYER --- */
#define NAVI_L_TOP KC_PGUP, KC_BSPC, KC_UP, KC_DEL, KC_PGDN
#define NAVI_L_MID KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END
#define NAVI_L_BOT KC_CAPS, KC_INS, CW_TOGG, KC_APP, KC_PSCR
#define NAVI_R_TOP DE_LDAQ, DE_LSAQ, DE_RSAQ, DE_RDAQ, DE_ACUT
#define NAVI_R_MID DE_DEG, TC_MDOT, TS_SRQU, TA_LSQU, TG_RSQU
#define NAVI_R_BOT DE_NDSH, DE_MDSH, DE_DLQU, DE_LDQU, DE_RDQU
#define NAVI_L6_TOP _ADD_L_TOP, NAVI_L_TOP
#define NAVI_L6_MID _ADD_L_MID, NAVI_L_MID
#define NAVI_L6_BOT _ADD_L_BOT, NAVI_L_BOT
#define NAVI_R6_TOP NAVI_R_TOP, KC_MNXT
#define NAVI_R6_MID NAVI_R_MID, KC_MPLY
#define NAVI_R6_BOT NAVI_R_BOT, KC_MPRV
// Thumbs
#define NAVI_L3_TMB TG(_NAVI), KC_ENT, TG(_NUMS)
#define NAVI_RI_TMB OS_RALT, LY_TOGG
#define NAVI_R2_TMB LY_TOGG, OS_RALT
#define NAVI_RA_TMB DE_SLNG
#define NAVI_R3_TMB NAVI_R2_TMB, NAVI_RA_TMB

/* --- NUMBERS LAYER --- */
#define NUMS_L_TOP KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define NUMS_L_MID LGUI_T(KC_F6), LALT_T(KC_F7), LSFT_T(KC_F8), LCTL_T(KC_F9), KC_F10
#define NUMS_L_BOT KC_F11, KC_F12, KC_F13, KC_F14, KC_F15
#define NUMS_R_TOP DE_ASTR, DE_7, DE_8, DE_9, DE_SLSH
#define NUMS_R_MID DE_PLUS, RCTL_T(DE_4), RSFT_T(DE_5), LALT_T(DE_6), RGUI_T(DE_MINS)
#define NUMS_R_BOT DE_COLN, DE_1, DE_2, DE_3, DE_SCLN
#define NUMS_L6_TOP _ADD_L_TOP, NUMS_L_TOP
#define NUMS_L6_MID _ADD_L_MID, NUMS_L_MID
#define NUMS_L6_BOT _ADD_L_BOT, NUMS_L_BOT
#define NUMS_R6_TOP NUMS_R_TOP, DE_PND
#define NUMS_R6_MID NUMS_R_MID, DE_EURO
#define NUMS_R6_BOT NUMS_R_BOT, DE_CENT
// Thumbs
#define NUMS_L3_TMB TG(_NAVI), KC_ENT, TG(_NUMS)
#define NUMS_RI_TMB DE_0, DE_DOT
#define NUMS_R2_TMB DE_DOT, DE_0
#define NUMS_RA_TMB DE_COMM
#define NUMS_R3_TMB NUMS_RA_TMB, NUMS_R2_TMB

#ifdef COMBO_ENABLE
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record);
#endif

#ifdef OLED_ENABLE
bool            oled_task_user(void);
oled_rotation_t oled_init_user(oled_rotation_t rotation);
#endif
