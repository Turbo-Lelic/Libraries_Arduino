
/* 
 Stepper_28BYJ Motor Control - speed control
 
 This program drives a unipolar or bipolar stepper motor. 
 The motor is attached to digital pins 8 - 11 of the Arduino.
 A potentiometer is connected to analog input 0.
 Эта программ управляет униполярным или биполярным шаговым двигателем.
 Шаговый двигатель присоединён к цифровым выходам 8-11 платы Arduino. 
 Потенциометр присоединён к аналоговому входу 0. 
 
 The motor will rotate in a clockwise direction. The higher the potentiometer value,
 the faster the motor speed. Because setSpeed() sets the delay between steps, 
 you may notice the motor is less responsive to changes in the sensor value at
 low speeds.
 Двигатель будет вращаться по часовой стрелке. Чем выше напряжение снимаемое с потенциометра,
 тем выше будет скорость вращения. Потому что функция setSpeed() определяет задержки между шагами,
 вы можете заметить, что двигатель становится менее чувствительным к показаниям датчика на
 низких скоростях.
 
 Created 30 Nov. 2009
 Modified 28 Oct 2010
 by Tom Igoe
 
 */

#include <Stepper_28BYJ.h>

// количество шагов на один оборот
const int stepsPerRevolution = 4076;  // change this to fit the number of steps per revolution
// for your motor


// initialize the stepper library on pins 8 through 11:
// инициализируем библиотеку Stepper_28BYJ на выходы 8-11
Stepper_28BYJ myStepper_28BYJ(stepsPerRevolution, 8,9,10,11);            

// количество шагов, которые мотор уже сделал
int stepCount = 0;  // number of steps the motor has taken

void setup() {
  // nothing to do inside the setup
  // ничего не делаем внутри процедуры setup
}

void loop() {
  // read the sensor value:
  // читаем значение датчика на аналоговом входе 0
  int sensorReading = analogRead(A0);
  // map it to a range from 0 to 100:
  // масштабируем значение с аналогового входа
  // из диапазона 0..1023 в диапазон 0..100
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  // set the motor speed:
  // установить  скорость вращения
  if (motorSpeed > 0) {
    myStepper_28BYJ.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
	// прощагать 1/100 оборота
    myStepper_28BYJ.step(stepsPerRevolution/100);
  } 
}


