const int ledPin = 13;
long previousMillis = 0;  // will store last time LED was updated
int ledState = LOW;       // initially the led is OFF
long ledOnTime = 700;    // interval at which the LED should be on  (milliseconds)
long ledOffTime = 300;   // interval at which the LED should be off (milliseconds)

const int ledPin2 = 12;
long previousMillis2 = 0;  // will store last time LED was updated
int ledState2 = LOW;       // initially the led is OFF
long ledOnTime2 = 700;    // interval at which the LED should be on  (milliseconds)
long ledOffTime2 = 300;   // interval at which the LED should be off (milliseconds)

// we need pointers for previousMillis and ledState because the function updates the values
void flash(long *prevMillis, int *ledState, int ledPin, long ledOnTime, long ledOffTime) {
  long currentMillis = millis();
  if ((*ledState == HIGH) && (currentMillis - *prevMillis > ledOnTime)) {
    *prevMillis = currentMillis;
    *ledState = LOW;
    digitalWrite(ledPin, *ledState);
  } else if ((*ledState == LOW) && (currentMillis - *prevMillis > ledOffTime)) {
    *prevMillis = currentMillis;
    *ledState = HIGH;
    digitalWrite(ledPin, *ledState);
  }
};


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  flash(&previousMillis, &ledState, ledPin, ledOnTime, ledOffTime);
  flash(&previousMillis2, &ledState2, ledPin2, ledOnTime2, ledOffTime2);
}