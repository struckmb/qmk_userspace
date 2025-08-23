#define EE_HANDS

// // select at least on of these base layers
// #define QWERTY_ENABLE
// #define BONE_ENABLE
// #define NOTED_ENABLE
// #define COLEMAK_DH_ENABLE

// // some additionl layers can be added
// #define GAME_ENABLE (left hand qwerty + right hand arrows and numbers)
// #define ASETNIOP_ENABLE (corded writing)
// #define ARTSENIO_ENABLE (one handed writing)

// Mousekey mode
#ifdef MOUSEKEY_ENABLE
#    define MK_COMBINED
#    define MOUSEKEY_MAX_SPEED 4
#    define MOUSEKEY_TIME_TO_MAX 45
#    define MOUSEKEY_WHEEL_MAX_SPEED 20
#    define MOUSEKEY_WHEEL_TIME_TO_MAX 60
#endif // MOUSEKEY_ENABLE

#ifdef COMBO_ENABLE
#    define COMBO_SHOULD_TRIGGER
#endif // COMBO_ENABLE

#ifdef TAP_DANCE_ENABLE
#    define TAPPING_TERM 120
#    ifdef DYNAMIC_TAPPING_TERM_ENABLE
#        define DYNAMIC_TAPPING_TERM_INCREMENT 10
#    endif // DYNAMIC_TAPPING_TERM_ENABLE
#else
// Tap-hold settings
#    define TAPPING_TERM 300
#    define QUICK_TAP_TERM 175
#    define QUICK_TAP_TERM_PER_KEY
#    define HOLD_ON_OTHER_KEY_PRESS
#    define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#    define PERMISSIVE_HOLD
#    define TAP_CODE_DELAY 20
#    define TAPPING_FORCE_HOLD
#    define ONESHOT_TAP_TOGGLE 3
#endif // TAP_DANCE_ENABLED
