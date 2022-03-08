 
 #ifndef CHASE_H
 #define CHASE_H
 #define END_OF_CHASE };
 
 #include <Arduino.h>
 #include "gloabls.h"




 class ChaseLEDs
 {

 private:
      //hardware related vars
      const uint8_t *pins_;
      int numPins_;
    
      //counter related vars
      unsigned int idx;
      unsigned int kdx;          //    negative Index
     
      //time related vars
      unsigned long prevMillis_;
      
      //state related vars
      uint32_t state;
      uint32_t prevState;

      //private methods
      void sequencer(int afterglow, byte mode); //       handle hits
      uint8_t intervaler(uint16_t interval);   //        handle time
      void writeState(void);                  //         handle lits
 

  public:
  
    ChaseLEDs(const uint8_t *pins, int num);

    void chase(int afterglow, byte mode, uint16_t intveral);


 
END_OF_CHASE
 #endif