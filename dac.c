#include "main.h"

void DAC1_EN(void) {
    DACCON0bits.DAC1EN = 1;
    DACCON1 = 0x1F;
}

void DAC1_DIS(void) {
    DACCON0bits.DAC1EN = 0;
}
