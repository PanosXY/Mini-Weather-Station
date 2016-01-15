#ifndef RESOURCES_H
#define RESOURCES_H

#include "Types.h"

#define LS_CHANNEL 11


sbit DHT11_DATA at RA2_bit;
sbit DHT11_DIR  at TRISA2_bit;
sbit BT_EN_DIR  at TRISB0_bit;
sbit BT_EN_DATA at RB0_bit;


extern u8 Packet[10];


extern void InitDevice(void);
void InitIO(void);
void InitADC(void);
void InitTimer2(void);
void InitSerialPort(void);
void PacketInit(void);

#endif