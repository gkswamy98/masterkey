int RFIDResetPin = 4;

void setup(){
  Serial.begin(9600);
  pinMode(RFIDResetPin, OUTPUT);
  digitalWrite(RFIDResetPin, HIGH);
}

void loop(){
  int tag = 0;
  while(Serial.available()){
    int readByte = Serial.read();
    tag = (tag * 100) + readByte;
  }
  Serial.println(tag);
}
