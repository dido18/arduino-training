#include "flasher.h"

// define the constructor of the Flasher class
Flasher::Flasher(int pin, long on, long off) {
  ledPin = pin;
  pinMode(ledPin, OUTPUT);
  OnTime = on;
  OffTime = off;
  ledState = LOW;
  previousMillis = 0;
}

// define the concrete update method of the class
void Flasher::update() {
  unsigned long currentMillis = millis();

  if ((ledState == HIGH) && currentMillis - previousMillis >= OnTime) {
    ledState = LOW;
    previousMillis = currentMillis;
    digitalWrite(ledPin, ledState);
  } else if ((ledState == LOW) && currentMillis - previousMillis >= OffTime) {
    ledState = HIGH;
    previousMillis = currentMillis;
    digitalWrite(ledPin, ledState);
  }
}