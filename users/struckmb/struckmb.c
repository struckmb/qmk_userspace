#include "struckmb.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Return after running through all individual hooks
    if (keycode <= NO_MODS && record->event.pressed) {
        switch (keycode) {
            case NO_MODS:
                clear_oneshot_mods();
                return false;
            case DL_PREV:
                if (get_highest_layer(default_layer_state) > 0) {
                    set_single_persistent_default_layer(get_highest_layer(default_layer_state) - 1);
                } else {
                    set_single_persistent_default_layer(LAYER_SYMBL - 1);
                }
                return false;
            case DL_NEXT:
                // uint8_t next_default_layer = get_highest_layer(default_layer_state) + 1;
                if (get_highest_layer(default_layer_state) + 1 < LAYER_SYMBL) {
                    set_single_persistent_default_layer(get_highest_layer(default_layer_state) + 1);
                } else {
                    set_single_persistent_default_layer(0);
                }
                return false;
        }
    }

#ifdef OS_DETECTION_ENABLE
    switch (detected_host_os()) {
        case OS_MACOS:
            switch (keycode) {
                case KC_CUT:
                    if (record->event.pressed) {
                        tap_code16(G(KC_X));
                    }
                    return false;
                case KC_COPY:
                    if (record->event.pressed) {
                        tap_code16(G(KC_C));
                    }
                    return false;
                case KC_PSTE:
                    if (record->event.pressed) {
                        tap_code16(G(KC_V));
                    }
                    return false;
                case KC_BRIU:
                    if (record->event.pressed) {
                        register_code16(KC_BRMU);
                    } else {
                        unregister_code16(KC_BRMU);
                    }
                    return false;
                case KC_BRID:
                    if (record->event.pressed) {
                        register_code16(KC_BRMD);
                    } else {
                        unregister_code16(KC_BRMD);
                    }
                    return false;
            }
            break;

        case OS_LINUX:
        case OS_WINDOWS:
            switch (keycode) {
                case KC_CUT:
                    if (record->event.pressed) {
                        tap_code16(S(KC_DEL));
                    }
                    return false;
                case KC_COPY:
                    if (record->event.pressed) {
                        tap_code16(C(KC_INS));
                    }
                    return false;
                case KC_PSTE:
                    if (record->event.pressed) {
                        tap_code16(S(KC_INS));
                    }
                    return false;
            }
            break;
        default:
            break;
    }
#endif /* ifdef OS_DETECTION_ENABLE */

    return
    //     process_record_keymap(keycode, record) &&
    // #ifdef ENCODER_ENABLE
    //            process_record_encoder(keycode, record) &&
    // #endif // ENCODER_ENABLE
    true;
}

#ifdef QUICK_TAP_TERM
#    ifdef QUICK_TAP_TERM_PER_KEY
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_SPC:
            return 0; // no repeat
        default:
            return QUICK_TAP_TERM;
    }
}
#    endif // QUICK_TAP_TERM_PER_KEY
#endif     // QUICK_TAP_TERM

#ifdef HOLD_ON_OTHER_KEY_PRESS
#    ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_ENT:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}
#    endif // HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#endif     // HOLD_ON_OTHER_KEY_PRESS

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
