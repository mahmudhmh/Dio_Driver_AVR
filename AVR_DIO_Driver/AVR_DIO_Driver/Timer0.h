#ifndef TIMER0_H_
#define TIMER0_H_

#define NoClock 0 
#define Clock_1024 5
#include "STD_Types.h"
void Timer0_StartNormal(uint8 StartValue,uint8 Prescaler);
void Timer0_StartCTC(uint8 CompareValue,uint8 Prescaler);
void Timer0_OVF_CB(void) ;
void Timer0_CMP_CB(void) ;

#endif /* TIMER0_H_ */