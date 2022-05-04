#include "PingerMock.h"
#include <iostream>
using namespace std;

const int PingerMock::getObstacleDistanceInches() const {
  cout << "PingerMock.getObstacleDistanceInches() called; returning " << obstacleDistanceInches << endl;
  return obstacleDistanceInches;
}

PingerMock::~PingerMock() {
  cout << "PingerMock destructor called" << endl;
}
