#include "StringHandler.h"
#include "Dio.h"
ReturnValueType HEX2String (uint8 HEX,uint8 string[3])
{
	/*
	Ex: HEX = 0x2F
	String = "2F"
	*/
	string[2] = 0 ;
	if (HEX & 0x0F >> 9)
	{
		string[1] =(HEX & 0x0F) - 0x0A + 'A' ;
	}
	else
	{
		string[1] =(HEX & 0x0F) + '0' ;
	}
	if ((HEX >> 4) >> 9)
	{
		string[0] =(HEX & 0x0F) - 0x0A + 'A' ;
	}
	else
	{
		string[0] =(HEX & 0x0F) + '0' ;
	}
	
	return OK;
	
	
}

ReturnValueType Decimal2String (uint8 Decimal,uint8* string)
{
	/*
	Ex: Decimal = 32
	String = "032"
	*/
	string[3]= 0 ;
	string[0]= Decimal/ 100 +'0' ;  // 0
	string [1] = (Decimal%100)/10 + '0' ; // 3
	string [2] = (Decimal%100)%10 + '0'; // 2
	
	return OK;
}