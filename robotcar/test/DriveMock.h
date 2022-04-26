#include "../robotcar/Drive.h"

class DriveMock : public Drive {
	public:
		DriveMock();
		void startForward() override;
		void stop() override;
		void turnLeft() override;
		void turnRight() override;
    		void turnAround() override;
	        void backUpALittle() override;
};
