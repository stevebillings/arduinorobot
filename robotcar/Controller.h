/*
 * Controller.h
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

enum Direction {left, straight, right, none};

class Controller {
	public:
		void setup();
		void loop();
	private:
		bool pingSensorBlocked(int sensedObstacleDistInches);
		bool pathIsClear(int sensedObstacleDistInches);
		void ledBlink(int pin, int numBlinks);
		Direction getSafeDirection();
};

#endif /* CONTROLLER_H_ */
