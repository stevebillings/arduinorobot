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
#define LEFT_TO_RIGHT_DELTA -1
#define RIGHT_TO_LEFT_DELTA 1

Turret::Turret(Servo* servo, unsigned int pwmPin) {
#ifdef FAKE
	cout << "Turret ctor passed pin: " << pwmPin << endl;
#endif
	servoWrapper = new ServoWrapper(servo, pwmPin); // TODO delete this in dtor
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
	if (currentAngle > targetAngle) {
		rightToAngle(targetAngle);
	} else if (currentAngle < targetAngle) {
		leftToAngle(targetAngle);
	}
}

void Turret::rightToAngle(int targetAngle) {
#ifdef FAKE
	cout << "Moving right:" << endl;
#endif
	for (; currentAngle >= targetAngle; currentAngle += LEFT_TO_RIGHT_DELTA) {
		servoWrapper->write(currentAngle);
#ifndef FAKE
		delay(SHORT_DELAY);
#endif
	}
	currentAngle -= LEFT_TO_RIGHT_DELTA;
	adjustMinMax();
#ifdef FAKE
	cout << "Done moving right" << endl;
#endif
}

void Turret::leftToAngle(int targetAngle) {
#ifdef FAKE
	cout << "Moving left:" << endl;
#endif
	for (; currentAngle <= targetAngle; currentAngle += RIGHT_TO_LEFT_DELTA) {
		servoWrapper->write(currentAngle);
#ifndef FAKE
		delay(SHORT_DELAY);
#endif
	}
	currentAngle -= RIGHT_TO_LEFT_DELTA;
	adjustMinMax();
#ifdef FAKE
	cout << "Done moving left" << endl;
#endif
}

void Turret::report() {
#ifdef FAKE
	cout << "Max: " << maxAngle << "; Min: " << minAngle << endl;
#endif
}

void Turret::adjustMinMax() {
	if (currentAngle < minAngle) {
		minAngle = currentAngle;
	}
	if (currentAngle > maxAngle) {
		maxAngle = currentAngle;
	}
}
