int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  setColor(255, 0, 0);  
  delay(1000);
  setColor(0, 255, 0);   
  delay(1000);
  setColor(0, 0, 255);   
  delay(1000);
  setColor(255, 255, 0); 
  delay(1000);
  setColor(0, 255, 255); 
  delay(1000);
  setColor(255, 0, 255); 
  delay(1000);
  setColor(255, 255, 255); 
  delay(1000);
}

void setColor(int r, int g, int b) {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}
