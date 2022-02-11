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

void parseData(struct Msg *p){
  
  
}

void convertSerialData(struct Msg *p){
  int length = p->raw.length();
  int idx = 0;
  if (p->gate) // soon wont be relevant
  {
    for (int i = 0; i < length; i++)
    {
     // char msgsplit = p->raw[i];
      if (isDigit(p->raw[i]))
      {
        p->converted[idx] = p->raw.toInt();
      }
      if (p->raw[i] == ' ')//oder komma?
      {
        p->converted[idx++];
      }
      
      else{Serial.println("Please enter a integer Number and use Space as delimiter!");}
      
      //Serial.print(i);
    }
    Serial.println(p->converted[idx]); 
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