#pragma once

#define COMBO_COUNT 3

#include QMK_KEYBOARD_H
#include "keymap_german_extended.h"

#define TB_NEXT LCTL(KC_TAB)       // CTRL + TAB
#define TB_PREV LCTL(LSFT(KC_TAB)) // CTRL + SHIFT + TAB
#define UT_UNDO LCTL(DE_Z)         // CTRL + Z (Undo)
#define UT_REDO LCTL(LSFT(DE_Z))   // CTRL + SHIFT + Z (Redo)

enum custom_layers { _BASE = 0, _SYMB, _NAVI, _FUNC };

// ==================================================================================
// DIE FINALEN LEGO-BAUSTEINE
// ==================================================================================

/* --- BASE LAYER ---
 * Links:                      Rechts:
 * Z   Y   U   A   Q           P   B   M   L   F
 * C¹  S²  I³  E⁴  O⁵          D⁵  T⁴  N³  R²  H¹   [¹=GUI, ²=ALT, ³=SHIFT, ⁴=CTRL, ⁵=Layer-Hold]
 * V   X   Ü   Ä   Ö           W   G   ,   .   K
 *
 * Daumen Links:               Daumen Rechts:
 * NAVI/ESC  ENTER             SPACE  NAVI/TAB
 */
#define BASE_L_TOP DE_Z, DE_Y, DE_U, DE_A, DE_Q
#define BASE_R_TOP DE_P, DE_B, DE_M, DE_L, DE_F
#define BASE_L_MID LGUI_T(DE_C), LALT_T(DE_S), LSFT_T(DE_I), LCTL_T(DE_E), LT(_SYMB, DE_O)
#define BASE_R_MID LT(_SYMB, DE_D), RCTL_T(DE_T), RSFT_T(DE_N), LALT_T(DE_R), RGUI_T(DE_H)
#define BASE_L_BOT DE_V, DE_X, DE_UDIA, DE_ADIA, DE_ODIA
#define BASE_R_BOT DE_W, DE_G, DE_COMM, DE_DOT, DE_K
#define BASE_L_THUMBS LT(_NAVI, KC_ESC), KC_ENT
#define BASE_R_THUMBS KC_SPC, LT(_NAVI, KC_TAB)
#define EMPTY__THUMBS KC_TRNS, KC_TRNS

/* --- SYMBOL LAYER (Neo2 Ebene 3) ---
 * Links:                      Rechts:
 * …   _   [   ]   ^           !   <   >   =   &
 * \   /   {   }   *           ?   (   )   -   :
 * #   $   |   ~   `           +   %   "   '   ;
 *
 * Daumen Links:               Daumen Rechts:
 * TRNS  ſ                     @   TRNS
 */
#define SYMB_L_TOP DE_ELLP, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC
#define SYMB_R_TOP DE_EXLM, DE_LABK, DE_RABK, DE_EQL, DE_AMPR
#define SYMB_L_MID DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR
#define SYMB_R_MID DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN
#define SYMB_L_BOT DE_HASH, DE_DLR, DE_PIPE, DE_TILD, DE_GRV
#define SYMB_R_BOT DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN
#define SYMB_L_THUMBS KC_TRNS, DE_SLNG
#define SYMB_R_THUMBS DE_AT, KC_TRNS

/* --- NAVIGATION LAYER (Numpad) ---
 * Links:                      Rechts:
 * PGUP  BSPC  UP    DEL   PGDN        -   7   8   9   /
 * HOME  LEFT  DOWN  RGHT  END         +   4   5   6   *
 * REDO CS+Tab CAPS  C+Tab UNDO        :   1   2   3   =
 *
 * Daumen Links:               Daumen Rechts:
 * TRNS  TRNS                  0   TG(NAVI)
 */
#define NAVI_L_TOP KC_PGUP, KC_BSPC, KC_UP, KC_DEL, KC_PGDN
#define NAVI_R_TOP DE_MINS, DE_7, DE_8, DE_9, DE_SLSH
#define NAVI_L_MID KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END
#define NAVI_R_MID DE_PLUS, DE_4, DE_5, DE_6, DE_ASTR
#define NAVI_L_BOT UT_REDO, TB_PREV, CW_TOGG, TB_NEXT, UT_UNDO
#define NAVI_R_BOT DE_COLN, DE_1, DE_2, DE_3, DE_EQL
#define NAVI_L_THUMBS EMPTY__THUMBS
#define NAVI_R_THUMBS DE_0, TG(_NAVI)

/* --- FUNCTION LAYER ---
 * Links:                      Rechts:
 * F1    F2    F3    F4    INS         «     ‹     ›     »     ´
 * F5    F6    F7    F8    MENU        °     ·     ‚     ‘     '
 * F9    F10   F11   F12   PSCR        –     —     „     “     ”
 *
 * Daumen Links:               Daumen Rechts:
 * TRNS  TRNS                  TRNS  TG(NAVI)
 */
#define FUNC_L_TOP KC_F1, KC_F2, KC_F3, KC_F4, KC_INS
#define FUNC_R_TOP DE_LDAQ, DE_LSAQ, DE_RSAQ, DE_RDAQ, DE_ACUT
#define FUNC_L_MID KC_F5, KC_F6, KC_F7, KC_F8, KC_MENU
#define FUNC_R_MID DE_DEG, DE_MDOT, DE_SLQU, DE_LSQU, DE_RSQU
#define FUNC_L_BOT KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR
#define FUNC_R_BOT DE_NDSH, DE_MDSH, DE_DLQU, DE_LDQU, DE_RDQU
#define FUNC_L_THUMBS KC_TRNS, KC_TRNS
#define FUNC_R_THUMBS KC_TRNS, TG(_NAVI)
