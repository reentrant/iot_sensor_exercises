#include "main.h"

void PORTS_Init(void) {
    
    //ANSEL
    ANSELA = 0x30; 
    ANSELB = 0;
    ANSELC = 0;

    //TRIS
    TRISCbits.TRISC3 = 0; //CLC1 OUT
    
    TRISCbits.TRISC1 = 0; //TX --> BLUETOOTH RX
    TRISCbits.TRISC0 = 1; //RX <-- BLUETOOTH TX
    
    TRISCbits.TRISC4 = 1; //NCO out
    TRISCbits.TRISC5 = 0; //Piezo B
    
    TRISBbits.TRISB4 = 1; //SDA
    TRISBbits.TRISB6 = 1; //SCL

    TRISBbits.TRISB5 = 1; // IOC switch 2
    TRISBbits.TRISB7 = 1; // IOC switch 3

    TRISCbits.TRISC6 = 0; //CMD/MLDP
    TRISCbits.TRISC2 = 0; //SW Wake
    TRISAbits.TRISA2 = 0; //HW Wake
    
    //LATS
    LATCbits.LATC5 = 1;
    LATAbits.LATA2 = 0;
    LATCbits.LATC6 = 0;
    LATCbits.LATC2 = 0;

    //PPS: Peripheral Pin Select
    RC3PPSbits.RC3PPS = 0b00100; // CLC1OUT on RC3
    RC5PPSbits.RC5PPS = 0b00101; // CLC2OUT on RC5
    RC1PPSbits.RC1PPS = 0b10100; //TX
    RC4PPSbits.RC4PPS = 0b11101; //NCO OUT
    RB4PPSbits.RB4PPS = 0b11011; //SDA2
    RB6PPSbits.RB6PPS = 0b11010; //SCL2
    SSP2CLKPPSbits.SSP2CLKPPS = 0b01110; //SCL2
    SSP2DATPPSbits.SSP2DATPPS = 0b01100; //SDA2        
    RXPPSbits.RXPPS = 0b10000;
}
