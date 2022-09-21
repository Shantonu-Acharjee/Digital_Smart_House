int GasPin = A5;
int GasState = 0;

int GasFlag = 0;
int Bazzer = 11;

int GasDoorOpen = 100;
int GasDoorClose = 0;

#include <Servo.h>
Servo GasServo;


void setup() {
  Serial.begin(9600);
  pinMode(GasPin, INPUT);
  pinMode(Bazzer, OUTPUT);

  GasServo.attach(10);
  GasServo.write(GasDoorClose);
  
}


void loop() {
  
  GasState = analogRead(GasPin);

  Serial.print("Gas : ");
  Serial.println(GasState);
  

  if(GasState <= 200 && GasFlag == 0){
    
    digitalWrite(Bazzer, HIGH);
    GasServo.write(GasDoorOpen);
    delay(3000);
    digitalWrite(Bazzer, LOW);
    GasServo.write(GasDoorClose);
    delay(15);
    GasFlag = 1;
  }




  else if(GasState >= 350){
    GasFlag = 0;
    delay(15);
  }

}
