//opdracht 3
//Gemaakt door Nina Schrauwen

//ledpins als contanten definieren omdat ze vast staan
const int led1 = 8;    
const int led2 = 2;
const int led3 = 3;
const int led4 = 4;
const int led5 = 5;
const int led6 = 6;
const int led7 = 7;
const int potMeter = A1; //analoge ingang
const int timer = 50;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  //start de seriele communicatie
  
  //Leds definieren als output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //gebruik de map functie om vanaf een bepaalde waarde de leds aan te zetten
  digitalWrite(led1, map(analogRead(potMeter), 0, 400, 0, 1));  //zoals bijvoorbeeld bij waarde 400 gaat de eerste led branden
  digitalWrite(led2, map(analogRead(potMeter), 0, 500, 0, 1));
  digitalWrite(led3, map(analogRead(potMeter), 0, 600, 0, 1));
  digitalWrite(led4, map(analogRead(potMeter), 0, 700, 0, 1));
  digitalWrite(led5, map(analogRead(potMeter), 0, 800, 0, 1));
  digitalWrite(led6, map(analogRead(potMeter), 0, 900, 0, 1));
  digitalWrite(led7, map(analogRead(potMeter), 0, 1000, 0, 1));  //Bij de waarde 1000 horen alle leds tegelijkertijd aan te zijn
}
