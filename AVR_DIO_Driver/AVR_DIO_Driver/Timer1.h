#ifndef TIMER1_H_
#define TIMER1_H_

#include "STD_Types.h"
void Timer1_StartNormal(uint16 StartValue,uint8 Prescaler);
void Timer1_StartCTC(uint16 CompareValue,uint8 Prescaler);
void Timer1_OVF_CB(void) ;
void Timer1_CMP_CB(void) ;
#define NoClock 0
#define Clock_1024 5


#endif /* TIMER1_H_ */