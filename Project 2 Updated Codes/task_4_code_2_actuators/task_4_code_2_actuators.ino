int ENA = 10;
int motor1pin1 = 9;
int motor1pin2 = 8;
int motor2pin1 = 7;
int motor2pin2 = 6;
int ENB = 5;

int max_speed = 200;
int delay_time = 1385; //delay time for turn functions

void setup() {
  Serial.begin(9600);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(ENB, OUTPUT);

  delay(8000);
}

void loop() {
  analogWrite(ENA, max_speed+25); //Controlling speed (0 = off and 255 = max speed)
  analogWrite(ENB, max_speed); //Controlling speed (0 = off and 255 = max speed)

  forward();
  delay(150);
  
  for(int i=1; i<=4; i++){
    forward();
    delay(2200);
    FINISH(); //Movement 1
    delay(1000);

    right_turn_90();

    Serial.println(i);
  }
  exit(0);
}

void forward() {

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

}

void left() {

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

}

void right() {

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}

void backward() {

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

}

void FINISH() {

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
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
