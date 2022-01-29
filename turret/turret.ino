#include "Turret.h"

Turret* turret;

void setup() {
  turret = new Turret(9);
}

void loop() {
  turret->aimLeft();
  turret->aimRight();
  turret->aimLeft();
  turret->aimStraight();
  delay(60000*5);
}
