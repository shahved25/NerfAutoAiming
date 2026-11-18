/* This sketch shows how we plan to test the motor controls using the Arduino Serial Monitor. Type a command and press Send to change the simulated pan 
and tilt angles or toggle the two other motor states. The current settings are example values because we haven't tested the hardware yet. For now,
the sketch only prints the results and doesn't move any physical motors.
*/

int panAngle = 90;    // Left and right
int tiltAngle = 90;   // Up and down
int stepSize = 5;     // Change the angle by 5 degrees per command
int minimumAngle = 45;
int maximumAngle = 135;

bool motorOn = false;
bool auxiliaryServoOn = false;

void setup() {
  Serial.begin(9600);

  Serial.println("Simulation: no motors are connected.");
  Serial.println("W/S: tilt, A/D: pan, C: center");
  Serial.println("1: toggle motor, 2: toggle auxiliary servo");
}

void loop() {
  // Read one character whenever the Serial Monitor sends a command.
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == 'w' || command == 'W') {
      moveTilt(stepSize);
    } else if (command == 's' || command == 'S') {
      moveTilt(-stepSize);
    } else if (command == 'a' || command == 'A') {
      movePan(-stepSize);
    } else if (command == 'd' || command == 'D') {
      movePan(stepSize);
    } else if (command == 'c' || command == 'C') {
      // Return both simulated axes to their example center positions.
      panAngle = 90;
      tiltAngle = 90;
    } else if (command == '1') {
      toggleMotor();
    } else if (command == '2') {
      toggleAuxiliaryServo();
    } else {
      // Ignore line endings and other characters.
      return;
    }

    // Show the updated positions and motor states after each command.
    Serial.print("Pan: ");
    Serial.print(panAngle);
    Serial.print(" degrees | Tilt: ");
    Serial.print(tiltAngle);
    Serial.print(" degrees | Mock motor: ");
    Serial.print(motorOn ? "ON" : "OFF");
    Serial.print(" | Mock auxiliary servo: ");
    Serial.println(auxiliaryServoOn ? "ACTIVE" : "IDLE");
  }
}

// These functions change simulated values; they don't move real motors.
void movePan(int change) {
  // Keep the example position within the chosen range.
  panAngle = constrain(panAngle + change, minimumAngle, maximumAngle);
}

void moveTilt(int change) {
  tiltAngle = constrain(tiltAngle + change, minimumAngle, maximumAngle);
}

void toggleMotor() {
  motorOn = !motorOn;
}

void toggleAuxiliaryServo() {
  auxiliaryServoOn = !auxiliaryServoOn;
}