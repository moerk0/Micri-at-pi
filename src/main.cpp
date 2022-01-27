#include <Arduino.h>

#include "gloabls.h"
#include "config.h"
#include "msg.h"
#include "lights.h"

#include "RGBLed.h"


struct Lights lights[node_cnt];

unsigned long lastOnTime = 0;
int delayT = 300;


void dumpBits(){
  String msg;
  for (int i = 0; i < node_cnt; i++)
  {
  msg+= lights[i].state;   
  }
  
  Serial.println(msg);
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

void loop(){

  
  for (int i = 0; i < node_cnt; i++)
  {
    lights[i].state =! lights[i].state;
    digitalWrite(lights[i].led_pin, lights[i].state);
    delay(300);
    lights[i].state =! lights[i].state;
    digitalWrite(lights[i].led_pin, lights[i].state);
    
    

    dumpBits();
  }
    
  
  
  
}