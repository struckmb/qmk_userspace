#include "struckmb.h"

// Return after running through all individual hooks
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode <= NO_MODS && record->event.pressed) {
        switch (keycode) {
            case NO_MODS:
                clear_oneshot_mods();
                return false;
            case DL_PREV:
                if (LAYER_MAX > 0) {
                    uint8_t current_default_layer = get_highest_layer(default_layer_state);
                    if (current_default_layer > 0) {
                        set_single_persistent_default_layer(current_default_layer - 1);
                    } else  {
                        set_single_persistent_default_layer(LAYER_MAX);
                    }
                }
                return false;
            case DL_NEXT:
                if (LAYER_MAX > 0) {
                    uint8_t next_default_layer = get_highest_layer(default_layer_state) + 1;
                    if (next_default_layer > LAYER_MAX) {
                        set_single_persistent_default_layer(0);
                    } else {
                        set_single_persistent_default_layer(next_default_layer);
                    }
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
        case SEL_ALL:
            if (record->event.pressed) {
                tap_code16(macos ? G(DE_A) : C(DE_A));
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
    }

#ifdef OS_DETECTION_ENABLE
    if (macos) switch (keycode) {
        case DE_IEXL:
            if (record->event.pressed) {
                tap_code16(A(DE_5));
            }
            return false;
        case DE_IQUE:
            if (record->event.pressed) {
                tap_code16(A(DE_6));
            }
            return false;
        case DE_MDOT:
            if (record->event.pressed) {
                tap_code16(A(DE_DOT));
            }
            return false;
        case DE_NDSH:
            if (record->event.pressed) {
                tap_code16(A(DE_N));
            }
            return false;
        case DE_MDSH:
            if (record->event.pressed) {
                tap_code16(A(DE_4));
            }
            return false;
        case DE_LSAQ:
            if (record->event.pressed) {
                tap_code16(A(DE_B));
            }
            return false;
        case DE_LDAQ:
            if (record->event.pressed) {
                tap_code16(A(DE_V));
            }
            return false;
        case DE_RDAQ:
            if (record->event.pressed) {
                tap_code16(A(DE_X));
            }
            return false;
        case DE_RSAQ:
            if (record->event.pressed) {
                tap_code16(A(DE_Y));
            }
            return false;
        case DE_SLQU:
            if (record->event.pressed) {
                tap_code16(DE_COMM);
            }
            return false;
        case DE_LSQU:
        case DE_RSQU:
            if (record->event.pressed) {
                tap_code16(A(DE_D));
            }
            return false;
        case DE_DLQU:
            if (record->event.pressed) {
                tap_code16(DE_COMM);
                tap_code16(DE_COMM);
            }
            return false;
        case DE_LDQU:
        case DE_RDQU:
            if (record->event.pressed) {
                tap_code16(A(DE_S));
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
#endif // OS_DETECTION_ENABLE

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
