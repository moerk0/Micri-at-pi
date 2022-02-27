#include <Arduino.h>
#include "blinker.h"
#include "gloabls.h"

//quo vadis Code?
void TaskHandler::takeToken(){this->token=true;}
void TaskHandler::returnToken(){this->token=false;}
void TaskHandler::performHandshake(){(this->token) ? takeToken() : returnToken();}




Blinker::Blinker(int p, uint16_t delay){
    this->pin = p;
    pinMode(this->pin, OUTPUT);
    this->delayOn  = delay;
    this->delayOff = delay;
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
    debugMsg("last Time:\t", this->lastSwitchTime);
    debugMsg("delay Time:\t", i);
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
