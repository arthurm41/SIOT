int leds[] = {2, 3, 4, 5}; 
int numLeds = 4;           
int tempo = 300;           

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(leds[i], HIGH);
    delay(tempo);
    digitalWrite(leds[i], LOW);
  }
  for (int i = numLeds - 2; i > 0; i--) {
    digitalWrite(leds[i], HIGH);
    delay(tempo);
    digitalWrite(leds[i], LOW);
  }
}
