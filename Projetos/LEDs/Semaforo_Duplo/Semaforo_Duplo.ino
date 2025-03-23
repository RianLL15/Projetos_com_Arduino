//Primeiro Semáforo
#define Led1 2  //LED Vermelho
#define Led2 3  //LED Amarelo
#define Led3 4  //LED Verde

//Segundo Semáforo
#define Led4 5  //LED Vermelho
#define Led5 6  //LED Amarelo
#define Led6 7  //LED Verde

//Delay 
#define Tempo1 5000
#define Tempo2 2000

void setup()
{
//Primeiro Semáforo
pinMode(Led1, OUTPUT);//LED Vermelho
pinMode(Led2, OUTPUT);//LED Amarelo
pinMode(Led3, OUTPUT);//LED Verde

//Segundo Semáforo
pinMode(Led4, OUTPUT);//LED Vermelho
pinMode(Led5, OUTPUT);//LED Amarelo
pinMode(Led6, OUTPUT);//LED Verde

}
void loop()
{
digitalWrite(Led1, LOW);
digitalWrite(Led2, LOW);
digitalWrite(Led3, HIGH);
digitalWrite(Led4, HIGH);
digitalWrite(Led5, LOW);
digitalWrite(Led6, LOW);
delay(Tempo1);
digitalWrite(Led1, LOW);
digitalWrite(Led2, HIGH);
digitalWrite(Led3, LOW);
digitalWrite(Led4, HIGH);
digitalWrite(Led5, LOW);
digitalWrite(Led6, LOW);
delay(Tempo2);
digitalWrite(Led1, HIGH);
digitalWrite(Led2, LOW);
digitalWrite(Led3, LOW);
digitalWrite(Led4, LOW);
digitalWrite(Led5, LOW);
digitalWrite(Led6, HIGH);
delay(Tempo1);
digitalWrite(Led1, HIGH);
digitalWrite(Led2, LOW);
digitalWrite(Led3, LOW);
digitalWrite(Led4, LOW);
digitalWrite(Led5, HIGH);
digitalWrite(Led6, LOW);
delay(Tempo2);
}
