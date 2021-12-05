#include "KeyPad.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "LCD.h"
void KeyPad_Init (void)
{
	Dio_GroupSetDirection(KEYPAD_Rows_Port,KEYPAD_Rows_Mask,0xFF); // Rows output = 1
	Dio_GroupSetDirection(KEYPAD_Columns_Port,KEYPAD_Columns_Mask,0x00); // col input = 0
	Dio_GroupPullupState(KEYPAD_Columns_Port,KEYPAD_Columns_Mask,0xF0); // activate pull up R input
	Dio_GroupWrite(KEYPAD_Rows_Port,KEYPAD_Rows_Mask,0x00); // hktb f el output 0
}
ReturnValueType KeyPad_GetNumber (uint8 * Number)
{
	uint8 SegementValue = 0xFF ; 
	uint8 KeyPadValue = 0x00 ;
	Dio_GroupRead(KEYPAD_Columns_Port,KEYPAD_Columns_Mask,&SegementValue);// read col 
	if (SegementValue == 0xF0) return NOK ;//if not press hyb2a 0xf0
	_delay_ms(100);
	KeyPadValue = SegementValue ;
	Dio_GroupFlipDirection(KEYPAD_Columns_Port,KEYPAD_Columns_Mask);//bnbdl el input b output
	Dio_GroupFlipDirection(KEYPAD_Rows_Port,KEYPAD_Rows_Mask);//bnbdl el output b input
	Dio_GroupPullupStateFlip(KEYPAD_Rows_Port,KEYPAD_Rows_Mask);//active pull up 
	Dio_GroupWrite(KEYPAD_Columns_Port,KEYPAD_Columns_Mask,0x00);//bkhly el output b 0
	Dio_GroupRead(KEYPAD_Rows_Port,KEYPAD_Rows_Mask,&SegementValue);//h2ra el value el gdeda
		SegementValue = SegementValue >> 3;
	_delay_ms(100);
	KeyPadValue |= SegementValue ;	
	switch(KeyPadValue)
	{
		case 0xee:*Number = '1' ; break; 
		case 0xde:*Number = '2' ; break;
		case 0xbe:*Number = '3' ; break;
		case 0x7e:*Number = 'A' ; break;
		case 0xed:*Number = '4' ; break;
		case 0xdd:*Number = '5' ; break;
		case 0xbd:*Number = '6' ; break;
		case 0x7d:*Number = 'B' ; break;
		case 0xeb:*Number = '7' ; break;
		case 0xdb:*Number = '8' ; break;
		case 0xbb:*Number = '9' ; break;
		case 0x7b:*Number = 'C' ; break;
		case 0xe7:*Number = 'E' ; break;
		case 0xd7:*Number = '0' ; break;
		case 0xb7:*Number = 'F' ; break;
		case 0x77:*Number = 'D' ; break;
		default:
			 break;
				
	}
	_delay_ms(50);
	//return el col , el Rows to re init 
	Dio_GroupFlipDirection(KEYPAD_Columns_Port,KEYPAD_Columns_Mask);
	Dio_GroupFlipDirection(KEYPAD_Rows_Port,KEYPAD_Rows_Mask);
	Dio_GroupPullupStateFlip(KEYPAD_Columns_Port,KEYPAD_Columns_Mask);
	Dio_GroupWrite(KEYPAD_Rows_Port,KEYPAD_Rows_Mask,0x00);
	return OK;
}