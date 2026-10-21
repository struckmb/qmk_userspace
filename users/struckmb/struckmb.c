#include "struckmb.h"

#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
    // Anpassung des Caps Word an das deutsche Layout
    switch (keycode) {
        // Keycodes, die das Caps Word fortsetzen und geshiftet werden sollen
        case KC_A ... KC_Z:
        case DE_ADIA:
        case DE_ODIA:
        case DE_UDIA:
        case DE_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Shift auf die nächste Taste anwenden
            return true;

        // Keycodes, die das Caps Word fortsetzen, ohne geshiftet zu werden
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case DE_UNDS:
        case DE_SS:
            return true;

        default:
            return false; // Caps Word deaktivieren
    }
}
#endif /* ifdef CAPS_WORD_ENABLE */

#ifdef COMBO_ENABLE
// Definition aller Combos
const uint16_t PROGMEM j_combo[]     = {DE_L, DE_F, COMBO_END};
const uint16_t PROGMEM sz_combo[]    = {DE_DOT, DE_K, COMBO_END};
const uint16_t PROGMEM thumb_combo[] = {LT(_NAVI, KC_ESC), LT(_NAVI, KC_TAB), COMBO_END};

// Combo-Verzeichnis registrieren
combo_t key_combos[COMBO_COUNT] = {COMBO(j_combo, DE_J), COMBO(sz_combo, DE_SS), COMBO(thumb_combo, OSL(_FUNC))};
#endif // COMBO_ENABLE

// ==================================================================================
// GLOBALER OLED USERSPACE (PROFILGESTEUERT)
// ==================================================================================
#ifdef OLED_ENABLE

// Globale Animations-Variablen für beide Hälften im OLED-Scope
static uint32_t bongo_timer      = 0;
static bool     is_bongo_tapping = false;

// post_process_record_user fängt die Aktivität auf dem Master ab
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        is_bongo_tapping = true;
        bongo_timer      = timer_read32();
    }
}

// Rotationssteuerung basierend auf dem aktiven Tastatur-Profil
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
#    ifdef OLED_LAYOUT_VERTICAL
    // Durch die gespiegelte Bauweise der PCBs beim Draculad müssen die Displays
    // physisch immer das exakt gleiche Rotationsprofil aufweisen, egal wer Master ist!
    if (is_keyboard_left()) {
        return OLED_ROTATION_270; // Linke Hälfte steht damit aufrecht
    } else {
        return OLED_ROTATION_90; // Rechte Hälfte steht damit aufrecht
    }
#    else
    // Globaler Fallback: Standard-Querformat (z.B. Corne)
    if (is_keyboard_master()) {
        return OLED_ROTATION_0;
    } else {
        return OLED_ROTATION_180;
    }
#    endif
}

// Hauptfunktion für die Bildschirmausgabe
bool oled_task_user(void) {
    if (is_keyboard_master()) {
// ==========================================
// MASTER SEITE (Status-Zentrale)
// ==========================================
#    ifdef OLED_LAYOUT_VERTICAL
        // --- KOMPAKTES VERTIKAL-LAYOUT ---
        oled_write_ln_P(PSTR("QMK"), false);
        oled_write_ln_P(PSTR("---"), false);

        // Basis-Layout permanent anzeigen (getrennt von temporären Layern)
        uint8_t default_layer = get_highest_layer(default_layer_state);
        switch (default_layer) {
            case 0:
                oled_write_ln_P(PSTR("NOTE"), false);
                break;
            default:
                break;
        }

        // Aktive Zusatz-Layer mit visuellem Pfeil einblenden
        uint8_t layer = get_highest_layer(layer_state);
        switch (layer) {
            case 1:
                oled_write_ln_P(PSTR("->SYMB"), false);
                break;
            case 2:
                oled_write_ln_P(PSTR("->NAVI"), false);
                break;
            case 3:
                oled_write_ln_P(PSTR("->FUNC"), false);
                break;
            default:
                oled_write_ln_P(PSTR("      "), false); // Zeilenhöhe stabil halten
                break;
        }

        oled_write_ln_P(PSTR(""), false);

        // Aktive Modifikatoren im Hochformat untereinander auflisten
        uint8_t mods = get_mods();
        if (mods & MOD_MASK_SHIFT) oled_write_ln_P(PSTR("SFT"), false);
        if (mods & MOD_MASK_CTRL) oled_write_ln_P(PSTR("CTL"), false);
        if (mods & MOD_MASK_ALT) oled_write_ln_P(PSTR("ALT"), false);
        if (mods & MOD_MASK_GUI) oled_write_ln_P(PSTR("GUI"), false);

#    else
        // --- KLASSISCHES HORIZONTAL-LAYOUT ---
        oled_write_ln_P(PSTR("== QMK KEYBOARD =="), false);

        oled_write_P(PSTR("Layer: "), false);
        uint8_t layer = get_highest_layer(layer_state);
        switch (layer) {
            case 0:
                oled_write_ln_P(PSTR("Noted (Base)"), false);
                break;
            case 1:
                oled_write_ln_P(PSTR("Symbol (Neo3)"), false);
                break;
            case 2:
                oled_write_ln_P(PSTR("Navigation"), false);
                break;
            case 3:
                oled_write_ln_P(PSTR("Function"), false);
                break;
            default:
                oled_write_ln_P(PSTR("Custom"), false);
                break;
        }

        oled_write_ln_P(PSTR(""), false);

        uint8_t mods = get_mods();
        oled_write_P(PSTR("Mods: "), false);
        if (mods & MOD_MASK_SHIFT) oled_write_P(PSTR("SFT "), false);
        if (mods & MOD_MASK_CTRL) oled_write_P(PSTR("CTL "), false);
        if (mods & MOD_MASK_ALT) oled_write_P(PSTR("ALT "), false);
        if (mods & MOD_MASK_GUI) oled_write_P(PSTR("GUI "), false);
        if (!mods) oled_write_P(PSTR("None"), false);
        oled_write_ln_P(PSTR(""), false);
#    endif
    } else {
// ==========================================
// SLAVE SEITE (9-Zeichen vertikale Bongo Cat)
// ==========================================
#    ifdef OLED_LAYOUT_VERTICAL
        // Schleife prüft das gespiegelte Matrix-Array auf aktive Tasten
        bool key_pressed = false;
        for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
            if (matrix_get_row(i) > 0) {
                key_pressed = true;
                break;
            }
        }

        if (key_pressed) {
            is_bongo_tapping = true;
            bongo_timer      = timer_read32();
        }

        // Nach 250ms Inaktivität nimmt die Katze die Pfoten wieder hoch
        if (is_bongo_tapping && timer_elapsed32(bongo_timer) > 250) {
            is_bongo_tapping = false;
        }

        // Cursor zurücksetzen, um stabiles Hochkant-Rendering zu erzwingen
        oled_set_cursor(0, 0);

        // --- KOMPAKTE ASCII-KATZE (Exakt maximal 9 Zeichen breit) ---
        oled_write_ln_P(PSTR("  BONGO  "), false);
        oled_write_ln_P(PSTR("   CAT   "), false);
        oled_write_ln_P(PSTR(" ------- "), false);
        oled_write_ln_P(PSTR(""), false);
        oled_write_ln_P(PSTR("  /\\_/\\  "), false); // Ohren (9 Zeichen)
        oled_write_ln_P(PSTR(" (=o.o=) "), false);   // Gesicht (8 Zeichen, linksbündig für Symmetrie)

        if (is_bongo_tapping) {
            oled_write_ln_P(PSTR(" ( - \\ ) "), false); // Pfoten schlagen flach auf (9 Zeichen)
            oled_write_ln_P(PSTR("  m  _/  "), false);  // (9 Zeichen)
        } else {
            oled_write_ln_P(PSTR(" ( / - ) "), false);  // Pfoten angewinkelt oben (9 Zeichen)
            oled_write_ln_P(PSTR("  \\_  m  "), false); // (9 Zeichen)
        }

        oled_write_ln_P(PSTR(" [=====] "), false); // Die Trommel (9 Zeichen)
        oled_write_ln_P(PSTR("  U   U  "), false); // Füße (9 Zeichen)

#    else
        // --- Globaler Fallback: Horizontale Bongo Cat (z.B. Corne) ---
        extern const char bongo_cat_tap[];
        extern const char bongo_cat_idle[];

        if (is_bongo_tapping && timer_elapsed32(bongo_timer) > 250) {
            is_bongo_tapping = false;
        }

        if (is_bongo_tapping) {
            oled_write_raw_P(bongo_cat_tap, 256);
        } else {
            oled_write_raw_P(bongo_cat_idle, 256);
        }
#    endif
    }
    return false;
}
#endif // OLED_ENABLE
