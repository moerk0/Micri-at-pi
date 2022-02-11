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

enum SerialMonitorOptions{
    help,
    convert,
    error,
};

struct Lights{
    int pin;
    bool state;
    int dim_val;
    unsigned long lastOnTime;
    unsigned int delayT;
};
//TODO: converted is an Array!!!!!!
struct Msg{
    String raw;
    //int length;
    unsigned int converted[node_cnt];
    bool gate;
};
#endif