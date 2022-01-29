#include "Mode.h"

#ifndef FAKE
#include <Arduino.h>
#include <NewPing.h> 
#else
#define US_ROUNDTRIP_IN 146
#define MAX_SENSOR_DISTANCE 500
#endif

#include "Pinger.h"

Pinger::Pinger(unsigned int triggerPin, unsigned int echoPin) {
#ifndef FAKE
	p_pinger = new NewPing(triggerPin, echoPin, MAX_SENSOR_DISTANCE);
#endif
}

int Pinger::getObstacleDistanceInches() {
  int numReadings = 4;
  int sumOfReadings = 0;
  for (int i=0; i<numReadings; i++) {
#ifndef FAKE
    delay(10);
    unsigned int uS = p_pinger->ping();
#else
    unsigned int uS = 1000;
#endif
    sumOfReadings += uS/US_ROUNDTRIP_IN;
  }
  return sumOfReadings/numReadings;
}

Pinger::~Pinger() {
	delete p_pinger;
}
