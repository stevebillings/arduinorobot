#include "State.h"
#include "StateChooser.h"

State StateChooser::choose(State currentState, int inchesClearAhead) {
	return choose(currentState, inchesClearAhead, 0, 0);
}

State StateChooser::choose(State currentState, int inchesClearAhead, int inchesClearLeft, int inchesClearRight) {
	switch (currentState) {
		case initial:
			if (inchesClearAhead <= startSignalDistanceInches) {
				return startSignalInProgress;
			}
			return currentState;
		case startSignalInProgress:
			if (inchesClearAhead >= obstacleSafeDistanceInches) {
				return readyToDrive;
			}
			return currentState;
		case driving:
			if (inchesClearAhead < obstacleSafeDistanceInches) {
				return needToPause;
			}
			return currentState;
		case paused:
			if (inchesClearAhead >= obstacleSafeDistanceInches) {
				return readyToDrive;
			} else {
				return needToStop;
			}
		case stopped:
			if (inchesClearAhead >= obstacleSafeDistanceInches) {
				return readyToDrive;
			} else if (inchesClearLeft >= obstacleSafeDistanceInches) {
				return stoppedNeedToTurnLeft;
			} else if (inchesClearRight >= obstacleSafeDistanceInches) {
				return stoppedNeedToTurnRight;
			}
			return stoppedNeedToTurnAround;
		default:
			return needToStop;
	}
}
