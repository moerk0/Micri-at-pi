#include <Arduino.h>

#include "gloabls.h"

#include "RGBLed.h"

void makeLeds(struct Lights *p, int which_led){
    p->led_pin = which_led;
    pinMode(p->led_pin, OUTPUT);
}

void setLED(struct Lights *p){
    p->state =! p->state;
    digitalWrite(p->led_pin, p->state);
}

void sqLED(struct Lights *p, int t)
{
p->delayT = t;


};
