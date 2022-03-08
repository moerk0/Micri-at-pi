 
#include "chase.h"
#include <Arduino.h>



ChaseLEDs::ChaseLEDs(const uint8_t *pins, int num)
   : pins_(pins)
   , numPins_(num)
   , idx(0)
   , prevMillis_(0)
{
   for (int i = 0; i < numPins_; ++i) {
       pinMode(pins_[i], OUTPUT);
       digitalWrite(pins_[i], LOW);
   }
}

 



//its counting the adress of state. whatever this means.
void ChaseLEDs::sequencer(int afterglow, byte mode){


   bitWrite( state, idx++, 1 );
   
   kdx = ( idx - afterglow );
   kdx %= numPins_;
   
   bitWrite( state, kdx, 0 );
   
   
   idx %= numPins_;


}


void ChaseLEDs::writeState(){
   
   int s;
   for (int i = 0; i < numPins_; i++)
   {
      (state & (1<<i))? s = 1 : s = 0;
      digitalWrite(this->pins_[i], s);
   }
   
}




uint8_t ChaseLEDs::intervaler(uint16_t interval){
  
  
   uint8_t ret;
   if (interval <= millis() -prevMillis_){
                  prevMillis_=  millis();

                                          ret = 0x10;
   
   }
   else{ret = 0x00;}

   return ret;
   

}


void ChaseLEDs::chase(int afterglow, byte mode, uint16_t interval){
   if (intervaler(interval))
      sequencer(afterglow, mode);

//these 2/3   °|°  do the counting and timing
               //
               // 
//this third   ø|ø     does the hadware
   if (prevState != state){                //       Check if sate changed
      
      writeState();
      
      prevState = state;
    
   }
}