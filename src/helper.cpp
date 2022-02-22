#include <Arduino.h>
#include "gloabls.h"

bool pause_arythmic(struct Lights *p){
  //static unsigned long previousMillis;
  if (millis() - p->lastOnTime >= p->delayT)
  {
    p->lastOnTime = millis();
    return true;
  }
  return false;
  
}


bool pause_rythmic(unsigned int interval){
    static unsigned long lastOnTime;
    if (millis() - lastOnTime >= interval)
  {
    lastOnTime = millis();
    return true;
  }
  return false;
  
}

//goes with binaryBlinker
void binaryConverter(struct Msg *p, int inputNum){
  int maxInp =  pow(node_cnt,2)-1;
  
  if (inputNum > maxInp)
  {
    inputNum = maxInp;
    Serial.println("Input too high max num exceeded");
  }
  else{}//continue

  for (int i = (node_cnt-1); i >= 0 ; i--)
  {
    p->binStr += (bool)(inputNum & (1 << i));
  }
    Serial.println(p->binStr);
}

