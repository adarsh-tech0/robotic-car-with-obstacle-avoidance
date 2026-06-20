#include <Servo.h>

#define trigPin 6            // Define the trig pin of the ultrasonic sensor
#define echoPin 7            // Define the echo pin of the ultrasonic sensor
#define obstacleThreshold 20 // Define the threshold distance for obstacle (cm)
#define backMoveDistance 50  // Define the distance to move backward (cm)

char data = 0;   // Variable for storing received data
Servo myservo;   // Create a servo object

void setup() {
  Serial.begin(9600);          // Sets the baud for serial data transmission

  pinMode(2, OUTPUT);          // Motor control pins
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(trigPin, OUTPUT);    // Sets the trig pin as output
  pinMode(echoPin, INPUT);     // Sets the echo pin as input

  myservo.attach(9);           // Attach servo to pin 9
}

void loop() {
  if (Serial.available() > 0) {        // Send data only when you receive data
    data = Serial.read();              // Read the incoming data and store it
    Serial.print(data);                // Print value inside data in Serial monitor

    if (data == 'F') {
      moveForward();
    } else if (data == 'B') {
      moveBackward();
    } else if (data == 'R') {
      turnRight();
    } else if (data == 'L') {
      turnLeft();
    } else if (data == 'S') {
      stopVehicle();
    } else if (data == 'X') {         // Command to move back short distance
      moveBackShortDistance();
    }
  }

  // Obstacle detection with servo scan
  for (int angle = 0; angle <= 180; angle += 10) {  // Scan every 10 degrees
    myservo.write(angle);                            // Move servo to current angle
    delay(50);                                       // Wait for servo movement

    long duration, distance;

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;

    if (distance < obstacleThreshold) {
      stopVehicle();
      moveBackShortDistance();
      break;                                         // Stop scanning if obstacle found
    }
  }
}

void moveForward() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

void moveBackward() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void turnRight() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void turnLeft() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void stopVehicle() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void moveBackShortDistance() {
  // Move backward for a short distance (backMoveDistance cm)
  moveBackward();
  delay(backMoveDistance * 10);  // Adjust delay based on motor speed
  stopVehicle();
}
