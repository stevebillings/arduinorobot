#include "Drive.h"
#include "Pinger.h"
#include "Turret.h"

#define OBSTACLE_SAFE_DIST_INCHES 20
#define START_SIGNAL_DIST_INCHES 2

enum State {initial, startSignalInProgress, readyToDrive, driving, stopped};
enum Direction {left, straight, right, none};

Drive drive;
Pinger pinger(A4, A5);
Turret turret(9);

State state = initial;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  ledBlink(LED_BUILTIN, 3); // Bootup signal
}

void loop() {
  int sensedObstacleDistInches = pinger.getObstacleDistanceInches();
  switch (state) {
    case initial:
      if (pingSensorBlocked(sensedObstacleDistInches)) {
        state = startSignalInProgress;
        ledBlink(LED_BUILTIN, 1);
      }
      break;
    case startSignalInProgress:
    case stopped:
      if (pathIsClear(sensedObstacleDistInches)) {
        state = readyToDrive;
      }
      break;
    case readyToDrive:
      if (pathIsClear(sensedObstacleDistInches)) {
        drive.startForward();
        state = driving;
      }
      break;
    default: // driving
      if (!pathIsClear(sensedObstacleDistInches)) {
        drive.stop();
        state = stopped;
        Direction safeDirection = getSafeDirection();
        if (safeDirection == left) {
          drive.turnLeft();
        } else if (safeDirection == right) {
          drive.turnRight();
        }
      }
  }
  loopEnd();
}

bool pingSensorBlocked(int sensedObstacleDistInches) {
  return sensedObstacleDistInches < START_SIGNAL_DIST_INCHES;
}

bool pathIsClear(int sensedObstacleDistInches) {
  return sensedObstacleDistInches > OBSTACLE_SAFE_DIST_INCHES;
}

void ledBlink(int pin, int numBlinks) {
  for (int i=0; i<numBlinks; i++) {
    digitalWrite(pin, HIGH);
    delay(100);
    digitalWrite(pin, LOW);
    delay(100);
  }
}

Direction getSafeDirection() {
  int leftDistance = 0;
  int rightDistance = 0;

  turret.aimRight();
  rightDistance = pinger.getObstacleDistanceInches();

  turret.aimLeft();
  leftDistance = pinger.getObstacleDistanceInches();
  
  turret.aimStraight();

  if (leftDistance > rightDistance) {
    if (pathIsClear(leftDistance)) {
      return left;
    }
  } else {
    if (pathIsClear(rightDistance)) {
      return right;
    }
  }

  return none;
}

void loopEnd() {
  delay(100);
}
