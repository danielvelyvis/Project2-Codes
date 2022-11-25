int echo1 = 2;
int trig1 = 3;
int echo2 = 11;
int trig2 = 12;

long duration1, duration2;
int distance1, distance2;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:

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
  delay(100);
}

void ultrasonic2(){
  
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
  delay(100);
}
