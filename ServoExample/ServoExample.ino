// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>
#include <Servo.h> 

#define CORRECTION 15
#define STRAIGHT 90+CORRECTION
#define LEFT 180
#define RIGHT 0+CORRECTION

Servo servo1;

void setup() {
  servo1.attach(9);
}

int i;

// Test the DC motor, stepper and servo ALL AT ONCE!
void loop() {
  for (i=STRAIGHT; i<LEFT; i++) {
    servo1.write(i);
    delay(30);
 }
 
  for (i=LEFT; i!=RIGHT; i--) {
    servo1.write(i);
    delay(30);
 }
 
  for (i=RIGHT; i<STRAIGHT; i++) {
    servo1.write(i);
    delay(30);
 }
 delay(500000);
}
