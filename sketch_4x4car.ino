#include <AFMotor.h>

#include <SoftwareSerial.h>

#include <Servo.h>


Servo meuServo;
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
SoftwareSerial Bluetooth(A0, A1);

void setup() {
  // put your setup code here, to run once:
  meuServo.attach(9);
  meuServo.write(90);
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
  Serial.begin(9600);
  Bluetooth.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Bluetooth.available()){
    controlemotores();
  }
  
}






void controlemotores(){
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  char btcommand = Bluetooth.read();
  if (btcommand == 'F'){
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    meuServo.write(90);
  }else if (btcommand == 'B'){
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
    meuServo.write(90);
  }else if (btcommand == 'R'){
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    meuServo.write(90);
  }else if (btcommand == 'L'){
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
    meuServo.write(90);
  }else if (btcommand == 'C'){
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    meuServo.write(0);
  }else if (btcommand == 'S'){
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    meuServo.write(180);
  }else{
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    meuServo.write(90);
  }
  Serial.println(btcommand);
}