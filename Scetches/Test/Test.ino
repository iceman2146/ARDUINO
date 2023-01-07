char inChar;
int potVal;
#define redLed 12
#define greenLed 13
#define InputPort A0
void setup() {
  // put your setup code here, to run once:
  pinMode(InputPort,INPUT);
  pinMode(redLed, OUTPUT);
  digitalWrite(redLed, LOW);
  pinMode(greenLed, OUTPUT);
  digitalWrite(greenLed, LOW);
  Serial.begin(9600);
}

void loop() {
  potVal=analogRead(InputPort);
  byte lBuffer[] = {
      byte(potVal & 0xff),
      byte(potVal >> 8 & 0xff),
      byte(potVal >> 16 & 0xff),
      byte(potVal >> 24 & 0xff)
    };
  //Serial.println(potVal); 
  // put your main code here, to run repeatedly:
  delay(100);
  while (Serial.available()) {
    inChar = Serial.read();
    
    //todo
    //todoToUE();
    todoFromUE(lBuffer);
 
  }
}
void todoFromUE(byte lBuffer[]) {
  if (inChar == 'r') {
    //Serial.println("RED");
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
  } else if (inChar == 'g') {
    //Serial.println("GREEN");
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
  } 
  else if (inChar=='t'){
    Serial.write(lBuffer,4); 
  }
  
}
