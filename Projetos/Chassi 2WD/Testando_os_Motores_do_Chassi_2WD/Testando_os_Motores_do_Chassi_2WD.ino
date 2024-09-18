//motor_A
int IN1 = 11 ;
int IN2 = 10 ;
 
//motor_B
int IN3 = 9 ;
int IN4 = 8 ;

//Inicializa Pinos
void setup(){
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}
 
void loop(){

   // anda pra frente
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);

  delay(1000);

  // andar pra atrás
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);

  delay(1000);

  // virar pra esquerda
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  
  delay(1000);

  // virar pra direita
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);

  delay(1000);
 
}
