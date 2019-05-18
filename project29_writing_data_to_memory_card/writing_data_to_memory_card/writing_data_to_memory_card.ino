// Project 29 - Writing Data to the Memory Card
int b = 0;
#include <SD.h>
void setup()
{
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  pinMode(10, OUTPUT);
  // check that the microSD card exists and is usable
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
    for ( int a = 0 ; a < 11 ; a++ )
    {
      dataFile.print(a);
      dataFile.print(" multiplied by two is ");
      b = a * 2;
      dataFile.println(b, DEC);
    }
    dataFile.close(); // close the file once the system has finished with it
    // (mandatory)
  }
  // if the file isn't ready, show an error:
  else
  {
    Serial.println("error opening DATA.TXT");
  }
  Serial.println("finished");
  do {} while (1);
}
