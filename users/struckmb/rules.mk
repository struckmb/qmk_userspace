
# Common compilation flags
LTO_ENABLE ?= yes

# These should be enabled in all boards
MOUSEKEY_ENABLE = yes   # Mouse emulation keys
EXTRAKEY_ENABLE = yes   # OS signals like volume control
CAPS_WORD_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes

OS_DETECTION_ENABLE ?= yes

WPM_ENABLE ?= yes       # Get WPM reports as you type

# Manually configure these on each keyboard individually
# AUDIO_ENABLE            # Audio stuff
# BACKLIGHT_ENABLE        # Switch LEDs
# ENCODER_ENABLE          # Rotary encoder
# RGB_MATRIX_ENABLE       # RGB LEDs
# OLED_ENABLE             # For OLED

# Userspace code
SRC += struckmb.c

# OLED code
ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += bs-oled.c
endif
