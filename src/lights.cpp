#include <Arduino.h>

#include "gloabls.h"

#include "RGBLed.h"

void makeLeds(struct Lights *p, int which_led){
    p->pin = which_led;
    pinMode(p->pin, OUTPUT);
}

void ioLed(struct Lights *p){
    p->state =! p->state;
    digitalWrite(p->pin, p->state);
}

