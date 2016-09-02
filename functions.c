#include <assert.h>
#include "main.h"

uint8_t state = 0;

#ifdef TILT_PROGRAM_2000_WORDS
void TILT(void) {

    while (MENU == 0) {
        READ_ACCEL();
        CalcEulerAngles();

        DRoll = (int8_t) Roll;
        DPitch = (int8_t) Pitch;

        if (abs(DPitch) >= abs(DRoll)) {
            DRoll = 0;
        } else {
            DPitch = 0;
        }

        //            
        if (DPitch < -0) {
            G3 = abs(DPitch);
            G1 = B5 = B2 = B4 = G5 = 0;
            R5 = 50 - G3;
            if (R5 > 50) {
                R5 = 0;
            }
            Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4, B4, G5, R5, B5);
            if (Flag1 == 1 && abs(DPitch) > 15) {
                NCO_Ping(80);
                Flag2 = Flag3 = Flag4 = 1;
                Flag1 = 0;
            }

        }
        if (DPitch > 0) {
            G1 = abs(DPitch);
            G3 = B5 = B2 = B4 = G5 = 0;
            R5 = 50 - G1;
            if (R5 > 50) {
                R5 = 0;
            }

            Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4, B4, G5, R5, B5);
            if (Flag2 == 1 && abs(DPitch) > 15) {
                NCO_Ping(90);
                Flag1 = Flag3 = Flag4 = 1;
                Flag2 = 0;
            }

        }

        if (DRoll < 0.0) {
            B2 = abs(DRoll);
            B4 = B5 = G3 = G1 = G5 = 0;
            R5 = 50 - B2;
            if (R5 > 50) {
                R5 = 0;
            }
            Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4, B4, G5, R5, B5);
            if (Flag3 == 1 && abs(DRoll) > 15) {
                NCO_Ping(100);
                Flag1 = Flag2 = Flag4 = 1;
                Flag3 = 0;
            }

        }
        if (DRoll > 0.0) {
            B4 = abs(DRoll);
            B2 = B5 = G3 = G1 = G5 = 0;
            R5 = 50 - B4;
            if (R5 > 50) {
                R5 = 0;
            }
            Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4, B4, G5, R5, B5);
            if (Flag4 == 1 && abs(DRoll) > 15) {
                NCO_Ping(110);
                Flag1 = Flag2 = Flag3 = 1;
                Flag4 = 0;
            }

        }

        if (DPitch < 6 && DPitch > -6 && DRoll < 6 && DRoll > -6) {
            G3 = G1 = B4 = B2 = R5 = 0;
            R5 = 40;
            Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4, B4, G5, R5, B5);
            Flag1 = Flag2 = Flag3 = Flag4 = 1;
        }

        __delay_ms(30);

        if (MENU != 0)break;
    }
    Clear_LEDs();

}
#endif

#ifdef FADE_PROGRAM_2000_WORDS
void FADE(void) {

    Roll = 0;
    Pitch = 0;

    do {

        G4 = 0;
        for (Fade = 0; Fade < 230; Fade++) {
            R5 = -Fade;
            G1 = Fade;
            Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4, B4, G5, R5, B5);
            __delay_ms(1);
            if (MENU != 1)break;

        }

        for (Fade = 0; Fade < 230; Fade++) {
            R5 = Fade;
            G1 = -Fade;
            Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4, B4, G5, R5, B5);
            __delay_ms(1);
            if (MENU != 1)break;
        }

        G1 = 0;

        for (Fade = 0; Fade < 230; Fade++) {
            R5 = -Fade;
            G2 = Fade;
            Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4, B4, G5, R5, B5);
            __delay_ms(1);
            if (MENU != 1)break;
        }

        for (Fade = 0; Fade < 230; Fade++) {
            R5 = Fade;
            G2 = -Fade;
            Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4, B4, G5, R5, B5);
            __delay_ms(1);
            if (MENU != 1)break;
        }

        G2 = 0;

        for (Fade = 0; Fade < 230; Fade++) {
            R5 = -Fade;
            G3 = Fade;
            Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4, B4, G5, R5, B5);
            __delay_ms(1);
            if (MENU != 1)break;
        }

        for (Fade = 0; Fade < 230; Fade++) {
            R5 = Fade;
            G3 = -Fade;
            Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4, B4, G5, R5, B5);
            __delay_ms(1);
            if (MENU != 1)break;
        }

        G3 = 0;

        for (Fade = 0; Fade < 230; Fade++) {
            R5 = -Fade;
            G4 = Fade;
            Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4, B4, G5, R5, B5);
            __delay_ms(1);
            if (MENU != 1)break;
        }

        for (Fade = 0; Fade < 230; Fade++) {
            R5 = Fade;
            G4 = -Fade;
            Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4, B4, G5, R5, B5);
            __delay_ms(1);
            if (MENU != 1)break;
        }
        if (MENU != 1)break;
    } while (MENU == 1);

    Clear_LEDs();
}
#endif

#ifdef SQUEAKY_PROGRAM_2000_WORDS
void SQUEAKY(void) {


    I2C_Write8(BMA, 0x0F, 0x0C); //+/-16g
    NCO1CONbits.N1EN = 1;
    TRISCbits.TRISC4 = 0; //NCO ON
    TRISCbits.TRISC5 = 0;
    while (1) {
        READ_ACCEL();
        Gx = abs(ACCL_X);
        Gy = abs(ACCL_Y);
        Gz = abs(ACCL_Z);

        Gs[0] = Gx;
        Gs[1] = Gy;
        Gs[2] = Gz;
        float max = Gs[0];

        for (int i = 0; i < 3; i++) {
            if (Gs[i] > max) {
                max = Gs[i];
            }
        }

        if (max > 9) {
            TRISCbits.TRISC4 = 0; //NCO ON
            TRISCbits.TRISC5 = 0;
            R1 = R2 = R3 = R4 = R5 = (uint8_t) max * 2;
            Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4, B4, G5, R5, B5);
            for (uint8_t Sounds = 10; Sounds > 0; Sounds++) {
                //                NCO1INCL = (uint8_t) max + 100;
                //                __delay_us(300);
                NCO1INCL = (uint8_t) max + 100;
            }
        } else {
            TRISCbits.TRISC4 = 1; //NCO OFF
            TRISCbits.TRISC5 = 1;
            NCO1INCL = 0;
            Clear_LEDs();
        }

        if (MENU != 2)break;
    }
    Clear_LEDs();
    I2C_Write8(BMA, 0x0F, 0x03); //+/-2g
    NCO1CONbits.N1EN = 0;
    TRISCbits.TRISC4 = 1; //NCO OFF
    TRISCbits.TRISC5 = 1;

}
#endif


#ifdef DOUBLE_TAP_PROGRAM_2000_WORDS
void DOUBLE_TAP(void) {
    I2C_Write8(BMA, 0x16, 0x10); //Enable Double and Single Tap
    I2C_Write8(BMA, 0x2A, 0xF5); //375ms Window
    I2C_Write8(BMA, 0x2B, 0x0A); //Threshold (Default)
    //Clear all flags and delays.
    Delay = 0;
    Fade = 0;
    Flag1 = 0;
    Flag2 = 0;

    NCO1CONbits.N1EN = 1; //Turn on NCO

    while (1) {
        I2C_Temp = I2C_Read8(BMA, 0x09); //read interrupt REG for double tap interrupt 
        Delay++;

        //Breath effect of Middle LED (Execute while loop X times before updating LED. 
        if (Delay > 110) {
            if (Flag1 == 0) {
                Fade++;
            } else if (Flag1 == 1) {
                Fade--;
            }

            if (Fade > 65) {
                Flag1 = 1;
            } else if (Fade < 5) {
                Flag1 = 0;
            }
            R5 = Fade;
            Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4, B4, G5, R5, B5);
            Delay = 0;
        }

        if (I2C_Temp == 16) { //16 == Double Tap Interrupt Flag
            TRISCbits.TRISC4 = 0; //NCO ON
            TRISCbits.TRISC5 = 0;
            Flag2 ^= 1; //Toggle segment execution direction CW or CCW

            //Segment 1
            if (Flag2 == 1) {
                G4 = 120;
                NCO1INCL = 64;
            } else {
                G4 = 120;
                NCO1INCL = 255;
            }
            Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4, B4, G5, R5, B5);
            __delay_ms(50);

            //Segment 2
            if (Flag2 == 1) {
                G1 = 90;
                G4 = 0;
                NCO1INCL = 128;
            } else {
                G3 = 90;
                G4 = 0;
                NCO1INCL = 194;
            }
            Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4, B4, G5, R5, B5);
            __delay_ms(50);

            //Segment 3
            if (Flag2 == 1) {
                G2 = 60;
                G1 = 0;
                NCO1INCL = 194;
            } else {
                G2 = 60;
                G3 = 0;
                NCO1INCL = 128;
            }
            Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4, B4, G5, R5, B5);
            __delay_ms(50);

            //Segment 4
            if (Flag2 == 1) {
                G3 = 30;
                G2 = 0;
                NCO1INCL = 255;
            } else {
                G1 = 30;
                G2 = 0;
                NCO1INCL = 64;
            }
            Load_LEDS(G1, R1, B1, G2, R2, B2, G3, R3, B3, G4, R4, B4, G5, R5, B5);
            __delay_ms(50);

            //Segments completed Turn off NCO and Clear LEDS
            Clear_LEDs();
            TRISCbits.TRISC4 = 1; //NCO OFF
            TRISCbits.TRISC5 = 1;
            NCO1INCL = 0;
        }
        if (MENU != 3)break;
    }
    I2C_Write8(BMA, 0x16, 0x00); //Disable Double Tap
    NCO1CONbits.N1EN = 0;
    TRISCbits.TRISC4 = 1; //NCO OFF
    TRISCbits.TRISC5 = 1;


}
#endif

void sleep_seconds(const int seconds)
{
    state = MENU;
    // Let the compiler check:
    char int_err [sizeof(int) == 2];
    // or at runtime:
    assert(seconds * 1000 < 32767);
    for (volatile int i = 0; i < seconds * 1000; i++ )
    // NOTE: The volatile keyword assures this loop won't optimize.
    {
        __delay_ms(1);// 1ms
        if (state != MENU) 
            break;
    }
}
/*
 * FUNCTION: LED_sequence
 * DESCRIPTION: It turns the LED 1 during 1 second, then the LED 1 second and 
 * so on up to the LED 5.
 */
void LED_sequence(void)
{
    state = MENU;
    Clear_LEDs();
    if (state != MENU) return;
    __delay_us(10);
    
    // LED 1: white
    Load_LEDS(G1 = 128, R1 = 128, B1 = 128,
            G2 = 0, R2 = 0, B2 = 0, 
            G3 = 0, R3 = 0, B3 = 0, 
            G4 = 0, R4 = 0, B4 = 0, 
            G5 = 0, R5 = 0, B5 = 0);
    sleep_seconds(1);

    // LED 2: Red
    Load_LEDS(G1 = 0, R1 = 0, B1 = 0, 
            G2 = 0, R2 = 128, B2 = 0, 
            G3 = 0, R3 = 0, B3 = 0, 
            G4 = 0, R4 = 0, B4 = 0, 
            G5 = 0, R5 = 0, B5 = 0);
    sleep_seconds(1);

    // LED 3: Green
    Load_LEDS(G1 = 0, R1 = 0, B1 = 0, 
            G2 = 0, R2 = 0, B2 = 0, 
            G3 = 128, R3 = 0, B3 = 0, 
            G4 = 0, R4 = 0, B4 = 0, 
            G5 = 0, R5 = 0, B5 = 0);
    sleep_seconds(1);

    // LED 4: Blue
    Load_LEDS(G1 = 0, R1 = 0, B1 = 0, 
            G2 = 0, R2 = 0, B2 = 0, 
            G3 = 0, R3 = 0, B3 = 0, 
            G4 = 0, R4 = 0, B4 = 128, 
            G5 = 0, R5 = 0, B5 = 0);
    sleep_seconds(1);

    // LED 5: Red
    Load_LEDS(G1 = 0, R1 = 0, B1 = 0,
            G2 = 0, R2 = 0, B2 = 0, 
            G3 = 0, R3 = 0, B3 = 0, 
            G4 = 0, R4 = 0, B4 = 0, 
            G5 = 0, R5 = 128, B5 = 0);
    sleep_seconds(1);
    return;
}

#ifdef MOTION_DETECTION_PROGRAM_2000_WORDS
/*
 * FUNCTION: motion_detection
 * DESCRIPTION: It detects the motion;
 * 
 */
void motion_detection(void)
{
    float vector;
    state = MENU;
    Clear_LEDs();
    while (MENU == state) {
        G1 = R1 = B1 = 0;
        G2 = R2 = B2 = 0;
        G3 = R3 = B3 = 0;
        G4 = R4 = B4 = 0;
        G5 = R5 = B5 = 0;
        
        READ_ACCEL();
        vector = sqrt(pow(ACCL_X, 2) + pow(ACCL_Y, 2) + pow(ACCL_Z, 2));
        if (vector < 50)
        {
            R1 = R2 = R3 = R4 = 0;
        }
        else if (vector < 100 && vector > 50)
        {
            if (vector < 60)
            {
                R1 = 128;
            }
            else if (vector < 70)
            {
                R1 = R2 = 128;
#ifdef TEST
                if (ACCL_X > 0)
                {
                    if (ACCL_X < 50)
                    {
                        R5 = 128;
                    }
                    else
                    {
                        R1 = R3 = R5 = 128;
                    }
                }
                else
                {
                    if (ACCL_X > -50)
                    {
                        R5 = 128;
                    }
                    else
                    {
                        R2 = R4 = R5 = 128;
                    }            
                }
                if (ACCL_Y > 0)
                {
                    if (ACCL_Y < 50)
                    {
                        G5 = 128;
                    }
                    else
                    {
                        G1 = G3 = G5 = 128;
                    }
                }
                else
                {
                    if (ACCL_Y > -50)
                    {
                        G5 = 128;
                    }
                    else
                    {
                        G2 = G4 = G5 = 128;
                    }            
                }
                if (ACCL_Z > 0)
                {
                    if (ACCL_Z < 50)
                    {
                        B5 = 128;
                    }
                    else
                    {
                        B1 = B3 = B5 = 128;
                    }
                }
                else
                {
                    if (ACCL_Z > -50)
                    {
                        B5 = 128;
                    }
                    else
                    {
                        B2 = B4 = B5 = 128;
                    }            
                }
#endif
            }
            else if (vector < 80)
            {
                R1 = R2 = R3 = 128;
            }
            else if (vector < 90) 
            {
                R1 = R2 = R3 = R4 = 128;
            }
            else
            {
                R1 = R2 = R3 = R4 = R5 = 128;
            }
                
        }
        else if (vector < 140 && vector > 100)
        {
            if (vector < 110)
            {
                B1 = 128;
            }
            else if (vector < 120)
            {
                B1 = B2 = 128;
            }
            else if (vector < 130)
            {
                B1 = B2 = B3 = 128;
            }
            else
            {
                B1 = B2 = B3 = B4 = 128;
            }
        }
        else if (vector < 180 && vector > 140)
        {
            G1 = G2 = G3 = G4 = 128;
        }
        else if (vector < 220 && vector > 180)
        {
            R1 = R2 = R3 = R4 = 128;
            B1 = B2 = B3 = B4 = 128;
            G1 = G2 = G3 = G4 = 128;
        }
        else
        {
            R1 = R2 = R3 = R4 = R5 = 200;
            B1 = B2 = B3 = B4 = B5 = 200;
            G1 = G2 = G3 = G4 = G5 = 200;
        }
        Load_LEDS(  G1, R1, B1, 
                    G2, R2, B2, 
                    G3, R3, B3, 
                    G4, R4, B4, 
                    G5, R5, B5);
        __delay_ms(1);// 1ms
    }
}
#endif

#ifdef ACCEL_PROGRAM_2000_WORDS
/*
 * FUNCTION: axis_detection
 * DESCRIPTION: It detects the axis
 */
void axis_detection(void)
{
    state = MENU;
    Clear_LEDs();
    while (MENU == state) {
        G1 = R1 = B1 = 0;
        G2 = R2 = B2 = 0;
        G3 = R3 = B3 = 0;
        G4 = R4 = B4 = 0;
        G5 = R5 = B5 = 0;
        READ_ACCEL();
        if (ACCL_Y > 0)
        {
            if (ACCL_Y < 50)
            {
                G5 = 128;
            }
            else
            {
                G1 = G3 = G5 = 128;
            }
        }
        else
        {
            if (ACCL_Y > -50)
            {
                G5 = 128;
            }
            else
            {
                G2 = G4 = G5 = 128;
            }            
        }      
        __delay_ms(1);// 1ms
    }
}
#endif


#ifndef EMBEDDED_C_SIGNED_INTEGERS
/*!
* @brief Sign extend a signed 12-bit value to a signed 16-bit value.
*
* @param[in] input A 12-bit signed value, in 2's complement format.
*
* @return int16_t A 16-bit signed value, in 2's complement format.
*/
int16_t signextend(uint16_t input)
{
   int16_t  output;
   // NOTE: There?s good info on the 2?s complement representation of signed
   // integers at: http://en.wikipedia.org/wiki/Two's_complement.
   // Here only the least significant 12-bits are properly formatted as 2?s
   // complement. The upper 4 bits are garbage that your code needs to modify.
   
   const uint16_t sign_12bit = 0x0800;
   const uint16_t sign_16bit = 0x8000;
   
   if (input & sign_12bit)
   {
       // it is negative
              output = input | 0xF000;
   }
   else
   {
       // it is positive
       // 1st. Clear garbage:
       output = input & 0x0FFF;
   }

   return (output);
}
#endif

/*
 * HISTORY:
 * -----------------------------------------------------------------------------
 * AUTHOR   TICKET   DATE         DESCRIPTION
 * -----------------------------------------------------------------------------
 * JRA              03-07-2016   Added LED_sequence()
 * JRA              03-08-2016   Added sleep_seconds() 
 * JRA              03-09-2016   Added motion_detection()
 * JRA              08-29-2016   Activate in the code LED_Sequence();
 * JRA              09-02-2016   Added int16_t signextend(uint16_t); 
 */

