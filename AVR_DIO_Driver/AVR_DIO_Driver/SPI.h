#ifndef SPI_H_
#define SPI_H_
#include "STD_Types.h"
#include <avr/io.h>
#define MOSI PINB5
#define MISO PINB6
#define SS   PINB4
#define SCK  PINB7
#define MASTER 1
#define SLAVE 0
#define Invalid -1
#define SPIMODE SLAVE


ReturnValueType SPI_Init(void);
#if (SPIMODE == MASTER)
ReturnValueType SPI_SingleSendReceive(uint8 U8SendData,uint8* ReceivedData);
ReturnValueType SPI_BrustSendReceive(uint8* U8SendData,uint8* ReceivedData,uint8 BytesNumber);
#endif




#endif /* SPI_H_ */