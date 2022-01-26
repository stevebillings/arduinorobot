#include <Arduino.h>
#include <Servo.h>
#include "Turret.h"

#define SERVO_LEFT 180
#define SERVO_RIGHT 10
#define SHORT_DELAY 25
#define LEFT_TO_RIGHT_DELTA -1
#define RIGHT_TO_LEFT_DELTA 1

Turret::Turret(unsigned int pwmPin) {
  // No matter what I write to it, it starts by going far right, and doesn't budge from there
  servo1.writeMicroseconds(1500);
	servo1.attach(9);
  currentAngle = SERVO_STRAIGHT;
  // TEMP does nothing
  //servo1.write(50); // temp
  //delay(1000);
  //servo1.write(130); // temp
  //delay(1000);
  // end TEMP
  //aimLeft();
  //aimRight();
  //aimStraight();
	//toAngle(SERVO_STRAIGHT);
}

void Turret::aimRight() {
	toAngle(SERVO_RIGHT);
}

void Turret::aimLeft() {
  toAngle(SERVO_LEFT);
}

void Turret::aimStraight() {
  toAngle(SERVO_STRAIGHT);
}

// private

void Turret::toAngle(int targetAngle) {
  if (currentAngle > targetAngle) {
    rightToAngle(targetAngle);
  } else if (currentAngle < targetAngle) {
    leftToAngle(targetAngle);
  }
}

void Turret::rightToAngle(int targetAngle) {
    for (; currentAngle >= targetAngle; currentAngle += LEFT_TO_RIGHT_DELTA) {
      servo1.write(currentAngle);
      delay(SHORT_DELAY);
  }
}

void Turret::leftToAngle(int targetAngle) {
  for (; currentAngle <= targetAngle; currentAngle += RIGHT_TO_LEFT_DELTA) {
    servo1.write(currentAngle);
    delay(SHORT_DELAY);
  }
}
