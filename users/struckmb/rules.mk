OS_DETECTION_ENABLE = yes
MOUSEKEY_ENABLE = yes
CAPS_WORD_ENABLE = yes
REPEAT_KEY_ENABLE = yes

# Userspace code
SRC += struckmb.c

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	DYNAMIC_TAPPING_TERM_ENABLE = yes
endif
