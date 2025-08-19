int led = 9; // LED no pino 9

const char* morse[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",   // A-I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."         // S-Z
};

String frase = "ARDUINO CHAT"; // frase para transmitir

int tempoPonto = 200;   // ponto = 200 ms
int tempoTraco = 600;   // traço = 600 ms
int tempoSimbolo = 200; // intervalo entre ponto/traço
int tempoLetra = 600;   // intervalo entre letras
int tempoPalavra = 1200; // intervalo entre palavras

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  transmitirMorse(frase);
  delay(5000); // repete a cada 5 segundos
}

void transmitirMorse(String texto) {
  texto.toUpperCase();
  for (int i = 0; i < texto.length(); i++) {
    char c = texto.charAt(i);
    if (c == ' ') {
      delay(tempoPalavra);
    } else if (c >= 'A' && c <= 'Z') {
      String codigo = morse[c - 'A'];
      for (int j = 0; j < codigo.length(); j++) {
        if (codigo[j] == '.') piscar(tempoPonto);
        else if (codigo[j] == '-') piscar(tempoTraco);
        delay(tempoSimbolo);
      }
      delay(tempoLetra);
    }
  }
}

void piscar(int duracao) {
  digitalWrite(led, HIGH);
  delay(duracao);
  digitalWrite(led, LOW);
  delay(tempoSimbolo);
}
