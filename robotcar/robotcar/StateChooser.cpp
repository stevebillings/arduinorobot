#include "State.h"
#include "StateChooser.h"

const State StateChooser::choose(const State currentState, const int inchesClearAhead) const {
	return choose(currentState, inchesClearAhead, 0, 0);
}

const State StateChooser::choose(const State currentState, const int inchesClearAhead, const int inchesClearLeft, const int inchesClearRight) const {
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
