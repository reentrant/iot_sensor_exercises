#include "main.h"

void UART_Init(void) {
    TXSTAbits.TX9 = 0; // select 8 data bits
    TXSTAbits.TXEN = 1; // enable transmit
    TXSTAbits.SYNC = 0; // -> configures the EUSART1 for asynchronous operation.

    RCSTAbits.SPEN = 1; // serial port is enabled
    RCSTAbits.RX9 = 0; // select 8 data bits

    RCSTAbits.CREN = 1; // receive enabled

    //SPBRG = 16; // here is calculated value of SPBRGH and SPBRGL 115200 @ 32MHz FOSC
    SPBRG = 207; // here is calculated value of SPBRGH and SPBRGL 9600 @ 32MHz FOSC
    TXSTAbits.BRGH = 1; // -> 
    BRG16 = 0;          // -> 

    PIR1bits.RCIF = 0; // make sure receive interrupt flag is clear
    PIE1bits.RCIE = 0; // enable UART Receive interrupt
    INTCONbits.PEIE = 1; // Enable peripheral interrupt
    INTCONbits.GIE = 1; // enable global interrupt
}

void USARTWriteString(const char *str) {
    while (*str != '\0') {
        USARTWriteChar(*str);
        str++;
    }
}

void USARTWriteChar(char ch) {
    while (!PIR1bits.TXIF);

    TXREG = ch;
}

uint8_t USARTReadChar(void) {
    /* retrieve one byte */
    while (!RCIF) /* set when register is not empty */
        continue;
    return RCREG;
}

