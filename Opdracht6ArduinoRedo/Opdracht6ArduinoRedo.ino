//Bron: https://docs.arduino.cc/learn/electronics/servo-motors
//Geschreven door Nina Schrauwen

#include <Servo.h>

Servo servo;

//Vaste en flexibele variabelen definiëren.
const int BTN = 12;
const int BTN2= 2;

int btn_status = LOW;
int btn_status2 = LOW;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   //start seriele communicatie -- om print statements te kunnen maken in de monitor
  servo.attach(4);      //meegeen op welke pin de servo zit aangesloten

  pinMode(BTN, INPUT);    //inputs definiëren aan de variabelen
  pinMode(BTN2, INPUT);

} //end setup

void standstill()    //functie om de servo zijn positie te houden voor 2 seconden.
{
  if(pos == 120)     //als de positie op 120 graden staat
  {
    servo.write(pos);   
    delay(2000);    //dan op die positie 2 seconden wachten
  } //end if pos
} // end standstill()


void loop() {
    // put your main code here, to run repeatedly:
  btn_status = digitalRead(BTN);       //knoppen uitlezen 1 = HIGH, 0 = LOW
  btn_status2 = digitalRead(BTN2);

  //Serial.println(btn_status);
  //Serial.println(btn_status2);
  
  if(btn_status == HIGH && btn_status2 == HIGH)  //als beiden knoppen ingedrukt wordt dan..
  {
    Serial.println("Pressed");
    for(pos = 0; pos <=120; pos++)     //..dan vanaf 0 tot 120 graden draaien, in stapjes van 1 graden omhoog
    {
      servo.write(pos);                //de positie wordt bepaald door de waarden in de for loop
      //Serial.println(pos);
      delay(1000/120); // 1 seconde wachten {gewenste duur miliseconden} / {aantal graden} == juiste delay voor de gewenste tijd
      standstill();   // voer de functie standstill uit zodat de servo op zijn plek blijft voor 2 seconden, enkel wanneer de positie 120 graden is
    } //end for btn2 ++

    

    for(pos = 120; pos >=0; pos--)   //eigenlijk precies dezelfde loop als de vorige echter gaat deze van 120 graden naar 0, dus precies de andere kant op terug naar de beginpositie
    {
      servo.write(pos);
      //Serial.println(pos);
      delay(1000/120);   // 1 seconde wachten {gewenste duur miliseconden} / {aantal graden} == juiste delay voor de gewenste tijd
    } //end for btn2 --
  } //end if btn + btn2
  
  if(btn_status == LOW && btn_status2 == LOW) //als er geen knoppen ingedrukt worden dan..
  {
    servo.write(0);                       // neem de positie 0 (graden) aan en blijf daar
  } //end if buttons off
  

  if(btn_status == HIGH && btn_status2 == LOW)  //als de eerste knop ingedrukt wordt dan..
  {
    for(pos = 0; pos <=120; pos++)   //..dan in stapjes van 1 van 0 tot en met 120 graden draaien
    {
      servo.write(pos);             //servo neem de positie aan van het aantal graden dat wordt gegeven door de for loop
      //Serial.println(pos);
      delay(1000/120);   // 1 seconde wachten {gewenste duur miliseconden} / {aantal graden} == juiste delay voor de gewenste tijd
    } //end for btn ++

    for(pos = 120; pos >=0; pos--) //eigenlijk precies dezelfde loop als hiervoor maar dan andersom, van 120 naar 0 graden
    {
      servo.write(pos);
      //Serial.println(pos);
      delay(1000/120);   // 1 seconde wachten  {gewenste duur miliseconden} / {aantal graden} == juiste delay voor de gewenste tijd
    } //end for btn --
  } //end if btn



  if(btn_status == LOW && btn_status2 == HIGH) //als de tweede knop ingedrukt wordt dan..
  {
    for(pos = 0; pos <=120; pos++)   //..dan in stapjes van 1 van 0 tot en met 120 graden draaien
    {
      servo.write(pos);           //servo neem de positie aan van het aantal graden dat wordt gegeven door de for loop
      //Serial.println(pos);
      delay(500/120);   // 0,5 seconde wachten {gewenste duur miliseconden} / {aantal graden} == juiste delay voor de gewenste tijd
    } //end for btn2 ++

    for(pos = 120; pos >=0; pos--)   //eigenlijk precies dezelfde loop als hiervoor maar dan andersom, van 120 naar 0 graden
    {
      servo.write(pos);
      //Serial.println(pos);
      delay(500/120);   // 0,5 seconde wachten {gewenste duur miliseconden} / {aantal graden} == juiste delay voor de gewenste tijd
    } //end for btn2 --
  } //end if btn2

} //end loop()