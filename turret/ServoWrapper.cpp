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
#include "Servo.h"
#else
#include <Arduino.h>
#include <Servo.h>
#endif
#include "ServoWrapper.h"

ServoWrapper::ServoWrapper(unsigned int pwmPin) {
#ifdef FAKE
	cout << "ServoWrapper ctor passed pin: " << pwmPin << endl;
#endif
	servo = new Servo();
	servo->attach(pwmPin);
}

void ServoWrapper::write(unsigned int targetAngle) {
#ifdef FAKE
	cout << "ServoWrapper::write() passed targetAngle: " << targetAngle << endl;
#else
	servo->write(targetAngle);
#endif
}
