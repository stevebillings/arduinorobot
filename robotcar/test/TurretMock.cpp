#include <iostream>
#include "TurretMock.h"
using namespace std;

void TurretMock::aimRight() const {
	printf("TurretMock::aimRight() called\n");
}
void TurretMock::aimLeft() const {
	printf("TurretMock::aimLeft() called\n");
}
void TurretMock::aimStraight() const {
	printf("TurretMock::aimStraight() called\n");
}
