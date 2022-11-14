/*
 * robocraft.h
 *
 * RoboCraft - library fo RoboCraft.ru project
 * RoboCraft - библиотека для проекта RoboCraft.ru
 * 
 *
 * Written by noonv, July 2009.
*/

#ifndef robocraft_h
#define robocraft_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif 

class RoboCraft
{
	public:
		RoboCraft();
		void hello();
	private:
		int motorA;
		int motorB;
};

#endif // #ifndef robocraft_h