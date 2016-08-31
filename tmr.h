/* 
 * File:   tmr.h
 * Author: C13066
 *
 * Created on September 8, 2015, 10:58 AM
 */


//Defines
volatile uint16_t timer1ReloadVal;


//Functions
void TMR2_Init();
void TMR1_Init(void);
void TMR1_StartTimer(void);
void TMR1_StopTimer(void);


//END OF FILE
