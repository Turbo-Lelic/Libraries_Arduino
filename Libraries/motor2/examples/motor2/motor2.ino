#include <motor2.h>
int SPEED=255;
motor2 s_motor(9,5,4,10,3,2);
void setup() {
s_motor.begin();
}
void loop() {
s_motor.FORWARD(SPEED);
delay(1000);
s_motor.BACKWARD(SPEED);
delay(1000);
s_motor.RIGHT(SPEED);
delay(1000);
s_motor.LEFT(SPEED);
delay(1000);
s_motor.STOP();
delay(1000);
}
