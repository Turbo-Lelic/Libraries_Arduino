/*
 * MotorKnob
 *
 * A stepper motor follows the turns of a potentiometer
 * (or other sensor) on analog input 0.
 *
 * Шаговый двигатель вращается в зависимости от значения
 * напряжения на потенциометре на аналоговом входе 0
 *
 * http://www.arduino.cc/en/Reference/Stepper
 * This example code is in the public domain.
 * примеры для работы с шаговым двигателем 28BYJ-48
 */

#include <Stepper_28BYJ.h>

// change this to the number of steps on your motor
// изменить количество шагов для вашего мотора
#define STEPS 4078

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
// создаём экземпляр класса Stepper_28BYJ,
// указываем количество шагов и какие выводы используются для управления
Stepper_28BYJ stepper(STEPS, 8, 9, 10, 11);

// the previous reading from the analog input
// переменная для хранения предыдущего значения аналогового вывода
int previous = 0;

void setup()
{
  // set the speed of the motor to 3 RPMs
  // установим скорость вращения 3 об/мин
  stepper.setSpeed(3);
}

void loop()
{
  // get the sensor value
  // получить значение с аналогового входа
  int val = analogRead(0);

  // move a number of steps equal to the change in the
  // sensor reading
  // повернуть вал на количество оборотов равное разнице
  // текущего и последнего значения аналогового входа
  stepper.step(val - previous);

  // remember the previous value of the sensor
  // запомнить последнее значение аналогового входа
  previous = val;
}