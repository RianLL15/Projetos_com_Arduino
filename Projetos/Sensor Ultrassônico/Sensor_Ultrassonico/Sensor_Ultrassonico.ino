#include <NewPing.h>

#define TRIGGER_PIN  12  
#define ECHO_PIN     11  
#define MAX_DISTANCE 200 //Defina a distância maxima

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

void setup() {
  Serial.begin(9600); 
}

void loop() {
  delay(50);                     
  Serial.print("Distância: ");
  Serial.print(sonar.ping_cm()); 
  Serial.println("cm");
}
