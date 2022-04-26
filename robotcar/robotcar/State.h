
#ifndef STATE_H_
#define STATE_H_

enum State {
	initial,
	startSignalInProgress,
	readyToDrive,
	driving,
	needToStop,
	stopped,
	stoppedNeedToTurnLeft,
	stoppedNeedToTurnRight,
	stoppedNeedToTurnAround};

#endif
