#pragma once

#define COMBO_COUNT 5

#include QMK_KEYBOARD_H
#include "keymap_german_extended.h"

enum custom_layers { _NOTED = 0, _QWERTZ, _SYMB, _NAVI, _FUNC };
enum custom_keycodes { LY_TOGG = SAFE_RANGE };

// ==================================================================================
// DIE GLOBALEN DAUMEN-BAUSTEINE
// ==================================================================================
#define EMPTY__THUMBS KC_TRNS, KC_TRNS
#define BASE_L_THUMBS LT(_NAVI, KC_ESC), LGUI_T(KC_ENT)
#define BASE_ML_THUMB LT(_NAVI, KC_TAB)
#define BASE_R_THUMBS KC_SPC, LT(_NAVI, KC_TAB)

// ==================================================================================
// DIE TASTEN-ZEILEN (3x5 ANORDNUNG)
// ==================================================================================

/* --- NOTED LAYER --- */
#define NOTED_L_TOP DE_Z, DE_Y, DE_U, DE_A, DE_Q
#define NOTED_L_MID LGUI_T(DE_C), LALT_T(DE_S), LSFT_T(DE_I), LCTL_T(DE_E), LT(_SYMB, DE_O)
#define NOTED_L_BOT DE_V, DE_X, DE_UDIA, DE_ADIA, DE_ODIA
#define NOTED_R_TOP DE_P, DE_B, DE_M, DE_L, DE_F
#define NOTED_R_MID LT(_SYMB, DE_D), RCTL_T(DE_T), RSFT_T(DE_N), LALT_T(DE_R), RGUI_T(DE_H)
#define NOTED_R_BOT DE_W, DE_G, DE_COMM, DE_DOT, DE_K

/* --- QWERTZ LAYER --- */
#define QWERTZ_L_TOP DE_Q, DE_W, DE_E, DE_R, DE_T
#define QWERTZ_L_MID LGUI_T(DE_A), LALT_T(DE_S), LSFT_T(DE_D), LCTL_T(DE_F), LT(_SYMB, DE_G)
#define QWERTZ_L_BOT DE_Y, DE_X, DE_C, DE_V, DE_B
#define QWERTZ_R_TOP DE_Z, DE_U, DE_I, DE_O, DE_P
#define QWERTZ_R_MID LT(_SYMB, DE_H), RCTL_T(DE_J), RSFT_T(DE_K), LALT_T(DE_L), RGUI_T(DE_ODIA)
#define QWERTZ_R_BOT DE_N, DE_M, DE_COMM, DE_DOT, DE_SS

/* --- SYMBOL LAYER --- */
#define SYMB_L_TOP DE_ELLP, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC
#define SYMB_L_MID DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR
#define SYMB_L_BOT DE_HASH, DE_DLR, DE_PIPE, DE_TILD, DE_GRV
#define SYMB_R_TOP DE_EXLM, DE_LABK, DE_RABK, DE_EQL, DE_AMPR
#define SYMB_R_MID DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN
#define SYMB_R_BOT DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN
#define SYMB_L_THUMBS KC_TRNS, KC_TRNS
#define SYMB_ML_THUMB G(DE_CIRC)
#define SYMB_R_THUMBS DE_AT, KC_RALT

/* --- NAVIGATION LAYER --- */
#define NAVI_L_TOP KC_PGUP, KC_BSPC, KC_UP, KC_DEL, KC_PGDN
#define NAVI_L_MID KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END
#define NAVI_L_BOT KC_CAPS, KC_INS, CW_TOGG, KC_MENU, KC_PSCR
#define NAVI_R_TOP DE_MINS, DE_7, DE_8, DE_9, DE_SLSH
#define NAVI_R_MID DE_PLUS, RCTL_T(DE_4), RSFT_T(DE_5), LALT_T(DE_6), RGUI_T(DE_ASTR)
#define NAVI_R_BOT DE_COLN, DE_1, DE_2, DE_3, DE_SCLN
#define NAVI_L_THUMBS TG(_NAVI), DE_COMM
#define NAVI_R_THUMBS DE_0, DE_DOT

/* --- FUNCTION LAYER --- */
#define FUNC_L_TOP KC_F1, KC_F2, KC_F3, KC_F4, KC_TRNS
#define FUNC_L_MID KC_F5, KC_F6, KC_F7, KC_F8, KC_TRNS
#define FUNC_L_BOT KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS
#define FUNC_R_TOP DE_LDAQ, DE_LSAQ, DE_RSAQ, DE_RDAQ, DE_ACUT
#define FUNC_R_MID DE_DEG, DE_MDOT, DE_SLQU, DE_LSQU, DE_RSQU
#define FUNC_R_BOT DE_NDSH, DE_MDSH, DE_DLQU, DE_LDQU, DE_RDQU
#define FUNC_L_THUMBS TG(_NAVI), KC_TRNS
#define FUNC_R_THUMBS DE_SLNG, LY_TOGG

#ifdef COMBO_ENABLE
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record);
#endif

#ifdef OLED_ENABLE
bool            oled_task_user(void);
oled_rotation_t oled_init_user(oled_rotation_t rotation);
#endif
