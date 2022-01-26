/*
 * Turret.h
 *
 *  Created on: Jan 18, 2022
 *      Author: steve
 */

#ifndef TURRET_H_
#define TURRET_H_

#include "ServoWrapper.h"

class Turret {
	private:
		ServoWrapper* servoWrapper;
		int currentAngle;
		int minAngle;
		int maxAngle;
		void toAngle(int targetAngle);
		void rightToAngle(int targetAngle);
		void leftToAngle(int targetAngle);
		void adjustMinMax();

	public:
		Turret(unsigned int pwmPin);
		void aimRight();
		void aimLeft();
		void aimStraight();
		void report();
};

#endif /* TURRET_H_ */
