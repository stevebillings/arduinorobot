#include "../robotcar/Drive.h"

class DriveMock : public Drive {
	public:
		DriveMock();
		void startForward() const override;
		void pause() const override;
		void stop() const override;
		void turnLeft() const override;
		void turnRight() const override;
    		void turnAround() const override;
	        void backUpALittle() const override;
};
