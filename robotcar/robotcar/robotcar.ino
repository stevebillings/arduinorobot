#include "TurretReal.h"
#include "DriveReal.h"
#include "PingerReal.h"
#include "State.h"
#include "Controller.h"

Turret* turret;
DriveReal drive;
PingerReal pinger(A4, A5);
Controller* controller;
State currentState = initial;

void setup() {
  turret = new TurretReal(9);
  controller = new Controller(turret, drive, pinger);

  currentState = controller->setup();
}

void loop() {
  currentState = controller->loop(currentState);
  delay(250);
}
