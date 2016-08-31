#include "main.h"

void TMR2_Init(void) {
    TMR2 = 0x00; // Clear TMR2
    PR2 = 0x04; 
    T2CONbits.TMR2ON = 1; // Enable TMR2  
}

void TMR1_Init(void) {
    //Set the Timer to the options selected in the GUI

    //nT1SYNC do_not_synchronize; T1CKPS 1:1; TMR1CS LFINTOSC; TMR1ON disabled; 
    T1CON = 0xC4;

    //T1GVAL disabled; T1GSPM disabled; T1GSS T1G; T1GTM disabled; T1GPOL low; T1GGO_nDONE done; TMR1GE disabled; 
    T1GCON = 0x00;

    //TMR1H 223; 
    TMR1H = 0xDF;

    //TMR1L 0; 
    TMR1L = 0x00;

    // Load the TMR value to reload variable
    timer1ReloadVal = (TMR1H << 8) | TMR1L;

    PIE1bits.TMR1IE = 1; //Enable TMR1 interrupt

    // Clearing IF flag.
    PIR1bits.TMR1IF = 0;

    // Start TMR1
    TMR1_StartTimer();
}

void TMR1_StartTimer(void) {
    // Start the Timer by writing to TMRxON bit
    T1CONbits.TMR1ON = 1;
}

void TMR1_StopTimer(void) {
    // Stop the Timer by writing to TMRxON bit
    T1CONbits.TMR1ON = 0;
}

void TMR1_Reload(void) {
    //Write to the Timer1 register
    TMR1H = (timer1ReloadVal >> 8);
    TMR1L = timer1ReloadVal;
}
