/*
 * robocraft.cpp 
 *
 * RoboCraft - библиотека дл¤ проекта RoboCraft.ru
 *
 * Written by noonv, July 2009.
 */

#ifndef robocraft_cpp
#define robocraft_cpp

#include "robocraft.h"

//
// конструктор - вызываетс¤ всегда при создании экземпл¤ра класса RoboCraft
//
RoboCraft::RoboCraft()
{
	Serial.begin(9600);
}

//
// просто говорим "Hello" :)
//
void RoboCraft::hello()
{
	
	Serial.println("Hello :)");
}


#endif // #ifndef robocraft_cpp