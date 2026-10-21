#pragma once

// #define OLED_DISABLE_TIMEOUT // Spart Platz, wenn kein automatischer Standby gebraucht wird

// Falls der Speicher immer noch hakt, kannst du die nächste Zeile einkommentieren:
// #define OLED_FONT_END 127    // Lädt nur die erste Hälfte des Zeichensatzes (spart ca. 500 Bytes)

// --- Lokale Trackball-Konfiguration ---
#ifdef POINTING_DEVICE_ENABLE
#    define SPLIT_POINTING_ENABLE           // Zwingend erforderlich für Split-Mäuse/Trackballs!
#    define PIMORONI_TRACKBALL_ADDRESS 0x0A // Standard I2C-Adresse
#    define PIMORONI_TRACKBALL_SCALE 5      // Geschwindigkeit (höher = schneller)
#    define POINTING_DEVICE_COMBINED
#    define POINTING_DEVICE_RIGHT // Trackball sitzt auf der rechten Hälfte
#    define POINTING_DEVICE_HIRES_SCROLL_ENABLE
#    define POINTING_DEVICE_HIRES_SCROLL_MULTIPLIER 75
// Falls die Richtung nach dem Flashen noch invertiert sein sollte,
// kannst du alternativ diese beiden Zeilen nutzen:
// #   define PIMORONI_TRACKBALL_INVERT_X
// #   define PIMORONI_TRACKBALL_INVERT_Y
#endif
