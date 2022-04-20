const int ledPin =  15;
const int interruptPin = 13;

int ledState = LOW;            
int n = 0;


unsigned long previousMillis = 0;        

const long period = 2000;           
const long duty = 25;

void blink_ISR() {
  int LedStateread = digitalRead(interruptPin);
  Serial.print(millis());
  Serial.print(":");
  Serial.println(LedStateread);
}

void setup() {
  Serial.begin(9600);
  while (!Serial);
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT);
  attachInterrupt(interruptPin, blink_ISR, CHANGE);
}

int duty_int = 100/duty;
int interval = period/duty_int;

void loop() {

  unsigned long currentMillis = millis();
  
  noInterrupts();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    if (n%duty_int == 0) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    n = n+1;
    
    
    digitalWrite(ledPin, ledState);
    
  }
  interrupts();
  blink_ISR();
}
