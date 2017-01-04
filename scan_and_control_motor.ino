int RFIDResetPin = 4;
int MotorStepPin = 2;
int tagID = 1234567890;

void setup(){
  Serial.begin(9600);
  pinMode(RFIDResetPin, OUTPUT);
  digitalWrite(RFIDResetPin, HIGH);
  pinMode(MotorStepPin, OUTPUT);
}

void loop(){
  int tag = 0;
  while(Serial.available()){
    int readByte = Serial.read();
    tag = (tag * 100) + readByte;
  }
  if(tag == tagID){
    for(int x = 0; x < 8000; x++){
      digitalWrite(MotorStepPin, HIGH); //Trigger one step forward
      delay(1);
      digitalWrite(MotorStepPin, LOW); //Pull step pin low so it can be triggered again
      delay(1);
    }
    delay(2000);
  }
}
