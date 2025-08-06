// IR Sensor Pins
#define LEFT_SENSOR 2
#define RIGHT_SENSOR 3

// Left Motors
#define IN1 4
#define IN2 5
#define ENA 9

// Right Motors
#define IN3 6
#define IN4 7
#define ENB 10

void setup() {
  // IR Sensors
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);

  // Motor Pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}

// Motor control functions
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 150); // Speed can be adjusted

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 150);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 150);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 150);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}

void stopBot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void loop() {
  int leftSensor = digitalRead(LEFT_SENSOR);
  int rightSensor = digitalRead(RIGHT_SENSOR);

  if (leftSensor == LOW && rightSensor == LOW) {
    // Both on black line
    moveForward();
  } else if (leftSensor == LOW && rightSensor == HIGH) {
    // Right on white, turn right
    turnRight();
  } else if (leftSensor == HIGH && rightSensor == LOW) {
    // Left on white, turn left
    turnLeft();
  } else {
    // Both on white, stop
    stopBot();
  }
}

