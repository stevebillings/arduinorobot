#include <Servo.h>

class Turret {
	public:
		Turret(unsigned int pwmPin);
		void aimRight();
		void aimLeft();
		void aimStraight();

	private:
		Servo servo;
		int currentAngle;
		void toAngle(int targetAngle);
};
