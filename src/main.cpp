#include <Arduino.h>
#include "gloabls.h"
#include "config.h"
#include "msg.h"
#include "lights.h"
#include "helper.h"
#include "RGBLed.h"

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
void binaryBlink(int inp){
    int i;

    for ( i = 0; i < node_cnt; i++)
    {
     if (inp % 2 == 0)
     {
       lights[i].state = LOW;
     }
     else{lights[i].state = HIGH;}

      digitalWrite(lights[i].pin, lights[i].state);
      inp /= 2;
    }
    
    Serial.print("Overall: ");      
    for (int j = i-1;  j >=0; j--)
    {
        Serial.print(lights[j].state);
    }  
    Serial.print('\n'); 
}

void binarySequencer(){
  if (parseData(&msg)){
      int idx = 0;

    while (msg.converted[repititions] != 0){
      if (pause_rythmic(msg.converted[time])){
        binaryBlink(msg.converted[idx]);
        idx ++;
        idx %= SEQ_LEN;
          
        msg.converted[repititions]--;
      }
    } 
    off();
  }
} 




//TODO: Configure On AND off Time
//TODO: Make Default on and Default off a param
//Chase could be a simple counter, so it would not be dependend on the adress of light.
void chase(byte mode){
  static unsigned int idx;
  if (pause_arythmic(&lights[idx]))
{
    ioLed(&lights[idx]);

    if (!lights[idx].state){ //default off 
      switch (mode)
      {
      case anticlockwise:
        idx--;
        break;
      
      case clockwise:
      idx ++; 
        break;
      }

    idx %= node_cnt;    
    }
}


}

void setup(){
  Serial.begin(9600);
  
  int tmp[] = {LED_0, LED_1, LED_2,LED_3}; // Add LEDs here
  int tmp_delayT[] = {25,50,75,100};  //Adjust delay Time here. Could also be in a typedef section
  for (int i = 0; i < node_cnt; i++)
  {
    makeLeds(&lights[i], tmp[i]);
    tmp_delayT[i]*= FACTOR;
    lights[i].delayT = tmp_delayT[i]; 
  }
   
}




void loop(){
  binarySequencer();
  
}
  

//  Serial.println("________END_____________________");
  //  binaryConverter(&msg, random(0,15));
  //  for (int i = 0; i < node_cnt; i++)
  //  {
  //  binaryBlinker(&msg, &lights[i], i);
  //  }
  //  msg.binStr = "";

    
    

    
  
  
  
