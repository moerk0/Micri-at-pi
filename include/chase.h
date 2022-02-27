 
 #ifndef CHASE_H
 #define CHASE_H
 
 #include <Arduino.h>
 #include "gloabls.h"




 class ChaseLEDs
 {
 public:
   ChaseLEDs(const uint8_t *pins, int num, unsigned long advanceTime);

   void loop(byte mode);

   unsigned long advanceTime() const { return _advanceTime; }
   void setAdvanceTime(unsigned long advanceTime) { _advanceTime = advanceTime; }
   //if u run in anticlkw mode, setSnake will also be reveresed
   void setSnake(int seqLeng){ snake = seqLeng ; }
 
 protected:
     virtual void advance(uint8_t prevPin, uint8_t nextPin, byte mode);
     uint8_t previousPin(int n);
         
 
 private:
     const uint8_t *_pins;
     int _numPins;
     unsigned int _currentIndex;
     unsigned long _advanceTime;
     unsigned long _lastChange;
     int snake;
     bool state;
 };
 
 #endif