// Project 63 - Building an Arduino Dialer
#include <SoftwareSerial.h>
SoftwareSerial cell(2, 3);
void setup()
{
  pinMode(7, INPUT);
  cell.begin(9600);
  delay(30000); // give the GSM module time to initialize network location
}
void callSomeone()
{
  cell.println("ATDxxxxxxxxxx"); // dial the phone number xxxxxxxxxx
  // change xxxxxxxxxx to your desired phone number (with area code)
  delay(20000); // wait 20 seconds.
  cell.println("ATH"); // end call
  delay(60000); // wait 60 seconds for GSM module
}
void loop()
{
  if (digitalRead(7) == HIGH)
  {
    callSomeone();
  }
}
