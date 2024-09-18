#include <SoftwareSerial.h>

SoftwareSerial serialdobluetooth(8, 9);  // Portas para o serial do bluetooth (RX, TX)

#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4

int valordobluetooth;

void setup() {

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  serialdobluetooth.begin(9600);
}

void loop() {

  //Indentifica se o módulo bluetooth está ou não ligado
  if (serialdobluetooth.available()) {

    valordobluetooth = serialdobluetooth.read();
  }

  //Vermelho
  if (valordobluetooth == 'W') {

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    //Para o motor B
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }


  //Verde
  if (valordobluetooth == 'S') {

    //Para o motor A
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    //Para o motor B
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }

  //Azul
  if (valordobluetooth == 'D') {

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    //Para o motor B
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  //Branco
  if (valordobluetooth == 'A') {

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    //Para o motor B
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
  if (valordobluetooth == 'Q') {

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    //Para o motor B
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}