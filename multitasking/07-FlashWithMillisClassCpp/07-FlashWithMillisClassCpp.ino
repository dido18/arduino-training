#include "flasher.h"

const int ledPin = 13;
long ledOnTime = 2000;
long ledOffTime = 1000;

const int ledPin2 = 12;
long ledOnTime2 = 700;
long ledOffTime2 = 300;

Flasher led1(ledPin, ledOnTime, ledOffTime);
Flasher led2(ledPin2, ledOnTime2, ledOffTime2);

void setup() {}


void loop() {
  led1.update();
  led2.update();
}