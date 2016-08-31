#include "main.h"

void Load_LEDS(uint8_t L1G, uint8_t L1R, uint8_t L1B, uint8_t L2G, uint8_t L2R, uint8_t L2B, uint8_t L3G, uint8_t L3R, uint8_t L3B, uint8_t L4G, uint8_t L4R, uint8_t L4B, uint8_t L5G, uint8_t L5R, uint8_t L5B) {

    _LED_String[0] = L1G;
    _LED_String[1] = L1R;
    _LED_String[2] = L1B;
    _LED_String[3] = L2G;
    _LED_String[4] = L2R;
    _LED_String[5] = L2B;
    _LED_String[6] = L3G;
    _LED_String[7] = L3R;
    _LED_String[8] = L3B;
    _LED_String[9] = L5G;
    _LED_String[10] = L5R;
    _LED_String[11] = L5B;
    _LED_String[12] = L4G;
    _LED_String[13] = L4R;
    _LED_String[14] = L4B;

    for (j = 0; j < 15; j++) {
        SSP1BUF = _LED_String[j];
        __delay_us(9);
    }
}

void Clear_LEDs(void) {

    Load_LEDS(G1 = 0, R1 = 0, B1 = 0, G2 = 0, R2 = 0, B2 = 0, G3 = 0, R3 = 0, B3 = 0, G4 = 0, R4 = 0, B4 = 0, G5 = 0, R5 = 0, B5 = 0);

}
