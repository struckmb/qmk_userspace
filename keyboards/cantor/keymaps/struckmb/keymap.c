#include "struckmb.h"

#define CANTOR_MAP(...) LAYOUT_split_3x6_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_NOTED] = CANTOR_MAP(          //
        NOTED_L6_TOP, NOTED_R6_TOP, //
        NOTED_L6_MID, NOTED_R6_MID, //
        NOTED_L6_BOT, NOTED_R6_BOT, //
        BASE_L3_TMB, BASE_R3_TMB),

    [_QWERT] = CANTOR_MAP(          //
        QWERT_L6_TOP, QWERT_R6_TOP, //
        QWERT_L6_MID, QWERT_R6_MID, //
        QWERT_L6_BOT, QWERT_R6_BOT, //
        BASE_L3_TMB, BASE_R3_TMB),

    [_SYMB] = CANTOR_MAP(         //
        SYMB_L6_TOP, SYMB_R6_TOP, //
        SYMB_L6_MID, SYMB_R6_MID, //
        SYMB_L6_BOT, SYMB_R6_BOT, //
        SYMB_L3_TMB, SYMB_R3_TMB),

    [_NAVI] = CANTOR_MAP(         //
        NAVI_L6_TOP, NAVI_R6_TOP, //
        NAVI_L6_MID, NAVI_R6_MID, //
        NAVI_L6_BOT, NAVI_R6_BOT, //
        NAVI_L3_TMB, NAVI_R3_TMB),

    [_NUMS] = CANTOR_MAP(         //
        NUMS_L6_TOP, NUMS_R6_TOP, //
        NUMS_L6_MID, NUMS_R6_MID, //
        NUMS_L6_BOT, NUMS_R6_BOT, //
        NUMS_L3_TMB, NUMS_R3_TMB),
};
