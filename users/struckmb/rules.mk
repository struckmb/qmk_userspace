# Aktiviert das Combo-Feature global
COMBO_ENABLE = yes

# ZWINGEND: Sagt QMK, dass die Combos in deiner zentralen Userspace-Datei liegen
INTROSPECTION_KEYMAP_C = $(USER_PATH)/struckmb.c

# Deine restlichen, empfohlenen Performance-Optionen
COMMAND_ENABLE = yes
LTO_ENABLE = yes
TAP_DANCE_ENABLE = no
