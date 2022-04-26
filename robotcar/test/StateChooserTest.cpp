#include "../robotcar/State.h"
#include "../robotcar/StateChooser.h"
#include "../robotcar/StateNamer.h"
#include <iostream>
#include <gtest/gtest.h>
using namespace std;

StateChooser *stateChooser;
StateNamer *stateNamer;

//EXPECT_STRNE("hello", "world");
//EXPECT_EQ(7 * 6, 42);
//EXPECT_STREQ("hello", "hello");

TEST(StateChooserTestInitial, BasicAssertions) {
	stateChooser = new StateChooser();
	stateNamer = new StateNamer();

	State newState = stateChooser->choose(initial, 10);

	EXPECT_EQ(initial, newState);
}

TEST(StateChooserTestStartSignalInitiated, BasicAssertions) {
	stateChooser = new StateChooser();
	stateNamer = new StateNamer();

	State newState = stateChooser->choose(initial, 2);

	EXPECT_EQ(startSignalInProgress, newState);
}

TEST(StateChooserTestStartSignalCompleted, BasicAssertions) {
	stateChooser = new StateChooser();
	stateNamer = new StateNamer();

	State newState = stateChooser->choose(startSignalInProgress, 20);

	EXPECT_EQ(readyToDrive, newState);
}

TEST(StateChooserTestContinue, BasicAssertions) {
	stateChooser = new StateChooser();
	stateNamer = new StateNamer();

	State newState = stateChooser->choose(driving, 30);

	EXPECT_EQ(driving, newState);
}

TEST(StateChooserTestStop, BasicAssertions) {
	stateChooser = new StateChooser();
	stateNamer = new StateNamer();

	State newState = stateChooser->choose(driving, 5);

	EXPECT_EQ(needToStop, newState);
}

TEST(StateChooserTestTurnLeft, BasicAssertions) {
	stateChooser = new StateChooser();
	stateNamer = new StateNamer();

	State newState = stateChooser->choose(stopped, 5, 30, 5);

	EXPECT_EQ(stoppedNeedToTurnLeft, newState);
}

TEST(StateChooserTestTurnRight, BasicAssertions) {
	stateChooser = new StateChooser();
	stateNamer = new StateNamer();

	State newState = stateChooser->choose(stopped, 5, 5, 30);

	EXPECT_EQ(stoppedNeedToTurnRight, newState);
}

TEST(StateChooserTestTurnAround, BasicAssertions) {
	stateChooser = new StateChooser();
	stateNamer = new StateNamer();

	State newState = stateChooser->choose(stopped, 5, 5, 5);

	EXPECT_EQ(stoppedNeedToTurnAround, newState);
}
