int flamePin = 2;
int buzzPin = 11;
void setup() {
pinMode( flamePin, INPUT );
pinMode( buzzPin, OUTPUT );
}
void loop() {
if( !digitalRead( flamePin ) )
digitalWrite( buzzPin, HIGH );
else
digitalWrite( buzzPin, LOW );
}
