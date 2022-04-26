#include "PingerMock.h"
#include <iostream>
using namespace std;

void f(Pinger& pinger) {
	printf("f() was passed something\n");
}

int main() {
	printf("Hi\n");
	PingerMock pinger(99);
	int dist = pinger.getObstacleDistanceInches();
	printf("PingerMock returned distance of %d inches\n", dist);

	f(pinger);
}
