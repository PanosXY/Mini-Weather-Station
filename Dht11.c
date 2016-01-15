#include "Types.h"
#include "Resources.h"
#include "Dht11.h"


u8 TOUT;
u8 CheckSum;
u8 T_Byte0;
u8 T_Byte1;
u8 RH_Byte0;
u8 RH_Byte1;

void StartSignal(void){

    DHT11_DIR  = 0; //Data port is output
    DHT11_DATA = 0;
    Delay_ms(25);   //Low for at least 18us
    DHT11_DATA = 1;
    Delay_ms(30);   //High for 20-30us
    DHT11_DIR  = 1; //Data port is input
}

u8 CheckResponse(void){

    TOUT       = 0;
    TMR2       = 0;
    TMR2ON_bit = 1;              //Start TMR2 while waiting for sensor responce
    while(!DHT11_DATA && !TOUT); //If there's no response within 256us, the Timer2 overflow
    if(TOUT) return 0;           //and exit
    else{
        TMR2 = 0;
        while(DHT11_DATA && !TOUT);
        if(TOUT) return 0;
        else{
             TMR2ON_bit = 0;
             return 1;
        }
    }
}

u8 ReadByte(void){
    u8 num = 0, i;
    
    DHT11_DIR = 1;
    for(i = 0; i < 8; i++){
        while(!DHT11_DATA);
        TMR2 = 0;
        TMR2ON_bit = 1;    //Start TMR2 from 0 when a low to high data pulse
        while(DHT11_DATA); //is detected and wait until it falls low again
        TMR2ON_bit = 0;    //Stop TMR2 when the data pulse false low
        if(TMR2 > 40) num |= 1 << (7-i); //If time > 40us, DHT11_DATA is 1
    }
    return num;
}

void GetTemperatureHumidity(void){
    u8 check;

    StartSignal();
    check = CheckResponse();
    if(check){
    RH_Byte0 = ReadByte();
    RH_Byte1 = ReadByte();
    T_Byte0  = ReadByte();
    T_Byte1  = ReadByte();

    if(CheckSum == ((RH_Byte0 + RH_Byte1 + T_Byte0 + T_Byte1) & 0xFF))
         Packet[4] = '0' + RH_Byte1;
         Packet[3] = '0' + RH_Byte0;
         Packet[1] = '0' + T_Byte1;
         Packet[0] = '0' + T_Byte0;
    }
}