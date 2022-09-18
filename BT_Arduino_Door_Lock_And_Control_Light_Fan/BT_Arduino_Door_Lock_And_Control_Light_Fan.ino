#include <Servo.h>
Servo MainGateServo;  

String inputString = "";
String command = "";
String value = "";
String password = "1234"; // This is the password. You can set any pasword.
boolean stringComplete = false;   
char inChar;

int DoorOpenPoint = 100;
int DoorClosePoint = 0;

//Light Fan Section
int led = 13;
int fan = 12;


void setup(){
  
  Serial.begin(9600);  // baud rate is 9600 must match with bluetooth 
  inputString.reserve(50);  // reserve 50 bytes in memory to save for string manipulation 
  command.reserve(50);
  value.reserve(50);
  boolean stringOK = false;
  MainGateServo.attach(9);  // attaches the servo on pin 9 to the servo object
  MainGateServo.write(DoorClosePoint);

  pinMode(led, OUTPUT);
  pinMode(fan, OUTPUT);
  
}




void loop(){
  
  if (stringComplete) {
    delay(100);
    int pos = inputString.indexOf('=');
    
    if (pos > -1) {
        command = inputString.substring(0, pos);
        value = inputString.substring(pos+1, inputString.length()-1);  // extract command up to \n exluded
        
    if(!password.compareTo(value) && (command == "OPEN")){
          
           openDoor(); // call openDoor() function
           Serial.println(" OPEN"); // sent open feedback to phone
           delay(100);
           }
           
    else if(!password.compareTo(value) && (command == "CLOSE")){
          
           closeDoor();
           Serial.println(" CLOSE"); // sent " CLOSE" string to the phone 
           delay(100);
           }

           
    else if(password.compareTo(value)){
          
           Serial.println(" WRONG");
           delay(100);
           }

            
        } 
       

       inputString = "";
       stringComplete = false;
    }

 
}// Loop End -------------






void serialEvent() {
  
  while (Serial.available()) {
    
    inChar = Serial.read(); 
    Serial.println(inChar);

    inputString += inChar;
    if (inChar == '\n' || inChar == '\r') {
      stringComplete = true;
    } 
    
// For Light Fan ----------------------------------Start -----------------

    if(inChar =='a')
    digitalWrite(led,HIGH);
    
    else if(inChar == 'b')
      digitalWrite(led,LOW);




// For FAN

    else if(inChar == 'c')
      digitalWrite(fan,HIGH);


    else if(inChar == 'd')
      digitalWrite(fan,LOW);


//Light Fan End -----------------xx------------------------------

    
    

    
  }
}



void openDoor(){
  MainGateServo.write(DoorOpenPoint); 
  delay(15);
  /*
  MainGateServo.write(0); 
  delay(15);
  */  
}



void closeDoor(){
  MainGateServo.write(DoorClosePoint);
  delay(15); 
}
