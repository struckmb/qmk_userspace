#include "struckmb.h"

#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
    // adapt caps word to german layout
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case DE_ADIA:
        case DE_ODIA:
        case DE_UDIA:
        case DE_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case DE_UNDS:
        case DE_SS:
            return true;

        default:
            return false; // Deactivate Caps Word.
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
