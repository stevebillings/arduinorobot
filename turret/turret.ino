#include "Turret.h"

#include <Servo.h>
Servo* servo;
Turret* turret;

void setup() {
  servo = new Servo();
  turret = new Turret(servo, 9);
}

void loop() {
  turret->aimLeft();
  turret->aimRight();
  turret->aimLeft();
  turret->aimStraight();
  delay(60000);
}
