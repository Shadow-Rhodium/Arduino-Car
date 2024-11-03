#include <Servo.h>

Servo steeringServo;  // Servo for steering
const int motor1Pin = 5; // Pin for the DC motor
const int motor2Pin = 6; // Pin for the DC motor
const int steeringPin = 9; // Pin for the servo motor
const int buttonPin = 7;     // Button to start the car's movement
bool isStarted = false;      // Flag to check if the button is pressed


// Parameters (modify these to suit your hardware)
const int speed = 200; // Speed for DC motor (0-255)
const int turnAngle = 45; // Angle for a 1.5 meter radius left turn
const unsigned long moveDuration5m = 5000; // Time to move 5 meters
const unsigned long moveDuration1m = 1000; // Time to move 1 meter
const unsigned long turnDuration = 2000; // Time to make the turn with 1.5m radius

void setup() {
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with pull-up

}
  
void loop() {
  if (digitalRead(buttonPin) == LOW) { // Check if button is pressed
    delay(50);                         // Debounce delay
    if (digitalRead(buttonPin) == LOW) {
      isStarted = true;
    }
  }

  if (isStarted) {

  analogWrite(motor1Pin, speed); // Move forward
  analogWrite(motor2Pin, speed); // Move forward
  delay(moveDuration5m); // Move 5 meters
  
  // First turn (left, 1.5m radius)
  digitalWrite(steeringPin, HIGH);
  delay(turnDuration); // Time for the left turn
  digitalWrite(steeringPin, LOW); // Straighten the wheels again
  
  // Move forward 1 meter
  delay(moveDuration1m);
  
  // Second turn (left, 1.5m radius)
  digitalWrite(steeringPin, HIGH); // Straighten the wheels again
  delay(turnDuration); // Time for the left turn
  digitalWrite(steeringPin, LOW); // Straighten the wheels again
  
  // Move forward 5 meters
  delay(moveDuration5m);
  
  // Stop the car
  analogWrite(motor1Pin, 0); // Stop the DC motor
  analogWrite(motor2Pin, 0); // Stop the DC motor

}

    
  }
