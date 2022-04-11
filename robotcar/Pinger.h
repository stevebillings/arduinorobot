#ifndef FAKE
#include <NewPing.h> 
#else
#define NewPing int // TODO gotta be a better way
#endif

class Pinger {
	public:
#ifndef FAKE
		Pinger(unsigned int triggerPin, unsigned int echoPin);
#endif
		int getObstacleDistanceInches();
#ifndef FAKE
		~Pinger();
#endif
	private:
#ifndef FAKE
		NewPing *p_pinger;
#endif
};
