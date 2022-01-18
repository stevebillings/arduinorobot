#include <Servo.h> 

#define SHORT_DELAY 25
#define RIGHT_MAX 6
#define LEFT_MAX 180
#define LEFT_TO_RIGHT_DELTA -1
#define RIGHT_TO_LEFT_DELTA 1
#define STRAIGHT 96

Servo servo1;
int currentAngle = STRAIGHT;

void setup() {
  servo1.attach(9);
  delay(1000);
}

void loop() {
  lookLeft();
  lookRight();
  lookStraight();
  delay(30000);
}

void lookRight() {
  toAngle(RIGHT_MAX);
}

void lookLeft() {
  toAngle(LEFT_MAX);
}

void lookStraight() {
  toAngle(STRAIGHT);
}

///////////////////////////

void toAngle(int targetAngle) {
  if (currentAngle > targetAngle) {
    lookRight(targetAngle);
  } else if (currentAngle < targetAngle) {
    lookLeft(targetAngle);
  }
}

void lookRight(int targetAngle) {
    for (; currentAngle >= targetAngle; currentAngle += LEFT_TO_RIGHT_DELTA) {
      servo1.write(currentAngle);
      delay(SHORT_DELAY);
  }
}

void lookLeft(int targetAngle) {
  for (; currentAngle <= targetAngle; currentAngle += RIGHT_TO_LEFT_DELTA) {
    servo1.write(currentAngle);
    delay(SHORT_DELAY);
  }
}