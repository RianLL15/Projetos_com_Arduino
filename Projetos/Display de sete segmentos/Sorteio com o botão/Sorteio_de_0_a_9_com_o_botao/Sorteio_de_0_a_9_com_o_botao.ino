int numero = 0;
void setup()
{
// Botão
pinMode(2, INPUT);
// Primerio Display de 7 segmentos
pinMode(3, OUTPUT);//A
pinMode(4, OUTPUT);//B
pinMode(5, OUTPUT);//C
pinMode(6, OUTPUT);//D
pinMode(7, OUTPUT);//E
pinMode(8, OUTPUT);//F
pinMode(11, OUTPUT);//G

}
void loop()
{
if (digitalRead(2) == LOW) {
numero +=1;
}
if (numero == 0) {
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(11, HIGH);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
digitalWrite(14, LOW);
digitalWrite(15, LOW);
digitalWrite(16, LOW);
digitalWrite(17, LOW);
digitalWrite(18, HIGH);
digitalWrite(19, LOW);
digitalWrite(20, LOW);
digitalWrite(21, LOW);
digitalWrite(22, LOW);
digitalWrite(23, LOW);
digitalWrite(24, LOW);
digitalWrite(25, HIGH);
}
if (numero == 1) {
digitalWrite(3, HIGH);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
digitalWrite(11, HIGH);
}
if (numero == 2) {
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, HIGH);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, HIGH);
digitalWrite(11, LOW);
}
if (numero == 3) {
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
digitalWrite(11, LOW);
}
if (numero == 4) {
digitalWrite(3, HIGH);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, LOW);
digitalWrite(11, LOW);
}
if (numero == 5) {
digitalWrite(3, LOW);
digitalWrite(4, HIGH);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, HIGH);
digitalWrite(8, LOW);
digitalWrite(11, LOW);
}
if (numero == 6) {
digitalWrite(3, LOW);
digitalWrite(4, HIGH);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(11, LOW);
}
if (numero == 7) {
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
digitalWrite(11, HIGH);
}
if (numero == 8) {
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(11, LOW);
}
if (numero == 9) {
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, LOW);
digitalWrite(11, LOW);
}
}