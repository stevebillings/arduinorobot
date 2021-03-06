#include "Turret.h"
#include "Drive.h"
#include "Pinger.h"
#include "State.h"
#include "StateNamer.h"
#include "StateChooser.h"
#include "Controller.h"

State state = initial;

const State Controller::setup() const {
	return state;
}

const State Controller::loop(State state) const {
  const StateChooser stateChooser;
  const int sensedObstacleDistInchesAhead = pinger.getObstacleDistanceInches();
  int sensedObstacleDistInchesLeft = 0;
  int sensedObstacleDistInchesRight = 0;
  if (state == stopped) {
  	turret.aimLeft();
  	sensedObstacleDistInchesLeft = pinger.getObstacleDistanceInches();

  	turret.aimRight();
  	sensedObstacleDistInchesRight = pinger.getObstacleDistanceInches();
  
  	turret.aimStraight();
  }
  state = stateChooser.choose(state, sensedObstacleDistInchesAhead, sensedObstacleDistInchesLeft, sensedObstacleDistInchesRight);
  switch (state) {
	case needToPause:
		drive.pause();
		state = paused;
		break;
	case needToStop:
		drive.stop();
    		drive.backUpALittle();
		state = stopped;
		break;
	case readyToDrive:
		drive.startForward();
		state = driving;
		break;
	case stoppedNeedToTurnLeft:
		drive.turnLeft();
		state = stopped;
		break;
	case stoppedNeedToTurnRight:
		drive.turnRight();
		state = stopped;
		break;
	case stoppedNeedToTurnAround:
		drive.turnAround();
		state = stopped;
		break;
	default:
		break;
  }
  return state;
}
