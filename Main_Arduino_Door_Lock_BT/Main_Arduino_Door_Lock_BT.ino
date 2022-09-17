#include <Servo.h>
Servo myservo;  

String inputString = "";
String command = "";
String value = "";
String password = "1234"; // This is the password. You can set any pasword.
boolean stringComplete = false;                    



void setup(){
  
  Serial.begin(9600);  // baud rate is 9600 must match with bluetooth 
  inputString.reserve(50);  // reserve 50 bytes in memory to save for string manipulation 
  command.reserve(50);
  value.reserve(50);
  boolean stringOK = false;
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  
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
   
}


void serialEvent() {
  
  while (Serial.available()) {
    
    char inChar = (char)Serial.read(); 
    inputString += inChar;
    if (inChar == '\n' || inChar == '\r') {
      stringComplete = true;
    } 
  }
}



void openDoor(){
  myservo.write(0); 
  delay(100);   
}



void closeDoor(){
  myservo.write(100);
  delay(100); 
}
