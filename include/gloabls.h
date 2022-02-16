#ifndef GLOBALS_H
#define GLOBALS_H
#include "config.h"

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

struct Msg{
    // char binStr[node_cnt]; //Wär schön is aber nicht
    String binStr;//Is it in Heap or stack?
    unsigned int converted[SEQ_LEN];
    bool gate;
};
#endif