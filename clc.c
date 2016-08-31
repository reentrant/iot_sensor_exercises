#include "main.h"

void CLC1_Init(void) {

    CLC1GLS0 = 0x05;
    CLC1GLS1 = 0x10;
    CLC1GLS2 = 0x08;
    CLC1GLS3 = 0x20;
    CLC1SEL0 = 0x10;
    CLC1SEL1 = 0x12;
    CLC1SEL2 = 0x13;
    CLC1SEL3 = 0x00;
    CLC1POL = 0x01;
    CLC1CON = 0x80;
    CLCIN0PPS = 0x00;
    CLCIN1PPS = 0x00;
    CLCIN2PPS = 0x00;
    CLCIN3PPS = 0x00;

}

void CLC2_Init(void) {

    CLC2GLS0 = 0x02;
    CLC2GLS1 = 0x00;
    CLC2GLS2 = 0x00;
    CLC2GLS3 = 0x00;
    CLC2SEL0 = 0x00;
    CLC2SEL1 = 0x00;
    CLC2SEL2 = 0x00;
    CLC2SEL3 = 0x00;
    CLC2POL = 0x80;
    CLC2CON = 0x81;
    CLCIN0PPS = 0x14;
    CLCIN1PPS = 0x00;
    CLCIN2PPS = 0x14;
    CLCIN3PPS = 0x00;

}
