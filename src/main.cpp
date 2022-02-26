#include <Arduino.h>
#include "gloabls.h"
#include "config.h"
#include "msg.h"
#include "lights.h"
#include "helper.h"
#include "RGBLed.h"
#include "blinker.h"

Blinker blinkers[node_cnt]= {
  Blinker(LED_0, 20000),
  Blinker(LED_1, 2000),
  Blinker(LED_2, 200),
  Blinker(LED_3, 20)
  };

struct Lights lights[node_cnt];
struct Msg msg;

//Easy way to turn off All leds
void off(){
  for (int i = 0; i < node_cnt; i++)
  {
    digitalWrite(lights[i].pin,LOW);
  }
}

//hard coded, does not need external storage, performs the calc on the fly.


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
  off();
}
 




//TODO: Configure On AND off Time
//TODO: Make Default on and Default off a param
//Chase could be a simple counter, so it would not be dependend on the adress of light.
void chase(byte mode){
  static unsigned int idx;
  for (int i = 0; i < node_cnt; i++)
  {
    blinkers[i].run();
  }
  
}





void setup(){
  Serial.begin(9600);
  
  int tmp[] = {LED_0, LED_1, LED_2,LED_3}; // Add LEDs here
  int tmp_delayI[] = {25,50,75,100};  //Adjust delay Time here. Could also be in a typedef section
  int tmp_delayO[3];   //Adjust delay Time here. Could also be in a typedef section
  // int idx = 3;
  // for (int i = 0; i < 3; i++)
  // {
  //   tmp_delayO[i] = tmp_delayI[idx--];
  // }

  // Serial.println(tmp_delayO[3]);
  
  for (int i = 0; i < node_cnt; i++){
    makeLeds(&lights[i],tmp[i]);
  //   blinkers[i].setPin(tmp[i]);
  //   blinkers[i].setDelayTime(tmp_delayI[i],tmp_delayO[i]);
  }
}




void loop(){

// off();
// binarySequencer();  
chase(anticlockwise);
}
  

//  Serial.println("________END_____________________");
  //  binaryConverter(&msg, random(0,15));
  //  for (int i = 0; i < node_cnt; i++)
  //  {
  //  binaryBlinker(&msg, &lights[i], i);
  //  }
  //  msg.binStr = "";

    
// void chase(byte mode){
//   static unsigned int idx;
//   if (pause_arythmic(&lights[idx]))
// {
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

//     idx %= node_cnt;    
//     }
// }    

    
  
  
  
