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

void processSerialData(struct Msg *p){
  int length = p->raw.length();
  if (p->gate)
  {
    for (int i = 0; i < length; i++)
    {
     // char msgsplit = p->raw[i];
      if (isDigit(p->raw[i]))
      {
        p->converted = p->raw.toInt();
      }
      else{Serial.println("Please enter a integer Number!");}
      
      //Serial.print(i);
    }
    Serial.println(p->converted); 
    p->gate = !p->gate;
  }
  
  
  
  // if (isDigit())
  // {
  //   /* code */
  // }
  
}
 
void dumpString(struct Msg *p){
  if(p->gate){
     Serial.println(p->raw);

     p->gate = ! p->gate;
  }
 }