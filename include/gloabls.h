#ifndef GLOBALS_H
#define GLOBALS_H

enum Leds{
    node1,
    node2,
    node3,
    node4,
    node_cnt,
};

enum ChaseMode{
    anticlockwise,
    clockwise,
};

struct Lights{
    int pin;
    bool state;
    int dim_val;
    unsigned long lastOnTime;
    unsigned int delayT;
};

#endif