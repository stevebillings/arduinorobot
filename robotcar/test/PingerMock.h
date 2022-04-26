#include "../robotcar/Pinger.h"

class PingerMock : public Pinger {
	public:
		PingerMock(int obstacleDistanceInches);
		int getObstacleDistanceInches() override;
		~PingerMock();
	private:
		int obstacleDistanceInches;
};
