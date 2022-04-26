#include "DriveMock.h"
#include <iostream>
using namespace std;

DriveMock::DriveMock() {
	printf("DriveMock object constructed\n");
}

void DriveMock::startForward() {
	printf("DriveMock: starting forward...\n");
}

void DriveMock::stop() {
	printf("DriveMock: stopping\n");
}

void DriveMock::turnRight() {
	printf("DriveMock: turning right\n");
}

void DriveMock::turnLeft() {
	printf("DriveMock: turning left\n");
}

void DriveMock::turnAround() {
	printf("DriveMock: turning around\n");
}

void DriveMock::backUpALittle() {
	printf("DriveMock: backing up a little\n");
}
