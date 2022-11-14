/* 
 Stepper_28BYJ Motor Control - one revolution
 
 This program drives a unipolar or bipolar stepper motor. 
 The motor is attached to digital pins 8 - 11 of the Arduino.
 Эта программ управляет униполярным или биполярным шаговым двигателем.
 Шаговый двигатель присоединён к цифровым выходам 8-111 платы Arduino.
 
 Двигатель должен вращаться один оборот в одном направлении, затем
 один оборот в другом направлении. 
  
 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe
 
 */

#include <Stepper_28BYJ.h>

// количество шагов на один оборот
const int stepsPerRevolution = 4078;  // change this to fit the number of steps per revolution
                                     // for your motor

// initialize the stepper library on pins 8 through 11:
// инициализируем библиотеку Stepper_28BYJ на выходы 8-11
Stepper_28BYJ myStepper_28BYJ(stepsPerRevolution, 8,9,10,11);            

void setup() {
  // set the speed at 3 rpm:
  // установим скорость 3 об/мин
  myStepper_28BYJ.setSpeed(3);
  // initialize the serial port:
  // инициализируем последовательный порт
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  // шагаем 1 оборот в одном направлении
   Serial.println("clockwise");
  myStepper_28BYJ.step(stepsPerRevolution);
  delay(500);
  
   // step one revolution in the other direction:
   // шагаем 1 оборот в другом направлении
  Serial.println("counterclockwise");
  myStepper_28BYJ.step(-stepsPerRevolution);
  delay(500); 
}