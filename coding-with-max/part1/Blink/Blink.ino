const int LED = 13;
const int BUTTON = 7;

int val = 0;

void setup() {
  Serial.begin(9200);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT); // the BUTTON is an input 
}

void loop() {
  val = digitalRead(BUTTON);  
 // TODO: mettere delay(100) .  per sperimentare di quanti millisecondi devono passare per rendere frustrante l'interazione con l'hardware
  if (val == HIGH){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }
}