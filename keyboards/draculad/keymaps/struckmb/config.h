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

// comment that out if your trackball is on the left side
#define TRACKBALL_RIGHT

#ifdef TRACKBALL_RIGHT
#    define PIMORONI_TRACKBALL_INVERT_X
#    define PIMORONI_TRACKBALL_INVERT_Y
#endif // TRACKBALL_RIGHT
#define POINTING_DEVICE_ROTATION_90

#define QWERTY_ENABLE
// #define BONE_ENABLE

#ifdef COMBO_ENABLE
#    define EXTRA_SHORT_COMBOS
// #    define COMBO_SHOULD_TRIGGER
#endif // COMBO_ENABLE
