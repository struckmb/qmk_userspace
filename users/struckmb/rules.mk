

# These options should be the same for all boards
AVR_USE_MINIMAL_PRINTF = yes
BOOTMAGIC_ENABLE = yes
CAPS_WORD_ENABLE = yes
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
GRAVE_ESC_ENABLE = no
KEY_OVERRIDE_ENABLE = no
SPACE_CADET_ENABLE = no

# Set per keyboard
EXTRAKEY_ENABLE ?= yes      # OS signals like volume control (+ 548)
MOUSEKEY_ENABLE ?= yes      # Mouse emulation keys
OS_DETECTION_ENABLE ?= yes  # (+ 1086)
WPM_ENABLE ?= yes           # Get WPM reports as you type (+ 852)
# Common compilation flags
LTO_ENABLE ?= yes

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
