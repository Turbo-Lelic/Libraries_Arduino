
/*
 * Libtest.cpp 
 *
 * Libtest - библиотека дл¤ проекта robo-labs.ru
 *
 * Written by noonv, 02 2016.
 */

#ifndef Libtest_cpp
#define Libtest_cpp

#include "Libtest.h"

//
// конструктор - вызываетс¤ всегда при создании экземпл¤ра класса Libtest
//
Libtest::Libtest()
{
	Serial.begin(9600);
}

//
// просто говорим "Hello World :)" :)
//
void Libtest::hello_world()
{
	
	Serial.println("Hello World :)");
}

// Создание функци с параметрами (переменными)
// Синтаксис: [тип возвращаемого значения функцией] [имя функции]::[имя функ.]([переменные используемые в функ])
int Libtest::summa(int x, int y)
{
	int z; // декларация переменной "z" куда будет сохраняться результат суммы
	z = x + y; // складываем два числа и сохраняем в переменной "z"
	return z; // возвращаем z
	
}

// Создание функции мигания светодиода
void Libtest::led_onoff(int pin, int pause)
{
	digitalWrite(pin,HIGH);
	delay(pause);
	digitalWrite(pin,LOW);
	delay(pause);
}


#endif // #ifndef Libtest_cpp
