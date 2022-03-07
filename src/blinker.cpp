#include <Arduino.h>
#include "blinker.h"
#include "gloabls.h"



Blinker::Blinker(int p, uint16_t delay)
:   pin(p)
,   delayOn(delay)
,   delayOff(delay)
{
    pinMode(pin, OUTPUT);   //      No this-> need, y is that so?
}

void Blinker::writeLed(){
    digitalWrite(this->pin, this->state);
}

void Blinker::setLED(bool state){
    digitalWrite(this->pin, state);
}


bool Blinker::run(){
  uint16_t i;
  if (this->state)
      i = this->delayOn;
  else 
      i = this->delayOff;

    this->prevState = this->state;
  
  if (millis() - this->lastSwitchTime >= i)
  {
    this->lastSwitchTime = millis();
    this->state ^= 1;
    writeLed();
  }

  return this->state;
}

void Blinker::setDelayTime(int i, int o){
    this->delayOn   = i;
    this->delayOff  = o;
}
void Blinker::setPin(int p){
    this->pin = p;
    pinMode(this->pin, OUTPUT);
}

 

