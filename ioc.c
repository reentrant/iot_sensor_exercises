#include "main.h"

void IOC_Init(void) {
    IOCBNbits.IOCBN5 = 1; // Negative edge IOC enabled RB5
    IOCBNbits.IOCBN7 = 1; // Negative edge IOC enabled RB7
    IOCBFbits.IOCBF5 = 0; // Clear IOC flag
    IOCBFbits.IOCBF7 = 0; // Clear IOC flag
    PIE0bits.IOCIE = 1; // Enable IOC interrupts
}


