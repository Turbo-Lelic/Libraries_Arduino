#ifndef MOTOR2_CPP
#define MOTOR2_CPP
#include "motor2.h"


motor2::motor2(int ENA,int IN1,int IN2,int ENB,int IN3,int IN4) {
  _ENA = ENA;
  _IN1 = IN1;
  _IN2 = IN2;
_ENB = ENB;
  _IN3 = IN3;
  _IN4 = IN4;
  


}

void motor2::begin(void) {
  // set up the pins!

 pinMode(_ENA,OUTPUT);  
 pinMode(_IN1,OUTPUT);  
 pinMode(_IN2,OUTPUT);  
 pinMode(_ENB,OUTPUT);  
 pinMode(_IN3,OUTPUT);  
 pinMode(_IN4,OUTPUT); 
}

//boolean S == Scale.  True == Farenheit; False == Celcius
void motor2::FORWARD(int SPEED)
{
digitalWrite(_IN1,1);
digitalWrite(_IN2,0);

digitalWrite(_IN3,0);
digitalWrite(_IN4,1);

analogWrite(_ENA,SPEED);
analogWrite(_ENB,SPEED);
}

void motor2::BACKWARD(int SPEED)
{
digitalWrite(_IN1,0);
digitalWrite(_IN2,1);

digitalWrite(_IN3,1);
digitalWrite(_IN4,0);

analogWrite(_ENA,SPEED);
analogWrite(_ENB,SPEED);
}

void motor2::LEFT(int SPEED)
{
digitalWrite(_IN1,1);
digitalWrite(_IN2,0);

digitalWrite(_IN3,1);
digitalWrite(_IN4,0);

analogWrite(_ENA,SPEED);
analogWrite(_ENB,SPEED);
}

void motor2::RIGHT(int SPEED)
{
digitalWrite(_IN1,0);
digitalWrite(_IN2,1);

digitalWrite(_IN3,0);
digitalWrite(_IN4,1);

analogWrite(_ENA,SPEED);
analogWrite(_ENB,SPEED);
}
void motor2::STOP()
{
digitalWrite(_IN1,0);
digitalWrite(_IN2,1);

digitalWrite(_IN3,0);
digitalWrite(_IN4,1);

analogWrite(_ENA,0);
analogWrite(_ENB,0);
}

#endif MOTOR_CPP




