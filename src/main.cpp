#include <Arduino.h>

#include "gloabls.h"
#include "config.h"
#include "msg.h"
#include "lights.h"

#include "RGBLed.h"


#define FACTOR 10

struct Lights lights[node_cnt];

//TODO: Configure On and off Time
bool pause(struct Lights *p, unsigned int interval){
  //static unsigned long previousMillis;
  if (millis() - p->lastOnTime >= p->delayT)
  {
    p->lastOnTime = millis();
    return true;
  }
  return false;
  
}


void ioLed(struct Lights *p){
  p->state = !p->state;
  digitalWrite(p->pin, p->state);
}
//TODO: Make Default on and Default off a param
void chase(byte mode){
  static unsigned int idx;
if (pause(&lights[idx], 0))
{
    ioLed(&lights[idx]);
    if (!lights[idx].state){
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
  
  int tmp[] = {LED_0, LED_1, LED_2,LED_3};
  int tmp_delayT[] = {25,50,75,100};
  for (int i = 0; i < node_cnt; i++)
  {
  makeLeds(&lights[i], tmp[i]);
  tmp_delayT[i]*= FACTOR;
  lights[i].delayT = tmp_delayT[i]; //individual Delay Time
  }
   
}




void loop(){
  chase(clockwise);
}
  


  

    
    

    
  
  
  
