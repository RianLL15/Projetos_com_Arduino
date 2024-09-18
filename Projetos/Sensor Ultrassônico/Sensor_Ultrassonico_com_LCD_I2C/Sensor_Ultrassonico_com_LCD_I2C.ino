#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

#define TRIGGER_PIN  12  
#define ECHO_PIN     11

long distancePol;

void setup()
{

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Iniciando...");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);  
  lcd.print("Dist.1:");
  lcd.setCursor(0,1);
  lcd.print("Dist.2:");
}

void loop()
{
  long duration, distance;
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration/2) / 29.1;
  distancePol = duration*0.0133/2;
  lcd.setCursor(9,0);   
  lcd.print("                         ");  
  lcd.setCursor(9,0);    
  lcd.print(                distance); 
  lcd.print(" cm");  
  lcd.setCursor(9,1);  
  lcd.print("                         "); 
  lcd.setCursor(9,1);   
  lcd.print(distancePol);
  lcd.print(" pol");  
  delay(200); 
}