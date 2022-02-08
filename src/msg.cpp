#include <Arduino.h>
#include "gloabls.h"

void getSerialData(struct Msg *p){
  String msg;
  while (Serial.available() > 0){
    char inChar = Serial.read();  
    if (inChar == '\r'){
      p->raw = msg;
      p->gate = !p->gate;
      break;
    }
    else{
    msg += (char)inChar;
    //delay(3);
    }
  }
}

        // int lenght = msg.length();
        // Serial.print(lenght);
        // Serial.println(msg);
 String collectBits(struct Lights *p){
  String msg;
  while(msg.length() <= node_cnt){
  msg+= p->state;
  delay(3);
 }
  return msg;
}
 
void dumpString(struct Msg *p){
  if(p->gate){
     Serial.println(p->raw);
     p->gate = ! p->gate;
  }
 }