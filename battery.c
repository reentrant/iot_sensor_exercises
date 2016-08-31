#include "main.h"

void CalcVBattery(void) {
    ADCON0bits.ADON = 1; // turn on ADC
    ADCON0bits.CHS = 0x04; // Selects channel to read
    __delay_us(10);
    ADC_Convert(); 
    BATTV_F = Volts*100;
    BATTV = ((uint16_t) BATTV_F); //Shift 2 decimal places and cast and move into 16U  
    ADCON0bits.ADON = 0; // turn on ADC
}
