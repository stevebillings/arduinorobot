
#ifndef STATE_H_
#define STATE_H_

enum State {
	initial,
	startSignalInProgress,
	readyToDrive,
	driving,
	needToPause,
	paused,
	needToStop,
	stopped,
	stoppedNeedToTurnLeft,
	stoppedNeedToTurnRight,
	stoppedNeedToTurnAround};

#endif
