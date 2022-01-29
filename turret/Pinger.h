#ifndef FAKE
#include <NewPing.h> 
#else
#define NewPing int // TODO gotta be a better way
#endif

class Pinger {
	public:
		Pinger(unsigned int triggerPin, unsigned int echoPin);
		int getObstacleDistanceInches();
		~Pinger();
	private:
		NewPing *p_pinger;
};
