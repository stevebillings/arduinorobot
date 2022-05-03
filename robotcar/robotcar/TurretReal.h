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
		const int servoStraight = 100;
		const int servoLeft = 180;
		const int servoRight = 10;
		const int shortDelay = 25;
		const int leftToRightDelta = -4;
		const int rightToLeftDelta = 4;

	public:
		TurretReal(int pwmPin);
		void aimRight();
		void aimLeft();
		void aimStraight();
		~TurretReal();
};

#endif /* TURRETREAL_H_ */
