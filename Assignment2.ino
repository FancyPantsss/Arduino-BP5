//Bron is: https://forum.arduino.cc/t/counting-number-of-times-a-button-is-pushed/188166/2
//Opdracht 2
//Gemaakt door: Nina Schrauwen

//Constante variabelen die niet veranderen.
const int led = 11;
const int btn = 12;
const int timer = 50; // delay

//Variabelen die zullen veranderen door het proces heen.
int counter = 0;
int buttonStatus = 0;
int lastButtonStatus = 0;

void setup() {
  // put your setup code here, to run once:
  //Led lampje geeft de output in deze situatie en de knop geeft de input.
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 //Het uitlezen van de input van de knop, ofterwijl of de knop wordt ingedrukt of niet.
 buttonStatus = digitalRead(btn);

//De huidige status wordt vergeleken met de vorige status, namelijk of die niet hetzelfde zijn.
 if(buttonStatus != lastButtonStatus){
    //Als de knop ingedrukt wordt dan wordt er 1 bij de teller opgeteld.
    if(buttonStatus == HIGH){
      counter += 1;
    }
     
 }

//De huidige status wordt nu omgezet naar de vorige status.
 lastButtonStatus = buttonStatus;

  //Als de teller gedeeld door 2 0 oplevert dan wordt het led lampje aangezet.
  if(counter % 2 == 0){
    digitalWrite(led, HIGH);
   }
   //Als de teller gedeeld door 2 geen 0 oplever dan wordt het led lampje uitgezet.
    else{
      digitalWrite(led, LOW);
      }

  //Het duurt 50 miliseconden voordat je weer het lampje aan of uit kan zetten.    
  delay(timer);    
    
 
}
