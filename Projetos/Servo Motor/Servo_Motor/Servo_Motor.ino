#include <Servo.h>
 
Servo servo;
 
const int pinoPOT = A0; 
const int pinoServo = 3; 
 
int leituraA0;      
  
void setup(){
  servo.attach(pinoServo); 
  pinMode(pinoPOT, INPUT);
} 
void loop(){ 
  leituraA0 = analogRead(pinoPOT);  
  leituraA0 = map(leituraA0, 0, 1023, 0, 180); 
  servo.write(leituraA0); 
  delay(1); 
}
