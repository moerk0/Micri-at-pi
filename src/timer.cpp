#include <Arduino.h>
#include "gloabls.h"

bool pause_led(struct Lights *p){
  //static unsigned long previousMillis;
  if (millis() - p->lastOnTime >= p->delayT)
  {
    p->lastOnTime = millis();
    return true;
  }
  return false;
  
}


bool pause_msg(unsigned int interval){
    static unsigned long lastOnTime;
    if (millis() - lastOnTime >= interval)
  {
    lastOnTime = millis();
    return true;
  }
  return false;
  
}
