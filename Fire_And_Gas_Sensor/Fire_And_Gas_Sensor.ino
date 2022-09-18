int FirePin = A0;
int GasPin = A1;

int FireState = 0;
int GasState = 0;

int Bazzer = 11;
int WaterPamp = 12;

int GasFlag = 0;

void setup() {
  Serial.begin(9600);
  pinMode(FirePin, INPUT);
  pinMode(GasPin, INPUT);
  pinMode(Bazzer, OUTPUT);
  pinMode(WaterPamp, OUTPUT);

}

void loop() {
  FireState = analogRead(FirePin);
  GasState = analogRead(GasPin);

  Serial.print("Fire : ");
  Serial.println( FireState);

  Serial.print("Gas : ");
  Serial.println(GasState);
  

  if(FireState <= 200){
    digitalWrite(Bazzer, HIGH);
    digitalWrite(WaterPamp, HIGH);
    delay(1000);
    digitalWrite(Bazzer, LOW);
    digitalWrite(WaterPamp, LOW);
  }

 


  if(GasState <= 200 && GasFlag == 0){
    GasFlag = 1;
    digitalWrite(Bazzer, HIGH);
    delay(1000);
    digitalWrite(Bazzer, LOW);
  }


  if(GasState > 350){
    GasFlag = 0;
  }

}
