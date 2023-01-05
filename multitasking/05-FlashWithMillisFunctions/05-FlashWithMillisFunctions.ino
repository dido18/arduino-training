const int ledPin = 13;
const int ledPin2 = 12;

long previousMillis = 0;  // will store last time LED was updated
int ledState = LOW;       // initially the led is OFF
long ledOnTime = 2000;    // interval at which the LED should be on  (milliseconds)
long ledOffTime = 1000;   // interval at which the LED should be off (milliseconds)

long previousMillis2 = 0;  // will store last time LED was updated
int ledState2 = LOW;       // initially the led is OFF
long ledOnTime2 = 700;     // interval at which the LED should be on  (milliseconds)
long ledOffTime2 = 300;    // interval at which the LED should be off (milliseconds)


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
}


void loop() {
    myflash(&previousMillis, &ledState, ledPin, ledOnTime, ledOnTime);
    myflash(&previousMillis2, &ledState2, ledPin2, ledOnTime2, ledOffTime2);
}

