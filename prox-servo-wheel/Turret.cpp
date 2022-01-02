#include <Arduino.h>
#include <Servo.h>
#include "Turret.h"

#define SERVO_LEFT 0
#define SERVO_STRAIGHT 90
#define SERVO_RIGHT 180

Turret::Turret(unsigned int pwmPin) {
	servo.attach(pwmPin);
	servo.write(SERVO_STRAIGHT);
}

void Turret::aimRight() {
	servo.write(SERVO_RIGHT);
	delay(1000);
}

void Turret::aimLeft() {
	servo.write(SERVO_LEFT);
	delay(1000);
}

void Turret::aimStraight() {
	servo.write(SERVO_STRAIGHT);
	delay(1000);
}
