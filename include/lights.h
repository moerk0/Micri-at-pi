# ifndef LIGHTS_H
#define LIGHTS_H

void makeLeds(struct Lights *p, int which_led);
void ioLed(struct Lights *p);
void binaryBlinker(char input, struct Lights *p);

#endif