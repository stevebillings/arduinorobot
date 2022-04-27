#include <Arduino.h>
#include <Servo.h>
#include "TurretReal.h"

#define SERVO_STRAIGHT 100
#define SERVO_LEFT 180
#define SERVO_RIGHT 10
#define SHORT_DELAY 25
#define LEFT_TO_RIGHT_DELTA -4
#define RIGHT_TO_LEFT_DELTA 4

TurretReal::TurretReal(int pwmPin) {
	servo = new Servo();
  servo->attach(pwmPin);
	currentAngle = SERVO_STRAIGHT;
	minAngle = currentAngle;
	maxAngle = currentAngle;
}

void TurretReal::aimRight() {
	toAngle(SERVO_RIGHT);
}

void TurretReal::aimLeft() {
	toAngle(SERVO_LEFT);
}

void TurretReal::aimStraight() {
	toAngle(SERVO_STRAIGHT);
}

// private

void TurretReal::toAngle(int targetAngle) {
	servo->write(targetAngle);
        delay(750);
}

TurretReal::~TurretReal() {
	delete servo;
}
