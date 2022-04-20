int GPIOPIN = 15;

void setup() {
  pinMode(GPIOPIN,OUTPUT);
}

void loop() {
  delay(1500);
  digitalWrite(GPIOPIN,HIGH);
  delay(500);
  digitalWrite(GPIOPIN,LOW);
}
