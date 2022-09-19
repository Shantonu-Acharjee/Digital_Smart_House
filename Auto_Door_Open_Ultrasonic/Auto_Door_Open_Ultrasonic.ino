#include <Servo.h>
Servo AutoDoorServo;


int trigPinA =A0;
int echoPinA =A1; //Should Be analog
int distanceA;
long durationA;
int led = 13;

void setup(){
 pinMode(trigPinA,OUTPUT);
 pinMode(echoPinA,INPUT);
 pinMode(led, OUTPUT);

 AutoDoorServo.attach(9);
 Serial.begin(9600);
  
}



void loop() {

digitalWrite(trigPinA,LOW);
delayMicroseconds(2);
digitalWrite(trigPinA,HIGH);
delayMicroseconds(10);
digitalWrite(trigPinA,LOW);
durationA=pulseIn(echoPinA,HIGH);
distanceA = durationA*0.034/2;


if(distanceA <= 15){
  AutoDoorServo.write(100);
  digitalWrite(led, HIGH);
  delay(1000);
}

else{
  AutoDoorServo.write(0);
  digitalWrite(led, LOW);
  delay(15);
}

Serial.println(distanceA);
}
