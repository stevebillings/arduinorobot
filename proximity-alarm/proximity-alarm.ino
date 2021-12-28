#include <NewPing.h> 

#define PROXIMITY_LED_PIN 12
#define DRIVING_LED_PIN 11
#define TRIG_PIN A4
#define ECHO_PIN A5
#define OBSTACLE_SAFE_DIST_INCHES 6
#define START_SIGNAL_DIST_INCHES 2

enum State { initial, startSignalInProgress, driving, stopped };

NewPing pinger(TRIG_PIN, ECHO_PIN, MAX_SENSOR_DISTANCE);

State state = initial;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PROXIMITY_LED_PIN, OUTPUT);
  pinMode(DRIVING_LED_PIN, OUTPUT);
  ledBlink(DRIVING_LED_PIN, 3); // Bootup signal
}

void loop() {
  int sensedObstacleDistInches = getObstacleDistanceInches();
  alertIfObstacle(sensedObstacleDistInches);
  switch (state) {
    case initial:
      if (pingSensorBlocked(sensedObstacleDistInches)) {
        state = startSignalInProgress;
        ledBlink(DRIVING_LED_PIN, 1);
      }
      break;
    case startSignalInProgress:
    case stopped:
      if (pathIsClear(sensedObstacleDistInches)) {
        state = driving;
        startDriving();
      }
      break;
    default: // driving
      if (!pathIsClear(sensedObstacleDistInches)) {
        state = stopped;
        stopDriving();
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

void alertIfObstacle(int sensedObstacleDistInches) {
      if (!pathIsClear(sensedObstacleDistInches)) {
        proximityLedOn();
      } else {
        proximityLedOff();
      }
}

void startDriving() {
  digitalWrite(DRIVING_LED_PIN, HIGH);
}

void stopDriving() {
  digitalWrite(DRIVING_LED_PIN, LOW);
}

void proximityLedOn() {
  digitalWrite(PROXIMITY_LED_PIN, HIGH);
}

void proximityLedOff() {
  digitalWrite(PROXIMITY_LED_PIN, LOW);
}

void ledBlink(int pin, int numBlinks) {
  for (int i=0; i<numBlinks; i++) {
    digitalWrite(pin, HIGH);
    delay(100);
    digitalWrite(pin, LOW);
    delay(100);
  }
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
