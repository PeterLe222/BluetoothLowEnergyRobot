#include "AFMotor.h"

AF_DCMotor motor (3, MOTOR12_64KHZ);
AF_DCMotor motor2(4, MOTOR12_64KHZ);

void setup() {
  
  Serial.begin(9600);
  motor.setSpeed(255);
  motor2.setSpeed(255);
  
}
char state;

void loop() {
  
  state = Serial.read(); // recieve command from bluetooth
  Serial.println(state);
  // go forward
  if (state == 'a' || state == 'A'|| state == 'e' || state == 'E')
  {
    motor.run(FORWARD);
    motor2.run(FORWARD);
  }
  // go backward
  if (state == 'c' || state == 'C'|| state == 'g' || state == 'G')
  {
    motor.run(BACKWARD);
    motor2.run(BACKWARD);
  }
  // turn left
  if (state == 'd' || state == 'D'|| state == 'h' || state == 'H')
  {
    motor.run(FORWARD);
    motor2.run(BACKWARD);
  }
  // turn right
  if (state == 'b' || state == 'B'|| state == 'f' || state == 'F')
  {
    motor2.run(FORWARD);
    motor.run(BACKWARD);
  }
  // stop the robot
  if (state == 0)
  {
    motor.run(RELEASE);
    motor2.run(RELEASE);
  }
}
