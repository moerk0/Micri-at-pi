#include <Arduino.h>
#include "gloabls.h"

bool pause_arythmic(struct Lights *p){
  //static unsigned long previousMillis;
  if (millis() - p->lastSwitchTime >= p->delayT)
  {
    p->lastSwitchTime = millis();
    return true;
  }
  return false;
  
}


bool pause_rythmic(unsigned int interval){
    static unsigned long lastOnTime;
    if (millis() - lastOnTime >= interval)
  {
    lastOnTime = millis();
    return true;
  }
  return false;
  
}

//goes with binaryBlinker
void binaryConverter(struct Msg *p, int inputNum){
  int maxInp =  pow(node_cnt,2)-1;
  
  if (inputNum > maxInp)
  {
    inputNum = maxInp;
    Serial.println("Input too high max num exceeded");
  }
  else{}//continue

  for (int i = (node_cnt-1); i >= 0 ; i--)
  {
//    p->binStr += (bool)(inputNum & (1 << i));
  }
    Serial.println(p->binStr);
}

//this would be nicer if it would not need an inp, but then if have to iterate very much in taht func.
void binCalc(int inp, struct Msg *p){
  int i;
  for ( i = 0; i < node_cnt; i++)
  {
    if (inp%2 == 0){p->binStr[i] = '0';}
    else{p->binStr[i]='1';}
    
    inp /=2;
  }
  Serial.print("Result:\t");
  for (int j = i-1; j >=0;j--){
    Serial.print(p->binStr[j]);
  }
   Serial.print('\n');
  
  
}





// void vers1(){
//   for (i = 0; i < 8; i++)
//   {
//     a = 1<<i;
//     visualize();
//     delay(10);
//   }
// }

// void vers2(int interval){
   
//   if (pause_rythmic(interval))
//   {
//     a = 1<<i;
//     visualize();
//     i++;
//     i %= 8;
//     }
// }
// void vers3(int interval){
   
//   if (pause_rythmic(interval))
//   {
//     i %= bit_len;
//     bitWrite(a,i++,1);
//     k = (i - afterglow);
//     k %= bit_len;
//     bitWrite(a,k,0);
//     visualize();
//     }
// }


// void loop(){

// if (msgRecieved('\r')){
//   s = !s; 
//   i = 0;
//   }

//   if(s){
//   vers3(150);
// }



