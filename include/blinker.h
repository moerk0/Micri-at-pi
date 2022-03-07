#ifndef CLASS_H
#define CLASS_H

#include <Arduino.h>


class Blinker
{
private:
    int pin;
    uint16_t delayOn, delayOff;
    bool state;
    unsigned long lastSwitchTime = 0;

    void writeLed(void);


public:
    bool prevState;

    Blinker(int pin, uint16_t interval);
    bool run(void);
    void setLED(bool state);
    void setDelayTime(int i, int o);
    void setPin(int p);
    // void chase();

};




#endif