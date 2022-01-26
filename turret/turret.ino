#include "Turret.h"

Turret turret(9);
int i;

void setup() {
    i = 0;
}

void loop() {
  if (i < 2) {
    turret.aimLeft();
    turret.aimRight();
    turret.aimStraight();
  }
  i++;
  delay(1000);
}
