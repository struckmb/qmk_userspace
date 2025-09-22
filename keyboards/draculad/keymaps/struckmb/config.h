/*
Copyright 2021 @mangoiv

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#define QWERTY_ENABLE
#define NOTED_ENABLE
// #define BONE_ENABLE
// #define NEO2_ENABLE
// #define COLEMAK_DH_ENABLE
// #define DVORAK_DE_ENABLE

// If more than 4 layers are activated, uncomment the following block
/* #ifdef LAYER_STATE_8BIT
 * #    undef LAYER_STATE_8BIT
 * #    define LAYER_STATE_16BIT
 * #endif // LAYER_STATE_8BIT
 */

#ifdef OLED_ENABLE
#    define OLED_PORTRAIT
#endif // OLED_ENABLE

#ifdef POINTING_DEVICE_ENABLE
#    define POINTING_DEVICE_ROTATION_90
x// comment out the next line if your trackball is on the left side
#    define TRACKBALL_RIGHT
#    ifdef TRACKBALL_RIGHT
#        define PIMORONI_TRACKBALL_INVERT_X
#        define PIMORONI_TRACKBALL_INVERT_Y
#    endif // TRACKBALL_RIGHT
#endif     // ifdef POINTING_DEVICE_ENABLE

#ifdef RGBLIGHT_ENABLE
// #    undef RGBLIGHT_ANIMATIONS // disable ALL animations
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT // (264k)  Enable static gradient mode.
// o
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD    // (636k)  Enable rainbow mood animation mode.
// #define RGBLIGHT_EFFECT_RAINBOW_SWIRL   // (670k)  Enable rainbow swirl animation mode.
// #define RGBLIGHT_EFFECT_BREATHING       // (904k)  Enable breathing animation mode.
// #define RGBLIGHT_EFFECT_CHRISTMAS       // (922k)  Enable christmas animation mode.
// #define RGBLIGHT_EFFECT_TWINKLE         // (1574k) Enable twinkle animation mode.
// #define RGBLIGHT_EFFECT_RGB_TEST        // (596k)  Enable RGB test animation mode.
#endif
