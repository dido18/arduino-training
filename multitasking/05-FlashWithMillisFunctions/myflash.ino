
void myflash(long *prevMillis, int *ledState, int ledPin, long ledOnTime, long ledOffTime) {
  long currentMillis = millis();
  if ((*ledState == HIGH) && (currentMillis - *prevMillis > ledOnTime)) {
    Serial.println("switiching LOW");
    *prevMillis = currentMillis;
    *ledState = LOW;
    digitalWrite(ledPin, *ledState);
  } else if ((*ledState == LOW) && (currentMillis - *prevMillis > ledOffTime)) {
    *prevMillis = currentMillis;
    Serial.println("switiching OFF");

    *ledState = HIGH;
    digitalWrite(ledPin, *ledState);
  }
};