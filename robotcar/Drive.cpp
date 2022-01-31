#include "Mode.h"
#include "Drive.h"
#ifdef FAKE
#include <iostream>
using namespace std;
#else
#include <Arduino.h>
#include <AFMotor.h>
#endif

#define DRIVING_SPEED_RIGHT 108
#define DRIVING_SPEED_LEFT 100
// Apparently I reversed +/- on the left wheel
#define LEFT_WHEEL_FORWARD BACKWARD
#define LEFT_WHEEL_BACKWARD FORWARD
#define RIGHT_WHEEL_FORWARD FORWARD
#define RIGHT_WHEEL_BACKWARD BACKWARD
#define QUARTER_TURN_DURATION 800

#ifndef FAKE
AF_DCMotor motorLeft(2);
AF_DCMotor motorRight(1);
#endif

Drive::Drive() {
#ifdef FAKE
	printf("Drive object constructed\n");
#else
	motorLeft.setSpeed(0);
	motorLeft.run(RELEASE);
	motorLeft.run(LEFT_WHEEL_FORWARD);
  
	motorRight.setSpeed(0);
	motorRight.run(RELEASE);
	motorRight.run(RIGHT_WHEEL_FORWARD);
#endif
}

void Drive::startForward() {
#ifdef FAKE
	printf("Drive: starting forward...\n");
#else
  motorLeft.run(LEFT_WHEEL_FORWARD);
  motorRight.run(RIGHT_WHEEL_FORWARD);
	motorLeft.setSpeed(DRIVING_SPEED_LEFT);
	motorRight.setSpeed(DRIVING_SPEED_RIGHT);
#endif
}

void Drive::stop() {
#ifdef FAKE
	printf("Drive: stopping\n");
#else
	motorLeft.setSpeed(0);
	motorRight.setSpeed(0);
#endif
}

void Drive::turnRight() {
#ifdef FAKE
	printf("Drive: turning right\n");
#else
	motorLeft.run(LEFT_WHEEL_FORWARD);
	motorRight.run(RIGHT_WHEEL_BACKWARD);
	motorLeft.setSpeed(DRIVING_SPEED_LEFT);
	motorRight.setSpeed(DRIVING_SPEED_RIGHT);
	delay(QUARTER_TURN_DURATION);
	motorLeft.run(LEFT_WHEEL_FORWARD);
	motorRight.run(RIGHT_WHEEL_FORWARD);
	motorLeft.setSpeed(0);
	motorRight.setSpeed(0);
#endif
}

void Drive::turnLeft() {
#ifdef FAKE
	printf("Drive: turning left\n");
#else
	motorLeft.run(LEFT_WHEEL_BACKWARD);
	motorRight.run(RIGHT_WHEEL_FORWARD);
	motorLeft.setSpeed(DRIVING_SPEED_LEFT);
	motorRight.setSpeed(DRIVING_SPEED_RIGHT);
	delay(QUARTER_TURN_DURATION);
  motorLeft.setSpeed(0);
  motorRight.setSpeed(0);
	motorLeft.run(LEFT_WHEEL_FORWARD);
	motorRight.run(RIGHT_WHEEL_FORWARD);
#endif
}

void Drive::turnAround() {
  turnLeft();
  turnLeft();
}
