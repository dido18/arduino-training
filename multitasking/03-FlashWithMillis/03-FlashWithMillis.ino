/**
**/
const int ledPin = 13;


long previousMillis = 0;          // will store last time LED was updated
int ledState = LOW;               // initially the led is OFF

long ledOnTime = 2000;            // interval at which the LED should be on  (milliseconds)
long ledOffTime = 1000;           // interval at which the LED should be off (milliseconds)

void  setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {

  long currentMillis = millis();

  // if the state of the led is ON and the time passed in which the led should be ON then switch OFF the led  
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
}