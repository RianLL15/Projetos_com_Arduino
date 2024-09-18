#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int x = 0;
int Estado = 0;

LiquidCrystal_I2C lcd(0x3F, 16, 2); 

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("    Contador  ");
  lcd.setCursor(0, 1);
  lcd.print(x);
  lcd.print("     =Voltas  ");
}
void loop()
{
  int Sensor = digitalRead(7);
  if (Estado == 0)
  {
    switch (Sensor) {

      case 1 : Estado = 1; lcd.setCursor (0, 1); x = x + 1; lcd.print(x); break;
      case 0 : Estado = 0; break;

    }
  }

  if (Sensor == LOW) {
    Estado = 0;
  }
}
