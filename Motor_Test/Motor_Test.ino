#include <IRremote.h>

#define IR_RECEIVE_PIN 2

int ENA = 10;
int motor1pin1 = 9;
int motor1pin2 = 8;
int motor2pin1 = 7;
int motor2pin2 = 6;
int ENB = 5;

int sec = 100;
int max_speed = 255;

#define IR_BUTTON_PLAY_PAUSE 64
#define IR_BUTTON_FAST_FORWARD 67
#define IR_BUTTON_REWIND 68
#define IR_BUTTON_VOL_UP 70
#define IR_BUTTON_VOL_DOWN 21
#define IR_BUTTON_STOP 71
/*#define IR_BUTTON_1 12
  #define IR_BUTTON_2 24
  #define IR_BUTTON_3 94*/

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

  forward();
  delay(1000);
  FINISH();
  delay(200);

  backward();
  delay(1000);
  FINISH();
  delay(200);

  /*left();
  delay(1000);
  FINISH();
  delay(200);

  right();
  delay(1000);
  FINISH();
  delay(200);*/

}
void forward() {

  analogWrite(ENA, max_speed); //Controlling speed (0 = off and 255 = max speed)
  analogWrite(ENB, max_speed); //Controlling speed (0 = off and 255 = max speed)


  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}

void right() {

  analogWrite(ENA, max_speed); //Controlling speed (0 = off and 255 = max speed)
  analogWrite(ENB, max_speed); //Controlling speed (0 = off and 255 = max speed)

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

}

void left() {

  analogWrite(ENA, max_speed); //Controlling speed (0 = off and 255 = max speed)
  analogWrite(ENB, max_speed); //Controlling speed (0 = off and 255 = max speed)

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}

void backward() {

  analogWrite(ENA, max_speed); //Controlling speed (0 = off and 255 = max speed)
  analogWrite(ENB, max_speed); //Controlling speed (0 = off and 255 = max speed)

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

/*void acc(){
  for (int i = 0; i < max_speed; i+=4) { 
    analogWrite(ENA, i); 
    analogWrite(ENB, i);  
  } 
}

void dec(){
  for (int i = max_speed; i > 0; i-=4){
    analogWrite(ENA, i);
    analogWrite(ENB, i);
    delay(20);
  }
}*/
