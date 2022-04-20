#include <Arduino_LSM9DS1.h>

float x, y, z;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");

  if (!IMU.begin()) {
    Serial.println("The IMU could not be initialized");
    while (1);
  }

  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println("Hz");
}

void loop() {
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
