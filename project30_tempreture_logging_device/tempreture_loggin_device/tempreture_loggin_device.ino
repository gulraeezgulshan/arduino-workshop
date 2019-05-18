// Project 30 - Creating a Temperature-Logging Device
#include <SD.h>
float sensor, voltage, celsius;
void setup()
{
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  pinMode(10, OUTPUT);
  // check that the microSD card exists and can be used
  if (!SD.begin(8))
  {
    Serial.println("Card failed, or not present");
    // stop sketch
    return;
  }
  Serial.println("microSD card is ready");
}
void loop()
{
  // create the file for writing
  File dataFile = SD.open("DATA.TXT", FILE_WRITE);
  // if the file is ready, write to it:
  if (dataFile)
  {
    for ( int a = 0 ; a < 481 ; a++ ) // 480 minutes in 8 hours
    {
      sensor = analogRead(0);
      voltage = (sensor * 5000) / 1024; // convert raw sensor value to
      // millivolts
      voltage = voltage - 500;
      celsius = voltage / 10;
      dataFile.print(" Log: ");
      dataFile.print(a, DEC);
      dataFile.print(" Temperature: ");
      dataFile.print(celsius, 2);
      dataFile.println(" degrees C");
      delay(599900); // wait just under one minute
    }
    dataFile.close(); // mandatory
    Serial.println("Finished!");
    do {} while (1);
  }
}
