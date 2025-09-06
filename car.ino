#include <Servo.h>
Servo myServo;

const int trig = 2;
const int echo = 3;
const int moto = 4;
int ca = 90; // start in front
long dur;
float dis;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(moto, OUTPUT);

  myServo.attach(9); // safe PWM pin
  myServo.write(ca);
  Serial.println("Hello Dexter Morgan");
}

void loop() {
  // Motor ON
  digitalWrite(moto, HIGH);

  // Ultrasonic measurement
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  dur = pulseIn(echo, HIGH);
  dis = dur * 0.034 / 2;

  Serial.print("The distance is: ");
  Serial.println(dis);

  // Sweep servo and stop motor if object is near
  if (dis <= 20 && dis > 0) {
    digitalWrite(moto, LOW);
    ca += 30;
    if (ca > 180) ca = 90;
    myServo.write(ca);
    delay(500); // give servo time to move
  }

  delay(100); // small loop delay
}
