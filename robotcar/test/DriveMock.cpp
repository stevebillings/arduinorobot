#include "DriveMock.h"
#include <iostream>
using namespace std;

DriveMock::DriveMock() {
	printf("DriveMock object constructed\n");
}

void DriveMock::startForward() const {
	printf("DriveMock: starting forward...\n");
}

void DriveMock::pause() const {
	printf("DriveMock: pausing\n");
}

void DriveMock::stop() const {
	printf("DriveMock: stopping\n");
}

void DriveMock::turnRight() const {
	printf("DriveMock: turning right\n");
}

void DriveMock::turnLeft() const {
	printf("DriveMock: turning left\n");
}

void DriveMock::turnAround() const {
	printf("DriveMock: turning around\n");
}

void DriveMock::backUpALittle() const {
	printf("DriveMock: backing up a little\n");
}
