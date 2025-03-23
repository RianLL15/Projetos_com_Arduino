#define BUTTON 2

// Pinos dos segmentos para cada display (unidades)
const int segmentPins[3][7] = {
  {22, 23, 24, 25, 26, 27, 28}, // Unidades
};

int counter = 0;

// Matriz para display de anodo comum (1 = apagado, 0 = aceso)
const byte numbers[10][7] = {
  {0,0,0,0,0,0,1}, // 0
  {1,0,0,1,1,1,1}, // 1
  {0,0,1,0,0,1,0}, // 2
  {0,0,0,0,1,1,0}, // 3
  {1,0,0,1,1,0,0}, // 4
  {0,1,0,0,1,0,0}, // 5
  {0,1,0,0,0,0,0}, // 6
  {0,0,0,1,1,1,1}, // 7
  {0,0,0,0,0,0,0}, // 8
  {0,0,0,0,1,0,0}  // 9
};

// Função para exibir um número em um display específico
void displayNumber(int num, const int segment[7]) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segment[i], numbers[num][i]);
  }
}

void setup() {
  // Configurar pinos dos segmentos como saída
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 7; j++) {
      pinMode(segmentPins[i][j], OUTPUT);
    }
  }

  pinMode(BUTTON, INPUT_PULLUP); // Botão com resistor pull-up interno

  // Inicializar display com 000
  displayNumber(0, segmentPins[0]); // Unidades
}

void loop() {
  while (digitalRead(BUTTON) == LOW) { // Enquanto o botão estiver pressionado
    counter = (counter + 1) % 10; // Incrementa e reinicia ao atingir 9

    int unidades = counter % 10;

    displayNumber(unidades, segmentPins[0]); // Atualiza Unidades

    delay(200); // Controle da velocidade de contagem
  }
}