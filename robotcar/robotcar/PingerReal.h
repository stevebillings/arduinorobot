#include "Pinger.h"
#include <NewPing.h> 

class PingerReal : public Pinger {
	public:
		PingerReal(unsigned int triggerPin, unsigned int echoPin);
		const int getObstacleDistanceInches() const override;
		~PingerReal();
	private:
		NewPing *p_pinger;
};
