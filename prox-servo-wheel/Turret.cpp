#include <Arduino.h>
#include <Servo.h>
#include "Turret.h"

#define SERVO_LEFT 0
#define SERVO_STRAIGHT 90
#define SERVO_RIGHT 180

Turret::Turret(unsigned int pwmPin) {
	servo.attach(pwmPin);
	toAngle(SERVO_STRAIGHT);
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
	int incr;
	if (currentAngle == targetAngle) {
		// make sure (might be initializing)
		servo.write(currentAngle);
		delay(500);
		return;
	}
	if (currentAngle < targetAngle) {
		incr = 1;
	} else {
		incr = -1;
	}
	for ( ; currentAngle != targetAngle; currentAngle += incr) {
		servo.write(currentAngle);
		delay(50);
	}
}
