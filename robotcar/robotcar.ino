#include "Mode.h"
#include "Turret.h"
#include "Drive.h"
#include "Pinger.h"
#include "Controller.h"

Turret* turret;
Drive* drive;
Pinger* pinger;
Controller* controller;

void setup() {
  turret = new Turret(9);
  drive = new Drive();
  pinger = new Pinger(A4, A5);
  controller = new Controller(turret, drive, pinger);
}

void loop() {
  controller->loop();
}
