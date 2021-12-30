#include <NewPing.h> 
#include <AFMotor.h>
#include <Servo.h>

#define TRIG_PIN A4
#define ECHO_PIN A5
#define OBSTACLE_SAFE_DIST_INCHES 6
#define START_SIGNAL_DIST_INCHES 2
#define SERVO_LEFT 0
#define SERVO_STRAIGHT 90
#define SERVO_RIGHT 180

enum State { initial, startSignalInProgress, readyToDrive, driving, stopped };

NewPing pinger(TRIG_PIN, ECHO_PIN, MAX_SENSOR_DISTANCE);

Servo servo;
AF_DCMotor motor(1);
State state = initial;

void setup() {
  servo.attach(9); // 10, which I believe is the other option, didn't work for some reason
  servo.write(90);
  pinMode(LED_BUILTIN, OUTPUT);

  motor.setSpeed(0);
  motor.run(RELEASE);
  motor.run(FORWARD);
  
  ledBlink(LED_BUILTIN, 3); // Bootup signal
}

void loop() {
  int sensedObstacleDistInches = getObstacleDistanceInches();
  switch (state) {
    case initial:
      if (pingSensorBlocked(sensedObstacleDistInches)) {
        state = startSignalInProgress;
        ledBlink(LED_BUILTIN, 1);
      }
      break;
    case startSignalInProgress:
    case stopped:
      if (pathIsClear(sensedObstacleDistInches)) {
        state = readyToDrive;
      }
      break;
    case readyToDrive:
      if (pathIsClear(sensedObstacleDistInches)) {
        startDriving();
        state = driving;
      }
      break;
    default: // driving
      if (!pathIsClear(sensedObstacleDistInches)) {
        stopDriving();
        lookAround();
        state = stopped;
      }
  }
  loopEnd();
}

bool pingSensorBlocked(int sensedObstacleDistInches) {
  return sensedObstacleDistInches < START_SIGNAL_DIST_INCHES;
}

bool pathIsClear(int sensedObstacleDistInches) {
  return sensedObstacleDistInches > OBSTACLE_SAFE_DIST_INCHES;
}

void driveIfClear(int sensedObstacleDistInches) {
      if (!pathIsClear(sensedObstacleDistInches)) {
        stopDriving();
        ledBlink(LED_BUILTIN, 3);
      } else {
        startDriving();
      }
}

void startDriving() {
  digitalWrite(LED_BUILTIN, HIGH);
  motor.setSpeed(5);
  //motor.run(FORWARD);
  //motor.run(RELEASE);
}

void stopDriving() {
  digitalWrite(LED_BUILTIN, LOW);
  motor.setSpeed(0);
  //motor.run(BRAKE);
}

void ledBlink(int pin, int numBlinks) {
  for (int i=0; i<numBlinks; i++) {
    digitalWrite(pin, HIGH);
    delay(100);
    digitalWrite(pin, LOW);
    delay(100);
  }
}

void lookAround() {
  int servoAngle;
  for (servoAngle = SERVO_STRAIGHT; servoAngle <= SERVO_RIGHT; servoAngle += 1) {
    servo.write(servoAngle);
    delay(15);
  }
  for (servoAngle = SERVO_RIGHT; servoAngle >= SERVO_LEFT; servoAngle -= 1) {
    servo.write(servoAngle);
    delay(15);
  }
  for (servoAngle = SERVO_LEFT; servoAngle <= SERVO_STRAIGHT; servoAngle += 1) {
    servo.write(servoAngle);
    delay(15);
  }
  servo.write(SERVO_STRAIGHT);
}

int getObstacleDistanceInches() {
  delay(60);
  int numReadings = 4;
  int sumOfReadings = 0;
  for (int i=0; i<numReadings; i++) {
    delay(10);
    unsigned int uS = pinger.ping();
    sumOfReadings += uS/US_ROUNDTRIP_IN;
  }
  return sumOfReadings/numReadings;
}

void loopEnd() {
  delay(100);
}
