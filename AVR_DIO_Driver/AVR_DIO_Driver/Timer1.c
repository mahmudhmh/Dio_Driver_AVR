#include "STD_Types.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Bitwise.h"
#include "Timer1.h"
void Timer1_StartNormal(uint16 StartValue,uint8 Prescaler)
{
	TCNT1 = StartValue ;
	ClearBit(TCCR1A,WGM10); ClearBit(TCCR1A,WGM11);
	ClearBit(TCCR1B,WGM12); ClearBit(TCCR1B,WGM13);
	//SetBit(TCCR1B,CS10) ; ClearBit(TCCR1B,CS11) ; SetBit(TCCR1B,CS12) ;
	SetBit(TIMSK,TOIE1);
	TCCR1B = (TCCR1B & ~0x07 )|(Prescaler & 0x07);
	
}
void Timer1_StartCTC(uint16 CompareValue,uint8 Prescaler)
{
	OCR1AL = (uint8)CompareValue ;
	OCR1AH = (uint8) (CompareValue>>8) ;
	ClearBit(TCCR1A,WGM10); ClearBit(TCCR1A,WGM11); SetBit(TCCR1B,WGM12); ClearBit(TCCR1B,WGM13);
	SetBit(TIMSK,OCIE1A) ;
	TCCR1B = (TCCR1B & ~0x07 )|(Prescaler & 0x07);
}
void Timer1_OVF_CB(void)
{
	ToggleBit(PORTA,0);
}
void Timer1_CMP_CB(void) {}
ISR(TIMER1_OVF_vect)
{
	Timer1_OVF_CB();
}
// ISR(TIMER1_COMPA_vect)
// {
// 	Timer1_CMP_CB();
// }