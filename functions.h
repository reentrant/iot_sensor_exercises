/* 
 * File:   functions.h
 * Author: C13066
 *
 * Created on September 8, 2015, 1:19 PM
 */

//Defines


//Functions
void TILT(void);
void FADE(void);
void SQUEAKY(void);
void DOUBLE_TAP(void);

void Check_x(void);
void Check_y(void);
void Check_z(void);
void LED_sequence(void);
void motion_detection(void);
void axis_detection(void);
void sleep_seconds(int );
#ifndef EMBEDDED_C_SIGNED_INTEGERS
int16_t signextend(uint16_t);
#endif
//Global Vars
uint8_t Fade;
int8_t DRoll, DPitch;
float Gx, Gy, Gz;
float Gs[3];
uint8_t Flag1, Flag2, Flag3, Flag4;
uint8_t Delay;

/*
 * HISTORY:
 * -----------------------------------------------------------------------------
 * AUTHOR   TICKET   DATE         DESCRIPTION
 * -----------------------------------------------------------------------------
 * JRA               03-07-2016   Added LED_sequence()
 * JRA               03-08-2016   Added sleep_seconds()
 * JRA               09-02-2016   Added signextend()
 */
 