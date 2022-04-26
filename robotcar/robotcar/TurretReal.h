#ifndef TURRETREAL_H_
#define TURRETREAL_H_

#include "Turret.h"
#include <Servo.h>

class TurretReal : public Turret {
	private:
		Servo* servo;
		int currentAngle;
		int minAngle;
		int maxAngle;
		void toAngle(int targetAngle);

	public:
		TurretReal(int pwmPin);
		void aimRight();
		void aimLeft();
		void aimStraight();
};

#endif /* TURRETREAL_H_ */
