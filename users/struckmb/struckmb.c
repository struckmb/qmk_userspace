#include "struckmb.h"

#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case DE_ADIA:
        case DE_ODIA:
        case DE_UDIA:
        case DE_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case DE_UNDS:
        case DE_SS:
            return true;
        default:
            return false;
    }
}
#endif

#ifdef COMBO_ENABLE
// --- GLOBALE SYSTEM COMBOS ---
#    ifdef LAST_COL_COMBOS
// --- NOTED LAYER COMBOS ---
const uint16_t PROGMEM j_noted_combo[]  = {DE_L, DE_F, COMBO_END};
const uint16_t PROGMEM sz_noted_combo[] = {LALT_T(DE_R), RGUI_T(DE_H), COMBO_END};

// --- QWERT LAYER COMBOS ---
const uint16_t PROGMEM ue_qwertz_combo[] = {DE_O, DE_P, COMBO_END};
const uint16_t PROGMEM ae_qwertz_combo[] = {LALT_T(DE_L), RGUI_T(DE_ODIA), COMBO_END};
#    endif // LAST_COL_COMBOS
const uint16_t PROGMEM thumb_combo[] = {LT(_NAVI, KC_ESC), LT(_NAVI, KC_TAB), COMBO_END};

// Combo-Verzeichnis registrieren (Index 0 bis 4)
combo_t key_combos[COMBO_COUNT] = {
#    ifdef LAST_COL_COMBOS
    COMBO(j_noted_combo, DE_J),      // Index 0
    COMBO(sz_noted_combo, DE_SS),    // Index 1
    COMBO(ue_qwertz_combo, DE_UDIA), // Index 2
    COMBO(ae_qwertz_combo, DE_ADIA), // Index 3
#    endif                           // LAST_COL_COMBOS
    COMBO(thumb_combo, OSL(_FUNC))};

#    ifdef LAST_COL_COMBOS
// Intelligenter Filter: Schränkt Combos strikt auf ihre jeweiligen Base-Layer ein
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    uint8_t current_base = get_highest_layer(default_layer_state);
    if (combo_index < 2) return (current_base == _NOTED);
    return combo_index > 3 || current_base == _QWERT;
}
#    endif // LAST_COL_COMBOS
#endif     // COMBO_ENABLE

#ifdef OLED_ENABLE
// Globale Variablen für Animationen im OLED-Scope
static uint32_t bongo_timer      = 0;
static bool     is_bongo_tapping = false;

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        is_bongo_tapping = true;
        bongo_timer      = timer_read32();
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
#    ifdef OLED_LAYOUT_VERTICAL
    return is_keyboard_left() ? OLED_ROTATION_270 : OLED_ROTATION_90;
#    else
    return is_keyboard_master() ? OLED_ROTATION_0 : OLED_ROTATION_180;
#    endif
}

bool oled_task_user(void) {
    uint8_t default_layer = get_highest_layer(default_layer_state);
    uint8_t layer         = get_highest_layer(layer_state);
    uint8_t mods          = get_mods();
    bool    caps_lock     = host_keyboard_led_state().caps_lock;
    bool    caps_active =
#    ifdef CAPS_WORD_ENABLE
        is_caps_word_on() ||
#    endif
        caps_lock;

#    ifdef OLED_LAYOUT_VERTICAL
    if (is_keyboard_master()) {
        oled_write_ln_P(PSTR("\n========="), false);
        oled_write_ln_P(PSTR("   QMK   "), false);
        oled_write_ln_P(PSTR("=========\n"), false);

        oled_write_ln_P(PSTR("  BASE   "), true);
        oled_write_ln_P(default_layer == _QWERT ? PSTR(" QWERT") : PSTR(" NOTED "), false);

        switch (layer) {
            case _SYMB:
                oled_write_ln_P(PSTR("  > Symb\n"), false);
                break;
            case _NAVI:
                oled_write_ln_P(PSTR("  > Navi\n"), false);
                break;
            case _FUNC:
                oled_write_ln_P(PSTR("  > Func\n"), false);
                break;
#        ifdef POINTING_DEVICE_ENABLE
            case _PNTR:
                oled_write_ln_P(PSTR(" > Point\n"), false);
                break;
#        endif // POINTING_DEVICE_ENABLE
            default:
                oled_write_ln_P(PSTR("        \n"), false);
                break;
        }

        oled_write_ln_P(PSTR(" [MODS]  "), true);
        oled_write_ln_P(mods & MOD_MASK_CTRL ? PSTR(" *CTRL") : PSTR("  ctrl"), false);
        oled_write_ln_P(caps_lock ? PSTR("*CAPSLCK*") : caps_active || (mods & MOD_MASK_SHIFT) ? PSTR(" *SHIFT  ") : PSTR("  shift  "), caps_active);
        oled_write_ln_P(mods & MOD_MASK_ALT ? PSTR(" *ALT") : PSTR("  alt"), false);
        oled_write_ln_P(mods & MOD_MASK_GUI ? PSTR(" *GUI") : PSTR("  gui"), false);

    } else {
        for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
            if (matrix_get_row(i) > 0) {
                is_bongo_tapping = true;
                bongo_timer      = timer_read32();
                break;
            }
        }

        if (is_bongo_tapping && timer_elapsed32(bongo_timer) > 350) {
            is_bongo_tapping = false;
        }

        oled_set_cursor(0, 0);

        oled_write_ln_P(PSTR("\n  -------"), false);
        oled_write_ln_P(PSTR("   BONGO"), false);
        oled_write_ln_P(PSTR("    CAT"), false);
        oled_write_ln_P(PSTR("  -------"), false);
        oled_write_ln_P(PSTR(""), false);
        oled_write_ln_P(PSTR("  /\\___/\\\n  (=o.o=)"), false);

        if (is_bongo_tapping) {
            if ((timer_read32() % 200) > 100) {
                oled_write_ln_P(PSTR("  ( - / )\n   m   _/"), false);
            } else {
                oled_write_ln_P(PSTR("  ( \\ - )\n   \\_  m"), false);
            }
        } else {
            oled_write_ln_P(PSTR("  ( / \\ )\n   \\_ _/"), false);
        }

        oled_write_ln_P(PSTR("  [=====]\n  [=====]\n   U   U"), false);
    }
#    else // OLED_LAYOUT_VERTICAL
    if (is_keyboard_master()) {
        oled_write_ln_P(PSTR("== QMK KEYBOARD =="), false);

        oled_write_P(PSTR("Base:   "), false);
        oled_write_ln_P(default_layer == _QWERT ? PSTR("QWERT Layout") : PSTR("Noted Layout"), false);

        oled_write_P(PSTR("  └> "), false);
        switch (layer) {
            case _SYMB:
                oled_write_ln_P(PSTR("Symbols   "), false);
                break;
            case _NAVI:
                oled_write_ln_P(PSTR("Navigation"), false);
                break;
            case _FUNC:
                oled_write_ln_P(PSTR("Function  "), false);
                break;
#        ifdef POINTING_DEVICE_ENABLE
            case _PNTR:
                oled_write_ln_P(PSTR("Pointer   "), false);
                break;
#        endif // POINTING_DEVICE_ENABLE
            default:
                oled_write_ln_P(PSTR("None      "), false);
                break;
        }

        oled_write_P(PSTR("Mods: "), false);
        if (mods & MOD_MASK_CTRL) oled_write_P(PSTR(" CTL"), false);
        if (mods & MOD_MASK_SHIFT) oled_write_P(PSTR(" SFT"), false);
        if (mods & MOD_MASK_ALT) oled_write_P(PSTR(" ALT"), false);
        if (mods & MOD_MASK_GUI) oled_write_P(PSTR(" GUI"), false);
        if (!mods) oled_write_P(PSTR(" N/A"), false);
        if (caps_active) {
            oled_write_ln_P(caps_lock ? PSTR("     [CapsLOCK]     ") : PSTR("     [CapsWord]     "), true);
        } else {
            oled_write_ln_P(PSTR(""), false);
        }

    } else {
        extern const char bongo_cat_tap[];
        extern const char bongo_cat_idle[];

        if (is_bongo_tapping) {
            if (timer_elapsed32(bongo_timer) > 350) {
                is_bongo_tapping = false;
                oled_write_raw_P(bongo_cat_idle, 256);
            } else {
                oled_write_raw_P(bongo_cat_tap, 256);
            }
        } else {
            oled_write_raw_P(bongo_cat_idle, 256);
        }
    }
#    endif     // OLED_LAYOUT_VERTICAL
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LY_TOGG:
            if (record->event.pressed) {
                uint8_t current_default = get_highest_layer(default_layer_state);
                if (current_default == _QWERT) {
                    set_single_persistent_default_layer(_NOTED);
                } else {
                    set_single_persistent_default_layer(_QWERT);
                }
            }
            return false;

        default:
            return true;
    }
}
