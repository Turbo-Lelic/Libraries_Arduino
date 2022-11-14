/*
  Stepper_28BYJ.cpp - - Stepper_28BYJ library for Wiring/Arduino - Version 0.4
  Модифицированная библиотека для управления шаговым двигателем 28BYJ
  
  Original library     (0.1) by Tom Igoe.
  //Two-wire modifications   (0.2) by Sebastian Gassner
  Combination version   (0.3) by Tom Igoe and David Mellis
  Bug fix for four-wire   (0.4) by Tom Igoe, bug fix from Noah Shibley
  Модифицирована для 28BYJ - alex48 (www.alex48.110kpd.ru

  Управленине униполярным шаговым двигателем подключенным по 4-х проводной схеме.

  Если подключать несколько шаговых двигателей к одному микроконтроллеру,
  вывод микроконтролера быстро заканчиваются, так как для подключения каждого
  двигателя используется 4 вывода.

  Последовательность управляющих сигналов для 28BYJ следующая:
  
  C0 - BLUE
  C1 - PINK
  C2 - YELLOW
  C3 - ORANGE
  Шаг	C0	C1	C2	C3
    1	0	0	0	1
    2	0	0	1	1
    3	0	0	1	0
    4	0	1	1	0
    5	0	1	0	0
    6	1	1	0	0
    7	1	0	0	0
    8	1	0	0	1

  The circuits can be found at 
 
http://www.arduino.cc/en/Tutorial/Stepper_28BYJ
 
 
 */


#include "Arduino.h"
#include "Stepper_28BYJ.h"

/*
 конструктор для 4-проводной схемы подключения двигателя
 указываем какие выводы используются для управления двигателем
 */

Stepper_28BYJ::Stepper_28BYJ(int number_of_steps, int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4)
{
  // инициализируем значение переменных
  this->step_number = 0;	// номер текущего шага двигателя
  this->speed = 0;			// скорость двигателя в оборотах в минуту
  this->direction = 0;      // направление вращения
  this->last_step_time = 0;	// метка времени в мс, когда был сделан последний шаг
  this->number_of_steps = number_of_steps;	// количество шагов на 1 оборот
  
  // указываем к каким выводам Ардуино подключен двигатель
  this->motor_pin_1 = motor_pin_1;
  this->motor_pin_2 = motor_pin_2;
  this->motor_pin_3 = motor_pin_3;
  this->motor_pin_4 = motor_pin_4;
  
  // устанавливаем режим работы выводов на ВЫВОД
  pinMode(this->motor_pin_1, OUTPUT);
  pinMode(this->motor_pin_2, OUTPUT);
  pinMode(this->motor_pin_3, OUTPUT);
  pinMode(this->motor_pin_4, OUTPUT); 
}

/*
  устанавливаем скорость вращения в минутах
*/
void Stepper_28BYJ::setSpeed(long whatSpeed)
{
  this->step_delay = 60L * 1000L / this->number_of_steps / whatSpeed;
}

/*
  Передвигаемся на steps_to_move steps шагов. Если значение отрицательное,
  то вращаемся в обратном направлении  
 */
void Stepper_28BYJ::step(int steps_to_move)
{  
  int steps_left = abs(steps_to_move);	// определяем сколько шагов нужно сделать
  
  // определяем направление вращения в зависимости от знака количества шагов
  if (steps_to_move > 0) {this->direction = 1;}
  if (steps_to_move < 0) {this->direction = 0;}

  // в цикле уменьшаем количество шагов, которые нужно прошагать на 1
  while(steps_left > 0) {
  // шагаем только если выдержана сооветствующая пауза
  if (millis() - this->last_step_time >= this->step_delay) {
	  // запоминаем, когда был сделан последний шаг
      this->last_step_time = millis();
	  // увеличиваем или уменьшаем номер текущего шага
	  // в зависимости от направления вращения
      if (this->direction == 1) {
        this->step_number++;
        if (this->step_number == this->number_of_steps) {
          this->step_number = 0;
        }
      } 
      else { 
        if (this->step_number == 0) {
          this->step_number = this->number_of_steps;
        }
        this->step_number--;
      }
	  // уменьшаем количество шагов, которые осталось прошагать
      steps_left--;
	  // переходим к следующему шагу 0, 1, 2, 3, 4, 5, 6 или 7
      stepMotor(this->step_number % 8);
    }
  }
}

/*
 1 шаг (вперёд или назад)
 */
void Stepper_28BYJ::stepMotor(int thisStep)
{
	Serial.println(thisStep);
	switch (thisStep) {
		case 0:    // 0001
			digitalWrite(motor_pin_1, LOW);
			digitalWrite(motor_pin_2, LOW);
			digitalWrite(motor_pin_3, LOW);
			digitalWrite(motor_pin_4, HIGH);
		break;
		case 1:    // 0011
			digitalWrite(motor_pin_1, LOW);
			digitalWrite(motor_pin_2, LOW);
			digitalWrite(motor_pin_3, HIGH);
			digitalWrite(motor_pin_4, HIGH);
		break;
		case 2:    //0010
			digitalWrite(motor_pin_1, LOW);
			digitalWrite(motor_pin_2, LOW);
			digitalWrite(motor_pin_3, HIGH);
			digitalWrite(motor_pin_4, LOW);
		break;
		case 3:    //0110
			digitalWrite(motor_pin_1, LOW);
			digitalWrite(motor_pin_2, HIGH);
			digitalWrite(motor_pin_3, HIGH);
			digitalWrite(motor_pin_4, LOW);
		break;
		case 4:    // 0100
			digitalWrite(motor_pin_1, LOW);
			digitalWrite(motor_pin_2, HIGH);
			digitalWrite(motor_pin_3, LOW);
			digitalWrite(motor_pin_4, LOW);
		break;
		case 5:    // 1100
			digitalWrite(motor_pin_1, HIGH);
			digitalWrite(motor_pin_2, HIGH);
			digitalWrite(motor_pin_3, LOW);
			digitalWrite(motor_pin_4, LOW);
		break;
		case 6:    //1000
			digitalWrite(motor_pin_1, HIGH);
			digitalWrite(motor_pin_2, LOW);
			digitalWrite(motor_pin_3, LOW);
			digitalWrite(motor_pin_4, LOW);
		break;
		case 7:    //1001
			digitalWrite(motor_pin_1, HIGH);
			digitalWrite(motor_pin_2, LOW);
			digitalWrite(motor_pin_3, LOW);
			digitalWrite(motor_pin_4, HIGH);
		break;
	}
}

/*
  метода возвращает версию библиотеки
*/
int Stepper_28BYJ::version(void)
{
  return 4;
}
