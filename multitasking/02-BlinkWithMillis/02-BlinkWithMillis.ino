/**
 Using the delay() function to switch on/off a led every second
**/
const int ledPin = 13;


long previousMillis = 0;   // will store last time LED was updated
int ledState = LOW;            // initially the led is OFF
// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long ledOnTime = 1000;           // interval at which to blink (milliseconds)

void  setup() {
  // initialize the digital pin as an output.
  pinMode(ledPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the 
  // difference between the current time and last time you blinked 
  // the LED is bigger than the interval at which you want to 
  // blink the LED
  long currentMillis = millis();
  if(currentMillis - previousMillis > ledOnTime) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}