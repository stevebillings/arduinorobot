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
		static const int drivingSpeedRight = 170;
		static const int drivingSpeedLeft = 140;
		// Apparently I reversed +/- on the left wheel
		static const int leftWheelForward = BACKWARD;
		static const int leftWheelBackward = FORWARD;
		static const int rightWheelForward = FORWARD;
		static const int rightWheelBackward = BACKWARD;
		static const int quarterTurnDuration = 500;
		static const int shortDuration = 150;
};
