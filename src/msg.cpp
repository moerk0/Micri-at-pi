#include <Arduino.h>
#include "gloabls.h"

void parseData(struct Msg *p){
  while(Serial.available() > 0){
    for (int i = 0; i < node_cnt; i++)
    {
      p->converted[i] = Serial.parseInt();
    }

    if (Serial.read()== '\r'){
      for (int i = 0; i < node_cnt; i++)
      {
      Serial.println(p->converted[i]);
      }
      break;
    }
  }
}



