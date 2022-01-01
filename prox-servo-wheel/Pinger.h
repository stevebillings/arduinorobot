#include <NewPing.h> 

class Pinger {
	public:
		Pinger(unsigned int triggerPin, unsigned int echoPin);
		int getObstacleDistanceInches();
		~Pinger();
	private:
		NewPing *p_pinger;
};
