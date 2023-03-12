const int buttonPin = 2; 
int buttonState = 0; 
const int ledPin = 13; 

void setup()
{
  // start serial port at 9600 bps:
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}



void loop()
{ 
  buttonState = digitalRead(buttonPin);
  char inByte = 0;
  // if we get a valid byte, read analog ins:
  if (buttonState == HIGH) {
    // get incoming byte:
    //inByte = Serial.read();
    digitalWrite(ledPin, HIGH);
    // byte read, send three characters
    //Serial.print("$");
    Serial.write("@");
   
  }
  else{
    digitalWrite(ledPin, LOW);
    //Serial.print("0");
  }
}

