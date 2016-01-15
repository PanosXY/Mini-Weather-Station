#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include "Types.h"

#define ADC_MIN      40
#define ADC_MAX      1000


extern void GetLuminosity(void);
u32 map(u32 x, u32 in_min, u32 in_max, u32 out_min, u32 out_max);

#endif