#include <Arduino.h>

#include "gloabls.h"
#include "config.h"
#include "msg.h"
#include "lights.h"

#include "RGBLed.h"


struct Lights lights[node_cnt];

unsigned long lastOnTime = 0;



void dumpBits(){
  String msg;
  for (int i = 0; i < node_cnt; i++)
  {
  msg+= lights[i].state;   
  }
  
  Serial.println(msg);
}

void blink(unsigned int t, struct Lights *p){
  
  if (millis()- lastOnTime > t )
  {
  p->state =! p->state;
  lastOnTime = millis();
  }
  digitalWrite(p->pin, p->state);
  
}

void setup(){
  Serial.begin(9600);
  
  int tmp[] = {LED_0, LED_1, LED_2,LED_3};
  for (int i = 0; i < node_cnt; i++)
  {
  makeLeds(&lights[i], tmp[i]);
  lights[i].delayT = 300;
  }
  

   
}

void debugMSG(){


}

void blinkLed(struct Lights *p, unsigned int interval){

  if (millis()- p->lastOnTime > interval )
  {
    p->state = !p->state;
    digitalWrite(p->pin, p->state);
    p->lastOnTime = millis();
  }
}

void loop(){
    blinkLed(&lights[0],1000);
    
    blinkLed(&lights[0], 1000);

    blinkLed(&lights[1],500);
    
    blinkLed(&lights[1], 500);
    
    blinkLed(&lights[2],250);
    
    blinkLed(&lights[2], 250);
    
    blinkLed(&lights[3],125);
    
    blinkLed(&lights[3], 125);
  }
  


  

    
    

    
  
  
  
