

# OLED_DRIVER_ENABLE = yes
PIMORONI_TRACKBALL_ENABLE = no

# Hardware settings
ifneq (,$(findstring draculad,$(KEYBOARD)))
    # Elective features
    # COMBO_ENABLE = yes
    ENCODER_ENABLE = no
    OLED_ENABLE = yes
    # Nonexistent features
    AUDIO_ENABLE = no
    BACKLIGHT_ENABLE = no
    RGB_MATRIX_ENABLE = no
	RGBLIGHT_ENABLE = yes
    # Space savers
    NKRO_ENABLE = no
    VELOCIKEY_ENABLE = no
    WPM_ENABLE = yes
endif

ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), yes)
	MOUSEKEY_ENABLE = yes
	POINTING_DEVICE_ENABLE = yes
	POINTING_DEVICE_DRIVER = pimoroni_trackball
else
	MOUSEKEY_ENABLE = no
	POINTING_DEVICE_ENABLE = no
endif
