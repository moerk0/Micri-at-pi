#include <Arduino.h>
#include <TM1637Display.h>

#include "gloabls.h"
#include "config.h"
#include "config_env.h"
#include "msg.h"
#include "lights.h"
#include "helper.h"
#include "blinker.h"
#include "chase.h"


// Blinker blinkers[node_cnt]= {
//   Blinker(LED_0, 50),
//   Blinker(LED_1, 50),
//   Blinker(LED_2, 50),
//   Blinker(LED_3, 50)
//   };

// Blinker blinker (DEBUG_PIN_7, 3000);
// Blinker blinker1(DEBUG_PIN_4, 2000);
// struct LDR ldr;
// struct Msg msg;
// struct Lights lights[node_cnt];



 uint8_t pins[] = {DEBUG_PIN_0,
                   DEBUG_PIN_1,
                   DEBUG_PIN_2,
                   DEBUG_PIN_3,
                   DEBUG_PIN_4,
                   DEBUG_PIN_5,
                   DEBUG_PIN_6,
                   DEBUG_PIN_7,
 };
ChaseLEDs chaser(pins, sizeof(pins));

TM1637Display display(CLK, DIO);


void debugMsg(String msg, int val){
    Serial.println(msg + ":\t" + String(val));
    // Serial.println("________END_____________________");
}




// void binarySequencer(){
//   if (parseData(&msg))
//   {
//     int i = 0;
//     while (msg.converted[repititions] != 0)
//     {
//       if (pause_rythmic(msg.converted[time]))
//       {
//         binCalc(msg.converted[i],&msg);

//         Serial.print("LEd States:\t");
//         for (int j = 0; j < node_cnt; j++){
//           binaryBlinker(&msg,&lights[j],j);
//         }
//         Serial.print('\n');
//         i++;
//         msg.converted[repititions]--;
//         i%= SEQ_LEN;
//       }
//     }
//   }
//   // off();
// }
 




//TODO: Make Default on and Default off a param
//Chase could be a simple counter, so it would not be dependend on the adress of light.
// void chase(byte mode){
//   static unsigned int idx = 0;
//   if(blinkers[idx].run() && !blinkers[idx].prevState){
//     idx++;
//     idx%= node_cnt;
//   }
  
// }





void setup(){
  Serial.begin(9600);
    display.setBrightness(0x0f);

}

void visual(uint8_t a){

    Serial.print(a,BIN);
    Serial.print('\t');
    Serial.print(a,HEX);
    Serial.print('\t');
    Serial.print('\t');
    Serial.print(a,DEC);
    Serial.print('\t');
    Serial.print('\t');
    Serial.print("i: ");
   // Serial.print(i);
    // Serial.print('\t');
    // Serial.print('\t');
    // Serial.print("k: ");
    // Serial.print(k);
    // Serial.print('\t');
    // Serial.print('\t');
    // Serial.print("l: ");
    // Serial.print(ldr.val);
    Serial.println();
}

  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };


void loop(){
  chaser.chase( 5, 0x00, 100 );
  display.showNumberDec(chaser.getState(), true);
  //  display.setSegments(data);
}

