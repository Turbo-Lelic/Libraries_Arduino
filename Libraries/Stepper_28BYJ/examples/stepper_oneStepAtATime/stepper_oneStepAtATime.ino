
/* 
 Stepper_28BYJ Motor Control - one step at a time
 
 This program drives a unipolar or bipolar stepper motor. 
 The motor is attached to digital pins 8 - 11 of the Arduino.
 Эта программ управляет униполярным или биполярным шаговым двигателем.
 Шаговый двигатель присоединён к цифровым выходам 8-11 платы Arduino. 
 
 The motor will step one step at a time, very slowly.  You can use this to
 test that you've got the four wires of your stepper wired to the correct
 pins. If wired correctly, all steps should be in the same direction.
 Мотор будет шагать по одному шагу за раз, вращение будет медленным.
 Вы можете использовать этот пример, чтобы проверить, что двигатель
 подключен правильно (к соответствующим выводам).
 Если всё подключено правильно, все шаги будут в одном направлении.
 
 Use this also to count the number of steps per revolution of your motor,
 if you don't know it.  Then plug that number into the oneRevolution
 example to see if you got it right.
 Этот пример, чтобы посчитать количество шагов на 1 оборот для своего двигателя,
 если вы его не знаете. Затем запишите полученное значение в переменную 
 oneRevolution, чтобы понять правильно ли посчитано количество оборотов за минуту.
 
 Created 30 Nov. 2009
 by Tom Igoe
 
 */

#include <Stepper_28BYJ.h>

// количество шагов на один оборот
const int stepsPerRevolution = 4078;  // change this to fit the number of steps per revolution
                                     // for your motor

// initialize the stepper library on pins 8 through 11:
// инициализируем библиотеку Stepper_28BYJ на выходы 8-11
Stepper_28BYJ myStepper_28BYJ(stepsPerRevolution, 8,9,10,11);            

// количество шагов, которые мотор уже сделал
int stepCount = 0;         // number of steps the motor has taken

void setup() {
  // initialize the serial port:
  // инициализируем последовательный порт  
  Serial.begin(9600);
}

void loop() {
  // step one step:
  // делаем 1 шаг
  myStepper_28BYJ.step(1);
  Serial.print("steps:" );
  Serial.println(stepCount);
  stepCount++;
  delay(500);
}

