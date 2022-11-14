
#include <AFMotor.h>  // Подключаем библиотеку для работы с шилдом 
#include <Servo.h>  // Подключаем библиотеку для работы с сервоприводами, можно не подключать
#include <Ultrasonic.h>

#define TRIGGER_PIN  14
#define ECHO_PIN     15

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
Servo servo2;
int d = 20;
int speed_max = 250;
int speed_povorot = 100;
int speed_FB = 150;
char btCommand;
// Подключаем моторы к клеммникам M1, M2, M3, M4
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
  servo2.attach(9);
  servo2.write(90);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void loop() {

  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.print("MS: ");
  Serial.print(microsec);
  Serial.print(", CM: ");
  Serial.print(cmMsec);
  int angl = servo2.read();
  
if ((cmMsec) < d && angl == 90)  {
    mot_stop();
    servo2.write(45);
    delay(1000);
    microsec = ultrasonic.timing();
    cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
}

if ((cmMsec) > d && angl == 90)  {
    mot_forward(speed_FB);   
}

if ((cmMsec) < d && angl == 45)  {
    mot_stop();
    delay(1000);
    servo2.write(125);
    microsec = ultrasonic.timing();
    cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
}


if (angl == 125  && (cmMsec) > d){
  mot_left(speed_povorot);
  delay(500);
  servo2.write(90);
  delay(500);
  microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
}

if (angl == 45  && (cmMsec) > d){
  mot_right(speed_povorot);
  delay(500);
  servo2.write(90);
  delay(500);
  microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
}


}

void mot_stop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void mot_forward(int speed_FB)
{
  // Двигаемся условно вперед одну секунду
  motor1.run(FORWARD); // Задаем движение вперед
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  motor1.setSpeed(speed_FB); // Задаем скорость движения
  motor2.setSpeed(speed_FB);
  motor3.setSpeed(speed_FB);
  motor4.setSpeed(speed_FB);
}

void mot_backward(int speed_FB)
{
  // Двигаемся условно назад одну секунду
  motor1.run(BACKWARD); // Задаем движение вперед
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  motor1.setSpeed(speed_FB); // Задаем скорость движения
  motor2.setSpeed(speed_FB);
  motor3.setSpeed(speed_FB);
  motor4.setSpeed(speed_FB);
}

void mot_left(int speed_povorot)
{
  // Двигаемся условно влево одну секунду
  motor3.run(BACKWARD); // Задаем движение вперед
  motor4.run(BACKWARD);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor1.setSpeed(speed_povorot); // Задаем скорость движения
  motor2.setSpeed(speed_povorot);
  motor3.setSpeed(speed_povorot);
  motor4.setSpeed(speed_povorot);
}

void mot_right(int speed_povorot)
{
  // Двигаемся условно вправо одну секунду
  motor3.run(FORWARD); // Задаем движение вперед
  motor4.run(FORWARD);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor1.setSpeed(speed_povorot); // Задаем скорость движения
  motor2.setSpeed(speed_povorot);
  motor3.setSpeed(speed_povorot);
  motor4.setSpeed(speed_povorot);
}



