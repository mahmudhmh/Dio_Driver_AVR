#include "SevenSegement.h"
#include "Dio.h"

uint8 CH1Value = 0 ;
uint8 CH2Value = 0 ;

void SevenSegement_Init(void)
{
	Dio_GroupSetDirection(EnablePort,EnableMask,EnableMask);
	Dio_GroupSetDirection(DataPort,DataMask,DataMask);
	Dio_GroupWrite(EnablePort,EnableMask,~EnableMask);
	
}
ReturnValueType SevenSegement_State(SSChaneelType SSChaneel,SSStateType SSState)
{
	ReturnValueType ReturnValue = OK; 
	switch (SSChaneel)
	{
		case CH1:
			if (SSState == Disable) Dio_PinWrite(EnablePort,EN1,PinLow);
			else if (SSState == Enable) Dio_PinWrite(EnablePort,EN1,PinHigh);
			else ReturnValue = NOK;
			break;
		case CH2:
			if (SSState == Disable) Dio_PinWrite(EnablePort,EN2,PinLow);
			else if (SSState == Enable) Dio_PinWrite(EnablePort,EN2,PinHigh);
			else ReturnValue = NOK;
			break;
		default:
			ReturnValue = NOK ;
			break;		
	}
	return ReturnValue;
}
ReturnValueType SevenSegement_Write(SSChaneelType SSChaneel,uint8 Value)
{
	ReturnValueType ReturnValue= OK;
	
	switch (SSChaneel)
	{
	case CH1:
		CH1Value = Value ;
		Value = Value << DataAlign ;
		SevenSegement_State(CH2,Disable);
		SevenSegement_State(CH1,Enable);
		
		 Dio_GroupWrite(DataPort,DataMask,Value);
		 _delay_ms(1);
		SevenSegement_State(CH1,Disable); 
		 
		break;
	case CH2:
		CH2Value = Value ;
		Value = Value << DataAlign ;
		SevenSegement_State(CH1,Disable);
		SevenSegement_State(CH2,Enable);
		
		Dio_GroupWrite(DataPort,DataMask,Value);
		_delay_ms(1);
		SevenSegement_State(CH2,Disable);
		break;
	default:
		ReturnValue = NOK ;
		break;		
	}
	return ReturnValue;
}
ReturnValueType SevenSegement_Refresh(void)
{
	ReturnValueType ReturnValue = OK;
	SevenSegement_Write(CH1,CH1Value);
	_delay_ms(1);
	SevenSegement_Write(CH2,CH2Value);
	_delay_ms(1);
	
	return ReturnValue;
}
