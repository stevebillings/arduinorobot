#include "Drive.h"
#include <AFMotor.h>

class DriveReal : public Drive {
	public:
		DriveReal();
		void startForward() const override;
		void pause() const override;
		void stop() const override;
		void turnLeft() const override;
		void turnRight() const override;
    		void turnAround() const override;
	        void backUpALittle() const override;
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
