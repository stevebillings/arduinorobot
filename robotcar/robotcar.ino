#include "Mode.h"
#include "TurretReal.h"
#include "DriveReal.h"
#include "Pinger.h"
#include "PingerReal.h"
#include "State.h"
#include "Controller.h"

Turret* turret;
Drive* drive;
Pinger* pinger;
Controller* controller;
State currentState = initial;

void setup() {
  turret = new TurretReal(9);
  drive = new DriveReal();
  pinger = new PingerReal(A4, A5);
  controller = new Controller(turret, drive, pinger);

  currentState = controller->setup();
}

void loop() {
  currentState = controller->loop(currentState);
  delay(250);
}
