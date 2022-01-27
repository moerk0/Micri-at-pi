#ifndef GLOBALS_H
#define GLOBALS_H

enum Leds{
    node1,
    node2,
    node3,
    node4,
    node_cnt,
};

struct Lights{
    int led_pin;
    bool state;
    int dim_val;
    unsigned long lastOnTime;
    int delayT;
};

#endif