#define ledpin 2
#define porpin A0
int valorpot;

void setup(){

  pinMode(ledpin, OUTPUT);
 
}

void loop(){ 
 
  valorpot = analogRead(porpin);
  analogWrite(ledpin, valorpot / 4);
  delay(500);
}