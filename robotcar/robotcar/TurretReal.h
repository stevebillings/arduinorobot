#ifndef TURRETREAL_H_
#define TURRETREAL_H_

#include "Turret.h"
#include <Servo.h>

// Seems dumb to expose this here
#define SERVO_STRAIGHT 100

class TurretReal : public Turret {
	private:
		int pwmPin;
		Servo* servo;
		int currentAngle;
		int minAngle;
		int maxAngle;
		void toAngle(int targetAngle);

	public:
		TurretReal(int pwmPin) :pwmPin{pwmPin} {
			servo = new Servo();
  			servo->attach(this->pwmPin);
			currentAngle = SERVO_STRAIGHT;
			minAngle = currentAngle;
			maxAngle = currentAngle;
		}
		void aimRight();
		void aimLeft();
		void aimStraight();
		~TurretReal();
};

#endif /* TURRETREAL_H_ */
