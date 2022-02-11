#include <Arduino.h>

#include "gloabls.h"
#include "config.h"
#include "msg.h"
#include "lights.h"
#include "timer.h"
#include "RGBLed.h"


#define FACTOR 10

struct Lights lights[node_cnt];
struct Msg msg;

//TODO: Configure On AND off Time



//TODO: Make Default on and Default off a param, Move To Lights.cpp
//Chase could be a simple counter, so it would not be dependend on 
void chase(byte mode){
  static unsigned int idx;
  if (pause_led(&lights[idx]))
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
  
  int tmp[] = {LED_0, LED_1, LED_2,LED_3}; // Add LEDs here
  int tmp_delayT[] = {25,50,75,100};  //Adjust delay Time here
  for (int i = 0; i < node_cnt; i++)
  {
  makeLeds(&lights[i], tmp[i]);
  tmp_delayT[i]*= FACTOR;
  lights[i].delayT = tmp_delayT[i]; 
  }
   
}




void loop(){
  parseData(&msg);
  //processMonitorOptions(parseData(&msg));  
  
  chase(clockwise);
 
  
}
  


  

    
    

    
  
  
  
