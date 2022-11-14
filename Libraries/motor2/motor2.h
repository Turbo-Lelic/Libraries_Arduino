#ifndef MOTOR2_H
#define MOTOR2_H
#if defined(ARDUINO)&&ARDUINO>=100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif


class motor2 
{
 private:
 int _ENA,_IN1,_IN2,_ENB, _IN3,_IN4;

 public:
 //motor2();
 motor2(int ENA,int IN1,int IN2,int ENB,int IN3,int IN4);
void begin(void);
void FORWARD(int SPEED);
void BACKWARD(int SPEED);
void RIGHT(int SPEED);
void LEFT(int SPEED);
void STOP();
};

#endif MOTOR2_H
