/**
**/
const int ledPin = 13;
const int ledPin2 = 12;


long previousMillis = 0;          // will store last time LED was updated
int ledState = LOW;               // initially the led is OFF
long ledOnTime = 2000;            // interval at which the LED should be on  (milliseconds)
long ledOffTime = 1000;           // interval at which the LED should be off (milliseconds)


long previousMillis2 = 0;          // will store last time LED was updated
int ledState2 = LOW;               // initially the led is OFF
long ledOnTime2 = 700;            // interval at which the LED should be on  (milliseconds)
long ledOffTime2 = 300;           // interval at which the LED should be off (milliseconds)


void  setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {

  long currentMillis = millis();

  if((ledState == HIGH) && (currentMillis - previousMillis > ledOnTime)) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;
    // change the state of the LED     
    ledState = LOW;
    digitalWrite(ledPin, ledState);
  } else if ((ledState == LOW) && (currentMillis - previousMillis > ledOffTime)) {
    previousMillis = currentMillis;     
    ledState = HIGH;
    digitalWrite(ledPin, ledState);
  }

   // check the state of the second led
  if((ledState2 == HIGH) && (currentMillis - previousMillis2 > ledOnTime2)) {
      previousMillis2 = currentMillis;
      ledState2 = LOW;
      digitalWrite(ledPin2, ledState2);
    } else if ((ledState2 == LOW) && (currentMillis - previousMillis2 > ledOffTime2)) {
      previousMillis2 = currentMillis;
      ledState2 = HIGH;
      digitalWrite(ledPin2, ledState2);
    }
}