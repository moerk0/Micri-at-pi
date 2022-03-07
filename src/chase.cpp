 
#include "chase.h"
#include <Arduino.h>
#include "gloabls.h"
 
ChaseLEDs::ChaseLEDs(const uint8_t *pins, int num, unsigned long advanceTime)
   : _pins(pins)
   , _numPins(num)
   , _currentIndex(0)
   , _advanceTime(advanceTime)
   , _lastChange(0)
   , state(LOW)
{
   for (uint8_t index = 0; index < _numPins; ++index) {
       pinMode(_pins[index], OUTPUT);
       digitalWrite(_pins[index], LOW);
   }
}

void ChaseLEDs::loop(byte mode){


    if ((millis() - _lastChange) >= _advanceTime) {
        switch (mode){
            case clockwise:
                advance(previousPin(snake), _pins[_currentIndex], mode);
                _currentIndex++ ;
                _currentIndex %= _numPins;
            break;

            case anticlockwise:
                advance(previousPin(snake), _pins[_currentIndex], mode);
                if(_currentIndex == 0)
                    _currentIndex = _numPins - 1;
                else
                _currentIndex--;
            break;
        }

        _lastChange = millis();
    }
}

void ChaseLEDs::advance(uint8_t prevPin, uint8_t nextPin, byte mode){
    if (mode == clockwise || mode == anticlockwise){
    state = ! state;
     digitalWrite(nextPin, state);
    state = ! state;
     digitalWrite(prevPin, state);
    }
 }
 

 uint8_t ChaseLEDs::previousPin(int n){
     
    int result;
    result =(_currentIndex + _numPins - n) % _numPins; 
    (result == -1) ? result = _numPins - 1 : result = result;
    debugMsg("result:\t", result);
    return _pins[result];

 }