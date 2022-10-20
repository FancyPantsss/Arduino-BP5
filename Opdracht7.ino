//opdracht 7 servo + ultrasoon 
//Nina Schrauwen
#include <Servo.h>  //servo implementeren

//servo definieren
Servo servo;

//constanten definieren
const int trigPin = 7;
const int echoPin = 6;

//niet constanten definieren
float time;
float distance;
int pos;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //seriele communicatie starten
  servo.attach(9);  //servo aangesloten op deze pin
   
   //inputs en output definieren
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float readUltra(){   //ultrasoon uitlezen
  // put your main code here, to run repeatedly:
  //uit 
  digitalWrite(trigPin, LOW); //triggerpin low zetten
  delayMicroseconds(5); //wacht tot de triggerpin ook echt uit is 

  //aan
  digitalWrite(trigPin, HIGH); //ultrasoon aanzetten
  delayMicroseconds(10);

  //uit
  digitalWrite(trigPin, LOW); //triggerpin uitzetten
  return pulseIn(echoPin, HIGH); //echopin aanzetten
}

void loop() {
  // put your main code here, to run repeatedly:
  time = readUltra();  //lees ultrasoon via de functie
  distance = time / 58;
  pos = constrain(map(distance, 4, 10, 180, 0), 0, 181); //de servo motor kan draaien tussen de 0 en 180 graden op basis van de gegeven afstand
  
  //reset wanneer 181 graden is bereikt anders werkt de functie niet meer
  if(pos == 181){ 
    servo.write(0);
  } else servo.write(pos);
}
