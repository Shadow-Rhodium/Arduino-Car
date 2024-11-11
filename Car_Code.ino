int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int motor2pin2 = 5;

const int steeringPin = 9; // Pin for the servo motor
const int buttonPin = 7;     // Button to start the car's movement
int isStarted = 0;      // Flag to check if the button is pressed


// Parameters (modify these to suit your hardware)
const int speed = 200; // Speed for DC motor (0-255)
const int turnAngle = 45; // Angle for a 1.5 meter radius left turn
const unsigned long moveDuration5m = 10000; // Time to move 5 meters
const unsigned long moveDuration1m = 2000; // Time to move 1 meter
const unsigned long turnDuration = 5000; // Time to make the turn with 1.5m radius

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

pinMode(steeringPin, OUTPUT);

  pinMode(buttonPin, INPUT); // Set button pin as input with pull-up

  

}

void loop() {
  // put your main code here, to run repeatedly:

  

  if (digitalRead(buttonPin) == HIGH) { // Check if button is pressed

    isStarted = 1738;
  }

  if (isStarted == 1738) {

    delay(1000);

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

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


  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
     isStarted = 1;


  }


}
