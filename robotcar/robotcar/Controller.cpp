#include "Turret.h"
#include "Drive.h"
#include "Pinger.h"
#include "State.h"
#include "StateNamer.h"
#include "StateChooser.h"
#include "Controller.h"

#define OBSTACLE_SAFE_DIST_INCHES 6
#define START_SIGNAL_DIST_INCHES 2

State state = initial;
int stuckCount = 0;

Controller::Controller(Turret* turret, Drive* drive, Pinger* pinger) {
  this->turret = turret;
  this->drive = drive;
  this->pinger = pinger;
}

State Controller::setup() {
	return state;
}

State Controller::loop(State state) {
  StateChooser stateChooser;
  int sensedObstacleDistInchesAhead = pinger->getObstacleDistanceInches();
  int sensedObstacleDistInchesLeft = 0;
  int sensedObstacleDistInchesRight = 0;
  if (state == stopped) {
  	turret->aimLeft();
  	sensedObstacleDistInchesLeft = pinger->getObstacleDistanceInches();

  	turret->aimRight();
  	sensedObstacleDistInchesRight = pinger->getObstacleDistanceInches();
  
  	turret->aimStraight();
  }
  state = stateChooser.choose(state, sensedObstacleDistInchesAhead, sensedObstacleDistInchesLeft, sensedObstacleDistInchesRight);
  switch (state) {
	case needToStop:
		drive->stop();
    		drive->backUpALittle();
		state = stopped;
		break;
	case readyToDrive:
		drive->startForward();
		state = driving;
		break;
	case stoppedNeedToTurnLeft:
		drive->turnLeft();
		state = stopped;
		break;
	case stoppedNeedToTurnRight:
		drive->turnRight();
		state = stopped;
		break;
	case stoppedNeedToTurnAround:
		drive->turnAround();
		state = stopped;
		break;
  }
  return state;
}
