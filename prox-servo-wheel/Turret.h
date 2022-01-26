#include <Servo.h>

#define SERVO_STRAIGHT 100

class Turret {
	public:
		Turret(unsigned int pwmPin);
		void aimRight();
		void aimLeft();
		void aimStraight();

	private:
		Servo servo1;
		int currentAngle = SERVO_STRAIGHT;
		void toAngle(int targetAngle);
    void rightToAngle(int targetAngle);
    void leftToAngle(int targetAngle);
};
