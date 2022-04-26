#include "PingerMock.h"
#include <iostream>
using namespace std;

PingerMock::PingerMock(int obstacleDistanceInches) {
	this->obstacleDistanceInches = obstacleDistanceInches;
}

int PingerMock::getObstacleDistanceInches() {
  cout << "PingerMock.getObstacleDistanceInches() called; returning " << obstacleDistanceInches << endl;
  return obstacleDistanceInches;
}

PingerMock::~PingerMock() {
  cout << "PingerMock destructor called" << endl;
}
