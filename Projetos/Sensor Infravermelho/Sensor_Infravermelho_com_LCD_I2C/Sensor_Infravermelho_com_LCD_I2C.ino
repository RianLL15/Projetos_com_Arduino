
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); 

int sensor = 7;

void setup()
{
  lcd.init();
  lcd.backlight(); 
  pinMode (sensor, INPUT);
}

void loop()
{
  int estado; 
  estado = digitalRead(sensor);

  if(estado == 0)
  {
  lcd.setCursor(0, 0); 
  lcd.print("Objeto Detectado");
  delay(1000);               
  lcd.clear(); 
  }
  else
  {
    lcd.setCursor(3, 0);
    lcd.print("Objeto nao");
    lcd.setCursor(4, 1);
    lcd.print("Detectado");
    delay(200);
    lcd.clear();
  };



}
