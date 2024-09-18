#include <LedControl.h>

//Pino 12 = DIN, Pino 11 = CLK, Pino 10 = CS e 1 = Quantidade de Displays
LedControl lc = LedControl(12, 11, 10, 1);

int T = 500;
int P = 50;

void setup() 
{
  lc.shutdown(0,false); //Define se os Leds vão estar desligados ou não 
  lc.setIntensity(0,1); //Define o blilho para o display 1. Valores 1 até 15
  lc.clearDisplay(0); //Desativa todos os leds para o display 1
  
}

void loop() 
{  

  lc.setRow(0, 0, B10000001); 
  lc.setRow(0, 7, B10000001); 
  delay(T);
  lc.setRow(0, 0, B00000000); 
  lc.setRow(0, 7, B00000000); 
  delay(P);
  lc.setRow(0, 1, B01000010); 
  lc.setRow(0, 6, B01000010); 
  delay(T);
  lc.setRow(0, 1, B00000000); 
  lc.setRow(0, 6, B00000000); 
  delay(P);
  lc.setRow(0, 2, B00100100); 
  lc.setRow(0, 5, B00100100); 
  delay(T);
  lc.setRow(0, 2, B00000000); 
  lc.setRow(0, 5, B00000000); 
  delay(P);
  lc.setRow(0, 3, B00011000); 
  lc.setRow(0, 4, B00011000); 
  delay(T);
  lc.setRow(0, 3, B00000000); 
  lc.setRow(0, 4, B00000000); 
  delay(P);
  lc.setRow(0, 2, B00100100); 
  lc.setRow(0, 5, B00100100); 
  delay(T);
  lc.setRow(0, 2, B00000000); 
  lc.setRow(0, 5, B00000000); 
  delay(P);
  lc.setRow(0, 1, B01000010); 
  lc.setRow(0, 6, B01000010); 
  delay(T);
  lc.setRow(0, 1, B00000000); 
  lc.setRow(0, 6, B00000000); 
  delay(P);
  lc.setRow(0, 0, B11111111); 
  lc.setRow(0, 1, B10000001);
  lc.setRow(0, 2, B10000001); 
  lc.setRow(0, 3, B10000001);
  lc.setRow(0, 4, B10000001); 
  lc.setRow(0, 5, B10000001);
  lc.setRow(0, 6, B10000001);
  lc.setRow(0, 7, B11111111); 
  delay(T);
  lc.setRow(0, 0, B00000000); 
  lc.setRow(0, 1, B00000000);
  lc.setRow(0, 2, B00000000); 
  lc.setRow(0, 3, B00000000);
  lc.setRow(0, 4, B00000000); 
  lc.setRow(0, 5, B00000000);
  lc.setRow(0, 6, B00000000);
  lc.setRow(0, 7, B00000000);
  delay(P);
  lc.setRow(0, 0, B00000000); 
  lc.setRow(0, 1, B01111110);
  lc.setRow(0, 2, B01000010); 
  lc.setRow(0, 3, B01000010);
  lc.setRow(0, 4, B01000010); 
  lc.setRow(0, 5, B01000010);
  lc.setRow(0, 6, B01111110);
  lc.setRow(0, 7, B00000000); 
  delay(T);
  lc.setRow(0, 0, B00000000); 
  lc.setRow(0, 1, B00000000);
  lc.setRow(0, 2, B00000000); 
  lc.setRow(0, 3, B00000000);
  lc.setRow(0, 4, B00000000); 
  lc.setRow(0, 5, B00000000);
  lc.setRow(0, 6, B00000000);
  lc.setRow(0, 7, B00000000);
  delay(P);
  lc.setRow(0, 0, B00000000); 
  lc.setRow(0, 1, B00000000);
  lc.setRow(0, 2, B00111100); 
  lc.setRow(0, 3, B00100100);
  lc.setRow(0, 4, B00100100); 
  lc.setRow(0, 5, B00111100);
  lc.setRow(0, 6, B00000000);
  lc.setRow(0, 7, B00000000); 
  delay(T);
  lc.setRow(0, 0, B00000000); 
  lc.setRow(0, 1, B00000000);
  lc.setRow(0, 2, B00000000); 
  lc.setRow(0, 3, B00000000);
  lc.setRow(0, 4, B00000000); 
  lc.setRow(0, 5, B00000000);
  lc.setRow(0, 6, B00000000);
  lc.setRow(0, 7, B00000000);
  delay(P); 
  lc.setRow(0, 3, B00011000);
  lc.setRow(0, 4, B00011000);  
  delay(T);
  lc.setRow(0, 3, B00000000);
  lc.setRow(0, 4, B00000000); 
  delay(P);
  lc.setRow(0, 0, B10000001); 
  lc.setRow(0, 1, B01000010);
  lc.setRow(0, 2, B00100100); 
  lc.setRow(0, 3, B00011000);
  lc.setRow(0, 4, B00011000); 
  lc.setRow(0, 5, B00100100);
  lc.setRow(0, 6, B01000010);
  lc.setRow(0, 7, B10000001); 
  delay(T);
  lc.setRow(0, 0, B00000000); 
  lc.setRow(0, 1, B00000000);
  lc.setRow(0, 2, B00000000); 
  lc.setRow(0, 3, B00000000);
  lc.setRow(0, 4, B00000000); 
  lc.setRow(0, 5, B00000000);
  lc.setRow(0, 6, B00000000);
  lc.setRow(0, 7, B00000000);
  delay(P);
  lc.setRow(0, 0, B00100000); 
  lc.setRow(0, 1, B00010000);
  lc.setRow(0, 2, B00001001); 
  lc.setRow(0, 3, B00111010);
  lc.setRow(0, 4, B01011100); 
  lc.setRow(0, 5, B10010000);
  lc.setRow(0, 6, B00001000);
  lc.setRow(0, 7, B00000100);
  delay(T);
  lc.setRow(0, 0, B00000000); 
  lc.setRow(0, 1, B00000000);
  lc.setRow(0, 2, B00000000); 
  lc.setRow(0, 3, B00000000);
  lc.setRow(0, 4, B00000000); 
  lc.setRow(0, 5, B00000000);
  lc.setRow(0, 6, B00000000);
  lc.setRow(0, 7, B00000000);
  delay(P);
  lc.setRow(0, 0, B00001000); 
  lc.setRow(0, 1, B00000100);
  lc.setRow(0, 2, B01100100); 
  lc.setRow(0, 3, B10011000);
  lc.setRow(0, 4, B00011001); 
  lc.setRow(0, 5, B00100110);
  lc.setRow(0, 6, B00100000);
  lc.setRow(0, 7, B00010000);
  delay(T);
  lc.setRow(0, 0, B00000000); 
  lc.setRow(0, 1, B00000000);
  lc.setRow(0, 2, B00000000); 
  lc.setRow(0, 3, B00000000);
  lc.setRow(0, 4, B00000000); 
  lc.setRow(0, 5, B00000000);
  lc.setRow(0, 6, B00000000);
  lc.setRow(0, 7, B00000000);
  delay(P);
}
