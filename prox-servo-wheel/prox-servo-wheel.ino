#include <NewPing.h> 
#include <AFMotor.h>
#include <Servo.h>
#include "drive.h"

#define TRIG_PIN A4
#define ECHO_PIN A5
#define OBSTACLE_SAFE_DIST_INCHES 20
#define START_SIGNAL_DIST_INCHES 2
#define SERVO_LEFT 0
#define SERVO_STRAIGHT 90
#define SERVO_RIGHT 180

enum State {initial, startSignalInProgress, readyToDrive, driving, stopped};
enum Direction {left, straight, right, none};

NewPing pinger(TRIG_PIN, ECHO_PIN, MAX_SENSOR_DISTANCE);

Drive drive;
Servo servo;
State state = initial;

void setup() {
  servo.attach(9); // 10, which I believe is the other option, didn't work for some reason
  servo.write(90);
  pinMode(LED_BUILTIN, OUTPUT);
  drive.init();
  ledBlink(LED_BUILTIN, 3); // Bootup signal
}

void loop() {
  int sensedObstacleDistInches = getObstacleDistanceInches();
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
  rightDistance = getObstacleDistanceInches();

  servo.write(SERVO_LEFT);
  delay(1000);
  leftDistance = getObstacleDistanceInches();
  
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

int getObstacleDistanceInches() {
  delay(60);
  int numReadings = 4;
  int sumOfReadings = 0;
  for (int i=0; i<numReadings; i++) {
    delay(10);
    unsigned int uS = pinger.ping();
    sumOfReadings += uS/US_ROUNDTRIP_IN;
  }
  return sumOfReadings/numReadings;
}

void loopEnd() {
  delay(100);
}
