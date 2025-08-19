
const byte NUM_BITS = 4;  
const int ledPins[8] = {2, 3, 4, 5, 6, 7, 8, 9}; 
const unsigned int INTERVALO_MS = 400; 

void setup() {
  for (byte i = 0; i < NUM_BITS; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  for (unsigned int valor = 0; valor < (1U << NUM_BITS); valor++) {
    mostraBinario(valor);
    delay(INTERVALO_MS);
  }
}

void mostraBinario(unsigned int valor) {
  for (byte bit = 0; bit < NUM_BITS; bit++) {
    bool estado = (valor >> bit) & 0x01;
    digitalWrite(ledPins[bit], estado ? HIGH : LOW);
  }
}
