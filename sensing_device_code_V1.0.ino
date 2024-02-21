#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

const int ledPin = 2; // LED pin

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  Wire.begin();
  mpu.initialize();
  
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed");
    for(;;); // Infinite loop
  } else {
    Serial.println("MPU6050 connection successful");
  }
}

void loop() {
  // Reading the raw values from accelerometer and gyroscope
  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Placeholder for converting raw values to angles and comparing them
  // For demonstration, let's assume a very simple check based on raw accelerometer values
  if (abs(ax) > 10000 || abs(ay) > 10000) { // These thresholds are arbitrary
    digitalWrite(ledPin, HIGH); // Turn LED on
  } else {
    digitalWrite(ledPin, LOW); // Turn LED off
  }

  delay(100); // Delay for a short period of time
}

