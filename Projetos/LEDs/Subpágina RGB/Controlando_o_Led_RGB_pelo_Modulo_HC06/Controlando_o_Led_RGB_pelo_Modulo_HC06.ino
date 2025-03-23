#include <SoftwareSerial.h> 

SoftwareSerial serialdobluetooth(8,9); // Portas para o serial do bluetooth (RX, TX)

#define Red  3
#define Green  4
#define Blue  5

int valordobluetooth; 

void setup() {

  serialdobluetooth.begin(9600); 
  pinMode(Red, OUTPUT); 
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);
  
}

void loop() {

  //Indentifica se o módulo bluetooth está ou não ligado
  if (serialdobluetooth.available()) {

  valordobluetooth = serialdobluetooth.read();

  }

  //Vermelho
  if (valordobluetooth=='R'){

  digitalWrite(Red, LOW);
  digitalWrite(Green, HIGH);
  digitalWrite(Blue, HIGH);

  }

  //Verde
  if (valordobluetooth=='G'){

  digitalWrite(Red, HIGH);
  digitalWrite(Green, LOW);
  digitalWrite(Blue, HIGH);

  }

  //Azul
  if (valordobluetooth=='B'){

  digitalWrite(Red, HIGH);
  digitalWrite(Green, HIGH);
  digitalWrite(Blue, LOW);

  }

  //Branco
  if (valordobluetooth=='W'){

  digitalWrite(Red, LOW);
  digitalWrite(Green, LOW);
  digitalWrite(Blue, LOW);

  }

  //Amarelo
  if (valordobluetooth=='Y'){

  digitalWrite(Red, LOW);
  digitalWrite(Green, LOW);
  digitalWrite(Blue, HIGH);

  }

  //Magenta
  if (valordobluetooth=='M'){

  digitalWrite(Red, LOW);
  digitalWrite(Green, HIGH);
  digitalWrite(Blue, LOW);

  }
}
