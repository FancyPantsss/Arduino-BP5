//Bron: https://docs.arduino.cc/built-in-examples/control-structures/ForLoopIteration
//Opdracht 1
//Gemaakt door: Nina Schrauwen

//timer definieren als variabele die niet verandert -> timer is voor de delay
const int timer = 100;

void setup() {
  // put your setup code here, to run once:
  //Deze code zegt loop door de leds vanaf ledpin 1 tot 8 en niet hoger.
  for(int thisPin = 1; thisPin < 9; thisPin++ ){
    //De ledpin is een vorm van output
    pinMode(thisPin, OUTPUT);
  }
}
void loop() {
  // put your main code here, to run repeatedly:

  //Deze code loopt van ledpin 1 tot en met 8. 
  for(int thisPin = 1; thisPin < 9; thisPin++){

    //De ledpin gaat eerst aan, dan volgt een timer v. 100ms, dan gaat de led uit.
    digitalWrite(thisPin, HIGH);  //led aan
    delay(timer);                 //delay van 100ms
    digitalWrite(thisPin, LOW);   // led uit
    
  }// einde for loop

  //Deze code loopt van ledpin 8 tot en met 1.
  for(int thisPin = 8; thisPin > 0; thisPin--){

    //De ledpin gaat eerst aan, dan volgt een timer v. 100ms, dan gaat de led uit.
    digitalWrite(thisPin, HIGH);  //led aan
    delay(timer);                 //delay
    digitalWrite(thisPin, LOW);   //uit
  }  //einde for loop
    
} //einde loop
