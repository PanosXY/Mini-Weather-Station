#include "Types.h"
#include "LightSensor.h"
#include "Resources.h"

u8 Luminosity;

void GetLuminosity(void){
     u16 ADCValue;
     u8 i, digit;

     ADCValue   = ADC_Read(LS_CHANNEL);
     Luminosity = (u8)map(ADCValue, ADC_MIN, ADC_MAX, 0, 100);
     
     i = 7;
     while(Luminosity > 0){
         digit = Luminosity % 10;
         Packet[i] = '0' + digit;
         Luminosity /= 10;
         i--;
     }
}

u32 map(u32 x, u32 in_min, u32 in_max, u32 out_min, u32 out_max){

  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}