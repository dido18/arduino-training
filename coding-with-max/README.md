

# Coding with Massimo

This training are inspired by the  `Coding With Massimo` lessons.

Sessions
- part 1:  (1 Marzo 2023)
  - Story Arduino
  - Arduino Start Kit
  - First Sketch: Blink a led. 
  - First Circuit: Blink with a resistor
  - Sketch: Blink with a button
  - Sketch: Servo Motor
- part 2: I2C + Cloud 


## Part 1
 - materiale per 3 gg  + 2 gg di progettino
 

## Story 
Arduino: nasce come strumento per insegnare interaction design.
Il nome deriva dal bar `Arduino` situato a Ivrea (che ora non esiste più) in cui Massimo Banzi era noto frequentare per fare aperitivo.
Inizialmente è stato dato questo nome dicendo "tanto si può sempre cambiare" poi è rimasto quello.


Loop of the interaction design:
- design
- build
- repeat

Chiudere il loop in maniera facile è lo scopo iniziale di arduino con una scheda semplice da programmare con un ambiente di sviluppo intuitivo.

Arduino si inpira a Processing (https://processing.org/).
Un linguaggio di programmazione che nasce al MIT per insegnare a programmare agli interaction designers
Arduino è inspirato da Processing ma collegato all'hardware.

Inolte Arduino

### Main components

- Sensors
- microntroller 
	- *AVR* : e uno dei primo nasce da un progettto niversitario nelgli anni 90.Rese standarad l'utilizzo della memeoria flash  inel processore. Avere una memorua flash nel microprocessore permette di riprogrammare il controllore più  volte.
- Actuators
- Arduino IDE: facilitare 

## Intro Arduino starter KIT
- è basato su 15 progetti dove la scatola ( basata su 400 prototipi :) 

### board: Arduino uno (R3)
in fase di creazione della board viene flashato un firmware che fa lampeggiare la luce verde.
- usb: è stata una rivoluzione perchè gli altri avevano la seriale 

> [!definition] Time to blink
> Indica il tempo richiesto che passa da quando prendi la scheda la e risce a fare lampeggaire un led

- core arduino: un libreria in C++ che astre dal processore.  In arduino la funzione main si trava nel file ``#inclde arduino ` 


### Tutorial steps 

#### Connect led to Arduino board
1. connect the first led (red): 
   1. prendere un led
   2. collegare il piedino corto su GND e lungo su pin 13 (direttamente sulla scheda)

#### First sketch

``` c
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);// initialize digital pin LED_BUILTIN as an output.
}
  
// the loop function runs over and over again forever
void loop() {
	digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
	delay(1000); // wait for a second
	digitalWrite(LED_BUILTIN, LOW); // turn the LED off by making the voltage LOW
	delay(1000); // wait for a second
}
```

Spiegazione cose fondamentali:
- `OUTPUT` e `LED_BUILTIN`: sono macro definite da arduino
- `pinMode` è una funione che ..
- `digitalWrite` é una funzione che fa parte dell'**alfabeto di Arduino**
- `delay`: mette a riposo la scheda.


> [!definition] Alfabeto di Arduino
> Sono un set comandi che sono fondamentali che puoi fare "tutto" e sono comandi ortogonali (`analogRead` and `analogWrite`)


Steps:
 - modifiare il delay da 400 a 3000
 - autodetect: notare che la scheda viene riconosciuta in automatico (cosa molto innovativa)

Notare
- la `digitalWrite` è il primo esempio di collegamenteo tra il modo software e l'hardware.

Next
- usare le costanti `const` per definire 


``` c
const in LED = 13;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);// initialize digital pin LED_BUILTIN as an output.
}

void loop() {
	digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
	delay(1000); // wait for a second
	digitalWrite(LED_BUILTIN, LOW); // turn the LED off by making the voltage LOW
	delay(1000); // wait for a second
}
```


Questions: 
 - What happens if delay is very small ?? rimane sempre accesso
 - what happens if delays are differente (say 3 and 7) ? la percezione è che il led è sempre accesso ma è meno luminoso.
	 - si introduce il concetto di `PWM` . La differenza tra tutto il period e il duty (accesso).  La percentuale dil duty cycle ci dice la luminosita. che sfrutta la pesistenza dell'immagine dell'occhio. quindi accendendo e spegnendo un led cont tempi diversi, la percezione è che la luminosità è inferiore.

  #### First circuit 

- *breadboard*: il vnataggio   è che posso collegare i componenti tra di loto in modo facile sperimentando.
	- Il nome vero è solderless breadboard 

- *resistenza*: è un componente che "resiste" il flusso di corrente.  
	- attaccare la resistenza al gmabo corto del led.
	- 
``` c
const int pinLed = 9;

void setup() {
  pinMode(pinLed, OUTPUT);
}

void loop() {
  digitalWrite(pinLed, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(1000); // wait for a second
  digitalWrite(pinLed, LOW); // turn the LED off by making the voltage LOW
  delay(1000); // wait for a second
}
```


Esercizio
- Fare "respirare" il led con un fead in and fead out.
```c
/ the setup function runs once when you press reset or power the board

void setup() {

// initialize digital pin LED_BUILTIN as an output.

pinMode(LED, OUTPUT);

}

  

int fadeValue = 0; // max 255 values

int increase = 1;

void loop() {

analogWrite(pinLed, fadeValue); // turn the LED on (HIGH is the voltage level)

delay(30);

  

if (increase == 1){

fadeValue = fadeValue + 5;

}else{

fadeValue = fadeValue + 5;

}

if (fadeValue >= 255){

increase = 0;

}

if (fadeValue <= 0){

increase = 1;

}

  

}
```

#### Button and led


- `Corrente`:Spiegazione della corrente eletrrica come se fosee dell'acqua che passa nel tubo (fili).
- circuito:

``` c
const int LED = 13;
const int BUTTON = 7;
int val = 0;

void setup() {
pinMode(LED, OUTPUT);
pinMode(BUTTON, INPUT); // the BUTTON is an input
}

void loop() {
	val = digitalRead(BUTTON);
	// TODO: mettere delay(100) . per sperimentare di quanti millisecondi devono passare per rendere frustrante l'interazione con l'hardware
	if (val == HIGH){
		digitalWrite(LED, HIGH);
	}else{
		digitalWrite(LED, LOW);
	}
}
```

Questions:
- // TODO: mettere delay(100) prima dellif? . per sperimentare di quanti millisecondi devono passare per rendere frustrante l'interazione con l'hardware 
- togliere la resistenza, cosa succede ? se tocco i fili che va al in 7 il led si accede. perché ? come succede con gli amplificari audio, che se i piedini di ingresso di arduino sono sensibili che sono `floating` che 

Extensions
- metter un sensore di luce (connettere corto su resistenza e lunga su 5v), si ottiene un sesnosere di luce che accende il led.
- `analogRead`: connettere il pin collegato al ping lungo al pin A0. 
 
```c
int val = 0;

void setup() {
	Serial.begin(9200);
}

void loop() {
	val = analogRead(0);
	Serial.println(val);
	delay(100);
}
```


Idee
- fare un sensore di pressione con una spugna e due fili infilati dentro. pigiando la spugna la resistenza diminuisce.

##### Servo motore tamite analogRead
Example /servo/sweap


```c
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
	val = map(val, 0, 1023, 0, 255);
	val = constrain(val, 0, 180);
	s.write(val);
	Serial.println(val);
}
```

note on functon
- `map`
- `constraint` 

Esercizio
- fare un esercizio che usi: sensore si luce, servo motore che faccia qualcosa. Eg. un robottino che se gli metti davanti la mano prende paura.


*Serial communication*


#### Multple leds


Exercise.
 - fare il gioco del [simon](https://it.wikipedia.org/wiki/Simon_(gioco)): 4 pulsanti, 4 led e il cicalino.


## Part 2

8 march 2023

Material:
- Oplà kit

Concepts:
- I2C
- Interrupt ??

Other resource:
- https://www.youtube.com/@BenEater 

### I2C 
https://en.wikipedia.org/wiki/I%C2%B2C
The I2C was a I2C trademark symbol so can be used but with a different name (`TWI` Two Wire Interface). 
The i2C library in Arduino is called `wire` for this reason.

Every sensor has a unique address. This address is defined in the fabric. 
If there are sensors with the same address there is a problem.  
Some sensor the address can be changed (but not all).

There are two wires:
- SDA: the data transfer
- SCL: the clock signal 

Having two wires is important because the processor use the SCl to generate the clock and all the attached device follow that clock.

The standard speed communication is from 100 kbit/s to 5 Mibit/s.

Examples of I2c sensors: 
 - BNo055: https://www.bosch-sensortec.com/products/smart-sensors/bno055/ https://github.com/arduino-libraries/BNO055
 - TinkerKit Basic: is a connector to allow connection without error 

List of I2C devices
- https://i2cdevices.org/devices

The I2C sensor has also a `interupt` pin. The sensor can write into this sensor.


There is also a `I3C` specification `https://en.wikipedia.org/wiki/I3C_(bus)`

#### Oplà kit with I2C

[`ESLOV`](https://www.duffyfilm.com/arduino-introducing-eslov-iot-invention-kit/): Era un sistema to make the sensor intelligent. So that the sensor is able to preprocess the data, and the 
processor is able to read the data already processed. ESLOV è un villaggio della Svezia. Sulle board è rimasto questo attacco ma il sistema ESLOV non c'è più.




- Exercise 1: Show accelerometer from IotCarrier

```c++
/*
  Arduino LSM6DS3 - Simple Accelerometer

  This example reads the acceleration values from the LSM6DS3
  sensor and continuously prints them to the Serial Monitor
  or Serial Plotter.

  The circuit:
  - Arduino Uno WiFi Rev 2 or Arduino Nano 33 IoT

  created 10 Jul 2019
  by Riccardo Rizzo

  This example code is in the public domain.
*/

#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!carrier.IMUmodule.begin()) {
    Serial.println("Failed to initialize IMU!");

    while (1);
  }

  Serial.print("Accelerometer sample rate = ");
  Serial.print(carrier.IMUmodule.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Acceleration in G's");
  Serial.println("X\tY\tZ");
}

void loop() {
  float x, y, z;

  if (carrier.IMUmodule.accelerationAvailable()) {
    carrier.IMUmodule.readAcceleration(x, y, z);

    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);
  }
}

```


note 
- `carrier.IMUmodule.accelerationAvailable()` is a method to check if there is data on buffer 


Show the internal of the [Arduino_LS](https://github.com/arduino-libraries/Arduino_LSM6DS3)

- the define are used to set the address
- class: to encapsulate code and usually it has `begin` and `end` function. 

Extension
 - Add the temperature https://github.com/arduino-libraries/Arduino_HTS221
- usa il singleton, ma era un modo per semplificare. Adesso non si usa più ma si istanzia l'oggetto.

### Motors


DC motors

  - diodo 
  - MOSFET 
  - H-bridge: sono 4 mosfet. Usato per poter indicare anche la velocità e avanti e indietro.
    - `L293D`: ha 2 modalità
      - 1: 2 motori in velocità e direzione
      - 2: 4 motori solo un direzione


ADC motors
