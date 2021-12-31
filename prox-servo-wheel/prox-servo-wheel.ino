#include <NewPing.h> 
#include <AFMotor.h>
#include <Servo.h>

#define TRIG_PIN A4
#define ECHO_PIN A5
#define OBSTACLE_SAFE_DIST_INCHES 20
#define START_SIGNAL_DIST_INCHES 2
#define SERVO_LEFT 0
#define SERVO_STRAIGHT 90
#define SERVO_RIGHT 180

// Wheel DC motors
#define DRIVING_SPEED 100
#define LEFT_WHEEL_FORWARD FORWARD
#define RIGHT_WHEEL_FORWARD BACKWARD
#define LEFT_WHEEL_BACKWARD BACKWARD
#define RIGHT_WHEEL_BACKWARD FORWARD


enum State {initial, startSignalInProgress, readyToDrive, driving, stopped};
enum Direction {left, straight, right, none};

NewPing pinger(TRIG_PIN, ECHO_PIN, MAX_SENSOR_DISTANCE);

Servo servo;
AF_DCMotor motorLeft(1);
AF_DCMotor motorRight(2);
State state = initial;

void setup() {
  servo.attach(9); // 10, which I believe is the other option, didn't work for some reason
  servo.write(90);
  pinMode(LED_BUILTIN, OUTPUT);

  motorLeft.setSpeed(0);
  motorLeft.run(RELEASE);
  motorLeft.run(LEFT_WHEEL_FORWARD);
  
  motorRight.setSpeed(0);
  motorRight.run(RELEASE);
  motorRight.run(RIGHT_WHEEL_FORWARD);
  
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
        startDriving();
        state = driving;
      }
      break;
    default: // driving
      if (!pathIsClear(sensedObstacleDistInches)) {
        stopDriving();
        state = stopped;
        Direction safeDirection = getSafeDirection();
        if (safeDirection == left) {
          turnLeft();
        } else if (safeDirection == right) {
          turnRight();
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
        stopDriving();
        ledBlink(LED_BUILTIN, 3);
      } else {
        startDriving();
      }
}

void startDriving() {
  digitalWrite(LED_BUILTIN, HIGH);
  motorLeft.setSpeed(DRIVING_SPEED);
  motorRight.setSpeed(DRIVING_SPEED);
}

void stopDriving() {
  digitalWrite(LED_BUILTIN, LOW);
  motorLeft.setSpeed(0);
  motorRight.setSpeed(0);
}

void turnRight() {
  motorLeft.run(LEFT_WHEEL_FORWARD);
  motorRight.run(RIGHT_WHEEL_BACKWARD);
  motorLeft.setSpeed(100);
  motorRight.setSpeed(100);
  delay(500);
  motorLeft.run(LEFT_WHEEL_FORWARD);
  motorRight.run(RIGHT_WHEEL_FORWARD);
  motorLeft.setSpeed(0);
  motorRight.setSpeed(0);
}

void turnLeft() {
  motorLeft.run(LEFT_WHEEL_BACKWARD);
  motorRight.run(RIGHT_WHEEL_FORWARD);
  motorLeft.setSpeed(100);
  motorRight.setSpeed(100);
  delay(500);
  motorLeft.run(LEFT_WHEEL_FORWARD);
  motorRight.run(RIGHT_WHEEL_FORWARD);
  motorLeft.setSpeed(0);
  motorRight.setSpeed(0);
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
