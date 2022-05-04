#include "../robotcar/Pinger.h"

class PingerMock : public Pinger {
	public:
		PingerMock(int obstacleDistanceInches) : obstacleDistanceInches(obstacleDistanceInches) {};
		const int getObstacleDistanceInches() const override;
		~PingerMock();
	private:
		const int obstacleDistanceInches;
};
