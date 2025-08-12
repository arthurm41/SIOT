void setup() {
  pinMode(13, INPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  if(digitalRead(13)==LOW){
    digitalWrite(12,LOW);
    delay(1000);
  }else{
    digitalWrite(12, HIGH);
    delay(1000);
  }
}