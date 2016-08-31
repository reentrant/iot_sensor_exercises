#include "main.h"

void RN4020_Init(void) {

    MLDP = 1; //Set in MLDP mode
    SW_WAKE = 1;
    HW_WAKE = 1;

    if (PORTBbits.RB5 == 0) {

        sprintf(s, "\r\n");
        USARTWriteString(s);
        __delay_ms(100);

        for (uint8_t Toggle = 0; Toggle < 30; Toggle++) {
            Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4 = 200, B4, G5, R5, B5);
            __delay_ms(20);
            HW_WAKE ^= 1;
            Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4 = 0, B4, G5, R5, B5);
            __delay_ms(20);
        }
        HW_WAKE = 1;
        
    }

    MLDP = 0; //Set in CMD mode
    __delay_ms(100);
    MLDP = 1; //Set in MLDP mode
    

    sprintf(s, "\r\n");
    USARTWriteString(s);
    __delay_ms(5);

    sprintf(s, "+\r");
    USARTWriteString(s);
    __delay_ms(600);

    sprintf(s, "SF,1\r");
    USARTWriteString(s);
    __delay_ms(500);

    sprintf(s, "SR,10060800\r");
    USARTWriteString(s);
    __delay_ms(500);


    sprintf(s, "SS,00000001\r");
    USARTWriteString(s);
    __delay_ms(500);

    sprintf(s, "SN,IoTBadge\r");
    USARTWriteString(s);
    __delay_ms(1000);

    sprintf(s, "R,1\r");
    USARTWriteString(s);
    __delay_ms(1500);

    sprintf(s, "A\r");
    USARTWriteString(s);
    __delay_ms(500);


    MLDP = 1; //Set in MLDP mode
   

    PIE1bits.RCIE = 1; //Enable RX receive interrupt. 
}
