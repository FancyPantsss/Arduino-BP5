//Opdracht 8: Infrarood + 4 leds + millis();
//Geschreven door: Nina Schrauwen
// 0 = FD30CF, 1 = FD08F7, 2 = FD8877, 3 = FD48B7, 4 = FD28D7
// 5 = FDA857, 6 = FD6897, 7 = FD18E7, 8 = FD9867, 9 = FD58A7
#include <IRremote.h> // IR remote library importeren

//constante variabelen definieren
const int infraPin = 11;
const int ledPins[] = {2, 3, 4, 5};
const int timer = 100;
int flickerTimes[] = {100, 200, 300, 400};  //snelheid knipperen 
//Niet constante variabelen definieren
int ledStatus[] = {LOW, LOW, LOW, LOW};
int flickering = 0;  //kijken welke led er aan het knipperen is 
int ledsAan[]= {1, 1, 0, 0};   //de eerste 2 leds horen aan te staan - is dit nodig?
int activeFlicker = 0;                // welke led is er geselecteerd op dat moment 


unsigned long lastTimes[] = {0, 0, 0, 0};

//infraroodpin definieren
IRrecv irrecv(infraPin); 
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //seriele communicatie starten
  
  //input en outputs definieren
  irrecv.enableIRIn();
  pinMode(ledPins[0], OUTPUT);
  pinMode(ledPins[1], OUTPUT);
  pinMode(ledPins[2], OUTPUT);
  pinMode(ledPins[3], OUTPUT);

}

void flickerLed(){  //functie voor het knipperen voor het knipperen van de leds 
  unsigned long currentTime = millis();
  for(int i : ledPins)  //loopen door de ledpins 
  {
    //Serial.println(knippert);
    i = i-2;  //de leds beginnen bij 2 maar het tellen moet bij 0 beginnen
    //Serial.println(i);
    if( true ) // i0 = led4 i1 = led3, i2 = led2, i3 = led1     
    {
      if(currentTime - lastTimes[i] >= flickerTimes[i] && flickerTimes[i] != 0)  //de led die op dat moment in de loop is gaat knipperen door de millis functie, vervolgens weer volgende ledpin
      {
      lastTimes[i] = currentTime;
      ledStatus[i] = (ledStatus[i] == LOW) ? HIGH : LOW;
      digitalWrite(ledPins[i], ledStatus[i]);
      //Serial.print("Ledstatus: ");
      //Serial.println(ledStatus[i]);
      //Serial.print("i = ");
      //Serial.println(i);  //i = 2, ledStatus van 0 naar 1 van 1 naar 0
      }
    }
  
  }
}

void loop() {
  flickerLed();  //functie voor het knipperen aanroepen
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results))      //als de infrarood een signaal krijgt print dan de hexadecimale waarde luister daarna naar nieuwe signalen
  {
    Serial.println("Hex value: ");
    Serial.println(results.value, HEX);
    irrecv.resume();
    if(flickering != 0)  //selecteer snelheid
      { 
        switch(results.value)       //Kijken welke knop is ingedrukt 
        {
          case 0xFD28D7:            //Knop 4 = -OFF- in Tinkercad waarden
            activeFlicker = 0;
            for(int i : flickerTimes){
              if(i != 0)
              {
                activeFlicker++; //tel op hoeveel leds er actief aan het knipperen zijn
              }
            }
            
            if(activeFlicker > 2)              // Als er nog geen 2 leds aan het knipperen zijn 
            {
              flickerTimes[flickering - 1] = 0; //hij knippert niet als de flickertimes 0 is -1 omdat het tellen bij 0 begint ipv 1
              digitalWrite(ledPins[flickering - 1], LOW); //Led uitzetten die geselecteerd is 
              Serial.println("uit geselecteerd");
              Serial.println(flickerTimes[flickering - 1]);
				      Serial.println(flickering - 1);
            } else {
              Serial.println("al 2 uit");
              Serial.println(activeFlicker);
              }
          break;
          case 0xFD30CF:            //Knop 0 in Tinkercad waarden
            flickerTimes[flickering - 1] = random(8000, 15000);   //begint anders bij 1, terwijl array begint bij 0 // was 100
            Serial.println("snelheid 1 geselecteerd"); //snelheid random tussen de 8000 en de 15000ms
          break;

          case 0xFD08F7:            //Knop 1 in Tinkercad waarden
            flickerTimes[flickering - 1] = 200; //snelheid 200 geselecteerd 
            Serial.println("snelheid 2 geselecteerd");
          break;

          case 0xFD8877:            //Knop 2 in Tinkercad waarden
            flickerTimes[flickering - 1] = 300;    
            Serial.println("snelheid 3 geselecteerd"); //snelheid 300 geselecteerd 
          break;

          case 0xFD48B7:            //Knop 3 in Tinkercad waarden
            flickerTimes[flickering - 1] = 400;
            Serial.println("snelheid 4 geselecteerd");  //snelheid 400 geselecteerd
          break;

		  case 0xFFFFFFFF: //failsafe, geen knop gevonden
            break;
          
       }
      flickering = 10;  //er zijn 10 knoppen op de IR remote
    }
    if( flickering == 0 )  //welke led is er geselecteerd op dat moment
    {
      switch(results.value)       //Kijken welke knop is ingedrukt 
      {
        case 0xFD30CF:            //Knop 0 in Tinkercad waarden
          flickering = 1;    
        Serial.println("led 1 geselecteerd");
          break;

        case 0xFD08F7:            //Knop 1 in Tinkercad waarden
          flickering = 2; 
        Serial.println("led 2 geselecteerd");
          break;

        case 0xFD8877:            //Knop 2 in Tinkercad waarden
          flickering = 3;   
        Serial.println("led 3 geselecteerd");
          break;

        case 0xFD48B7:            //Knop 3 in Tinkercad waarden
          flickering = 4;
        Serial.println("led 4 geselecteerd");
          break;

        case 0xFFFFFFFF: //failsafe geen knop gevonden
          break;
    }
	
      
  }
    if(flickering == 10) flickering = 0;  //reset naar 0 wanneer de waarde op 10 komt
  delay(timer);
  }
}
