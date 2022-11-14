
#include <AFMotor.h>  // Подключаем библиотеку для работы с шилдом 
char btCommand;
// Подключаем моторы к клеммникам M1
AF_DCMotor motor1(1);

void setup()
{
  Serial.begin(9600);
  Serial.println("Ready");

  // Задаем максимальную скорость вращения моторов (аналог работы PWM)
  motor1.setSpeed(250);
  motor1.run(RELEASE);
}

void loop() {
  if (Serial.available() > 0) {

    btCommand = Serial.read();

    if (btCommand == 'F') {

      Serial.println("F");
      // Двигаемся условно вперед одну секунду
      motor1.run(FORWARD); // Задаем движение вперед
      motor1.setSpeed(250); // Задаем скорость движения
    }

    else
    {
      //Serial.println("Stop");
      motor1.run(RELEASE);
    }
  }
}
