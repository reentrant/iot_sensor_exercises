#include "main.h"

void I2C_Init(void) {

    SSP2ADD = 0x12; //Clock ~400KHz with 32MHz FOCS
    SSP2CON1 = 0b00001000;
    SSP2CON2 = 0;
    SSP2CON1bits.SSPEN = 1;
}

uint8_t I2C_Read8(uint8_t address, uint8_t RegADDR) {

    uint8_t DATA;

    while (!Idle); /* Don't start unless the MSSP module is idle */

    I2C_Start = 1; /* Set START bit */
    while (I2C_Start); /* Wait until hardware clears the SEN bit */

    SSP2BUF = address;
    while (!Idle);

    SSP2BUF = RegADDR;
    while (!Idle);

    I2C_Restart = 1;
    while (I2C_Restart);

    SSP2BUF = (address | 0x01);
    while (!Idle);

    SSP2CON2bits.RCEN = 1; /* Set Receive Enable bit (Master as a receiver) */
    while (!Idle);

    DATA = SSP2BUF;

    SSP2CON2bits.ACKDT = 1; /* Acknowledge bit, 0 = acknowledge uint8_t received */
    SSP2CON2bits.ACKEN = 1; /* Start Acknowledge sequence */
    while (SSP2CON2bits.ACKEN); /* Wait for end of acknowledge sequence */
    SSP2CON2bits.ACKDT = 0; /* Acknowledge bit, 0 = acknowledge uint8_t received */

    I2C_Stop = 1; /* Set STOP bit */
    while (!Idle); /* Wait while STOP condition established */

    return DATA;
}

void I2C_Write8(uint8_t address, uint8_t RegADDR, uint8_t val) {

    while (!Idle); /* Don't start unless the MSSP module is idle */

    I2C_Start = 1; /* Set START bit */
    while (I2C_Start); /* Wait until hardware clears the SEN bit */

    SSP2BUF = address;
    while (!Idle);

    SSP2BUF = (RegADDR | 0x80);
    while (!Idle);

    SSP2BUF = val;
    while (!Idle);

    I2C_Stop = 1; /* Set STOP bit */
    while (!Idle); /* Wait while STOP condition established */

}
