#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "Dio.h"

#define KEYPAD_Rows_Port C 
#define KEYPAD_Columns_Port B
#define KEYPAD_Rows_Mask 0b01111000
#define KEYPAD_Columns_Mask 0xF0

void KeyPad_Init (void);
ReturnValueType KeyPad_GetNumber (uint8 * Number);

#endif /* KEYPAD_H_ */