/* 
 * File:   WS2812B.h
 * Author: C13066
 *
 * Created on September 8, 2015, 12:31 PM
 */




//Functions
void Load_LEDS(uint8_t L1G, uint8_t L1R, uint8_t L1B, uint8_t L2G, uint8_t L2R, uint8_t L2B, uint8_t L3G, uint8_t L3R, uint8_t L3B, uint8_t L4G, uint8_t L4R, uint8_t L4B, uint8_t L5G, uint8_t L5R, uint8_t L5B);
void Clear_LEDs(void);

//Global Vars

//Variables used for LEDS////////////////////////////////////////////////////// 
//Order GREEN, RED & BLUE
 uint8_t _LED_String[15];
 uint8_t G1 = 0;
 uint8_t R1 = 0;
 uint8_t B1 = 0;

 uint8_t G2 = 0;
 uint8_t R2 = 0;
 uint8_t B2 = 0;

 uint8_t G3 = 0;
 uint8_t R3 = 0;
 uint8_t B3 = 0;

 uint8_t G4 = 0;
 uint8_t R4 = 0;
 uint8_t B4 = 0;

 uint8_t G5 = 0;
 uint8_t R5 = 0;
 uint8_t B5 = 0;

 uint8_t j;

//Defines





//END OF FILE



