//Opdracht 4
//https://arduinopoint.com/lm35-arduino-project/
//Gecodeerd door Nina Schrauwen

const int tempSens = A1;
const int timer = 1000;

int reading = 0;
float tempCel = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //start de seriele communicatie om de waarden (temp) in de monitor uit te kunnen lezen
}

void loop() {
  // put your main code here, to run repeatedly:
  reading = analogRead(tempSens); //lees de temp. sensor uit en geef de waarde aan de variabele

  tempCel = reading * (500 / 1024.0);  //omrekenen naar graden celcius

  Serial.print("Temperatuur in graden Celcius   = ");
  Serial.print(tempCel);   //print de temp ni Celcius
  Serial.print("\xB0"); //Graden symbool laten weergeven
  Serial.print("C");
  Serial.print("\n");  //nieuwe regel

  delay(timer);  //vertraging van 1 seconde
}
