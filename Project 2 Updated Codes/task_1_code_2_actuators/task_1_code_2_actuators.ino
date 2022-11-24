#include <IRremote.h>

#define IR_RECEIVE_PIN 4

int ENA = 10;
int motor1pin1 = 9;
int motor1pin2 = 8;
int motor2pin1 = 7;
int motor2pin2 = 6;
int ENB = 5;

int sec = 100;
int max_speed = 200;

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
  IrReceiver.begin(IR_RECEIVE_PIN);


  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  analogWrite(ENA, max_speed); //Controlling speed (0 = off and 255 = max speed)
  analogWrite(ENB, max_speed); //Controlling speed (0 = off and 255 = max speed)

  receive();

}

void receive(){
    if (IrReceiver.decode()) {
    IrReceiver.resume();
    //Serial.println(IrReceiver.decodedIRData.command);
    int command = IrReceiver.decodedIRData.command;
    switch (command) {

      case IR_BUTTON_PLAY_PAUSE: {
          forward();
          Serial.println("Forward");
          break;
        }
        case IR_BUTTON_VOL_UP: {
          forward();
          Serial.println("Forward");
          break;
        }
        case IR_BUTTON_VOL_DOWN: {
          backward();
          Serial.println("Backward");
          break;
        }
      case IR_BUTTON_FAST_FORWARD: {
          right();
          Serial.println("Right");
          break;
        }
        case IR_BUTTON_REWIND: {
          left();
          Serial.println("Left");
          break;
        }
      case IR_BUTTON_STOP: {
          FINISH();
          Serial.println("STOP");
          break;
        }
      default: {
          Serial.println("Button not recognized");
      }
    }
  }
}
void forward() {

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  delay(sec);
  FINISH();
}

void left() {

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

  delay(sec);
  FINISH();
}

void right() {

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  delay(sec);
  FINISH();
}

void backward() {

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

  delay(sec);
  FINISH();
}

void FINISH() {

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}
