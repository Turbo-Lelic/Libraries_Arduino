/*
 * Набор для экспериментов jssemKit
 * Код программы для опыта №1: lesson_L298N_CAR_01.ino
 *
 * L298N - драйвер двигателей
 *
 * 
*/
int IN3 = 3; // Input3 подключен к выводу 3 
int IN4 = 2;
int i;

void setup()
{
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
}

void loop()
{
  // На пару выводов "IN" поданы разноименные сигналы, мотор вращается   
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);     
  delay(4000);
 
  // на пару выводов "IN" поданы одноименные сигналы, мотор не вращается
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);     
  delay(2000);
  
  // меняем направление вращения двигателя
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH); 
  
  // Снова на пару выводов "IN" поданы одноименные сигналы, мотор не вращается
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);     
  delay(2000);

  }
