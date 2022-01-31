/*
 * Turret.cpp
 *
 *  Created on: Jan 18, 2022
 *      Author: steve
 */
#include "Mode.h"

#ifdef FAKE
#include <iostream>
using namespace std;
#else
#include <Arduino.h>
#endif
#include "Turret.h"
#include "ServoWrapper.h"

#define SERVO_STRAIGHT 100
#define SERVO_LEFT 180
#define SERVO_RIGHT 10
#define SHORT_DELAY 25
#define LEFT_TO_RIGHT_DELTA -4
#define RIGHT_TO_LEFT_DELTA 4

Turret::Turret(unsigned int pwmPin) {
#ifdef FAKE
	cout << "Turret ctor passed pin: " << pwmPin << endl;
#endif
	servoWrapper = new ServoWrapper(pwmPin); // TODO delete this in dtor
	currentAngle = SERVO_STRAIGHT;
	minAngle = currentAngle;
	maxAngle = currentAngle;
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
	servoWrapper->write(targetAngle);
#ifndef FAKE
  delay(750);
#endif
}
