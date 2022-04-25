#include <NewPing.h> 

class PingerReal : public Pinger {
	public:
		PingerReal(unsigned int triggerPin, unsigned int echoPin);
		int getObstacleDistanceInches() override;
		~PingerReal();
	private:
		NewPing *p_pinger;
};
