#include "main.h"

void ADC_Init(void) {
    ADCON0bits.ADON = 0; // ADC disabled for now
    ADCON1bits.ADFM = 1; // Right justified
    ADCON1bits.ADCS = 0b010; //Select Chan
    ADRESH = 0x00; // Clear
    ADRESL = 0x00; // Clear
}
/*
 * Description: The Analog-to-Digital Converter (ADC) allows conversion of an 
 *              analog input signal to a 10-bit binary representation of that 
 *              signal.
 * Output: ADRES: 10 bits width.
 */
float ADC_Convert(void) {

    //Start Conversion
    GO_nDONE = 1;
    while (GO_nDONE);
    Volts = (ADRES * 0.003222);
    return Volts;
}