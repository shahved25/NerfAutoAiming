#include <Servo.h>

// Each servo needs its own signal wire on the camera mount.
const int PAN_PIN = 9;
const int TILT_PIN = 10;
const int ROLL_PIN = 8;

const int CENTER_ANGLE = 90;
const int MIN_ANGLE = 75;
const int MAX_ANGLE = 105;
const int STEP_DEGREES = 2;

Servo panServo;
Servo tiltServo;
Servo rollServo;

int panAngle = CENTER_ANGLE;
int tiltAngle = CENTER_ANGLE;
int rollAngle = CENTER_ANGLE;

void setPan(int angle) {
  panAngle = constrain(angle, MIN_ANGLE, MAX_ANGLE);
  panServo.write(panAngle);
}

void setTilt(int angle) {
  tiltAngle = constrain(angle, MIN_ANGLE, MAX_ANGLE);
  tiltServo.write(tiltAngle);
}

void setRoll(int angle) {
  rollAngle = constrain(angle, MIN_ANGLE, MAX_ANGLE);
  rollServo.write(rollAngle);
}

void setup() {
  Serial.begin(9600);

  panServo.attach(PAN_PIN);
  tiltServo.attach(TILT_PIN);
  rollServo.attach(ROLL_PIN);

  setPan(CENTER_ANGLE);
  setTilt(CENTER_ANGLE);
  setRoll(CENTER_ANGLE);
}

void loop() {
  if (Serial.available() == 0) {
    return;
  }

  // Send a key in the Arduino Serial Monitor at 9600 baud.
  switch (Serial.read()) {
    case 'a': setPan(panAngle - STEP_DEGREES); break;
    case 'd': setPan(panAngle + STEP_DEGREES); break;
    case 'w': setTilt(tiltAngle - STEP_DEGREES); break;
    case 's': setTilt(tiltAngle + STEP_DEGREES); break;
    case 'q': setRoll(rollAngle - STEP_DEGREES); break;
    case 'e': setRoll(rollAngle + STEP_DEGREES); break;
  }
}
