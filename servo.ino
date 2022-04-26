#include <Servo.h>


Servo myServo;
int speed = 1200;
int step = 50;


void setup() {
myServo.attach(2);
Serial.begin(9600);
}


void loop() {
rollit(speed);
delay(10);
if (speed < 400){
step = +50;
}
if (speed >1600){
step = -50;
}
Serial.print("Speed: ");
Serial.println(speed);
speed = speed + step;
}


void rollit (int rollspeed){
myServo.writeMicroseconds(rollspeed);
delay (500);
}