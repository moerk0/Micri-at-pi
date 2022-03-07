#include <Arduino.h>
#include "gloabls.h"
#include "config.h"
#include "config_env.h"
#include "msg.h"
#include "lights.h"
#include "helper.h"
#include "blinker.h"
#include "chase.h"


// Blinker blinkers[node_cnt]= {
//   Blinker(LED_0, 50),
//   Blinker(LED_1, 50),
//   Blinker(LED_2, 50),
//   Blinker(LED_3, 50)
//   };

Blinker blinker (DEBUG_PIN_7, 3000);
Blinker blinker1(DEBUG_PIN_4, 2000);
struct LDR ldr;
struct Msg msg;



//  uint8_t pins[] = {LED_0,LED_1,LED_2,LED_3, LED_4,LED_5,LED_6};
// ChaseLEDs chaser(pins, sizeof(pins), 200);

// struct Lights lights[node_cnt];

void debugMsg(String msg, int val){
    Serial.println(msg + ":\t" + String(val));
    // Serial.println("________END_____________________");
}

//Easy way to turn off All leds
// void off(){
//   for (int i = 0; i < node_cnt; i++)
//   {
//     blinkers[i].setLED(false);
//   }
// }



// void binarySequencer(){
//   if (parseData(&msg))
//   {
//     int i = 0;
//     while (msg.converted[repititions] != 0)
//     {
//       if (pause_rythmic(msg.converted[time]))
//       {
//         binCalc(msg.converted[i],&msg);

//         Serial.print("LEd States:\t");
//         for (int j = 0; j < node_cnt; j++){
//           binaryBlinker(&msg,&lights[j],j);
//         }
//         Serial.print('\n');
//         i++;
//         msg.converted[repititions]--;
//         i%= SEQ_LEN;
//       }
//     }
//   }
//   // off();
// }
 




//TODO: Make Default on and Default off a param
//Chase could be a simple counter, so it would not be dependend on the adress of light.
// void chase(byte mode){
//   static unsigned int idx = 0;
//   if(blinkers[idx].run() && !blinkers[idx].prevState){
//     idx++;
//     idx%= node_cnt;
//   }
  
// }



// void chase(byte mode){
//   static unsigned int idx;
//   if (pause_arythmic(&lights[idx])){
//     ioLed(&lights[idx]);

//     if (!lights[idx].state){ //default off 
//       switch (mode)
//       {
//       case anticlockwise:
//         idx--;
//         break;
      
//       case clockwise:
//       idx ++; 
//         break;
//       }

//       idx %= node_cnt;    
//     }
//   }    
// }

void setup(){
  Serial.begin(9600);
  ldr.pin = A0;
  blinker.setDelayTime(500,800);
  blinker.setDelayTime(800,500);
  // chaser.setSnake(5);

  // for (int i = 0; i < 8; i++)
  // {
  // makeLeds(&lights[i], pins[i]);
  // }
  
}


uint8_t a = 0b00000000;
uint8_t bit_len = 8;
uint8_t afterglow = 3;
uint8_t k = 0;
uint8_t i = 0;
uint8_t s = 0x00;

void printStats(){
    Serial.print(a,BIN);
    Serial.print('\t');
    Serial.print(a,HEX);
    Serial.print('\t');
    Serial.print('\t');
    Serial.print(a,DEC);
    Serial.print('\t');
    Serial.print('\t');
    Serial.print("i: ");
    Serial.print(i);
    Serial.print('\t');
    Serial.print('\t');
    Serial.print("k: ");
    Serial.print(k);
    Serial.print('\t');
    Serial.print('\t');
    Serial.print("l: ");
    Serial.print(ldr.val);
    Serial.println();
}


void vers1(){
  for (i = 0; i < 8; i++)
  {
    a = 1<<i;
    printStats();
    delay(10);
  }
}

void vers2(int interval){
   
  if (pause_rythmic(interval))
  {
    a = 1<<i;
    printStats();
    i++;
    i %= 8;
    }
}
void vers3(int interval){
   
  if (pause_rythmic(interval))
  {
    bitWrite(a,i++,1);
    k = (i - afterglow);
    k %= bit_len;
    bitWrite(a,k,0);
    printStats();
    i %= bit_len;
    }
}


void loop(){

if (msgRecieved('\r')){
  s = !s; 
  i = 0;
  }

  if(s){
  vers3(150);
  ldr.val = analogRead(ldr.pin);
  for (int i = 0; i < bit_len; i++)
  {
  (a & (1<<i))? digitalWrite(DEBUG_PIN_7, HIGH) : digitalWrite(DEBUG_PIN_7, LOW);
   }
  

}



}

// chaser.loop(anticlockwise);

  // binarySequencer();

  //  binaryConverter(&msg, random(0,15));
  //  for (int i = 0; i < node_cnt; i++)
  //  {
  //  binaryBlinker(&msg, &lights[i], i);
  //  }
  //  msg.binStr = "";