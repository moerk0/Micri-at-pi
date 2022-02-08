#include <Arduino.h>

#include "gloabls.h"

void serialBehaviour(){
  String msg = "";
  while (Serial.available() > 0){
    char inChar = Serial.read();  
    if (inChar == '\r'){
        int lenght = msg.length();
        Serial.print(lenght);
        Serial.println(msg);
    }
    else{
    msg+= (char)inChar;
    //delay(3);
    }
  }
}
 String collectBits(struct Lights *p){
  String msg;
  while(msg.length() <= node_cnt){
  msg+= p->state;
  delay(3);
 }
  return msg;
}

bool dumpBits(String in_msg){
  int cnt;
    
}