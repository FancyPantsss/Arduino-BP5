//Bron is https://www.gadgetronicx.com/driving-rgb-led-pwm-signal/
//Opdracht 5
//Gecodeerd door Nina Schrauwen

//constante variabelen initializeren
const int ledPin1 = 11;
const int ledPin2 = 10;
const int ledPin3 = 9;
const int timer = 1;

//variabelen die nog kunnen veranderen initializeren
int valR = 0;
int valG = 0;
int valB = 0;

void setup() {
  // put your setup code here, to run once:
  
  //outputs definieren
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  loopColour(); //loop door de functie loopColour heen

}


void loopColour(){

  for(valB = 0; valB <= 255; valB++){   //loop door iedere mogelijke variabelen van blauw heen
    analogWrite(ledPin1, valB);
    
      for(valG = 0; valG <= 255; valG++){  //loop door iedere mogelijke variabelen van groen heen
        analogWrite(ledPin2, valG);

          for(valR = 0; valR <= 255; valR++){  //loop door iedere mogelijke variabelen van rood heen
            analogWrite(ledPin3, valR);
            delay(timer);
            
            
          } //einde nested for loop valR
          
      } // einde nested for loop valG
    
  } // einde for loop valB
  
} // einde funtie loopColour();
