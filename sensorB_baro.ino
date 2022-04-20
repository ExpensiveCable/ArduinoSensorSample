#include <Arduino_LPS22HB.h>

float temperature;
float pressure;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");

  if (!BARO.begin()) {
    Serial.println("The barometer could not be initialized");
    while (1);
  }
}

void loop() {
  temperature = BARO.readTemperature();
  pressure = BARO.readPressure();
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.print("Pressure = ");
  Serial.print(pressure);
  Serial.println("Pa");

}
