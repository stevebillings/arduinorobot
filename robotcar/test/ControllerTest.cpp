#include "TurretMock.h"
#include "DriveMock.h"
#include "PingerMock.h"
#include "../robotcar/State.h"
#include "../robotcar/Controller.h"
#include <iostream>
#include <gtest/gtest.h>
using namespace std;


Controller* controller;

TEST(ControllerTestInitial, BasicAssertions) {
	TurretMock turret;
	DriveMock drive;
	PingerMock pinger(20);
	controller = new Controller(turret, drive, pinger);

	State state = controller->setup();

	EXPECT_EQ(initial, state);
}

TEST(ControllerTestInitialStill, BasicAssertions) {
	TurretMock turret;
	DriveMock drive;
	PingerMock pinger(20);
	controller = new Controller(turret, drive, pinger);

	State state = controller->loop(initial);

	EXPECT_EQ(initial, state);
}

TEST(ControllerTestDrivingClear, BasicAssertions) {
	TurretMock turret;
	DriveMock drive;
	PingerMock pinger(20);
	controller = new Controller(turret, drive, pinger);

	State state = controller->loop(driving);

	EXPECT_EQ(driving, state);
}

TEST(ControllerTestDrivingBlocked, BasicAssertions) {
	TurretMock turret;
	DriveMock drive;
	PingerMock pinger(2);
	controller = new Controller(turret, drive, pinger);

	State state = controller->loop(driving);

	EXPECT_EQ(paused, state);
}

TEST(ControllerTestPausedBlocked, BasicAssertions) {
	TurretMock turret;
	DriveMock drive;
	PingerMock pinger(2);
	controller = new Controller(turret, drive, pinger);

	State state = controller->loop(paused);

	EXPECT_EQ(stopped, state);
}

TEST(ControllerTestStoppedClear, BasicAssertions) {
	TurretMock turret;
	DriveMock drive;
	PingerMock pinger(20);
	controller = new Controller(turret, drive, pinger);

	State state = controller->loop(stopped);

	EXPECT_EQ(driving, state);
}

TEST(ControllerTestStoppedBlocked, BasicAssertions) {
	TurretMock turret;
	DriveMock drive;
	PingerMock pinger(2);
	controller = new Controller(turret, drive, pinger);

	State state = controller->loop(stopped);

	EXPECT_EQ(stopped, state);
}
