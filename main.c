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

#define NUM_TESTS   4

static const uint16_t test[NUM_TESTS] = {0x0f64, 0x0fff, 0x2c, 0 };
static const int16_t  expect[NUM_TESTS] = {-156, -1, 44, 0 };

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
    
    Clear_LEDs();
    
    //Configure accelerometer
    BMA222E_Init();
#ifdef BLUETOOTH
    //Configure RN4020 BLE
    RN4020_Init();
    Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4, B4, G5, R5, B5 = 200);
#endif
    
    //Configure interrupt-on-change.
    IOC_Init();
#ifndef EMBEDDED_C__EX1_SIGNED_INTEGERS
    int n_errors = 0;
    
    sprintf(s, "\r\nBootCamp!!!\r\n");
    USARTWriteString(s);
    sprintf(s, "char size: %d bytes\r\n", sizeof(char));
    USARTWriteString(s);
    sprintf(s, "short size: %d bytes\r\n", sizeof(short));
    USARTWriteString(s);
    sprintf(s, "int  size: %d bytes\r\n", sizeof(int));// 2 bytes
    USARTWriteString(s);
    sprintf(s, "long size: %d bytes\r\n", sizeof(long));
    USARTWriteString(s);
    sprintf(s, "\r\n");
    USARTWriteString(s);
    READ_ACCEL();
    

    for (int i = 0; i < NUM_TESTS; ++i)
    {
        if (expect[i] != signextend(test[i]))
        {
            n_errors++;
        }
    }

    // Set the output pattern.
    if (n_errors > 0)
    {
        // Turn on red LED5.
        Load_LEDS(G1 = 0, R1 = 0, B1 = 0,
            G2 = 0, R2 = 0, B2 = 0, 
            G3 = 0, R3 = 0, B3 = 0, 
            G4 = 0, R4 = 0, B4 = 0, 
            G5 = 0, R5 = 128, B5 = 0);

        for (;;)
        {
            // Do nothing.
        }
    }
    else
#endif
    while (1) { //Main program loop
        switch (MENU) {
            case 0:
            {
                LED_sequence();//TILT();
                break;
            }
            case 1:
            {
#ifdef FADE_PROGRAM_2000_WORDS
                FADE();
#endif
                break;
            }
            case 2:
            {
#ifdef SQUEAKY_PROGRAM_2000_WORDS
                SQUEAKY();
#endif
                break;
            }
            case 3:
            {
#ifdef DOUBLE_TAP_PROGRAM_2000_WORDS
                DOUBLE_TAP();
#endif
                break;
            }
        }//switch
    }// while(1))
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
 * JRA              09-02-2016   Added the Bootcamp exercise1 using bitwise
 *                               operators in signextend()
 */
