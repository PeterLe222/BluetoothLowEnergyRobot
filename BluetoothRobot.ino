#include "AFMotor.h"

AF_DCMotor MOTOR_1 (3, MOTOR12_64KHZ); // define motor on channel 3 with 64KHz PWM
AF_DCMotor MOTOR_2 (4, MOTOR12_64KHZ); // define motor on channel 4 with 64KHz PWM

void setup() {
  
  Serial.begin(9600);
  MOTOR_1.setSpeed(255);  // set the max speed for motor 1
  MOTOR_2.setSpeed(255);  // set the max speed for motor 2
  
}

char state; // variable of recieving message from bluetooth

void loop() {
  
  state = Serial.read(); // recieve command from bluetooth
  Serial.println(state);
  // go forward
  if (state == 'a' || state == 'A'|| state == 'e' || state == 'E')
  {
    MOTOR_1.run(FORWARD);
    MOTOR_2.run(FORWARD);
  }
  // go backward
  if (state == 'c' || state == 'C'|| state == 'g' || state == 'G')
  {
    MOTOR_1.run(BACKWARD);
    MOTOR_2.run(BACKWARD);
  }
  // turn left
  if (state == 'd' || state == 'D'|| state == 'h' || state == 'H')
  {
    MOTOR_1.run(FORWARD);
    MOTOR_2.run(BACKWARD);
  }
  // turn right
  if (state == 'b' || state == 'B'|| state == 'f' || state == 'F')
  {
    MOTOR_2.run(FORWARD);
    MOTOR_1.run(BACKWARD);
  }
  // stop the robot
  if (state == 0)
  {
    MOTOR_1.run(RELEASE);
    MOTOR_2.run(RELEASE);
  }
}
