#include "Drive.h"

class DriveReal : public Drive {
	public:
		DriveReal();
		void startForward() override;
		void stop() override;
		void turnLeft() override;
		void turnRight() override;
    		void turnAround() override;
	        void backUpALittle() override;
};
