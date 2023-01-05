#include "flasher.h"

const int ledPin = 13;
long ledOnTime = 2000;
long ledOffTime = 1000;

const int ledPin2 = 12;
long ledOnTime2 = 700;
long ledOffTime2 = 300;


int ledButton = 2;

Flasher led1(ledPin, ledOnTime, ledOffTime);
Flasher led2(ledPin2, ledOnTime2, ledOffTime2);

void setup() {
  Serial.begin(9600);
  pinMode(ledButton, INPUT_PULLUP);
}


void loop() {
  led1.update();

  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on led when the
  // button's pressed, and off when it's not:
  if (digitalRead(ledButton) == LOW) {
    Serial.println("button pressed");
    led2.update();
  }
}