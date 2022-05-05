#include "Pinger.h"
#include <NewPing.h> 

class PingerReal : public Pinger {
	public:
		PingerReal(const unsigned int triggerPin, const unsigned int echoPin);
		const int getObstacleDistanceInches() const override;
		~PingerReal();
	private:
		NewPing *p_pinger;
};
