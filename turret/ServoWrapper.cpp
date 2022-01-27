/*
 * ServoWrapper.cpp
 *
 *  Created on: Jan 20, 2022
 *      Author: steve
 */
#include "Mode.h"

#ifdef FAKE
#include <iostream>
using namespace std;
#endif
#include "ServoWrapper.h"

#ifndef FAKE
#include <Arduino.h>
#include <Servo.h>

Servo servo;
#endif

ServoWrapper::ServoWrapper(unsigned int pwmPin) {
#ifdef FAKE
	cout << "ServoWrapper ctor passed pin: " << pwmPin << endl;
#else
	servo.attach(pwmPin);
#endif
}

void ServoWrapper::write(unsigned int targetAngle) {
#ifdef FAKE
	cout << "ServoWrapper::write() passed targetAngle: " << targetAngle << endl;
#else
	servo.write(targetAngle);
#endif
}
