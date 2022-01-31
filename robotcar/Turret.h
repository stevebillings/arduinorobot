/*
 * Turret.h
 *
 *  Created on: Jan 18, 2022
 *      Author: steve
 */

#ifndef TURRET_H_
#define TURRET_H_

#include "ServoWrapper.h"
#ifdef FAKE
#include "Servo.h"
#else
#include <Servo.h>
#endif

class Turret {
	private:
		ServoWrapper* servoWrapper;
		int currentAngle;
		int minAngle;
		int maxAngle;
		void toAngle(int targetAngle);

	public:
		Turret(unsigned int pwmPin);
		void aimRight();
		void aimLeft();
		void aimStraight();
};

#endif /* TURRET_H_ */
