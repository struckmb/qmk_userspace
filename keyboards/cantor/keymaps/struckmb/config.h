#pragma once

#define EE_HANDS

#define QWERTZ_ENABLE
// #define BONE_ENABLE
#define COLEMAK_ENABLE
#define MINE_ENABLE
// #define WORKMAN_ENABLE
// #define ASETNIOP_ENABLE
// #define ARTSENIO_ENABLE

#ifdef COMBO_ENABLE
#    define COMBO_SHOULD_TRIGGER
#endif // COMBO_ENABLE

// Tap-hold settings
#define TAPPING_TERM 200
#define TAP_CODE_DELAY 20
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD
#define ONESHOT_TAP_TOGGLE 2

// Mousekey mode
#ifdef MOUSEKEY_ENABLE
#    define MK_COMBINED
#    define MOUSEKEY_MAX_SPEED 4
#    define MOUSEKEY_TIME_TO_MAX 45
#    define MOUSEKEY_WHEEL_MAX_SPEED 20
#    define MOUSEKEY_WHEEL_TIME_TO_MAX 60
#endif // MOUSEKEY_ENABLE
