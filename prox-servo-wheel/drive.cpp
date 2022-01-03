#include "drive.h"
#include <Arduino.h>
#include <AFMotor.h>


AF_DCMotor motorLeft(1);
AF_DCMotor motorRight(2);

Drive::Drive() {
	motorLeft.setSpeed(0);
	motorLeft.run(RELEASE);
	motorLeft.run(LEFT_WHEEL_FORWARD);
  
	motorRight.setSpeed(0);
	motorRight.run(RELEASE);
	motorRight.run(RIGHT_WHEEL_FORWARD);
}

void Drive::startForward() {
	motorLeft.setSpeed(DRIVING_SPEED);
	motorRight.setSpeed(DRIVING_SPEED);
}

void Drive::stop() {
	motorLeft.setSpeed(0);
	motorRight.setSpeed(0);
}

void Drive::turnRight() {
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

void Drive::turnLeft() {
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
