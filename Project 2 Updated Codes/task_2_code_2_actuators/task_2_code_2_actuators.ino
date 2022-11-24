int ENA = 10;
int motor1pin1 = 9;
int motor1pin2 = 8;
int motor2pin1 = 7;
int motor2pin2 = 6;
int ENB = 5;

int sec = 100;
int max_speed = 200;
int delay_time = 1400;

void setup() {
  Serial.begin(9600);

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  analogWrite(ENA, max_speed+25); //Controlling speed (0 = off and 255 = max speed)
  analogWrite(ENB, max_speed); //Controlling speed (0 = off and 255 = max speed)

  delay(10000);

  forward();
  delay(2250); //SUBJECT TO CHANGE
  FINISH(); //Movement 1
  delay(1000);

  right_turn_90(); //Turn 1

  forward();
  delay(2000); //SUBJECT TO CHANGE
  FINISH(); //Movement 2
  delay(1000);

  left_turn_90(); //Turn 2

  forward();
  delay(2000); //SUBJECT TO CHANGE
  FINISH(); //Movement 3
  
  /*delay(4000);

  right_turn_90(); //Movement Test
  left_turn_90();//Movement Test

  backward(); //Movement Test
  delay(3000);
  
  FINISH();
  delay(1000);*/
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

void right_turn_90(){
  right();
  delay(delay_time-100);
  FINISH();
  delay(1000);
}

void left_turn_90(){
  left();
  delay(delay_time+100);
  FINISH();
  delay(1000);
}
