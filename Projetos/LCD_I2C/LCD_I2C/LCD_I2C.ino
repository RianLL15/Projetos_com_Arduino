#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);   

void setup() {
  lcd.init();     
  lcd.clear();  
  lcd.backlight();  
}
void loop() {
  lcd.setCursor(2, 0); 
  lcd.print("Ola Mundo");
  delay(1000);               
  lcd.clear(); 
  lcd.setCursor(2, 0); 
  lcd.print("Estou me");
  lcd.setCursor(2, 1);   
  lcd.print("Comunicando");  
  delay(1000);               
  lcd.clear();   
  lcd.setCursor(2, 0); 
  lcd.print("Pelo LCD");
  delay(1000);               
  lcd.clear();              
}