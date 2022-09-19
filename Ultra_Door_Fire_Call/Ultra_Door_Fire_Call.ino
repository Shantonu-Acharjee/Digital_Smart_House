#include <Servo.h>
Servo AutoDoorServo;


int trigPinA =A2;
int echoPinA =A0; //Should Be analog
int distanceA;
long durationA;

int Buzzer = 12;

int IrSensor = A4;
int IrState = 0;



//Call Function
#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 2);



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
  //delay(2000);

  //Fire Function Start-------------------------------------

  //Begin serial communication with Arduino and SIM800L
  mySerial.begin(9600);

  Serial.println("Initializing..."); 
  delay(1000);

  mySerial.println("AT"); //Once the handshake test is successful, i t will back to OK
  updateSerial();
  
  mySerial.println("ATD+ +8801821911454;"); //  change ZZ with country code and xxxxxxxxxxx with phone number to dial
  updateSerial();
  delay(20000); // wait for 20 seconds...
  mySerial.println("ATH"); //hang up
  updateSerial();
  }






else if(IrState > 200){
  digitalWrite(Buzzer, LOW);
}




//Serial.println(distanceA);
//Serial.println(IrState);
}// Void Lopp End





void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}
