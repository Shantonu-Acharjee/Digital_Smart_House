#include <Servo.h>
Servo AutoDoorServo;


int trigPinA =A2;
int echoPinA =A0; //Should Be analog
int distanceA;
long durationA;

int Buzzer = 12;

int IrSensor = A4;
int IrState = 0;

void setup(){
 pinMode(trigPinA,OUTPUT);
 pinMode(echoPinA,INPUT);
 pinMode(Buzzer, OUTPUT);

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
  AutoDoorServo.write(0);
  delay(2000);
}

else{
  AutoDoorServo.write(100);
  delay(15);
}





IrState = analogRead(IrSensor);
if(IrState <= 200){
  digitalWrite(Buzzer, HIGH);
  delay(2000);
}


else if(IrState > 200){
  digitalWrite(Buzzer, LOW);
}




//Serial.println(distanceA);
//Serial.println(IrState);
}
