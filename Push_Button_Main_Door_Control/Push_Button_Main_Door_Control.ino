#include <Servo.h>
Servo MainGateServo;  

int analogPin = A0; 
int val = 0; 

int DoorOpenPoint = 100;
int DoorClosePoint = 0;

void setup() {
  Serial.begin(9600); 
  pinMode(analogPin, INPUT); 

  MainGateServo.attach(9);  // attaches the servo on pin 9 to the servo object
  MainGateServo.write(DoorClosePoint);
}

void loop() {
  val = analogRead(analogPin);  
  Serial.println(val);   

  if(val >= 100){
    MainGateServo.write(DoorOpenPoint);
    delay(15);
  }


  else{
    MainGateServo.write(DoorClosePoint);
      delay(15); 
  }
  
}
