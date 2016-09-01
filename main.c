/* 
 * File:   main.c
 * Author: Willem J Smit, Chris Best
 * Willem.JSmit@microchip.com
 * Christopher.Best@microchip.com
 * Created in June 2015
 */
#include <assert.h>
//Includes
#include "main.h"

int main() {
    
    //Configure internal MCU modules
    PORTS_Init();
    PWM5_Init();
    TMR1_Init();
    TMR2_Init();
    SPI_Init();
    I2C_Init();
    UART_Init();
    CLC1_Init();
    CLC2_Init();
    ADC_Init();
    NCO_Init();
    
    //Clear LEDS
    Clear_LEDs();
    
    //Configure accelerometer
    BMA222E_Init();
    Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4, B4, G5, R5, B5 = 200);
#ifdef BLUETOOTH
    //Configure RN4020 BLE
    RN4020_Init();
#endif
    Clear_LEDs();
    
    //Configure interrupt-on-change.
    IOC_Init();

    while (1) { //Main program loop
        switch (MENU) {
            case 0:
            {
                
                LED_sequence();//motion_detection();//TILT();
                break;
            }
            case 1:
            {
                FADE();
                break;
            }
            case 2:
            {
                axis_detection();////SQUEAKY();
                break;
            }
            case 3:
            {
                LED_sequence();//DOUBLE_TAP();
                break;
            }
        }
    }
    return 0;
}





/*
 * 
 * HISTORY:
 * -----------------------------------------------------------------------------
 * AUTHOR   TICKET   DATE         DESCRIPTION
 * ----------------------------------------------------------------------------- 
 * JRA              04-13-2016   Added conditional define PROGRAM_2000_WORDS
 *                               to avoid memory constraints.
 * JRA              04-14-2016   Added definition for any_motion_detection()
 * JRA              08-29-2016   Activate in the code LED_Sequence(); 
 */
