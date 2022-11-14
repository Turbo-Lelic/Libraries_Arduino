
#include <AFMotor.h>  // Подключаем библиотеку для работы с шилдом 
#include <Servo.h>  // Подключаем библиотеку для работы с сервоприводами, можно не подключать
int k;
char btCommand;
// Подключаем моторы к клеммникам M1, M2, M3, M4
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  
  Serial.begin(9600);
  Serial.println("Ready");
 
   // Задаем максимальную скорость вращения моторов (аналог работы PWM) 
  motor1.setSpeed(250);
  motor1.run(RELEASE);
  motor2.setSpeed(250);
  motor2.run(RELEASE);
  motor3.setSpeed(250);
  motor3.run(RELEASE);
  motor4.setSpeed(250);
  motor4.run(RELEASE);
  
  
  
}

void loop(){
   if (Serial.available() > 0) {
       
  btCommand = Serial.read();
  
  if (btCommand == 'F'){
   
    //Serial.println("F");
    // Двигаемся условно вперед одну секунду 
  motor1.run(FORWARD); // Задаем движение вперед
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  motor1.setSpeed(250); // Задаем скорость движения
  motor2.setSpeed(250); 
  motor3.setSpeed(250); 
  motor4.setSpeed(250); 
      
  } 
   else if (btCommand == 'B'){
    
   // Serial.println("B");
    // Двигаемся условно вперед одну секунду 
  motor1.run(BACKWARD); // Задаем движение вперед
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  motor1.setSpeed(250); // Задаем скорость движения
  motor2.setSpeed(250); 
  motor3.setSpeed(250); 
  motor4.setSpeed(250); 
      
  }   

else if (btCommand == 'L'){
    
   // Serial.println("R");
    // Двигаемся условно вперед одну секунду 
  motor1.run(BACKWARD); // Задаем движение вперед
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  motor1.setSpeed(250); // Задаем скорость движения
  motor2.setSpeed(250); 
  motor3.setSpeed(250); 
  motor4.setSpeed(250); 
      
  }   

  else if (btCommand == 'R'){
    
   // Serial.println("B");
    // Двигаемся условно вперед одну секунду 
  motor1.run(FORWARD); // Задаем движение вперед
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  motor1.setSpeed(250); // Задаем скорость движения
  motor2.setSpeed(250); 
  motor3.setSpeed(250); 
  motor4.setSpeed(250); 
      
  }   
  
  else {  
    //Serial.println("Stop");
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  
  }
  
  
   }
}
