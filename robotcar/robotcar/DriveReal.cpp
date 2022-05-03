#include "DriveReal.h"
#include <Arduino.h>

AF_DCMotor motorLeft(2);
AF_DCMotor motorRight(1);

DriveReal::DriveReal() {
	motorLeft.setSpeed(0);
	motorLeft.run(RELEASE);
	motorLeft.run(leftWheelForward);
  
	motorRight.setSpeed(0);
	motorRight.run(RELEASE);
	motorRight.run(rightWheelForward);
}

void DriveReal::startForward() {
  motorLeft.run(leftWheelForward);
  motorRight.run(rightWheelForward);
	motorLeft.setSpeed(drivingSpeedLeft);
	motorRight.setSpeed(drivingSpeedRight);
}

void DriveReal::pause() {
	stop();
	delay(500);
}

void DriveReal::stop() {
	motorLeft.setSpeed(0);
	motorRight.setSpeed(0);
}

void DriveReal::turnRight() {
	motorLeft.run(leftWheelForward);
	motorRight.run(rightWheelBackward);
	motorLeft.setSpeed(drivingSpeedLeft);
	motorRight.setSpeed(drivingSpeedRight);
	delay(quarterTurnDuration);
	motorLeft.run(leftWheelForward);
	motorRight.run(rightWheelForward);
	motorLeft.setSpeed(0);
	motorRight.setSpeed(0);
}

void DriveReal::turnLeft() {
	motorLeft.run(leftWheelBackward);
	motorRight.run(rightWheelForward);
	motorLeft.setSpeed(drivingSpeedLeft);
	motorRight.setSpeed(drivingSpeedRight);
	delay(quarterTurnDuration);
	motorLeft.setSpeed(0);
	motorRight.setSpeed(0);
	motorLeft.run(leftWheelForward);
	motorRight.run(rightWheelForward);
}

void DriveReal::turnAround() {
  turnLeft();
  turnLeft();
}

void DriveReal::backUpALittle() {
	motorLeft.run(leftWheelBackward);
	motorRight.run(rightWheelBackward);
	motorLeft.setSpeed(drivingSpeedLeft);
	motorRight.setSpeed(drivingSpeedRight);
	delay(shortDuration);
	motorLeft.setSpeed(0);
	motorRight.setSpeed(0);
	motorLeft.run(leftWheelForward);
	motorRight.run(rightWheelForward);
}
