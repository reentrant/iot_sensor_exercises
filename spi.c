#include "main.h"

void SPI_Init(void) {
    // SPI configuration
    SSP1CON1bits.CKP = 0; // Idle state for clock is LOW
    SSP1CON1bits.SSPM = 0b0011; // SPI Master mode, clock = T2_match/2
    SSP1CON3bits.BOEN = 1; // SSPBUF updates ignoring BF for daisy-chained operation
    SSP1CON1bits.SSPEN = 1; // Enable the MSSP module
}

