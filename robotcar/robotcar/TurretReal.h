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
		static const int servoStraight = 100;
		static const int servoLeft = 180;
		static const int servoRight = 10;
		static const int shortDelay = 25;
		static const int leftToRightDelta = -4;
		static const int rightToLeftDelta = 4;

	public:
		TurretReal(int pwmPin);
		void aimRight();
		void aimLeft();
		void aimStraight();
		~TurretReal();
};

#endif /* TURRETREAL_H_ */
