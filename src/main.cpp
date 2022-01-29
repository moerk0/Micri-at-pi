#include <Arduino.h>

#include "gloabls.h"
#include "config.h"
#include "msg.h"
#include "lights.h"

#include "RGBLed.h"


struct Lights lights[node_cnt];

unsigned long lastOnTime = 0;





bool ioblink(struct Lights *p, unsigned int interval){
  bool done;
  if (millis()- p->lastOnTime > interval )
  {
    p->state = !p->state;
    digitalWrite(p->pin, p->state);
    done = false;
  }

  if (millis()- p->lastOnTime > interval * 2)
  {
   p->state = !p->state;
    digitalWrite(p->pin, p->state);
    p->lastOnTime = millis();
    done = true;
  }

  return done;
}

void setup(){
  Serial.begin(9600);
  
  int tmp[] = {LED_0, LED_1, LED_2,LED_3};
  for (int i = 0; i < node_cnt; i++)
  {
  makeLeds(&lights[i], tmp[i]);
  lights[i].delayT = 300;
  }
  
  ioblink(&lights[0], 1000);

   
}



void chase(){
  static int idx =0;
  if(ioblink(&lights[idx], 1000)){
    
    if (idx < node_cnt)
    {
      idx = 0;
    }
    else{idx ++;};
  }
  else{};
}


void loop(){
    // chase();
    ioblink(&lights[0], 1000);
  }
  


  

    
    

    
  
  
  
