#ifndef Flasher_h
#define Flasher_h

// include the Arduino standard functions and definitions(like digitalWrite(), OUTPUT)
#include <Arduino.h>

class Flasher {
private:
  unsigned long previousMillis = 0;
  long OnTime;
  long OffTime;
  int ledState;
  int ledPin;

public:
  // this is the constructor of the class
  Flasher(int pin, long on, long off);
  void update();
};
#endif