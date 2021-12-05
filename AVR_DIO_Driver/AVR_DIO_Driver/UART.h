#ifndef UART_H_
#define UART_H_
#include "STD_Types.h"
#define BuadRate 9600UL
#define CalculatedBaudRate (16000000UL/(16*BuadRate)-1)
ReturnValueType UART_Init(void);
ReturnValueType UART_SendChar(uint8 U8Data);
ReturnValueType UART_SendString(uint8* U8Data);
ReturnValueType UART_Receive(uint8* U8Data);


#endif /* UART_H_ */