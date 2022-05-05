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

void TurretReal::aimRight() const {
	toAngle(servoRight);
}

void TurretReal::aimLeft() const {
	toAngle(servoLeft);
}

void TurretReal::aimStraight() const {
	toAngle(servoStraight);
}

// private

void TurretReal::toAngle(int targetAngle) const {
	servo->write(targetAngle);
        delay(750);
}

TurretReal::~TurretReal() {
	delete servo;
}
