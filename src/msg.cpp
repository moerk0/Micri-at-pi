#include <Arduino.h>
#include "gloabls.h"

bool parseData(struct Msg *p){
  bool ret = false;
  while(Serial.available() > 0){
    for (int i = 0; i < seq_total_cnt; i++)
    {
      p->converted[i] = Serial.parseInt();
    }

    if (Serial.read() == '\r'){
      Serial.println("parsed: ");
      for (int i = 0; i < seq_total_cnt; i++)
      {
      Serial.print(p->converted[i]);
      Serial.print(", ");
      }
      Serial.println('\n');
      ret = true;
      break;
    }
  }
  return ret;
}


bool msgRecieved(char Inchar){
  bool ret = false;
  if (Serial.read() == Inchar)
    ret = true;
  else
    ret = false;

  return ret;
}
