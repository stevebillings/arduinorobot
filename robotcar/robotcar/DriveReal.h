#include "Drive.h"
#include <AFMotor.h>

class DriveReal : public Drive {
	public:
		DriveReal();
		void startForward() override;
		void pause() override;
		void stop() override;
		void turnLeft() override;
		void turnRight() override;
    		void turnAround() override;
	        void backUpALittle() override;
	private:
		const int drivingSpeedRight = 170;
		const int drivingSpeedLeft = 140;
		// Apparently I reversed +/- on the left wheel
		const int leftWheelForward = BACKWARD;
		const int leftWheelBackward = FORWARD;
		const int rightWheelForward = FORWARD;
		const int rightWheelBackward = BACKWARD;
		const int quarterTurnDuration = 500;
		const int shortDuration = 150;
};
