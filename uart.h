/* 
 * File:   uart.h
 * Author: C13066
 *
 * Created on September 8, 2015, 11:08 AM
 */



//Defines


//Functions
void UART_Init(void);
void USARTWriteString(const char *str);
void USARTWriteChar(char ch);
uint8_t USARTReadChar(void);

//Global Vars
char s[100]; //UART SEND STRING


//END OF FILE



