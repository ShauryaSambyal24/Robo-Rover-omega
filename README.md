Arduino Sonar Rover

A simple Arduino-based rover with an ultrasonic sensor mounted on a servo. The rover moves forward and stops when it detects an obstacle. The servo scans the environment to look for a clear path.

Features

Moves forward using a DC motor

Detects obstacles using an HC-SR04 ultrasonic sensor

Servo-mounted sonar rotates to scan for clear paths

Serial monitor displays distance readings

Components Needed

Arduino board (Uno, Nano, etc.)

HC-SR04 Ultrasonic Sensor

Servo motor

DC motor (or motor driver if needed)

Jumper wires

Power supply (battery or USB)

Wiring
Component	Arduino Pin
Trig (HC-SR04)	2
Echo (HC-SR04)	3
Motor control pin	4
Servo signal pin	9
Servo GND/VCC	GND/5V
Motor GND/VCC	GND/5V or external

Make sure to provide sufficient power to the motor and servo to avoid voltage drops.

Code Overview
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

  myServo.attach(9);
  myServo.write(ca);
  Serial.println("Hello Dexter Morgan");
}

void loop() {
  digitalWrite(moto, HIGH); // Motor ON

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

  // Stop motor and rotate servo if obstacle is near
  if (dis <= 20 && dis > 0) {
    digitalWrite(moto, LOW);
    ca += 30;
    if (ca > 180) ca = 90;
    myServo.write(ca);
    delay(500);
  }

  delay(100);
}


Moves the rover forward

Measures distance using the ultrasonic sensor

Stops motor if an obstacle is closer than 20 cm

Rotates the servo by 30° each time an obstacle is detected

Usage

Connect all components according to the wiring table.

Upload the .ino file to your Arduino using the Arduino IDE.

Open the Serial Monitor to view distance readings.

Power the motor and observe the rover’s obstacle detection behavior.

Notes & Improvements

Current servo rotation is fixed (+30°) — can be improved with scanning algorithms

Motor control is basic (ON/OFF) — consider using PWM for speed control

Add logic for turning the rover automatically based on servo readings

License

MIT License © Shaurya Sambyal

I can also make a more visually appealing, GitHub-ready version with badges, images, and sections like Roadmap, Contributing, etc. if you want.

Do you want me to do that next?
