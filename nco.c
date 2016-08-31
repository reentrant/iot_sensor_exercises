#include "main.h"

void NCO_Init(void) {

    NCO1CONbits.N1PFM = 0; //NCO1 operates in Fixed Duty Cycle mode, divide by 2
    NCO1CONbits.N1EN = 0; //NCO1 module is disabled

    //NCO1CLKbits.N1PWS = 0b011; //NCO1 output is active for 8 input clock periods
    NCO1CLKbits.N1CKS = 0b00; //16MHz

    NCO1INCL = 100;
}

void NCO_Ping(uint8_t NCOLoad) {

    TMR1_StartTimer();
    if (NCO1CONbits.N1EN == 0) {
        TRISCbits.TRISC4 = 1; //NCO OFF
        TRISCbits.TRISC5 = 1;
    } else {
        TRISCbits.TRISC4 = 0; //NCO on
        TRISCbits.TRISC5 = 0;
    }
    NCO1INCL = NCOLoad;

}
