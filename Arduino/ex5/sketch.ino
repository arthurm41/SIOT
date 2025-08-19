int leds[] = {3, 5, 6, 9};
int numLeds = 4;
int brilho = 0;
int tempo = 5;  // velocidade do fade (ms)

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < numLeds; i++) {
    // acende LED atual com fade in
    for (brilho = 0; brilho <= 255; brilho++) {
      analogWrite(leds[i], brilho);
      delay(tempo);
    }
    // apaga LED atual com fade out
    for (brilho = 255; brilho >= 0; brilho--) {
      analogWrite(leds[i], brilho);
      delay(tempo);
    }
  }
}
