#include "main.h"


void Temp9700Read(void) {

    ADCON0bits.ADON = 1; // turn on ADC
    ADCON0bits.CHS = 0b000101;
    __delay_us(10); // allow cap to charge
    ADC_Convert();
    ADCON0bits.ADON = 0; // turn off ADC

    Temperature = (Volts - 0.4);
    Temperature = Temperature / 0.0195;
    TEMP_F = (Temperature * 1.8) + 32.0; // temp in F

}
