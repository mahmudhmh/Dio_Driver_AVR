#ifndef SEVENSEGEMENT_H_
#define SEVENSEGEMENT_H_

#include "STD_Types.h"
#include "Bitwise.h"
#include "Dio.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#define EN1 2 //PB2
#define EN2 1 //PB1
#define EnablePort B
#define EnableMask 0x06
#define DataPort A
#define DataMask 0xF0
#define DataAlign 4
#define DataDecimalPort B
#define DataDecimalPin 3
typedef enum{CH1,CH2}SSChaneelType;
typedef enum{Disable,Enable}SSStateType;
void SevenSegement_Init(void);
ReturnValueType SevenSegement_State(SSChaneelType SSChaneel,SSStateType SSState);
ReturnValueType SevenSegement_Write(SSChaneelType SSChaneel,uint8 Value);
ReturnValueType SevenSegement_Refresh(void);




#endif /* SEVENSEGEMENT_H_ */