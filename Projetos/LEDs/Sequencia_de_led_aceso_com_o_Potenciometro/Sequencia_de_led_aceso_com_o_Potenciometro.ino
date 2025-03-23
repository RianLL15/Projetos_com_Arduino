const int porpin = A0;
int ledc = 9;
int ledpin[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};


void setup() {
  for (int thisled = 0; thisled < ledc; thisled++){

    pinMode(ledpin[thisled], OUTPUT);

  }

}

void loop() {

  int valorpot = analogRead(porpin);
  int ledlv = map(valorpot, 0, 1023, 0, 10);
  
  for (int thisled = 0; thisled < ledc; thisled++){

    if(thisled < ledlv){

      digitalWrite(ledpin[thisled], HIGH);

    }

    else {

      digitalWrite(ledpin[thisled], LOW);

    }

  }

}
