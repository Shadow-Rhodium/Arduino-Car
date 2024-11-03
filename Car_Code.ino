#include <Servo.h>

Servo steeringServo;  // Servo for steering
const int motorPin = 5; // Pin for the DC motor
const int steeringPin = 9; // Pin for the servo motor

// Parameters (modify these to suit your hardware)
const int speed = 200; // Speed for DC motor (0-255)
const int turnAngle = 45; // Angle for a 1.5 meter radius left turn
const unsigned long moveDuration5m = 5000; // Time to move 5 meters
const unsigned long moveDuration1m = 1000; // Time to move 1 meter
const unsigned long turnDuration = 2000; // Time to make the turn with 1.5m radius

void setup() {
  pinMode(motorPin, OUTPUT);
  steeringServo.attach(steeringPin);
  
  // Start by moving straight
  steeringServo.write(90); // 90 degrees for straight steering
  analogWrite(motorPin, speed); // Move forward
  delay(moveDuration5m); // Move 5 meters
  
  // First turn (left, 1.5m radius)
  steeringServo.write(90 - turnAngle); // Turn left
  delay(turnDuration); // Time for the left turn
  steeringServo.write(90); // Straighten the wheels again
  
  // Move forward 1 meter
  delay(moveDuration1m);
  
  // Second turn (left, 1.5m radius)
  steeringServo.write(90 - turnAngle); // Turn left
  delay(turnDuration); // Time for the left turn
  steeringServo.write(90); // Straighten the wheels again
  
  // Move forward 5 meters
  delay(moveDuration5m);
  
  // Stop the car
  analogWrite(motorPin, 0); // Stop the DC motor
}

void loop() {
  // No repeated actions needed
}
