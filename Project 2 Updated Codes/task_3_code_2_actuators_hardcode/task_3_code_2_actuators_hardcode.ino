// Code by Abhishek M

// define the two IR sensor inputs pins


//using the L298N, define the MOTOR in1 and in2 of the board
int ENA = 10;
int motor1pin1 = 9;
int motor1pin2 = 8;
int motor2pin1 = 7;
int motor2pin2 = 6;
int ENB = 5;

int echo1 = 2;
int trig1 = 3;
int echo2 = 11;
int trig2 = 12;

int Loop1 = 1;
int max_distance = 15;
int counter = 0;
int count_max = 48; //changes length traveled, one count is 0.25L

long duration1, duration2;
int distance1, distance2;

int max_speed = 150;
int delay_time = 1385; //delay time for turn functions
int turn_delay = 200; //time between obstacle evasion movements

void setup() {
  Serial.begin(9600);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

  delay(8000);
}


void loop() {
  analogWrite(ENA, max_speed); //Controlling speed (0 = off and 255 = max speed)
  analogWrite(ENB, max_speed); //Controlling speed (0 = off and 255 = max speed)

  ultrasonic();
  if (distance1 > max_distance) {
    forward_count();

    if (counter == count_max) {
      FINISH();
      exit(0);
    }
  }
  else {

    FINISH();
    delay(turn_delay);

    right_turn_90();
    FINISH();
    delay(turn_delay);

    forward();
    delay(1000);
    FINISH();
    delay(turn_delay);

    left_turn_90();
    FINISH();
    delay(turn_delay);

    for (int i = 0; i <= 8; i++) {//counter for this specific length traveled
      ultrasonic();
      forward_count();
    }
    FINISH();
    delay(turn_delay);

    left_turn_90();
    FINISH();
    delay(turn_delay);

    forward();
    delay(1000);
    FINISH();
    delay(turn_delay);

    right_turn_90();
    FINISH();
    delay(turn_delay);
  }
}


void forward_count() {
  forward();
  delay(100);
  counter++;
  Serial.println(counter);
  if (counter == count_max) {
    FINISH();
    exit(0);
  }
}

void left() {

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  Serial.println("left");
  delay(1000);

}

void right() {

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  Serial.println("right");
  delay(1000);
}

void backward() {

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

  Serial.println("backward");

}

void forward() {

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  Serial.println("forward");

}

void FINISH() {

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);

  delay(500);

}

void right_turn_90() {
  right();
  delay(delay_time);
  FINISH();

}

void left_turn_90() {
  left();
  delay(delay_time + 50);
  FINISH();
}

void ultrasonic() {
  ultrasonic1();
  ultrasonic2();
}

void ultrasonic1() {

  digitalWrite(trig1, LOW);
  delayMicroseconds(2);

  digitalWrite(trig1, HIGH);

  delayMicroseconds(10);
  digitalWrite(trig1, LOW);

  duration1 = pulseIn(echo1, HIGH);

  distance1 = duration1 * 0.034 / 2;

  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.println(" cm");
}

void ultrasonic2() {

  digitalWrite(trig2, LOW);
  delayMicroseconds(2);

  digitalWrite(trig2, HIGH);

  delayMicroseconds(10);
  digitalWrite(trig2, LOW);

  duration2 = pulseIn(echo2, HIGH);

  distance2 = duration2 * 0.034 / 2;

  Serial.print("Distance 2: ");
  Serial.print(distance2);
  Serial.println(" cm");
}
