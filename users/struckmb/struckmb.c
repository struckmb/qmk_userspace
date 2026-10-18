#include "struckmb.h"

// Zentrale Combo-Definitionen (Gültig für JEDE deiner QMK-Tastaturen)
const uint16_t PROGMEM j_combo[]  = {DE_L, DE_F, COMBO_END};
const uint16_t PROGMEM ss_combo[] = {DE_DOT, DE_K, COMBO_END};
const uint16_t PROGMEM os_shift[] = {DE_T, DE_N, COMBO_END};
const uint16_t PROGMEM os_ctrl[]  = {DE_COMM, DE_DOT, COMBO_END};
const uint16_t PROGMEM os_gui[]   = {DE_N, DE_R, COMBO_END};
const uint16_t PROGMEM os_alt[]   = {DE_G, DE_COMM, COMBO_END};

// Zentrales Combo-Verzeichnis
combo_t key_combos[COMBO_COUNT] = {
    //
    COMBO(j_combo, DE_J),           //
    COMBO(ss_combo, DE_SS),         //
    COMBO(os_shift, OSM(MOD_LSFT)), //
    COMBO(os_ctrl, OSM(MOD_LCTL)),  //
    COMBO(os_gui, OSM(MOD_LGUI)),   //
    COMBO(os_alt, OSM(MOD_LALT))    //
};

// Zentrale Makro-Ausführung (Fehlerfrei umgeschrieben ohne String-Verschmelzung)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case MAC_GT: // GUI + TAB
                register_code(KC_LGUI);
                tap_code(KC_TAB);
                unregister_code(KC_LGUI);
                return false;
            case MAC_AST: // ALT + SHIFT + TAB
                register_code(KC_LALT);
                register_code(KC_LSFT);
                tap_code(KC_TAB);
                unregister_code(KC_LSFT);
                unregister_code(KC_LALT);
                return false;
            case MAC_CST: // CTRL + SHIFT + TAB
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                tap_code(KC_TAB);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
                return false;
            case MAC_CT: // CTRL + TAB
                register_code(KC_LCTL);
                tap_code(KC_TAB);
                unregister_code(KC_LCTL);
                return false;
            case MAC_AT: // ALT + TAB
                register_code(KC_LALT);
                tap_code(KC_TAB);
                unregister_code(KC_LALT);
                return false;
        }
    }
    return true;
}
