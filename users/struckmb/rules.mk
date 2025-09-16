
# Common compilation flags
LTO_ENABLE ?= yes

# These options should be set for all boards
AVR_USE_MINIMAL_PRINTF = yes
CAPS_WORD_ENABLE = yes
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
EXTRAKEY_ENABLE = yes   # OS signals like volume control
GRAVE_ESC_ENABLE = no
KEY_OVERRIDE_ENABLE = yes
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no

MOUSEKEY_ENABLE ?= yes   # Mouse emulation keys
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
