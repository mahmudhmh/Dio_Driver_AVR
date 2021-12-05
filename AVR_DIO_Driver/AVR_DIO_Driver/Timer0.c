#include "Timer0.h"
#include "STD_Types.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Bitwise.h"
void Timer0_StartNormal(uint8 StartValue,uint8 Prescaler)
{
	TCNT0 = StartValue ;
	SetBit(TIMSK,TOIE0) ;
	ClearBit(TCCR0,WGM00); ClearBit(TCCR0,WGM01) ; // NormalMode
	TCCR0 = (TCCR0 & ~0x07) | (Prescaler & 0x07);
	
}
void Timer0_StartCTC(uint8 CompareValue,uint8 Prescaler)
{
	OCR0 = CompareValue ;
	TCNT0 = 0 ;
	SetBit(TIMSK,OCIE0) ;
	ClearBit(TCCR0,WGM00); SetBit(TCCR0,WGM01) ; // CTCMode
	TCCR0 = (TCCR0 & ~0x07) | (Prescaler & 0x07);
}
void Timer0_OVF_CB(void) 
{
	
}
void Timer0_CMP_CB(void) 
{
	
}

ISR(TIMER0_OVF_vect)
{
	Timer0_OVF_CB();
}

ISR(TIMER0_COMP_vect)
{
	Timer0_CMP_CB();
}