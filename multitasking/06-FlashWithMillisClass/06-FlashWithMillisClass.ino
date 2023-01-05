const int ledPin = 13;
long previousMillis = 0;  // will store last time LED was updated
long ledOnTime = 2000;    // interval at which the LED should be on  (milliseconds)
long ledOffTime = 1000;   // interval at which the LED should be off (milliseconds)

const int ledPin2 = 12;
long previousMillis2 = 0;  // will store last time LED was updated
long ledOnTime2 = 700;     // interval at which the LED should be on  (milliseconds)
long ledOffTime2 = 300;    // interval at which the LED should be off (milliseconds)

class Flasher {
  // Class Member Variables
  // These are initialized at startup
  int ledPin;    // the number of the LED pin
  long OnTime;   // milliseconds of on-time
  long OffTime;  // milliseconds of off-time

  // These maintain the current state
  int ledState;                  // ledState used to set the LED
  unsigned long previousMillis;  // will store last time LED was updated

  // Constructor - creates a Flasher
  // and initializes the member variables and state
public:
  Flasher(int pin, long on, long off) {
    ledPin = pin;
    pinMode(ledPin, OUTPUT);

    OnTime = on;
    OffTime = off;

    ledState = LOW;
    previousMillis = 0;
  }

  void update() {
    // check to see if it's time to change the state of the LED
    unsigned long currentMillis = millis();

    if ((ledState == HIGH) && (currentMillis - previousMillis >= OnTime)) {
      ledState = LOW;                  // Turn it off
      previousMillis = currentMillis;  // Remember the time
      digitalWrite(ledPin, ledState);  // Update the actual LED
    } else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime)) {
      ledState = HIGH;                 // turn it on
      previousMillis = currentMillis;  // Remember the time
      digitalWrite(ledPin, ledState);  // Update the actual LED
    }
  }
};

Flasher led1(ledPin, ledOnTime, ledOffTime);
Flasher led2(ledPin2, ledOnTime2, ledOffTime2);

void setup() {
}


void loop() {
  led1.update();
  led2.update();
}