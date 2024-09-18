#define Red  3
#define Green  4
#define Blue  5
int T = 2500;

void setup() {

  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);
}

void loop() {

  //Verdemlho
  digitalWrite(Red, LOW);
  digitalWrite(Green, HIGH);
  digitalWrite(Blue, HIGH);
  delay(T);

  //Verde
  digitalWrite(Red, HIGH);
  digitalWrite(Green, LOW);
  digitalWrite(Blue, HIGH);
  delay(T);

  //Azul
  digitalWrite(Red, HIGH);
  digitalWrite(Green, HIGH);
  digitalWrite(Blue, LOW);
  delay(T);

  //Branco
  digitalWrite(Red, LOW);
  digitalWrite(Green, LOW);
  digitalWrite(Blue, LOW);
  delay(T);

  //Amarelo
  digitalWrite(Red, LOW);
  digitalWrite(Green, LOW);
  digitalWrite(Blue, HIGH);
  delay(T);

  //Magenta
  digitalWrite(Red, LOW);
  digitalWrite(Green, HIGH);
  digitalWrite(Blue, LOW);
  delay(T);

  //Ciano
  digitalWrite(Red, HIGH);
  digitalWrite(Green, LOW);
  digitalWrite(Blue, LOW);
  delay(T);

}
