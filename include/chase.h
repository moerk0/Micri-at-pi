 
 #ifndef ChaseLEDs_h
 #define ChaseLEDs_h
 
 #include <Arduino.h>
 
 class ChaseLEDs
 {
 public:
     ChaseLEDs(const uint8_t *pins, int num, unsigned long advanceTime);
 
     void loop();
 
     unsigned long advanceTime() const { return _advanceTime; }
     void setAdvanceTime(unsigned long advanceTime) { _advanceTime = advanceTime; }
 
 protected:
     virtual void advance(uint8_t prevPin, uint8_t nextPin);
     uint8_t previousPin(int n) const
         { return _pins[(_currentIndex + _numPins - n) % _numPins]; }
 
 private:
     const uint8_t *_pins;
     int _numPins;
     int _currentIndex;
     unsigned long _advanceTime;
     unsigned long _lastChange;
 };
 
 #endif