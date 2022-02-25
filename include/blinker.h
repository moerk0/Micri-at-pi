#ifndef CLASS_H
#define CLASS_H

#include <Arduino.h>

// struct Lights{
//     int dim_val;
// };

class Blinker
{
private:
    int pin;
    unsigned int delayOn, delayOff;
    bool state;
    unsigned long lastSwitchTime = 0;

    void writeLed(void);


public:
    Blinker(int pin, int interval);
    bool run(void);
    void turnOff(void);
    void setDelayTime(int i, int o);
    void setPin(int p);
    // void chase();

};




#endif