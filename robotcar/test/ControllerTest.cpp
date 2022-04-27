#include "TurretMock.h"
#include "DriveMock.h"
#include "PingerMock.h"
#include "../robotcar/State.h"
#include "../robotcar/Controller.h"
#include <iostream>
#include <gtest/gtest.h>
using namespace std;


Controller* controller;

TEST(StateChooserTestInitial, BasicAssertions) {
	TurretMock turret;
	DriveMock drive;
	PingerMock pinger(20);
	controller = new Controller(turret, drive, pinger);

	State state = controller->setup();

	EXPECT_EQ(initial, state);
}

TEST(StateChooserTestInitialStill, BasicAssertions) {
	TurretMock turret;
	DriveMock drive;
	PingerMock pinger(20);
	controller = new Controller(turret, drive, pinger);

	State state = controller->loop(initial);

	EXPECT_EQ(initial, state);
}

TEST(StateChooserTestDrivingClear, BasicAssertions) {
	TurretMock turret;
	DriveMock drive;
	PingerMock pinger(20);
	controller = new Controller(turret, drive, pinger);

	State state = controller->loop(driving);

	EXPECT_EQ(driving, state);
}

TEST(StateChooserTestDrivingBlocked, BasicAssertions) {
	TurretMock turret;
	DriveMock drive;
	PingerMock pinger(2);
	controller = new Controller(turret, drive, pinger);

	State state = controller->loop(driving);

	EXPECT_EQ(stopped, state);
}

TEST(StateChooserTestStoppedClear, BasicAssertions) {
	TurretMock turret;
	DriveMock drive;
	PingerMock pinger(20);
	controller = new Controller(turret, drive, pinger);

	State state = controller->loop(stopped);

	EXPECT_EQ(driving, state);
}

TEST(StateChooserTestStoppedBlocked, BasicAssertions) {
	TurretMock turret;
	DriveMock drive;
	PingerMock pinger(2);
	controller = new Controller(turret, drive, pinger);

	State state = controller->loop(stopped);

	EXPECT_EQ(stopped, state);
}
