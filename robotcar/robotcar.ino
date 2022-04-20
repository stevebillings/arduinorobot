#include "Mode.h"
#include "Turret.h"
#include "Drive.h"
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
  turret = new Turret(9);
  drive = new Drive();
  pinger = new PingerReal(A4, A5);
  controller = new Controller(turret, drive, pinger);

  currentState = controller->setup();
}

void loop() {
  currentState = controller->loop(currentState);
  delay(250);
}
