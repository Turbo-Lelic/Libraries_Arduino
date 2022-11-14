/*
  Stepper_28BYJ.h - - Stepper_28BYJ library for Wiring/Arduino
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
  http://www.arduino.cc/en/Tutorial/Stepper
*/

// убедимся, что описание библиотеки подключается 1 раз
#ifndef Stepper_28BYJ_h
#define Stepper_28BYJ_h

// описание интерфейса библиотеки
class Stepper_28BYJ {
  public:
    // конструктор
    Stepper_28BYJ(int number_of_steps, int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4);

    // speed setter method:
    void setSpeed(long whatSpeed);

    // mover method:
    void step(int number_of_steps);

    int version(void);

  private:
    void stepMotor(int this_step);
   
    int direction;				// направление вращения
    int speed;					// скорость в оборотах в минуту
    unsigned long step_delay;	// задержка между шагами в мс, расчитана на основе скорости
    int number_of_steps;		// количество шагов на 1 оборот
    int step_number;			// номер текущего шага из общей последовательности разных шагов
    
    // motor pin numbers:
	// выводы используемые для подключения двигателя
    int motor_pin_1;
    int motor_pin_2;
    int motor_pin_3;
    int motor_pin_4;
    
    long last_step_time;		// метка времени в мс, когда был сделан последний шаг
};

#endif
