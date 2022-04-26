#include "State.h"
#include "StateNamer.h"

const char * StateNamer::getStateName(State state) {
  const char *p;
  switch(state) {
    case State::initial:
	p = "initial";
	break;
    case State::startSignalInProgress:
	p = "startSignalInProgress";
	break;
    case State::readyToDrive:
	p = "readyToDrive";
	break;
    case State::driving:
	p = "driving";
	break;
    case State::needToStop:
	p = "needToStop";
	break;
    case State::stopped:
	p = "stopped";
	break;
    case State::stoppedNeedToTurnLeft:
	p = "stoppedNeedToTurnLeft";
	break;
    case State::stoppedNeedToTurnRight:
	p = "stoppedNeedToTurnRight";
	break;
    case State::stoppedNeedToTurnAround:
	p = "stoppedNeedToTurnAround";
	break;
    default:
        p = "UNKNOWN";
  }
  return p;
}
