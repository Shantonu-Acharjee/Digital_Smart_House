int led = 13;
int fan = 12;
char t;


void setup() {
  
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(fan, OUTPUT);
  
  

}

void loop() {
  
  if(Serial.available()){
    t = Serial.read();
    Serial.println(t);
  }
  
  
  if(t=='a')
    digitalWrite(led,HIGH);
    
  else if(t== 'b')
  digitalWrite(led,LOW);




// For FAN

  else if(t== 'c')
  digitalWrite(fan,HIGH);


  else if(t== 'd')
  digitalWrite(fan,LOW);
    

}// Loop End
