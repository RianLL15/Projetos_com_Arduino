#define BUTTON 2

// Pinos dos segmentos para cada display (unidades, dezenas, centenas)
const int segmentPins[3][7] = {
  {22, 23, 24, 25, 26, 27, 28}, // Unidades
  {29, 30, 31, 32, 33, 34, 35}, // Dezenas
  {36, 37, 38, 39, 40, 41, 42}  // Centenas
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
  displayNumber(0, segmentPins[1]); // Dezenas
  displayNumber(0, segmentPins[2]); // Centenas
}

void loop() {
  while (digitalRead(BUTTON) == LOW) { // Enquanto o botão estiver pressionado
    counter = (counter + 1) % 1000; // Incrementa e reinicia ao atingir 999

    int unidades = counter % 10;
    int dezenas = (counter / 10) % 10;
    int centenas = (counter / 100) % 10;

    displayNumber(unidades, segmentPins[0]); // Atualiza Unidades
    displayNumber(dezenas, segmentPins[1]);  // Atualiza Dezenas
    displayNumber(centenas, segmentPins[2]); // Atualiza Centenas

    delay(200); // Controle da velocidade de contagem
  }
}