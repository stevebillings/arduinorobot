#include "TurretMock.h"
#include "DriveMock.h"
#include "PingerMock.h"
#include "../robotcar/State.h"
#include "../robotcar/Controller.h"
#include <iostream>
#include <gtest/gtest.h>
using namespace std;


Turret* turret;
Controller* controller;

TEST(StateChooserTestInitial, BasicAssertions) {
	turret = new TurretMock();
	DriveMock drive;
	PingerMock pinger(20);
	controller = new Controller(turret, drive, pinger);

	State state = controller->setup();

	EXPECT_EQ(initial, state);
}

TEST(StateChooserTestInitialStill, BasicAssertions) {
	turret = new TurretMock();
	DriveMock drive;
	PingerMock pinger(20);
	controller = new Controller(turret, drive, pinger);

	State state = controller->loop(initial);

	EXPECT_EQ(initial, state);
}

TEST(StateChooserTestDrivingClear, BasicAssertions) {
	turret = new TurretMock();
	DriveMock drive;
	PingerMock pinger(20);
	controller = new Controller(turret, drive, pinger);

	State state = controller->loop(driving);

	EXPECT_EQ(driving, state);
}

TEST(StateChooserTestDrivingBlocked, BasicAssertions) {
	turret = new TurretMock();
	DriveMock drive;
	PingerMock pinger(2);
	controller = new Controller(turret, drive, pinger);

	State state = controller->loop(driving);

	EXPECT_EQ(stopped, state);
}

TEST(StateChooserTestStoppedClear, BasicAssertions) {
	turret = new TurretMock();
	DriveMock drive;
	PingerMock pinger(20);
	controller = new Controller(turret, drive, pinger);

	State state = controller->loop(stopped);

	EXPECT_EQ(driving, state);
}

TEST(StateChooserTestStoppedBlocked, BasicAssertions) {
	turret = new TurretMock();
	DriveMock drive;
	PingerMock pinger(2);
	controller = new Controller(turret, drive, pinger);

	State state = controller->loop(stopped);

	EXPECT_EQ(stopped, state);
}
