#include <AFMotor.h>
#include <Servo.h>
#include "Drive.h"
#include "Pinger.h"

#define OBSTACLE_SAFE_DIST_INCHES 20
#define START_SIGNAL_DIST_INCHES 2
#define SERVO_LEFT 0
#define SERVO_STRAIGHT 90
#define SERVO_RIGHT 180

enum State {initial, startSignalInProgress, readyToDrive, driving, stopped};
enum Direction {left, straight, right, none};

Drive drive;
Pinger pinger(A4, A5);
Servo servo;
State state = initial;

void setup() {
  servo.attach(9); // 10, which I believe is the other option, didn't work for some reason
  servo.write(90);
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
        drive.forward();
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

void driveIfClear(int sensedObstacleDistInches) {
      if (!pathIsClear(sensedObstacleDistInches)) {
        drive.stop();
        ledBlink(LED_BUILTIN, 3);
      } else {
        drive.forward();
      }
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
  int servoAngle;
  int leftDistance = 0;
  int rightDistance = 0;

  servo.write(SERVO_RIGHT);
  delay(500);
  rightDistance = pinger.getObstacleDistanceInches();

  servo.write(SERVO_LEFT);
  delay(1000);
  leftDistance = pinger.getObstacleDistanceInches();
  
  servo.write(SERVO_STRAIGHT);

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
