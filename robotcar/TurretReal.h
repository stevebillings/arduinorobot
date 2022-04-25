#ifndef TURRETREAL_H_
#define TURRETREAL_H_

#include "Turret.h"
#include "ServoWrapper.h"
#include <Servo.h>

class TurretReal : public Turret {
	private:
		ServoWrapper* servoWrapper;
		int currentAngle;
		int minAngle;
		int maxAngle;
		void toAngle(int targetAngle);

	public:
		TurretReal(unsigned int pwmPin);
		void aimRight();
		void aimLeft();
		void aimStraight();
};

#endif /* TURRETREAL_H_ */
