#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Dio.h"
#include "Bitwise.h"
#include "LCD.h"
#include "StringHandler.h"
#include "I2C.h"
#define EEPROM_ADDRESS 0b1010000

int main(void)
{
	uint8 ReadValue = 0xAA ;
	uint8 ReadValueString[3]={0};
	LCD_Init();
	I2C_Init();
	/*I2C_Start();
	I2C_Write((EEPROM_ADDRESS<<1)|0); // Save ADDRESS
	I2C_Write(0x00); // internal location of memory
	I2C_Write(0x77); // data
	I2C_Stop();*/
	while (1)
	{
		
		_delay_ms(1000);
		I2C_Start();
		I2C_Write((EEPROM_ADDRESS<<1)|0);
		I2C_Write(0x00);
		I2C_Start();
		I2C_Write((EEPROM_ADDRESS<<1)|1);
		I2C_Read(&ReadValue);
		I2C_Stop();
		U8HEX2String(ReadValue,ReadValueString);
		LCD_Postion(1,1);
		LCD_DataString(ReadValueString);
	}
}
