#pragma once

#include_next "config.h"

// ==================================================================================
// GENERAL SPLIT & OLED SETTINGS (Immer aktiv, wenn das Display läuft)
// ==================================================================================
#ifdef OLED_ENABLE
// Aktiviert das vertikale Display-Profil im Userspace
#    define OLED_LAYOUT_VERTICAL

// Zwingend erforderlich, damit der Slave die Tastenanschläge für Bongo Cat sieht!
#    define SPLIT_TRANSPORT_MIRROR

// Font-Dimensionen für das vertikale Layout
#    define OLED_FONT_WIDTH 6
#    define OLED_FONT_HEIGHT 8
#endif

// ==================================================================================
// TRACKBALL / POINTING DEVICE SETTINGS (Nur aktiv, wenn in rules.mk eingeschaltet)
// ==================================================================================
#ifdef POINTING_DEVICE_ENABLE
#    define SPLIT_POINTING_ENABLE
#    define PIMORONI_TRACKBALL_ADDRESS 0x0A
#    define POINTING_DEVICE_COMBINED
#    define POINTING_DEVICE_RIGHT
#    define PIMORONI_TRACKBALL_SCALE 5
#    define PIMORONI_TRACKBALL_ROTATE
#endif
