/*
@author: Panagiotis Skiadas
@brief:  This program reads Luminosity, Temperature, Humidity
         and transmits them through the Serial Port every 20 secs
*/

#include "Types.h"
#include "Resources.h"
#include "LightSensor.h"
#include "Dht11.h"


void interrupt(){
     if(TMR2IF_bit){
         TOUT       = 1;
         TMR2ON_bit = 0; //Stop Timer
         TMR2IF_bit = 0; //Clear TMR2 Interrupt Flag
     }
}

void main() {
     InitDevice();
     
     while(1){
         GetLuminosity();
         GetTemperatureHumidity();
         Uart1_Write_Text(&packet[0]);
         Delay_ms(20000); //20sec
     }
}
