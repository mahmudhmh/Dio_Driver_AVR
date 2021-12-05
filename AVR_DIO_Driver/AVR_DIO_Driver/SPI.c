
#include "Dio.h"
#include <avr/io.h>
#include "SPI.h"


#if (SPIMODE == SLAVE)
#include <avr/interrupt.h>
	uint8 SPI_Slave_DataReceived = 0 ;
	uint8 SPI_Slave_DataSend = 0x5A ;
#endif

ReturnValueType SPI_Init(void)
{
	#if (SPIMODE == MASTER)
	Dio_PinSetDirection(B,MOSI,PinOutput);
	Dio_PinSetDirection(B,MISO,PinInput);
	Dio_PinSetDirection(B,SCK,PinOutput);
	Dio_PinSetDirection(B,SS,PinOutput);
	Dio_PinWrite(B,SS,PinHigh);
	SPCR = (1<<SPE) | (1<<MSTR) | (1<<SPR0);
	#endif
	
	#if ((SPIMODE == SLAVE))
	Dio_PinSetDirection(B,MOSI,PinInput);
	Dio_PinSetDirection(B,MISO,PinOutput);
	Dio_PinSetDirection(B,SCK,PinInput);
	Dio_PinSetDirection(B,SS,PinInput);
	Dio_PinPullupState(B,SS,Active);
	SPCR = (1<<SPE) ;
	ClearBit (SPCR,MSTR);
	SPDR = 0x00;
	#endif

	return OK;
	
}
#if (SPIMODE == MASTER)
ReturnValueType SPI_SingleSendReceive(uint8 U8SendData,uint8* ReceivedData)
{
	Dio_PinWrite(B,SS,PinLow);
	SPDR = U8SendData ;
	while (!GetBit(SPSR,SPIF));
	*ReceivedData=SPDR ;
	Dio_PinWrite(B,SS,PinHigh);
	return OK;
}

ReturnValueType SPI_BrustSendReceive(uint8* U8SendData,uint8* ReceivedData,uint8 BytesNumber)
{
	uint8 i = 0 ;
	for (i=0;i<BytesNumber;i++)
	{
		SPI_SingleSendReceive(*U8SendData++,ReceivedData++);
	}
	return OK;
}
#endif

#if (SPIMODE == SLAVE)
ISR(SPI_STC_vect)
{
	SPI_Slave_DataReceived = SPDR;
	SPDR = SPI_Slave_DataSend;
	
}
#endif