#include "struckmb.h"

// #define CAPS_WORD_ENABLE
// #define COMBO_ENABLE
// #define KEYBOARD_draculad
// #define OLED_ENABLE
// #define OLED_LAYOUT_VERTICAL

typedef struct {
    uint16_t keycode;
    uint16_t tap_keycode;
    uint8_t  modifier;
    uint8_t  row;
    uint8_t  col;
    uint32_t pressed_at;
    bool     pressed;
    bool     holding;
} tap_hold_key_t;

static tap_hold_key_t navi_tap_hold_keys[] = {
    {TC_MDOT, DE_MDOT, MOD_BIT(KC_LCTL), 0, 0, 0, false, false},
    {TS_SRQU, DE_SLQU, MOD_BIT(KC_LSFT), 0, 0, 0, false, false},
    {TA_LSQU, DE_LSQU, MOD_BIT(KC_LALT), 0, 0, 0, false, false},
    {TG_RSQU, DE_RSQU, MOD_BIT(KC_LGUI), 0, 0, 0, false, false},
};

static void activate_tap_hold(tap_hold_key_t *key) {
    if (!key->holding) {
        key->holding = true;
        register_mods(key->modifier);
    }
}

static bool process_tap_hold_key(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        for (uint8_t i = 0; i < ARRAY_SIZE(navi_tap_hold_keys); i++) {
            tap_hold_key_t *key = &navi_tap_hold_keys[i];
            if (key->pressed && key->row == record->event.key.row && key->col == record->event.key.col) {
                if (key->holding) {
                    unregister_mods(key->modifier);
                } else {
                    tap_code16(key->tap_keycode);
                }
                key->pressed = false;
                key->holding = false;
                return false;
            }
        }
    }

    for (uint8_t i = 0; i < ARRAY_SIZE(navi_tap_hold_keys); i++) {
        tap_hold_key_t *key = &navi_tap_hold_keys[i];
        if (record->event.pressed && key->pressed && key->keycode != keycode) {
            activate_tap_hold(key);
        }
    }

    for (uint8_t i = 0; i < ARRAY_SIZE(navi_tap_hold_keys); i++) {
        tap_hold_key_t *key = &navi_tap_hold_keys[i];
        if (key->keycode != keycode) {
            continue;
        }

        if (record->event.pressed) {
            key->pressed_at = timer_read32();
            key->row        = record->event.key.row;
            key->col        = record->event.key.col;
            key->pressed    = true;
            key->holding    = false;
        }
        return false;
    }

    return true;
}

void matrix_scan_user(void) {
    for (uint8_t i = 0; i < ARRAY_SIZE(navi_tap_hold_keys); i++) {
        tap_hold_key_t *key = &navi_tap_hold_keys[i];
        if (key->pressed && !key->holding && timer_elapsed32(key->pressed_at) >= TAPPING_TERM) {
            activate_tap_hold(key);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_tap_hold_key(keycode, record)) {
        return false;
    }

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

#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case DE_ADIA:
        case DE_ODIA:
        case DE_UDIA:
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
// --- NOTED LAYER COMBOS ---
const uint16_t PROGMEM j_noted_combo[]  = {DE_L, DE_F, COMBO_END};
const uint16_t PROGMEM sz_noted_combo[] = {LALT_T(DE_R), RGUI_T(DE_H), COMBO_END};

// --- QWERT LAYER COMBOS ---
const uint16_t PROGMEM ue_qwertz_combo[] = {DE_O, DE_P, COMBO_END};
const uint16_t PROGMEM ae_qwertz_combo[] = {LALT_T(DE_L), RGUI_T(DE_ODIA), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(j_noted_combo, DE_J),      // Index 0
    COMBO(sz_noted_combo, DE_SS),    // Index 1
    COMBO(ue_qwertz_combo, DE_UDIA), // Index 2
    COMBO(ae_qwertz_combo, DE_ADIA)  // Index 3
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    uint8_t current_layer = get_highest_layer(layer_state);
    return (current_layer == _NOTED) ? combo_index < 2 : combo_index > 1;
}
#endif // COMBO_ENABLE

#ifdef OLED_ENABLE
// Globale Variablen für Animationen im OLED-Scope
static uint32_t bongo_timer      = 0;
static bool     is_bongo_tapping = false;

static void render_thumb_keys(const char *first, const char *second, const char *third) {
    oled_set_cursor(0, oled_max_lines() - 1);
#    ifndef OLED_LAYOUT_VERTICAL
    oled_write_P(PSTR("Thumb: "), false);
#    endif

    oled_write_P(first, false);

    oled_write_P(PSTR(" "), false);
    oled_write_P(second, false);

    oled_write_P(PSTR(" "), false);
    oled_write_ln_P(third, false);
}

static void render_thumb_keymap(uint8_t layer) {
    if (is_keyboard_left()) {
        switch (layer) {
            case _SYMB:
                render_thumb_keys(PSTR("@ "), PSTR("Ret"), PSTR("G^"));
                break;
            case _NAVI:
                render_thumb_keys(PSTR("Nv"), PSTR("Ret"), PSTR("Tb"));
                break;
            case _NUMS:
                render_thumb_keys(PSTR("Nv"), PSTR(" , "), PSTR("Tb"));
                break;
            default:
                render_thumb_keys(PSTR("Ec"), PSTR("Ret"), PSTR("Tb"));
                break;
        }
    } else {
#    ifdef KEYBOARD_draculad
        switch (layer) {
            case _SYMB:
                render_thumb_keys(PSTR("Spc"), PSTR(""), PSTR("RAlt"));
                break;
            case _NAVI:
                render_thumb_keys(PSTR("lnS"), PSTR(""), PSTR("Base"));
                break;
            case _NUMS:
                render_thumb_keys(PSTR("  0"), PSTR(""), PSTR(" ."));
                break;
            default:
                render_thumb_keys(PSTR("Spc"), PSTR(""), PSTR("BSpc"));
                break;
        }
#    else
        switch (layer) {
            case _SYMB:
                render_thumb_keys(PSTR("Bsp"), PSTR("Spc"), PSTR("RAlt"));
                break;
            case _NAVI:
                render_thumb_keys(PSTR("Bsp"), PSTR("s"), PSTR("Base"));
                break;
            case _NUMS:
                render_thumb_keys(PSTR(","), PSTR("0"), PSTR("."));
                break;
            default:
                render_thumb_keys(PSTR("Bsp"), PSTR("Spc"), PSTR("Del"));
                break;
        }
#    endif
    }
}

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
            case _NUMS:
                oled_write_ln_P(PSTR("  > Nums\n"), false);
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
        render_thumb_keymap(layer);

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
        render_thumb_keymap(layer);
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
            case _NUMS:
                oled_write_ln_P(PSTR("Numbers   "), false);
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
        render_thumb_keymap(layer);

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
        render_thumb_keymap(layer);
    }
#    endif     // OLED_LAYOUT_VERTICAL
    return false;
}
#endif // OLED_ENABLE
