const int sensorPin = A0;
const int led1Pin = 3;
const int led2Pin = 4;
const int led3Pin = 5;

const float baselineTemperature = 15;


void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
}

void loop() {
  int sensorVal = analogRead(sensorPin);       // ADC reads value from 0-1023
  float voltage = (sensorVal / 1024.0) * 5.0;  // convert ADC analog read from 0-1023 to a voltage 0-5
  float temperature = (voltage - .5) * 100;    // convet volt to temperature:  every 10 millivots of change is equivalent to 1 degree celsuis.

  Serial.print("sensorVal:");
  Serial.print(sensorVal);
  Serial.print(" Voltage: ");
  Serial.print(voltage);
  Serial.print(" Temperature: ");
  Serial.print(temperature);
  Serial.println();

  if (temperature >= baselineTemperature && temperature < baselineTemperature + 3) {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
  } else if (temperature >= baselineTemperature && temperature <= baselineTemperature + 6) {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, LOW);
  } else if (temperature > baselineTemperature + 6) {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, HIGH);
  } else {
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
  }
  delay(1);
}
