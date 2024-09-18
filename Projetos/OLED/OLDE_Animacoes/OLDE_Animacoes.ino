//Site própria para essas animações: "https://animator.wokwi.com/".

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

int FRAME = 0;

#define SCREEN_I2C_ADDR 0x3C // ou 0x3D
#define SCREEN_WIDTH 128     // Define a largura em pixel do OLED
#define SCREEN_HEIGHT 64     // Define a altura em pixel do OLED
#define OLED_RST_PIN -1      // Reseta o pin 

Adafruit_SSD1306 display(128, 64, &Wire, OLED_RST_PIN);

 
#define FRAME_DELAY (45)
#define FRAME_WIDTH (64)
#define FRAME_HEIGHT (64)
#define FRAME_COUNT (sizeof(frames) / sizeof(frames[0]))
const byte PROGMEM frames[][512] = {
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,0,0,0,0,63,252,0,0,0,0,0,0,255,255,0,0,0,0,0,1,224,7,192,0,0,0,0,7,128,1,224,0,0,0,0,7,0,0,224,0,0,0,0,14,0,0,112,0,0,0,0,28,0,0,56,0,0,0,0,24,0,0,28,0,0,0,0,56,0,0,28,0,0,0,0,56,0,0,14,0,0,0,0,48,0,0,14,0,0,0,0,112,0,0,7,0,0,0,0,112,0,0,3,128,0,0,0,112,0,0,3,128,0,0,0,112,0,0,3,192,0,0,0,112,0,0,7,224,0,0,0,48,0,0,7,224,0,0,0,48,0,0,14,112,0,0,0,56,0,0,28,56,0,0,0,56,0,0,28,56,0,0,0,28,0,0,56,28,0,0,0,14,0,0,112,14,0,0,64,15,0,0,240,15,0,0,224,7,128,1,224,7,128,1,224,3,192,3,192,3,192,3,192,1,252,31,0,0,248,31,128,0,127,254,0,0,127,254,0,0,31,248,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,0,0,0,0,63,252,0,0,0,0,0,0,255,255,0,0,0,0,0,1,224,7,192,0,0,0,0,7,128,1,224,0,0,0,0,7,0,0,224,0,0,0,0,14,0,0,112,0,0,0,0,28,0,0,56,0,0,0,0,24,0,0,24,0,0,0,0,56,0,0,28,48,0,0,0,56,0,0,14,112,0,0,0,48,0,0,14,240,0,0,0,112,0,0,7,224,0,0,0,112,0,0,3,192,0,0,0,112,0,0,3,192,0,0,0,112,0,0,3,192,0,0,0,112,0,0,7,224,0,0,0,48,0,0,7,224,0,0,0,48,0,0,14,112,0,0,0,56,0,0,28,56,0,0,0,56,0,0,28,56,0,0,0,28,0,0,56,28,0,0,0,14,0,0,112,14,0,0,0,15,0,0,240,15,0,0,0,7,128,1,224,7,128,0,0,3,192,3,192,3,192,0,0,1,252,31,0,0,248,28,0,0,127,254,0,0,127,252,0,0,31,248,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,0,0,0,0,63,252,0,0,0,0,0,0,255,255,0,0,0,0,0,1,224,7,192,0,0,0,0,7,128,1,224,7,0,0,0,7,0,0,224,15,0,0,0,14,0,0,112,14,0,0,0,28,0,0,56,28,0,0,0,24,0,0,28,56,0,0,0,56,0,0,28,56,0,0,0,56,0,0,14,112,0,0,0,48,0,0,14,112,0,0,0,112,0,0,7,224,0,0,0,112,0,0,3,192,0,0,0,112,0,0,3,192,0,0,0,112,0,0,3,192,0,0,0,112,0,0,7,224,0,0,0,48,0,0,7,224,0,0,0,48,0,0,14,112,0,0,0,56,0,0,28,56,0,0,0,56,0,0,28,56,0,0,0,28,0,0,56,28,0,0,0,14,0,0,112,14,0,0,0,15,0,0,240,15,0,0,0,7,128,1,224,7,128,0,0,3,192,3,192,3,224,0,0,1,252,31,0,0,248,0,0,0,127,254,0,0,127,0,0,0,31,248,0,0,31,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,8,0,0,0,63,252,0,0,56,0,0,0,255,255,0,0,248,0,0,1,224,7,192,3,224,0,0,7,128,1,224,7,128,0,0,7,0,0,224,7,0,0,0,14,0,0,112,14,0,0,0,28,0,0,56,28,0,0,0,24,0,0,28,56,0,0,0,56,0,0,28,56,0,0,0,56,0,0,14,112,0,0,0,48,0,0,14,112,0,0,0,112,0,0,7,224,0,0,0,112,0,0,3,192,0,0,0,112,0,0,3,192,0,0,0,112,0,0,3,192,0,0,0,112,0,0,7,224,0,0,0,48,0,0,7,224,0,0,0,48,0,0,14,112,0,0,0,56,0,0,28,56,0,0,0,56,0,0,28,56,0,0,0,28,0,0,56,28,0,0,0,14,0,0,112,14,0,0,0,15,0,0,240,15,0,0,0,7,128,1,224,7,128,0,0,3,192,3,192,3,192,0,0,1,252,31,0,0,128,0,0,0,127,254,0,0,0,0,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,15,224,0,0,63,252,0,0,63,240,0,0,255,255,0,0,255,224,0,1,224,7,192,3,224,0,0,7,128,1,224,7,128,0,0,7,0,0,224,7,0,0,0,14,0,0,112,14,0,0,0,28,0,0,56,28,0,0,0,24,0,0,28,56,0,0,0,56,0,0,28,56,0,0,0,56,0,0,14,112,0,0,0,48,0,0,14,112,0,0,0,112,0,0,7,224,0,0,0,112,0,0,3,192,0,0,0,112,0,0,3,192,0,0,0,112,0,0,3,192,0,0,0,112,0,0,7,224,0,0,0,48,0,0,7,224,0,0,0,48,0,0,14,112,0,0,0,56,0,0,28,56,0,0,0,56,0,0,28,56,0,0,0,28,0,0,56,28,0,0,0,14,0,0,112,8,0,0,0,15,0,0,240,0,0,0,0,7,128,1,224,0,0,0,0,3,192,3,192,0,0,0,0,1,252,31,0,0,0,0,0,0,127,254,0,0,0,0,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,15,240,0,0,63,252,0,0,63,252,0,0,255,255,0,0,255,255,0,1,224,7,192,3,224,7,128,7,128,1,224,7,128,1,128,7,0,0,224,7,0,0,0,14,0,0,112,14,0,0,0,28,0,0,56,28,0,0,0,24,0,0,28,56,0,0,0,56,0,0,28,56,0,0,0,56,0,0,14,112,0,0,0,48,0,0,14,112,0,0,0,112,0,0,7,224,0,0,0,112,0,0,3,192,0,0,0,112,0,0,3,192,0,0,0,112,0,0,3,192,0,0,0,112,0,0,7,192,0,0,0,48,0,0,7,0,0,0,0,48,0,0,14,0,0,0,0,56,0,0,28,0,0,0,0,56,0,0,28,0,0,0,0,28,0,0,56,0,0,0,0,14,0,0,112,0,0,0,0,15,0,0,240,0,0,0,0,7,128,1,224,0,0,0,0,3,192,3,192,0,0,0,0,1,252,31,0,0,0,0,0,0,127,254,0,0,0,0,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,15,224,0,0,63,252,0,0,63,252,0,0,255,255,0,0,255,255,0,1,224,7,192,3,224,7,192,7,128,1,224,7,128,1,224,7,0,0,224,7,0,0,240,14,0,0,112,14,0,0,112,28,0,0,56,28,0,0,56,24,0,0,28,56,0,0,56,56,0,0,28,56,0,0,24,56,0,0,14,112,0,0,0,48,0,0,4,112,0,0,0,112,0,0,0,224,0,0,0,112,0,0,1,192,0,0,0,112,0,0,1,192,0,0,0,112,0,0,3,128,0,0,0,112,0,0,7,0,0,0,0,48,0,0,7,0,0,0,0,48,0,0,14,0,0,0,0,56,0,0,28,0,0,0,0,56,0,0,28,0,0,0,0,28,0,0,56,0,0,0,0,14,0,0,112,0,0,0,0,15,0,0,240,0,0,0,0,7,128,1,224,0,0,0,0,3,192,3,192,0,0,0,0,1,252,31,0,0,0,0,0,0,127,254,0,0,0,0,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,15,240,0,0,63,254,0,0,63,252,0,0,255,255,0,0,255,255,0,1,224,7,128,3,224,7,128,7,128,1,224,7,128,1,224,7,0,0,224,7,0,0,224,14,0,0,64,14,0,0,112,28,0,0,0,28,0,0,56,24,0,0,0,56,0,0,24,56,0,0,0,56,0,0,28,56,0,0,0,112,0,0,28,48,0,0,0,112,0,0,12,112,0,0,0,224,0,0,14,112,0,0,1,192,0,0,14,112,0,0,1,192,0,0,14,112,0,0,3,128,0,0,14,112,0,0,7,0,0,0,0,48,0,0,7,0,0,0,0,48,0,0,14,0,0,0,0,56,0,0,28,0,0,0,0,56,0,0,28,0,0,0,0,28,0,0,56,0,0,0,0,14,0,0,112,0,0,0,0,15,0,0,240,0,0,0,0,7,128,1,224,0,0,0,0,3,192,3,192,0,0,0,0,1,252,31,0,0,0,0,0,0,127,254,0,0,0,0,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,15,240,0,0,63,252,0,0,63,252,0,0,255,248,0,0,255,255,0,1,224,0,0,3,224,7,128,7,128,0,0,7,128,1,224,7,0,0,0,7,0,0,224,14,0,0,0,14,0,0,112,28,0,0,0,28,0,0,56,24,0,0,0,56,0,0,24,56,0,0,0,56,0,0,28,56,0,0,0,112,0,0,28,48,0,0,0,112,0,0,12,112,0,0,0,224,0,0,14,112,0,0,1,192,0,0,14,112,0,0,1,192,0,0,14,112,0,0,3,128,0,0,14,112,0,0,7,0,0,0,12,48,0,0,7,0,0,0,12,48,0,0,14,0,0,0,28,56,0,0,28,0,0,0,28,56,0,0,28,0,0,0,24,28,0,0,56,0,0,0,56,14,0,0,112,0,0,0,16,15,0,0,240,0,0,0,0,7,128,1,224,0,0,0,0,3,192,3,192,0,0,0,0,1,252,31,0,0,0,0,0,0,127,254,0,0,0,0,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,0,15,240,0,0,126,0,0,0,63,252,0,0,254,0,0,0,255,255,0,3,224,0,0,3,224,7,128,7,128,0,0,7,128,1,224,15,0,0,0,7,0,0,224,14,0,0,0,14,0,0,112,28,0,0,0,28,0,0,56,24,0,0,0,56,0,0,24,56,0,0,0,56,0,0,28,56,0,0,0,112,0,0,28,48,0,0,0,112,0,0,12,112,0,0,0,224,0,0,14,112,0,0,1,192,0,0,14,112,0,0,1,192,0,0,14,112,0,0,3,128,0,0,14,112,0,0,7,0,0,0,14,48,0,0,7,0,0,0,12,48,0,0,14,0,0,0,12,56,0,0,28,0,0,0,28,56,0,0,28,0,0,0,28,28,0,0,56,0,0,0,56,14,0,0,112,0,0,0,120,15,0,0,240,0,0,0,240,7,128,1,224,0,0,1,224,3,192,3,192,0,0,3,192,1,252,31,0,0,0,1,0,0,127,254,0,0,0,0,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,0,0,0,0,63,252,0,0,128,0,0,0,255,255,0,3,128,0,0,3,224,7,128,7,128,0,0,7,128,1,224,7,0,0,0,7,0,0,224,14,0,0,0,14,0,0,112,28,0,0,0,28,0,0,56,24,0,0,0,56,0,0,24,56,0,0,0,56,0,0,28,48,0,0,0,112,0,0,28,48,0,0,0,112,0,0,12,112,0,0,0,224,0,0,14,112,0,0,1,192,0,0,14,112,0,0,1,192,0,0,14,112,0,0,3,128,0,0,14,112,0,0,7,0,0,0,14,48,0,0,7,0,0,0,12,48,0,0,14,0,0,0,12,56,0,0,28,0,0,0,28,56,0,0,28,0,0,0,28,28,0,0,56,0,0,0,56,14,0,0,112,0,0,0,112,15,0,0,240,0,0,0,240,7,128,1,224,0,0,1,224,3,192,3,192,0,0,3,192,1,252,31,0,0,0,31,128,0,127,254,0,0,0,254,0,0,31,248,0,0,0,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,0,0,0,0,63,252,0,0,0,0,0,0,255,255,0,0,0,0,0,3,224,7,128,0,0,0,0,7,128,1,224,0,0,0,0,7,0,0,224,0,0,0,0,14,0,0,112,16,0,0,0,28,0,0,56,24,0,0,0,56,0,0,24,56,0,0,0,56,0,0,28,56,0,0,0,112,0,0,28,48,0,0,0,112,0,0,12,48,0,0,0,224,0,0,14,112,0,0,1,192,0,0,14,112,0,0,1,192,0,0,14,112,0,0,3,128,0,0,14,112,0,0,7,0,0,0,14,48,0,0,7,0,0,0,12,48,0,0,14,0,0,0,12,56,0,0,28,0,0,0,28,56,0,0,28,0,0,0,28,28,0,0,56,0,0,0,56,14,0,0,112,0,0,0,112,15,0,0,240,0,0,0,240,7,128,1,224,0,0,1,224,3,192,3,192,0,0,7,192,1,252,31,0,0,56,63,128,0,127,254,0,0,63,254,0,0,31,248,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,0,0,0,0,63,252,0,0,0,0,0,0,255,255,0,0,0,0,0,3,224,7,128,0,0,0,0,7,128,1,224,0,0,0,0,7,0,0,224,0,0,0,0,14,0,0,112,0,0,0,0,28,0,0,56,0,0,0,0,56,0,0,24,0,0,0,0,56,0,0,28,0,0,0,0,112,0,0,28,0,0,0,0,112,0,0,12,0,0,0,0,224,0,0,14,0,0,0,1,192,0,0,14,112,0,0,1,192,0,0,14,112,0,0,3,128,0,0,14,112,0,0,7,0,0,0,14,48,0,0,7,0,0,0,12,48,0,0,14,0,0,0,12,56,0,0,28,0,0,0,28,56,0,0,28,0,0,0,28,28,0,0,56,0,0,0,56,14,0,0,112,2,0,0,112,15,0,0,240,7,0,0,240,7,128,1,224,7,128,1,224,3,192,3,192,3,192,7,192,1,252,31,0,1,248,63,128,0,127,254,0,0,127,254,0,0,31,248,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,0,0,0,0,63,252,0,0,0,0,0,0,255,255,0,0,0,0,0,3,224,7,128,0,0,0,0,7,128,1,224,0,0,0,0,7,0,0,224,0,0,0,0,14,0,0,112,0,0,0,0,28,0,0,56,0,0,0,0,56,0,0,24,0,0,0,0,56,0,0,28,0,0,0,0,112,0,0,28,0,0,0,0,112,0,0,12,0,0,0,0,224,0,0,14,0,0,0,1,192,0,0,14,0,0,0,1,192,0,0,14,0,0,0,3,128,0,0,14,0,0,0,7,0,0,0,14,0,0,0,7,32,0,0,12,0,0,0,14,112,0,0,12,0,0,0,28,56,0,0,28,24,0,0,28,56,0,0,28,28,0,0,56,28,0,0,56,14,0,0,112,14,0,0,112,14,0,0,240,15,0,0,240,7,128,1,224,7,128,1,224,3,192,3,192,3,192,7,192,1,240,31,0,0,248,63,128,0,127,254,0,0,127,254,0,0,31,248,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,0,0,0,0,63,252,0,0,0,0,0,0,255,255,0,0,0,0,0,3,224,7,128,0,0,0,0,7,128,1,224,0,0,0,0,7,0,0,224,0,0,0,0,14,0,0,112,0,0,0,0,28,0,0,56,0,0,0,0,56,0,0,24,0,0,0,0,56,0,0,28,0,0,0,0,112,0,0,28,0,0,0,0,96,0,0,12,0,0,0,3,224,0,0,14,0,0,0,3,192,0,0,14,0,0,0,3,192,0,0,14,0,0,0,3,192,0,0,14,0,0,0,7,224,0,0,14,0,0,0,7,224,0,0,12,0,0,0,14,112,0,0,12,0,0,0,28,56,0,0,28,0,0,0,28,56,0,0,28,0,0,0,56,28,0,0,56,0,0,0,112,14,0,0,112,0,0,0,240,15,0,0,240,0,128,1,224,7,128,1,224,1,224,3,192,3,192,7,192,1,254,31,0,0,248,63,128,0,127,254,0,0,127,254,0,0,31,248,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,0,0,0,0,63,252,0,0,0,0,0,0,255,255,0,0,0,0,0,3,224,7,128,0,0,0,0,7,128,1,224,0,0,0,0,7,0,0,224,0,0,0,16,14,0,0,112,0,0,0,56,28,0,0,56,0,0,0,28,56,0,0,24,0,0,0,28,56,0,0,28,0,0,0,14,112,0,0,28,0,0,0,14,112,0,0,12,0,0,0,7,224,0,0,14,0,0,0,3,192,0,0,14,0,0,0,3,192,0,0,14,0,0,0,3,192,0,0,14,0,0,0,7,224,0,0,14,0,0,0,7,224,0,0,12,0,0,0,14,112,0,0,12,0,0,0,28,56,0,0,28,0,0,0,28,56,0,0,28,0,0,0,56,28,0,0,56,0,0,0,112,14,0,0,112,0,0,0,240,15,0,0,240,0,0,1,224,7,128,1,224,0,0,3,192,3,192,7,192,0,0,31,0,0,248,63,128,0,7,254,0,0,127,254,0,0,7,248,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,0,0,0,0,63,252,0,0,0,3,0,0,255,255,0,0,0,3,128,3,224,7,128,0,0,3,224,7,128,1,224,0,0,0,224,7,0,0,224,0,0,0,112,14,0,0,112,0,0,0,56,28,0,0,56,0,0,0,28,56,0,0,24,0,0,0,28,56,0,0,28,0,0,0,14,112,0,0,28,0,0,0,14,112,0,0,12,0,0,0,7,224,0,0,14,0,0,0,3,192,0,0,14,0,0,0,3,192,0,0,14,0,0,0,3,192,0,0,14,0,0,0,7,224,0,0,14,0,0,0,7,224,0,0,12,0,0,0,14,112,0,0,12,0,0,0,28,56,0,0,28,0,0,0,28,56,0,0,28,0,0,0,56,28,0,0,56,0,0,0,112,14,0,0,112,0,0,0,240,15,0,0,240,0,0,1,224,7,128,1,224,0,0,3,192,3,192,7,192,0,0,31,128,0,248,63,128,0,0,30,0,0,127,254,0,0,0,0,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,240,0,0,15,240,0,0,0,252,0,0,63,252,0,0,0,255,0,0,255,255,0,0,0,7,192,3,224,7,128,0,0,1,224,7,128,1,224,0,0,0,224,7,0,0,224,0,0,0,112,14,0,0,112,0,0,0,56,28,0,0,56,0,0,0,28,56,0,0,24,0,0,0,28,56,0,0,28,0,0,0,14,112,0,0,28,0,0,0,14,112,0,0,12,0,0,0,7,224,0,0,14,0,0,0,3,192,0,0,14,0,0,0,3,192,0,0,14,0,0,0,3,192,0,0,14,0,0,0,7,224,0,0,14,0,0,0,7,224,0,0,12,0,0,0,14,112,0,0,12,0,0,0,28,56,0,0,28,0,0,0,28,56,0,0,28,0,0,0,56,28,0,0,56,0,0,0,112,14,0,0,112,0,0,0,240,15,0,0,240,0,0,0,96,7,128,1,224,0,0,0,0,3,192,7,192,0,0,0,0,0,248,63,128,0,0,0,0,0,127,254,0,0,0,0,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,15,240,0,0,63,252,0,0,63,252,0,0,127,255,0,0,255,255,0,0,32,7,192,3,224,7,128,0,0,1,224,7,128,1,224,0,0,0,224,7,0,0,224,0,0,0,112,14,0,0,112,0,0,0,56,28,0,0,56,0,0,0,28,56,0,0,24,0,0,0,28,56,0,0,28,0,0,0,14,112,0,0,28,0,0,0,14,112,0,0,12,0,0,0,7,224,0,0,14,0,0,0,3,192,0,0,14,0,0,0,3,192,0,0,14,0,0,0,3,192,0,0,14,0,0,0,7,224,0,0,14,0,0,0,7,224,0,0,12,0,0,0,14,112,0,0,12,0,0,0,4,56,0,0,28,0,0,0,0,56,0,0,24,0,0,0,0,28,0,0,56,0,0,0,0,14,0,0,112,0,0,0,0,15,0,0,240,0,0,0,0,7,128,1,224,0,0,0,0,3,192,7,192,0,0,0,0,0,248,63,128,0,0,0,0,0,127,254,0,0,0,0,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,15,240,0,0,127,252,0,0,63,252,0,0,255,255,0,0,255,255,0,3,224,7,192,3,224,7,128,7,128,1,224,7,128,1,224,7,0,0,224,7,0,0,224,14,0,0,112,14,0,0,112,0,0,0,56,28,0,0,56,0,0,0,28,56,0,0,24,0,0,0,28,56,0,0,28,0,0,0,14,112,0,0,28,0,0,0,14,112,0,0,12,0,0,0,7,224,0,0,14,0,0,0,3,192,0,0,14,0,0,0,3,192,0,0,14,0,0,0,1,192,0,0,14,0,0,0,0,224,0,0,14,0,0,0,0,224,0,0,12,0,0,0,0,112,0,0,12,0,0,0,0,56,0,0,28,0,0,0,0,56,0,0,28,0,0,0,0,28,0,0,56,0,0,0,0,14,0,0,112,0,0,0,0,15,0,0,240,0,0,0,0,7,128,1,224,0,0,0,0,3,192,7,192,0,0,0,0,0,248,63,128,0,0,0,0,0,127,254,0,0,0,0,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,15,240,0,0,63,252,0,0,63,252,0,0,255,255,0,0,255,255,0,1,224,7,192,3,224,7,128,7,192,1,224,7,128,1,224,7,0,0,224,7,0,0,224,14,0,0,112,14,0,0,112,28,0,0,56,28,0,0,56,28,0,0,28,24,0,0,24,56,0,0,28,0,0,0,28,56,0,0,14,0,0,0,28,48,0,0,14,0,0,0,12,112,0,0,7,0,0,0,14,0,0,0,3,128,0,0,14,0,0,0,3,128,0,0,14,0,0,0,1,192,0,0,14,0,0,0,0,224,0,0,14,0,0,0,0,224,0,0,12,0,0,0,0,112,0,0,12,0,0,0,0,56,0,0,28,0,0,0,0,56,0,0,28,0,0,0,0,28,0,0,56,0,0,0,0,14,0,0,112,0,0,0,0,15,0,0,240,0,0,0,0,7,128,1,224,0,0,0,0,3,192,7,192,0,0,0,0,0,248,63,128,0,0,0,0,0,127,254,0,0,0,0,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,7,240,0,0,63,252,0,0,63,252,0,0,255,255,0,0,255,255,0,1,224,7,192,0,224,7,128,7,128,1,224,0,192,1,224,7,0,0,224,0,0,0,224,14,0,0,112,0,0,0,112,28,0,0,56,0,0,0,56,24,0,0,28,0,0,0,24,56,0,0,28,0,0,0,28,56,0,0,14,0,0,0,28,48,0,0,14,0,0,0,12,112,0,0,7,0,0,0,14,112,0,0,3,128,0,0,14,112,0,0,3,128,0,0,14,112,0,0,1,192,0,0,14,112,0,0,0,224,0,0,14,48,0,0,0,224,0,0,12,48,0,0,0,112,0,0,12,32,0,0,0,56,0,0,28,0,0,0,0,56,0,0,28,0,0,0,0,28,0,0,56,0,0,0,0,14,0,0,112,0,0,0,0,15,0,0,240,0,0,0,0,7,128,1,224,0,0,0,0,3,192,7,192,0,0,0,0,0,248,63,128,0,0,0,0,0,127,254,0,0,0,0,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,3,240,0,0,63,252,0,0,3,252,0,0,255,255,0,0,3,255,0,1,224,7,192,0,0,7,128,7,128,1,224,0,0,1,224,7,0,0,224,0,0,0,224,14,0,0,112,0,0,0,112,28,0,0,56,0,0,0,56,24,0,0,28,0,0,0,24,56,0,0,28,0,0,0,28,56,0,0,14,0,0,0,28,48,0,0,14,0,0,0,12,112,0,0,7,0,0,0,14,112,0,0,3,128,0,0,14,112,0,0,3,128,0,0,14,112,0,0,1,192,0,0,14,112,0,0,0,224,0,0,14,48,0,0,0,224,0,0,12,48,0,0,0,112,0,0,12,56,0,0,0,56,0,0,28,56,0,0,0,56,0,0,28,28,0,0,0,28,0,0,56,30,0,0,0,14,0,0,112,15,0,0,0,15,0,0,240,6,0,0,0,7,128,1,224,0,0,0,0,3,192,7,192,0,0,0,0,0,248,63,128,0,0,0,0,0,127,254,0,0,0,0,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,0,0,0,0,63,252,0,0,0,12,0,0,255,255,0,0,0,15,128,1,224,7,192,0,0,7,192,7,128,1,224,0,0,1,224,7,0,0,224,0,0,0,224,14,0,0,112,0,0,0,112,28,0,0,56,0,0,0,56,24,0,0,28,0,0,0,56,56,0,0,28,0,0,0,28,56,0,0,14,0,0,0,28,48,0,0,14,0,0,0,12,112,0,0,7,0,0,0,12,112,0,0,3,128,0,0,14,112,0,0,3,128,0,0,14,112,0,0,1,192,0,0,14,48,0,0,0,224,0,0,14,48,0,0,0,224,0,0,12,48,0,0,0,112,0,0,12,56,0,0,0,56,0,0,28,56,0,0,0,56,0,0,28,28,0,0,0,28,0,0,56,14,0,0,0,14,0,0,112,15,0,0,0,15,0,0,240,7,128,0,0,7,128,1,224,3,224,0,0,3,192,7,192,1,248,0,0,0,248,63,128,0,120,0,0,0,127,254,0,0,0,0,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,0,0,0,0,63,252,0,0,0,0,0,0,255,255,0,0,0,0,0,1,224,7,192,0,0,0,0,7,128,1,224,0,0,0,0,7,0,0,224,0,0,0,96,14,0,0,112,0,0,0,112,28,0,0,56,0,0,0,56,24,0,0,28,0,0,0,24,56,0,0,28,0,0,0,28,56,0,0,14,0,0,0,28,48,0,0,14,0,0,0,12,112,0,0,7,0,0,0,14,112,0,0,3,128,0,0,14,112,0,0,3,128,0,0,14,112,0,0,1,192,0,0,14,112,0,0,0,224,0,0,14,48,0,0,0,224,0,0,12,48,0,0,0,112,0,0,12,56,0,0,0,56,0,0,28,56,0,0,0,56,0,0,28,28,0,0,0,28,0,0,56,14,0,0,0,14,0,0,112,15,0,0,0,15,0,0,240,7,128,0,0,7,128,1,224,3,192,0,0,3,192,7,192,1,252,0,0,0,248,63,128,0,127,224,0,0,127,254,0,0,31,224,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,0,0,0,0,63,252,0,0,0,0,0,0,255,255,0,0,0,0,0,1,224,7,192,0,0,0,0,7,128,1,224,0,0,0,0,7,0,0,224,0,0,0,0,14,0,0,112,0,0,0,0,28,0,0,56,0,0,0,0,24,0,0,28,0,0,0,0,56,0,0,28,0,0,0,0,56,0,0,14,0,0,0,4,48,0,0,14,0,0,0,12,112,0,0,7,0,0,0,12,112,0,0,3,128,0,0,14,112,0,0,3,128,0,0,14,112,0,0,1,192,0,0,14,112,0,0,0,224,0,0,14,48,0,0,0,224,0,0,12,48,0,0,0,112,0,0,12,56,0,0,0,56,0,0,28,56,0,0,0,56,0,0,28,28,0,0,0,28,0,0,56,14,0,0,0,14,0,0,112,15,0,0,0,15,0,0,240,7,128,1,0,7,128,1,224,3,192,7,128,3,192,7,192,1,252,127,128,0,248,63,128,0,127,254,0,0,127,254,0,0,31,248,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,0,0,0,0,63,252,0,0,0,0,0,0,255,255,0,0,0,0,0,1,224,7,192,0,0,0,0,7,128,1,224,0,0,0,0,7,0,0,224,0,0,0,0,14,0,0,112,0,0,0,0,28,0,0,56,0,0,0,0,24,0,0,28,0,0,0,0,56,0,0,28,0,0,0,0,56,0,0,14,0,0,0,0,48,0,0,14,0,0,0,0,112,0,0,7,0,0,0,0,112,0,0,3,128,0,0,0,112,0,0,3,128,0,0,0,112,0,0,1,192,0,0,0,112,0,0,0,224,0,0,0,48,0,0,0,224,0,0,12,48,0,0,0,112,0,0,28,56,0,0,0,56,0,0,28,56,0,0,24,56,0,0,24,28,0,0,56,28,0,0,56,14,0,0,112,14,0,0,112,15,0,0,240,15,0,0,240,7,128,1,224,7,128,1,224,3,192,3,192,3,192,7,192,1,252,31,0,0,248,63,0,0,127,254,0,0,127,254,0,0,31,248,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,240,0,0,0,0,0,0,63,252,0,0,0,0,0,0,255,255,0,0,0,0,0,1,224,7,192,0,0,0,0,7,128,1,224,0,0,0,0,7,0,0,224,0,0,0,0,14,0,0,112,0,0,0,0,28,0,0,56,0,0,0,0,24,0,0,28,0,0,0,0,56,0,0,28,0,0,0,0,56,0,0,14,0,0,0,0,48,0,0,14,0,0,0,0,112,0,0,7,0,0,0,0,112,0,0,3,128,0,0,0,112,0,0,3,128,0,0,0,112,0,0,3,192,0,0,0,112,0,0,7,224,0,0,0,48,0,0,7,224,0,0,0,48,0,0,14,112,0,0,0,56,0,0,28,56,0,0,0,56,0,0,28,56,0,0,0,28,0,0,56,28,0,0,0,14,0,0,112,14,0,0,64,15,0,0,240,15,0,0,224,7,128,1,224,7,128,1,224,3,192,3,192,3,192,3,192,1,252,31,0,0,248,31,128,0,127,254,0,0,127,254,0,0,31,248,0,0,31,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_I2C_ADDR);
}

void loop() {
  display.clearDisplay();
  display.drawBitmap(32, 0, frames[FRAME], FRAME_WIDTH, FRAME_HEIGHT, 1);
  display.display();
  FRAME = (FRAME + 1) % FRAME_COUNT;
  delay(FRAME_DELAY);
}