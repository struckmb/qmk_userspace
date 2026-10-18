#pragma once

#define COMBO_COUNT 6
#include QMK_KEYBOARD_H
#include "keymap_german.h" // ZWINGEND: Ermöglicht die Nutzung von DE_ Keycodes

enum custom_layers { _BASE = 0, _SYMB, _NAVI };
enum custom_keycodes { MAC_GT = SAFE_RANGE, MAC_AST, MAC_CST, MAC_CT, MAC_AT };

// ==================================================================================
// DIE FINALEN LEGO-BAUSTEINE (Angepasst für deutsches OS-Layout)
// ==================================================================================

// --- BASE LAYER BAUSTEINE ---
// Physisches Z sendet DE_Y, physisches Y sendet DE_Z wegen der DE-Vertauschung
#define BASE_L_TOP DE_Z, DE_Y, KC_U, KC_A, KC_Q
#define BASE_R_TOP KC_P, KC_B, KC_M, DE_L, DE_F
#define BASE_L_MID LT(_SYMB, KC_C), KC_S, KC_I, KC_E, KC_O
#define BASE_R_MID KC_D, KC_T, KC_N, KC_R, LT(_SYMB, KC_H)
#define BASE_L_BOT KC_V, KC_X, DE_UDIA, DE_ADIA, DE_ODIA
#define BASE_R_BOT KC_W, KC_G, DE_COMM, DE_DOT, DE_K

// Reines ENTER links innen | Hold-Tap für NAV/ESCAPE rechts außen
#define BASE_L_THUMBS LT(_NAVI, KC_TAB), KC_ENT
#define BASE_R_THUMBS KC_SPC, LT(_NAVI, KC_ESC)
#define EMPTY__THUMBS KC_TRNS, KC_TRNS

// --- SYMBOL LAYER BAUSTEINE ---
#define SYMB_L_TOP DE_BSLS, DE_LBRC, DE_LCBR, DE_RCBR, DE_RBRC
#define SYMB_R_TOP DE_ASTR, DE_7, DE_8, DE_9, DE_SLSH
#define SYMB_L_MID DE_EQL, DE_QUES, DE_LPRN, DE_RPRN, DE_TILD
#define SYMB_R_MID DE_PLUS, DE_4, DE_5, DE_6, DE_MINS
#define SYMB_L_BOT DE_UNDS, DE_PIPE, DE_LABK, DE_RABK, DE_DLR
#define SYMB_R_BOT DE_DOT, DE_1, DE_2, DE_3, DE_COMM
#define SYMB_L_THUMBS EMPTY__THUMBS
#define SYMB_R_THUMBS DE_0, KC_TRNS

// --- NAVIGATION LAYER BAUSTEINE ---
#define NAVI_L_TOP KC_PGUP, KC_BSPC, KC_UP, KC_DEL, KC_PGDN
#define NAVI_R_TOP KC_INS, KC_F7, KC_F8, KC_F9, KC_F10
#define NAVI_L_MID KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END
#define NAVI_R_MID KC_MENU, KC_F4, KC_F5, KC_F6, KC_F11
#define NAVI_L_BOT MAC_GT, MAC_AST, MAC_CST, MAC_CT, MAC_AT
#define NAVI_R_BOT KC_PSCR, KC_F1, KC_F2, KC_F3, KC_F12
