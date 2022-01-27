#include <Arduino.h>

#include "gloabls.h"

void serialBehaviour(){

  String msg;
  if (Serial.available() > 0){
    while (Serial.available() > 0)
    {
      msg += char(Serial.read());
      delay(3);
    }

  int lenght = msg.length();

    Serial.println(msg);
    Serial.println("Der String ist " + String(lenght) + "Lang");
  }
}

