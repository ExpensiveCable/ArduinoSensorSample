#include <Arduino_LSM9DS1.h>
#include <Arduino_LPS22HB.h>
float temperature;
float pressure;
float x, y, z;
          
int n = 0;

unsigned long previousMillis = 0;        

const long period = 5000;           
const long duty = 20;
int duty_int = 100/duty;
int interval = period/duty_int;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");

  if (!IMU.begin()) {
    Serial.println("The IMU could not be initialized");
    while (1);
  }
  
  if (!BARO.begin()) {
    Serial.println("The barometer could not be initialized");
    while (1);
  }
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (n%duty_int == 0) {
      if (IMU.accelerationAvailable()) {
       IMU.readAcceleration(x, y, z);
       Serial.print("Acceleration: (");
       Serial.print(x);
       Serial.print(",");
       Serial.print(y);
       Serial.print(",");
       Serial.print(z);
       Serial.println(")");
      }
    } 
    else {
    }
    temperature = BARO.readTemperature();
    pressure = BARO.readPressure();
    Serial.print("Temperature = ");
    Serial.print(temperature);
    Serial.println("°C");
    Serial.print("Pressure = ");
    Serial.print(pressure);
    Serial.println("Pa");
    n = n+1;
  }
}
