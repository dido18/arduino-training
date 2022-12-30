 
unsigned long previousMills1 = 0;
long onTime1 = 2000;
long offTime1 = 3000;
int ledState1 = LOW;
const int ledPin1 =  13; 

unsigned long previousMills2 = 0;
long onTime2 = 350;
long offTime2 = 750;
int ledState2 = LOW;
const int ledPin2 =  12; 

void setup() {
    pinMode(ledPin1, OUTPUT); 
    pinMode(ledPin2, OUTPUT);
    Serial.begin(9600);
}

void loop() { 
  unsigned long currentMillis = millis();

 if ((ledState1 == HIGH) && currentMillis - previousMills1 >= onTime1){
    ledState1 = LOW;
    previousMills1 = currentMillis;
    digitalWrite(ledPin1, ledState1);
  }
  else if ((ledState1 == LOW) && currentMillis - previousMills1 >= offTime1){
     ledState1 = HIGH;
     previousMills1 = currentMillis;
     digitalWrite(ledPin1, ledState1);
  }

  if ((ledState2 == HIGH) && currentMillis - previousMills2 >= onTime2){
    ledState2 = LOW;
    previousMills2 = currentMillis;
    digitalWrite(ledPin2, ledState2);
  }
  else if ((ledState2 == LOW) && currentMillis - previousMills2 >= offTime2){
     ledState2 = HIGH;
     previousMills2 = currentMillis;
     digitalWrite(ledPin2, ledState2);
  }


         
}
