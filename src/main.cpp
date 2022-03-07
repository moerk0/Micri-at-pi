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

Blinker
 uint8_t pins[] = {LED_0,LED_1,LED_2,LED_3, LED_4,LED_5,LED_6};
ChaseLEDs chaser(pins, sizeof(pins), 200);

struct Lights lights[node_cnt];
struct Msg msg;

void debugMsg(String msg, int val){
    Serial.println(msg + String(val));
    // Serial.println("________END_____________________");
}

//Easy way to turn off All leds
// void off(){
//   for (int i = 0; i < node_cnt; i++)
//   {
//     blinkers[i].setLED(false);
//   }
// }



void binarySequencer(){
  if (parseData(&msg))
  {
    int i = 0;
    while (msg.converted[repititions] != 0)
    {
      if (pause_rythmic(msg.converted[time]))
      {
        binCalc(msg.converted[i],&msg);

        Serial.print("LEd States:\t");
        for (int j = 0; j < node_cnt; j++){
          binaryBlinker(&msg,&lights[j],j);
        }
        Serial.print('\n');
        i++;
        msg.converted[repititions]--;
        i%= SEQ_LEN;
      }
    }
  }
  // off();
}
 




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
  chaser.setSnake(5);
  // for (int i = 0; i < 8; i++)
  // {
  // makeLeds(&lights[i], pins[i]);
  // }
  
}




void loop(){
int val;

val = analogRead(A0);
Serial.println(val);
delay(500);

// chaser.loop(anticlockwise);

  // binarySequencer();
}

  //  binaryConverter(&msg, random(0,15));
  //  for (int i = 0; i < node_cnt; i++)
  //  {
  //  binaryBlinker(&msg, &lights[i], i);
  //  }
  //  msg.binStr = "";