#include <Arduino.h>
#include <Servo.h>
#include "TurretReal.h"

TurretReal::TurretReal(int pwmPin) {
	servo = new Servo();
  	servo->attach(pwmPin);
	currentAngle = servoStraight;
	minAngle = currentAngle;
	maxAngle = currentAngle;
}

void TurretReal::aimRight() {
	toAngle(servoRight);
}

void TurretReal::aimLeft() {
	toAngle(servoLeft);
}

void TurretReal::aimStraight() {
	toAngle(servoStraight);
}

// private

void TurretReal::toAngle(int targetAngle) {
	servo->write(targetAngle);
        delay(750);
}

TurretReal::~TurretReal() {
	delete servo;
}
