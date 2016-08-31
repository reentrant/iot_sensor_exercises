/* 
 * File:   ports.h
 * Author: C13066
 *
 * Created on September 8, 2015, 10:46 AM
 */



//Defines
#define MLDP            LATC6
#define SW_WAKE         LATC2
#define HW_WAKE         LATAbits.LATA2

//Functions
void PORTS_Init(void);

//END OF FILE
