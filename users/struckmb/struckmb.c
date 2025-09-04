#include "struckmb.h"

// Return after running through all individual hooks
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
    bool macos = detected_host_os() == OS_MACOS;
#else
    bool macos = false;
#endif // OS_DETECTION_ENABLE

    switch (keycode) {
        case CP_CUT:
            if (record->event.pressed) {
                tap_code16(macos ? G(DE_X) : S(KC_DEL));
            }
            return false;
        case CP_COPY:
            if (record->event.pressed) {
                tap_code16(macos ? G(DE_C) : C(KC_INS));
            }
            return false;
        case CP_PSTE:
            if (record->event.pressed) {
                tap_code16(macos ? G(DE_V) : S(KC_INS));
            }
            return false;
        case CP_PSTV:
            if (record->event.pressed) {
                tap_code16(macos ? LSAG(DE_V) : LCS(DE_V));
            }
            return false;
        case CP_UNDO:
            if (record->event.pressed) {
                tap_code16(macos ? G(DE_Z) : C(DE_Z));
            }
            return false;
        case CP_REDO:
            if (record->event.pressed) {
                tap_code16(macos ? LSG(DE_Z) : LCS(DE_Z));
            }
            return false;
#ifdef OS_DETECTION_ENABLE
        case KC_BRIU:
            if (macos) {
                if (record->event.pressed) {
                    if (detected_host_os() == OS_MACOS)
                        register_code16(KC_BRMU);
                } else {
                    unregister_code16(KC_BRMU);
                }
            }
            return false;
        case KC_BRID:
            if (macos) {
                if (record->event.pressed) {
                    if (detected_host_os() == OS_MACOS)
                        register_code16(KC_BRMD);
                } else {
                    unregister_code16(KC_BRMD);
                }
            }
            return false;
#endif // OS_DETECTION_ENABLE
    }

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
        case GUI_ENT:
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
