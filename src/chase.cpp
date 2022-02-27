 
 #include "chase.h"
 #include <Arduino.h>

 
 ChaseLEDs::ChaseLEDs(const uint8_t *pins, int num, unsigned long advanceTime)
     : _pins(pins)
     , _numPins(num)
     , _currentIndex(-1)
     , _advanceTime(advanceTime)
     , _lastChange(millis())
 {
     for (uint8_t index = 0; index < _numPins; ++index) {
         pinMode(_pins[index], OUTPUT);
         digitalWrite(_pins[index], LOW);
     }
 }
 
 void ChaseLEDs::loop()
 {
     if (_currentIndex >= 0) {
         if ((millis() - _lastChange) >= _advanceTime) {
             // Advance to the next LED in sequence.
             _currentIndex = (_currentIndex + 1) % _numPins;
             _lastChange += _advanceTime;
             advance(previousPin(1), _pins[_currentIndex]);
         }
     } else {
         // First time - light the first LED.
         _currentIndex = 0;
         _lastChange = millis();
           advance(previousPin(1), _pins[_currentIndex]);
       }
   }
   
   void ChaseLEDs::advance(uint8_t prevPin, uint8_t nextPin)
   {
       digitalWrite(prevPin, LOW);
       digitalWrite(nextPin, HIGH);
   }
   
