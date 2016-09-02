#include "main.h"
/*
 * Description: BMA222E: 8 bit, digital, triaxial acceleration sensor.
 * 
 * Setup Initial Values to BMA222E 
 * Register 0x00 Contains the CHIP ID
 * Register 0x0F allows the selection of the accelerometer g-range
 * Register 0x10 allows the selection of the acceleration data filter bandwidth.
 * Register 0x11 allows the selection of the main power modes
 * Register 0x13: bit 7: data_high_bw: configures the acceleration data 
 *                       acquisition and data output format.
 *                bit 6: shadow_dis: When shadowing is enabled, the MSB must be
 *                       always be read in order to remove the data lock.
 *                       With shadowing disabled, the contents of both MSB and
 *                       LSB registers is updated by a new value immediately.
 */
void BMA222E_Init(void) {
    I2C_Temp = I2C_Read8(BMA, 0x00); //Check device ID
    I2C_Write8(BMA, 0x0F, 0x03); //+/-2g
    I2C_Write8(BMA, 0x10, 0x0F); //1kHz data filter bandwidth
    I2C_Write8(BMA, 0x11, 0x00); //Normal Power mode
    I2C_Write8(BMA, 0x13, 0x00); //filtered data and shadowed enabled.
    NOP();
}


/**
 * Description: The width of acceleration dat is 8 bits given in two's 
 *              complement representation. The 8 bit data word for each axis is 
 *              contained in the MSB of the  acceleration data output registers
 *              0x3, 0x5, 0x7.
 *              READ_ACCEL() reads the current accelerometer raw values.
 *              Resolution: 15.63 mg/LSB
 */
void READ_ACCEL(void) {
#ifdef ACCELEROMETER
    unsigned char x_flag = 0, y_flag = 0, z_flag = 0;
    //Shadowing Procedure
    x_flag = I2C_Read8(BMA, 0x02);
    ACCL_X = (int8_t) (1 + ~I2C_Read8(BMA, 0x03)); //read X axis
    y_flag = I2C_Read8(BMA, 0x04);
    ACCL_Y = (int8_t) (1 + ~I2C_Read8(BMA, 0x05)); //read Y axis  
    z_flag = I2C_Read8(BMA, 0x06);
    ACCL_Z = (int8_t) (1 + ~I2C_Read8(BMA, 0x07)); //read Z axis  
#else
    signed char i2c_value, two_complement;
    float temperature = 0.0;
    i2c_value = I2C_Read8(BMA, 0x08);// Just change from unsigned to signed
    two_complement = (char) (1 + ~I2C_Read8(BMA, 0x08));
    temperature = 23 + (two_complement >> 1);// Offset = 23C, resolut = 0.5C/LSB 
    sprintf(s, "BMA222E: 8 bit Temperature: %d Celsius\r\n", (int) temperature);
    USARTWriteString(s);
    sprintf(s, "i2c value: %d \t 2' = %d \r\n", i2c_value, two_complement);
    USARTWriteString(s);
    sprintf(s, "\r\n");
    USARTWriteString(s);
#endif
}

/*
 * 
 * HISTORY:
 * -----------------------------------------------------------------------------
 * AUTHOR   TICKET   DATE         DESCRIPTION
 * -----------------------------------------------------------------------------
 * JRA              04-14/2016   Translate Accelerometer values from its 
 *                               unsigned two's complement format in the
 *                               READ_ACCEL() function to signed.
 */
