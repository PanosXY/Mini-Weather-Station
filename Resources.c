#include "Resources.h"
#include "Types.h"


u8 Packet[10];


void InitDevice(void){
     InitIO();
     PacketInit();
     InitADC();
     InitTimer2();
     InitSerialPort();
}

void InitIO(void){
     
     BT_EN_DIR  = 0;
     BT_EN_DATA = 1;
     
     DHT11_DIR  = 1; //DHT11 Sensor pin as input
     
     TRISB4_bit = 1; //Light Sensor pin as input
     ANSEL      = 0; //All Pins as digital I/O
     ANSELH     = 0;
     ANS11_bit  = 1; //Light Sensor pin as analog input
}

void InitADC(void){

     ADCS0_bit = 0; //A/D Conversion Clock -> Fosc/2
     ADCS1_bit = 0;

     CHS0_bit  = 1; //Analog Channel -> AN11
     CHS1_bit  = 1;
     CHS2_bit  = 0;
     CHS3_bit  = 1;

     ADON_bit  = 1; //ADC Enabled

     ADFM_bit  = 1; //A/D Conversion Result -> Right Justified
     
     VCFG1_bit = 0; //Voltage Reference - -> Vss
     VCFG0_bit = 0; //Voltage Reference + -> VDD
}

void InitTimer2(void){

     GIE_bit  = 1; //Enable Global Interrupts
     PEIE_bit = 1; //Enable Peripheral Interrupts
     
     C1ON_bit = 0;
     C2ON_bit = 0;
     
     TMR2IE_bit  = 1; //Enable Timer2 Interrupt
     TMR2IF_bit  = 0; //Clear Timer2 Flag

     TOUTPS0_bit = 0; //Timer2 Output Postscaler -> 1:1
     TOUTPS1_bit = 0;
     TOUTPS2_bit = 0;
     TOUTPS3_bit = 0;

     TMR2ON_bit  = 0; //Timer2 -> Off

     T2CKPS0_bit = 0; //Timer2 Prescaler -> 1:1
     T2CKPS1_bit = 0;

     TMR2        = 0;
}

void InitSerialPort(void){

      Delay_ms(50);
      UART1_Init(9600); //Init Serial with 9600 bps
      Delay_ms(50);
}

void PacketInit(void){
    packet[0] = '0';
    packet[1] = '0';
    packet[2] = ',';
    packet[3] = '0';
    packet[4] = '0';
    packet[5] = ',';
    packet[6] = '0';
    packet[7] = '0';
    packet[8] = '\n';
    packet[9] = 0;
}