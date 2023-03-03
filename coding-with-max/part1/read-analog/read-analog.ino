#include <Servo.h>

int val = 0;
const int sensorPin = 0;
const int servoPin = 9;

Servo s;

void setup() {
  Serial.begin(9200);
  s.attach(servoPin);
}

void loop() {
  val = analogRead(0);
  Serial.print(val);
  Serial.print(",");
  // il servo motore accetta solo i valori: 0-179
  // mi aspetto un moero tra `1,1023] e viene mappato in [0,255]
  val = map(val, 0, 1023, 0, 180);
  val = constrain(val, 0, 180);
  s.write(val);
  Serial.println(val);
}
