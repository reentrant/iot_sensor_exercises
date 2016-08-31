#include "main.h"

void PWM5_Init(void) {
    PWMTMRSbits.P5TSEL = 0b00; // PWM5 is based off TMR2
    PWM5DCH = 0x02;
    PWM5DCL = 0xC0;
    PWM5CONbits.PWM5POL = 0; // PWM output is active HIGH
    PWM5CONbits.PWM5EN = 1; // Enable PWM5
}