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

//not hard coded, reads from a string saved in msg.
void binaryBlinker(struct Msg *q,  struct Lights *p, byte which){
    if (q->binStr[which] == '1'){
        p->state = HIGH;
    }

    else{
        p->state = LOW;
    }
    
    digitalWrite(p->pin,p->state);
}