/* Copyright 2021 Batuhan Başerdem
 * <baserdem.batuhan@gmail.com> @bbaserdem
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "bs-oled.h"

/* #include <string.h> */
// Grab the print function
#ifdef ENCODER_ENABLE
// #   include "bs-encoder.h"
#endif // ENCODER_ENABLE

/* OLED
 * This contains general purpose oled code
 */

// Allow default to be overwritten by keymap if they return false
__attribute__ ((weak)) bool oled_task_keymap(void) {return true;}

// Do sane defaults for regular oled rendering
bool oled_task_user(void) {
    if (is_oled_on() && oled_task_keymap()) {
        if (is_keyboard_master()) {
            render_status_lite(0, 0, false);
        } else {
            render_qmk_logo(0, 0);
        }
    }
    return false;
}

/*-------------------------*\
|*---RENDERING FUNCTIONS---*|
\*-------------------------*/
void render_qmk_logo(uint8_t col, uint8_t row) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
    oled_set_cursor(col, row);
    oled_write_P(qmk_logo, false);
}
void render_qmk_small_logo(uint8_t col, uint8_t row) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0xa0,0xa1,0xa2,0xa3,0xa4,
        0xa5,0xa6,0xa7,0xa8,0xa9,0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0};
    oled_set_cursor(col, row);
    oled_write_P(qmk_logo, false);
}

void render_keymap(uint8_t col, uint8_t row, uint8_t def_layer, bool portrait) {
    oled_set_cursor(col, row);
    oled_write("Base: ", false);
    if (portrait) oled_write("\n  ", false);
    switch (def_layer) {
#ifdef QWERTY_ENABLE
        case LAYER_QWERTY:
            oled_write("QWERTY", false);
            break;
#endif // QWERTY_ENABLE
#ifdef NOTED_ENABLE
        case LAYER_NOTED:
            oled_write("NOTED ", false);
            break;
#endif /* ifdef NOTED_ENABLE */
#ifdef BONE_ENABLE
        case LAYER_BONE:
            oled_write("NOTED ", false);
            break;
#endif /* ifdef BONE_ENABLE */
#ifdef NEO2_ENABLE
        case LAYER_NEO2:
            oled_write("NEO2  ", false);
            break;
#endif /* ifdef NEO2_ENABLE */
#ifdef COLEMAK_DH_ENABLE
        case LAYER_COLEMAK_DH:
            oled_write("COLMKD", false);
            break;
#endif /* ifdef COLEMAK_DH_ENABLE */
#ifdef DVORAK_DE_ENABLE
        case LAYER_DVORAK_DE:
            oled_write("DVORAK", false);
            break;
#endif /* ifdef DVORAK_DE_ENABLE */
#       ifdef ASETNIOP_ENABLE
        case LAYER_ASETNIOP:
            oled_write("ASET++", false);
            break;
#       endif // ASETNIOP_ENABLE
#       ifdef ARTSENIO_ENABLE
        case LAYER_ARTSENIO:
            oled_write("ARTSEN", false);
            break;
#       endif // ARTSENIO_ENABLE
        default:
            oled_write(" N/A! ", false);
    }
}

void render_layer(uint8_t col, uint8_t row, uint8_t top_layer, bool portrait) {
    oled_set_cursor(col, row);
    oled_write("Layr: ", false);
    if (portrait) oled_write("\n  ", false);
    switch (top_layer) {
#ifdef ARTSENIO_ENABLE
        case L_ARTS_NUM:
            oled_write("AS 1/F1", false);
            break;
        case L_ARTS_SYM:
            oled_write("AS Sym.", false);
            break;
        case L_ARTS_PAR:
            oled_write("AS {[]}", false);
            break;
        case L_ARTS_NAV:
            oled_write("AS Nav.", false);
            break;
        case L_ARTS_MSE:
            oled_write("AS Mse ", false);
            break;
#endif // ARTSENIO_ENABLE
        case LAYER_SYMBL:
            oled_write("Symbols", false);
            break;
        case LAYER_LOWER:
            oled_write("Fn/Num ", false);
            break;
        case LAYER_RAISE:
            oled_write("Nav/Ed ", false);
            break;
#ifdef MOUSEKEY_ENABLE
        case LAYER_POINTER:
            oled_write("Mouse  ", false);
            break;
#endif // MOUSEKEY_ENABLE
        case LAYER_ATTIC:
            oled_write("Adjust ", false);
            break;
        default:
            oled_write("Default", false);
    }
}

void render_modifiers(uint8_t col, uint8_t row, uint8_t mods, uint8_t osms, bool portrait) {
    bool capsLock = host_keyboard_led_state().caps_lock || is_caps_word_on();
    // Write the modifier state
    oled_set_cursor(col, row);
    oled_write("Mods: ", false);
    if (portrait) oled_write("\n  ", false);
    oled_write((mods & MOD_MASK_SHIFT  ) ? "S" : " ", (osms & MOD_MASK_SHIFT  ));
    oled_write((mods & MOD_MASK_CTRL   ) ? "C" : " ", (osms & MOD_MASK_CTRL   ));
    oled_write((mods & MOD_BIT(KC_RALT)) ? "R" : " ", (osms & MOD_BIT(KC_RALT)));
    oled_write((mods & MOD_MASK_ALT    ) ? "A" : " ", (osms & MOD_MASK_ALT    ));
    oled_write((mods & MOD_MASK_GUI    ) ? "M" : " ", (osms & MOD_MASK_GUI    ));
    if (portrait) {
        oled_write("\n  ", false);
        oled_write(capsLock ? " CAPS " : "      ", capsLock);
    } else {
        oled_write(capsLock ? " L" : "  ", capsLock);
    }
}

void render_status_lite(uint8_t row, uint8_t col, bool portrait) {
    uint8_t oneshotMods  = get_oneshot_mods();
    uint8_t skipLength  = portrait ? 3 : 1;

    // Line 1/1-2: Layout
    render_keymap(col, row, get_highest_layer(default_layer_state), portrait);
    // Line 2/3-4: Layer State
    render_layer(col,  row + skipLength, get_highest_layer(layer_state), portrait);
    // Line 3/5-6: Modifiers
    render_modifiers(col, row + (2 * skipLength), get_mods() | oneshotMods, oneshotMods, portrait);

#ifdef WPM_ENABLE
    // Last line: WPM and layout
    oled_set_cursor(col, row + (3 * skipLength));
    oled_write("WPM: ", false);
    // if (portrait) oled_write("\n  ", false);

    oled_write(get_u8_str(get_current_wpm(), ' '), false);
#endif // WPM_ENABLE
}
