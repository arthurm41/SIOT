int leds[] = {2, 3, 4, 5, 6}; // pinos dos LEDs
int pot = A0; // potenciômetro

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  int valor = analogRead(pot); // lê o potenciômetro (0-1023)
  
  // converte para 0 a 5 níveis
  int nivel = map(valor, 0, 1023, 0, 5);

  // acende LEDs até o nível correspondente
  for (int i = 0; i < 5; i++) {
    if (i < nivel) {
      digitalWrite(leds[i], HIGH);
    } else {
      digitalWrite(leds[i], LOW);
    }
  }

  delay(50); // suaviza leitura
}
