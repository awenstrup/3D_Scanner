int a = 0;

void setup()
{ 
  //
  // start the serial port
  //
  long baudRate = 9600;       // NOTE1: The baudRate for sending & receiving programs must match
  Serial.begin(baudRate);     // NOTE2: Set the baudRate to 115200 for faster communication
}

void loop() 
{  

    a = analogRead(A0);
    Serial.println(a);
    

    //
    // delay after sending data so the serial connection is not over run
    //
    delay(1000);
}
