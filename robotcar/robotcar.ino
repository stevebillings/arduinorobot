#include "Controller.h"

Controller* controller;

void setup() {
  controller = new Controller();
}

void loop() {
  controller->loop();
}
