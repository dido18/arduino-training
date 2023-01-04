# Multi-tasking with arduino

Inspired by [here](https://learn.adafruit.com/multi-tasking-the-arduino-part-1?)

## Use the `delay()` function.

In the example `01-delay` the [delay()](https://www.arduino.cc/reference/en/language/functions/time/delay/) is used to
switch on /off a led.
The delay is a blocking function, it means that during the delay the program annot do other things, it is blocked.
The processor can't do anything else while it is blinking.

*Questions*:

- try to add another led and try to blink them simultaneously every second.

## Use the `millis()` function

The function [millis](https://www.arduino.cc/reference/en/language/functions/time/millis/) returns the number of
milliseconds passed since the program started.
This number will overflow (go back to zero), after approximately **50 days**.

*Example Code*:

Use the millis()  to prints on the serial port the number of milliseconds passed since the Arduino board started running
the code itself.

```c
unsigned long myTime;

void setup() {
  Serial.begin(9600);
}
void loop() {
  Serial.print("Time: ");
  myTime = millis();

  Serial.println(myTime); // prints time since program started
  delay(1000);              // wait a second so as not to send massive amounts of data
}
```

The result is as follows:

```aidl
Time: 0
Time: 999
Time: 1999
Time: 3000
Time: 4000
Time: 5000    <- after 5 seconds the reset button is pressed
Time: 0       <- the milliseconds passed are resetted
Time: 999
Time: 1999
```

We can use the millis function to check if a certain amount of time is passed.

```c
unsigned long previousMillis;
int period = 1000; // milliseconds period 

void setup() {
  Serial.begin(9600);
}
void loop() {
  long currentMillis = millis();

  if (currentMillis - previousMillis >  period){
    previousMillis = currentMillis;
    Serial.print("The elapsed milliseconds are: "); 
    Serial.println(period);
  }
}
```

The result is that every second the print is executed

```aidl
11:52:58.369 -> The elapsed milliseconds are: 1000
11:52:59.364 -> The elapsed milliseconds are: 1000
11:53:00.391 -> The elapsed milliseconds are: 1000
11:53:01.387 -> The elapsed milliseconds are: 1000
```

In the example `02-BlinkWithMIllis` the *millis()* function to switch on /off a led without relying on delay().
`BlinkWithoutMillis` remembers the current state of the LED and the last time it changed.
On each pass through the loop, it looks at the millis() clock to see if it is time to change the state of the LED again.

Questions:

- add another led and blink it at a different rate.
- how it is possible to have different time when the led is on and the led is off ? every 5 second switch on the led for
  2 seconds

### Flash with (using a state machine)

#### State + Machine = State Machine

Note that we have variables to keep track of whether the LED is ON or OFF.  
And variables to keep track of when the last change happened.  
That is the State part of the State Machine.

We also have code that looks at the state and decides when and how it needs to change.
That is the Machine part.  
Every time through the loop we ‘run the machine’ and the machine takes care of updating the state.