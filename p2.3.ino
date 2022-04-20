const int ledPin =  15;

int ledState = LOW;            
int n = 0;

unsigned long previousMillis = 0;        

const long period = 2000;           
const long duty = 25;

void setup() {
  pinMode(ledPin, OUTPUT);
}

int duty_int = 100/duty;
int interval = period/duty_int;

void loop() {

  unsigned long currentMillis = millis();

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
}
