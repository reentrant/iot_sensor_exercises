#include "main.h"

void BMA222E_Init(void) {
    I2C_Temp = I2C_Read8(BMA, 0x00); //Check device ID, will add more later
    I2C_Write8(BMA, 0x0F, 0x03); //+/-2g
    I2C_Write8(BMA, 0x10, 0x0F); //1kHz data filer bandwidth
    I2C_Write8(BMA, 0x11, 0x00); //Normal Power mode
    I2C_Write8(BMA, 0x13, 0x00); //filered data and shadowed
    NOP();
}

void READ_ACCEL(void) {
    ACCL_X = I2C_Read8(BMA, 0x03); //read X axis 
    ACCL_Y = I2C_Read8(BMA, 0x05); //read Y axis  
    ACCL_Z = I2C_Read8(BMA, 0x07); //read Z axis  
}
