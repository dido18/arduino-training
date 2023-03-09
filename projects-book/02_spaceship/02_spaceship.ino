const int buttonPin = 2;

const int led1Pin = 3; // green Led
const int led2Pin = 4;
const int led3Pin = 5;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);

  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
}

void loop() {
  int val;
  val = digitalRead(buttonPin);
  if (val == LOW){
    digitalWrite(led1Pin, HIGH);  // green led on
    digitalWrite(led2Pin, LOW);   // red led off
    digitalWrite(led3Pin, LOW);   // red led off
  }else{
    digitalWrite(led1Pin, LOW);
    
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, HIGH);
    delay(250);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, LOW);
    delay(250);
  }

}
