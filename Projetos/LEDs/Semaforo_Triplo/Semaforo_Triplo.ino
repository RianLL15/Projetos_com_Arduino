//Primeiro Semáforo
#define Led1 2  //LED Vermelho
#define Led2 3  //LED Amarelo
#define Led3 4  //LED Verde

//Segundo Semáforo
#define Led4 5  //LED Vermelho
#define Led5 6  //LED Amarelo
#define Led6 7  //LED Verde

//Terceiro Semáforo
#define Led7 8  //LED Vermelho
#define Led8 9  //LED Amarelo
#define Led9 10 //LED Verde

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

//Terceiro Semáforo
pinMode(Led7, OUTPUT);//LED Vermelho
pinMode(Led8, OUTPUT);//LED Amarelo
pinMode(Led9, OUTPUT);//LED Verde


}
void loop()
{
digitalWrite(Led1, LOW);
digitalWrite(Led2, LOW);
digitalWrite(Led3, HIGH);
digitalWrite(Led4, HIGH);
digitalWrite(Led5, LOW);
digitalWrite(Led6, LOW);
digitalWrite(Led7, HIGH);
digitalWrite(Led8, LOW);
digitalWrite(Led9, LOW);
delay(Tempo1);
digitalWrite(Led1, LOW);
digitalWrite(Led2, HIGH);
digitalWrite(Led3, LOW);
digitalWrite(Led4, HIGH);
digitalWrite(Led5, LOW);
digitalWrite(Led6, LOW);
digitalWrite(Led7, HIGH);
digitalWrite(Led8, LOW);
digitalWrite(Led9, LOW);
delay(Tempo2);
digitalWrite(Led1, HIGH);
digitalWrite(Led2, LOW);
digitalWrite(Led3, LOW);
digitalWrite(Led4, LOW);
digitalWrite(Led5, LOW);
digitalWrite(Led6, HIGH);
digitalWrite(Led7, HIGH);
digitalWrite(Led8, LOW);
digitalWrite(Led9, LOW);
delay(Tempo1);
digitalWrite(Led1, HIGH);
digitalWrite(Led2, LOW);
digitalWrite(Led3, LOW);
digitalWrite(Led4, LOW);
digitalWrite(Led5, HIGH);
digitalWrite(Led6, LOW);
digitalWrite(Led7, HIGH);
digitalWrite(Led8, LOW);
digitalWrite(Led9, LOW);
delay(Tempo2);
digitalWrite(Led1, HIGH);
digitalWrite(Led2, LOW);
digitalWrite(Led3, LOW);
digitalWrite(Led4, HIGH);
digitalWrite(Led5, LOW);
digitalWrite(Led6, LOW);
digitalWrite(Led7, LOW);
digitalWrite(Led8, LOW);
digitalWrite(Led9, HIGH);;
delay(Tempo1);
digitalWrite(Led1, HIGH);
digitalWrite(Led2, LOW);
digitalWrite(Led3, LOW);
digitalWrite(Led4, HIGH);
digitalWrite(Led5, LOW);
digitalWrite(Led6, LOW);
digitalWrite(Led7, LOW);
digitalWrite(Led8, HIGH);
digitalWrite(Led9, LOW);
delay(Tempo2);
}
