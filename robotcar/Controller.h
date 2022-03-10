/*
 * Controller.h
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

enum Direction {left, straight, right, none};

class Controller {
	public:
    Controller(Turret* turret, Drive* drive, Pinger* pinger);
		void setup();
		void loop();
	private:
    Turret* turret;
    Drive* drive;
    Pinger* pinger;
		bool pingSensorBlocked(int sensedObstacleDistInches);
		bool pathIsClear(int sensedObstacleDistInches);
		void ledBlink(int pin, int numBlinks);
		Direction getSafeDirection();
};

#endif /* CONTROLLER_H_ */
