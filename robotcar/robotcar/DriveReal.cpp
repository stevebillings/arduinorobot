#include "DriveReal.h"
#include <Arduino.h>
#include <AFMotor.h>

#define DRIVING_SPEED_RIGHT 170
#define DRIVING_SPEED_LEFT 150
// Apparently I reversed +/- on the left wheel
#define LEFT_WHEEL_FORWARD BACKWARD
#define LEFT_WHEEL_BACKWARD FORWARD
#define RIGHT_WHEEL_FORWARD FORWARD
#define RIGHT_WHEEL_BACKWARD BACKWARD
#define QUARTER_TURN_DURATION 500
#define SHORT_DURATION 150

AF_DCMotor motorLeft(2);
AF_DCMotor motorRight(1);

DriveReal::DriveReal() {
	motorLeft.setSpeed(0);
	motorLeft.run(RELEASE);
	motorLeft.run(LEFT_WHEEL_FORWARD);
  
	motorRight.setSpeed(0);
	motorRight.run(RELEASE);
	motorRight.run(RIGHT_WHEEL_FORWARD);
}

void DriveReal::startForward() {
  motorLeft.run(LEFT_WHEEL_FORWARD);
  motorRight.run(RIGHT_WHEEL_FORWARD);
	motorLeft.setSpeed(DRIVING_SPEED_LEFT);
	motorRight.setSpeed(DRIVING_SPEED_RIGHT);
}

void DriveReal::stop() {
	motorLeft.setSpeed(0);
	motorRight.setSpeed(0);
}

void DriveReal::turnRight() {
	motorLeft.run(LEFT_WHEEL_FORWARD);
	motorRight.run(RIGHT_WHEEL_BACKWARD);
	motorLeft.setSpeed(DRIVING_SPEED_LEFT);
	motorRight.setSpeed(DRIVING_SPEED_RIGHT);
	delay(QUARTER_TURN_DURATION);
	motorLeft.run(LEFT_WHEEL_FORWARD);
	motorRight.run(RIGHT_WHEEL_FORWARD);
	motorLeft.setSpeed(0);
	motorRight.setSpeed(0);
}

void DriveReal::turnLeft() {
	motorLeft.run(LEFT_WHEEL_BACKWARD);
	motorRight.run(RIGHT_WHEEL_FORWARD);
	motorLeft.setSpeed(DRIVING_SPEED_LEFT);
	motorRight.setSpeed(DRIVING_SPEED_RIGHT);
	delay(QUARTER_TURN_DURATION);
	motorLeft.setSpeed(0);
	motorRight.setSpeed(0);
	motorLeft.run(LEFT_WHEEL_FORWARD);
	motorRight.run(RIGHT_WHEEL_FORWARD);
}

void DriveReal::turnAround() {
  turnLeft();
  turnLeft();
}

void DriveReal::backUpALittle() {
	motorLeft.run(LEFT_WHEEL_BACKWARD);
	motorRight.run(RIGHT_WHEEL_BACKWARD);
	motorLeft.setSpeed(DRIVING_SPEED_LEFT);
	motorRight.setSpeed(DRIVING_SPEED_RIGHT);
	delay(SHORT_DURATION);
	motorLeft.setSpeed(0);
	motorRight.setSpeed(0);
	motorLeft.run(LEFT_WHEEL_FORWARD);
	motorRight.run(RIGHT_WHEEL_FORWARD);
}
