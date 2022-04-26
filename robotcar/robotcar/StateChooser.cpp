#include "State.h"
#include "StateChooser.h"

#define OBSTACLE_SAFE_DIST_INCHES 8
#define START_SIGNAL_DIST_INCHES 2

State StateChooser::choose(State currentState, int inchesClearAhead) {
	return choose(currentState, inchesClearAhead, 0, 0);
}

State StateChooser::choose(State currentState, int inchesClearAhead, int inchesClearLeft, int inchesClearRight) {
	switch (currentState) {
		case initial:
			if (inchesClearAhead <= START_SIGNAL_DIST_INCHES) {
				return startSignalInProgress;
			}
			return currentState;
		case startSignalInProgress:
			if (inchesClearAhead >= OBSTACLE_SAFE_DIST_INCHES) {
				return readyToDrive;
			}
			return currentState;
		case driving:
			if (inchesClearAhead < OBSTACLE_SAFE_DIST_INCHES) {
				return needToStop;
			}
			return currentState;
		case stopped:
			if (inchesClearAhead >= OBSTACLE_SAFE_DIST_INCHES) {
				return readyToDrive;
			} else if (inchesClearLeft >= OBSTACLE_SAFE_DIST_INCHES) {
				return stoppedNeedToTurnLeft;
			} else if (inchesClearRight >= OBSTACLE_SAFE_DIST_INCHES) {
				return stoppedNeedToTurnRight;
			}
			return stoppedNeedToTurnAround;
		default:
			return needToStop;
	}
}
