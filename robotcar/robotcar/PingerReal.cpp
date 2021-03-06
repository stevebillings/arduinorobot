#include <Arduino.h>
#include <NewPing.h> 
#include "PingerReal.h"

PingerReal::PingerReal(const unsigned int triggerPin, const unsigned int echoPin) {
	p_pinger = new NewPing(triggerPin, echoPin, MAX_SENSOR_DISTANCE);
}

const int PingerReal::getObstacleDistanceInches() const {
  const int numReadings = 4;
  int sumOfReadings = 0;
  for (int i=0; i<numReadings; i++) {
    delay(10);
    const unsigned int uS = p_pinger->ping();
    sumOfReadings += uS/US_ROUNDTRIP_IN;
  }
  return sumOfReadings/numReadings;
}

PingerReal::~PingerReal() {
	delete p_pinger;
}
