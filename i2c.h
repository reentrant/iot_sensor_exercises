/* 
 * File:   i2c.h
 * Author: C13066
 *
 * Created on September 8, 2015, 11:19 AM
 */

//Global Vars
int8_t I2C_Temp;

//Defines
#define Idle        !(SSP2STATbits.R_nW | (0x1F & SSP2CON2))
#define I2C_Start   (SSP2CON2bits.SEN)  /* I2C start */
#define I2C_Restart (SSP2CON2bits.RSEN)
#define I2C_Stop    (SSP2CON2bits.PEN)  /* I2C stop */


//Functions
void I2C_Init(void);
uint8_t I2C_Read8(uint8_t address, uint8_t RegADDR);
void I2C_Write8(uint8_t address, uint8_t RegADDR, uint8_t val);


//END OF FILE

