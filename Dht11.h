#ifndef DHT11_H
#define DHT11_H

#include "Types.h"
#include "Resources.h"


extern u8 TOUT;


void StartSignal(void);
u8 CheckResponse(void);
u8 ReadByte(void);
extern void GetTemperatureHumidity(void);

#endif