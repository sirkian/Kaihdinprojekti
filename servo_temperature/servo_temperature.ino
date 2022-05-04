#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#include <Servo.h>
#define SRVPIN 13    // Servo pin

Adafruit_BMP280 bme;
Servo mservo;
int highCount;
unsigned long delayTime;
float temperature;
// TODO: threshold from mobile
float threshold;
bool closed;

void setup() {
  Serial.begin(9600);
  highCount = 0;
  delayTime = 5000;
  temperature = 0;
  threshold = 24.0;
  closed = false;
  mservo.attach(SRVPIN);

  bool status;

  // default settings
  // (you can also pass in a Wire library object like &Wire2)
  status = bme.begin(0x76);  
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }  
}

void closeBlinds() {
  if (!closed) {
    mservo.writeMicroseconds(1000);
    delay(600);
    mservo.writeMicroseconds(1500);
    closed = true; 
  }
}

void loop() {
  temperature = bme.readTemperature();
  Serial.println(temperature); 
  if (temperature >= threshold) {
      highCount++;
  } else if (temperature < threshold) {
      highCount = 0;
  }
  if (highCount >= 3) {
    Serial.println("Too hot! Closing the blinds!");
    closeBlinds();   
  }
  delay(delayTime);
}
