#include <Arduino.h>
#include "blinker.h"

Blinker::Blinker(int p, int delay){
    this->pin = p;
    pinMode(this->pin, OUTPUT);
    this->delayOn  = delay;
    this->delayOff = delay;
}

void Blinker::writeLed(){
    digitalWrite(this->pin, this->state);
}

void Blinker::turnOff(){
    digitalWrite(this->pin, LOW);
}


bool Blinker::run(){
  uint8_t i;
  if (this->state)
      i = this->delayOn;
  else 
      i = this->delayOff;
  
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


// Blinker::~Blinker()
// {
// }

