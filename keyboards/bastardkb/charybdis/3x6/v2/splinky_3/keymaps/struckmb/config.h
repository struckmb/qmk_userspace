
#define QWERTY_ENABLE
#define BONE_ENABLE
#define COLEMAK_DH_ENABLE

/* Charybdis-specific features. */

#ifdef POINTING_DEVICE_ENABLE
#    define CHARYBDIS_DRAGSCROLL_REVERSE_Y // natural scrolling
// Automatically enable the pointer layer when moving the trackball.  See also:
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS`
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD`
// #    define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
// #    define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
// #    define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#endif // POINTING_DEVICE_ENABLE