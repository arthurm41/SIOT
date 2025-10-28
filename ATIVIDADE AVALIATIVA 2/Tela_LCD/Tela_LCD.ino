#include "DHT.h"

#define DHTPIN 2        // Pino de sinal do DHT11
#define DHTTYPE DHT11   // Tipo do sensor

DHT dht(DHTPIN, DHTTYPE);

int ledAzul = 8;
int ledVerde = 9;
int ledVermelho = 10;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(ledAzul, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

void loop() {
  float temperatura = dht.readTemperature();  // Lê temperatura em °C
  float umidade = dht.readHumidity();         // Lê umidade %

  if (isnan(temperatura) || isnan(umidade)) {
    Serial.println("Falha na leitura do DHT11!");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  Serial.print("Umidade: ");
  Serial.print(umidade);
  Serial.println(" %");

  // Controle dos LEDs conforme a temperatura
  if (temperatura < 25) {
    digitalWrite(ledAzul, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, LOW);
  } else if (temperatura >= 25 && temperatura < 30) {
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledVermelho, LOW);
  } else {
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, HIGH);
  }

  delay(2000); // Espera 2 segundos para nova leitura
}
