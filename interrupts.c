#include "main.h"

void interrupt ISR(void) {

    if (PIR1bits.RCIF == 1) {
        if (1 == RC1STAbits.OERR) {
            // EUSART error - restart

            RC1STAbits.CREN = 0;
            RC1STAbits.CREN = 1;
        }

        if (RCREG == '%') { //BUTTON1 PRRESS
            PIR0bits.IOCIF = 1;
            IOCBFbits.IOCBF5 = 1;
        }

        if (RCREG == '#') { //BUTTON2 PRRESS
            PIR0bits.IOCIF = 1;
            IOCBFbits.IOCBF7 = 1;
        }

        if (RCREG == '$') { //Send requested data
            //CalcTEMP9700(); //Get temperature
            Temp9700Read();
            CalcVBattery(); //Get batter voltage
            TRISCbits.TRISC4 = 0; //NCO on
            NCO1INCL = 10;

            sprintf(s, "@%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, ", G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4, B4, G5, R5, B5); //LED data
            USARTWriteString(s);
            sprintf(s, "%d, %d, %d, %d\r\n", (int8_t) Roll, (int8_t) Pitch, (int8_t) TEMP_F, BATTV); //XYZ, TEMP & BAT
            USARTWriteString(s);


            TRISCbits.TRISC4 = 1; //NCO off
            TRISCbits.TRISC5 = 1;
        }
    }

    if (PIR1bits.TMR1IF == 1) {
        TMR1_StopTimer();
        TRISCbits.TRISC4 = 1; //NCO Off
        TRISCbits.TRISC5 = 1;
        //TMR1H 223; 
        TMR1H = 0xEF;
        //TMR1L 0; 
        TMR1L = 0x00;
        // Load the TMR value to reload variable
        timer1ReloadVal = (TMR1H << 8) | TMR1L;
        PIR1bits.TMR1IF = 0;

    }

    if (PIR0bits.IOCIF) {
        if (IOCBFbits.IOCBF5) // Switch 2
        {
            MENU++;
            __delay_ms(250);
            MENU %= 4;
            IOCBFbits.IOCBF5 = 0; // Clear flag

        }
        if (IOCBFbits.IOCBF7) // Switch 3
        {
            NCO1CONbits.N1EN ^= 1;
            __delay_ms(250);
            IOCBFbits.IOCBF7 = 0; // Clear flag
        }
    }


}

