/* 
 * File:   BMA222E.h
 * Author: C13066
 *
 * Created on September 8, 2015, 11:33 AM
 */

//Defines
#define BMA 0x30 //Defice I2C address


//Functions
void BMA222E_Init(void);
void READ_ACCEL(void);

//Global Vars
int8_t ACCL_X;
int8_t ACCL_Y;
int8_t ACCL_Z;

//END OF FILE
