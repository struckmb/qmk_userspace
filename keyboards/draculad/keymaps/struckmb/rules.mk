
MOUSEKEY_ENABLE = no
OS_DETECTION_ENABLE = no
WPM_ENABLE = no       # Get WPM reports as you type

# only uncomment on the side you have your trackball on
POINTING_DEVICE_ENABLE = no
#POINTING_DEVICE_DRIVER = pimoroni_trackball


PIMORONI_TRACKBALL_ENABLE = no
ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), yes)
 POINTING_DEVICE_ENABLE = yes
 POINTING_DEVICE_DRIVER = pimoroni_trackball
 SRC += drivers/sensors/pimoroni_trackball.c
 QUANTUM_LIB_SRC += i2c_master.c
endif


# QUANTUM_LIB_SRC += i2c_master.c
OLED_DRIVER_ENABLE = yes

# Hardware settings
ifneq (,$(findstring draculad,$(KEYBOARD)))
    # Elective features
    # COMBO_ENABLE = yes
    ENCODER_ENABLE = yes
    OLED_ENABLE = yes
    # Nonexistent features
    AUDIO_ENABLE = no
    BACKLIGHT_ENABLE = no
    RGB_MATRIX_ENABLE = no
    # Space savers
    NKRO_ENABLE = no
    VELOCIKEY_ENABLE = no
    WPM_ENABLE = yes
endif
