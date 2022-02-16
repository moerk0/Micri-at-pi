#include <Arduino.h>
#include "gloabls.h"
#include "config.h"
#include "msg.h"
#include "lights.h"
#include "helper.h"
#include "RGBLed.h"




struct Lights lights[node_cnt];
struct Msg msg;


void binaryConverter(struct Msg *p, int inputNum){
  int maxInp =  pow(node_cnt,2)-1;
  
  if (inputNum > maxInp)
  {
    inputNum = maxInp;
    Serial.println("Input too high max num exceeded");
  }
  else{;}//continue

  for (int i = (node_cnt-1); i >= 0 ; i--)
  {
    p->binStr += (bool)(inputNum & (1 << i));
  }
    Serial.println(p->binStr);
}

void binaryBlinker(struct Msg *q,  struct Lights *p, byte which){
    if (q->binStr[which] == '1')
    {
        p->state = HIGH;
        digitalWrite(p->pin,p->state);
    }

    else{
        p->state = LOW;
        digitalWrite(p->pin,p->state);
    }
}



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
  // parseData(&msg);


  // chase(clockwise);
  if (pause_msg(50))
  {
   binaryConverter(&msg, random(0,15));
   for (int i = 0; i < node_cnt; i++)
   {
   binaryBlinker(&msg, &lights[i], i);
   }
   msg.binStr = "";
    Serial.println("________END_____________________");
  }
  
}
  


  

    
    

    
  
  
  
