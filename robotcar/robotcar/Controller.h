/*
 * Controller.h
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

enum Direction {left, straight, right, none};

class Controller {
	public:
    		Controller(Turret* turret, Drive* drive, Pinger& pinger) :turret{turret}, drive{drive}, pinger{pinger} {}
		State setup();
		State loop(State state);
	private:
		Turret* turret;
		Drive* drive;
		Pinger& pinger;
		bool pingSensorBlocked(int sensedObstacleDistInches);
		bool pathIsClear(int sensedObstacleDistInches);
		void ledBlink(int pin, int numBlinks);
		Direction getSafeDirection();
		const char * getDirectionName(Direction dir);
		const char * getStateName(State state);
};

#endif /* CONTROLLER_H_ */
