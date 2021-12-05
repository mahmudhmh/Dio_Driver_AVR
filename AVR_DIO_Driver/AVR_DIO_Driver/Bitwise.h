#ifndef BITWISE_H
#define BITWISE_H
#define SetBit(Byte,BitPosition) Byte|=(1<<BitPosition)
#define ClearBit(Byte,BitPosition) Byte&=~(1<<BitPosition)
#define ToggleBit(Byte,BitPosition) Byte^=(1<<BitPosition)
#define GetBit(Byte,BitPosition) (Byte>>BitPosition &0x01)
#endif
