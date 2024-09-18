#include <Arduino.h>
#include <Wire.h>
#include <MicroLCD.h>

//LCD_SH1106 lcd; 
LCD_SSD1306 lcd; 

void setup()
{
	lcd.begin();
}

void loop()
{
  lcd.setCursor(0, 0);
	lcd.setFontSize(FONT_SIZE_SMALL);
	lcd.println("Hello, world!");
  lcd.clear();
  lcd.setCursor(0, 0);
	lcd.setFontSize(FONT_SIZE_MEDIUM);
	lcd.println("Hello, world!");
	delay(1000);
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.setFontSize(FONT_SIZE_SMALL);
	lcd.println("Hello, world!");
	delay(1000);
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.setFontSize(FONT_SIZE_MEDIUM);
	lcd.println("Hello, world!");
	delay(1000);
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.setFontSize(FONT_SIZE_LARGE);
	lcd.println("Hello, world!");
	delay(1000);
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.setFontSize(FONT_SIZE_XLARGE);
	lcd.println("Hello, world!");
	delay(1000);
}

