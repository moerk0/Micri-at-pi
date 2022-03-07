#ifndef GLOBALS_H
#define GLOBALS_H
#include "config.h"
#include <Arduino.h>

//SEQ_LEN = seqN, not seq_total_cnt
enum Sequence{
    seq0,
    seq1,
    seq2,
    seq3,
    repititions,
    time,
    seq_total_cnt,
};
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
    mode_cnt,
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
    unsigned long lastSwitchTime;
    unsigned int delayT = 200;
};

//Maybe Msg is in reality the SequenceHandle struct???? Hmmmm
struct Msg{
    char binStr[node_cnt]; //Wär schön is aber nicht, sollte sein:[node_cnt*SEQ_LEN]
    //String binStr;//Is it in Heap or stack?
    unsigned int converted[seq_total_cnt]; 
    bool gate;
};


void debugMsg(String msg, int val);
#endif