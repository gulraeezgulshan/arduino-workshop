// Project 64 - Building an Arduino Texter
#include <SerialGSM.h>
#include <SoftwareSerial.h>
SerialGSM cell(2, 3);
void setup()
{
  pinMode(7, INPUT);
  delay(30000); // wait for the GSM module
  cell.begin(9600);
}
void textSomeone()
{
  cell.Verbose(true); // used for debugging
  cell.Boot();
  cell.FwdSMS2Serial();
  cell.Rcpt("+xxxxxxxxxxx"); // replace xxxxxxxxxxx with the
  // recipient's cell number
  cell.Message("This is the contents of a text message");
  cell.SendSMS();
}
void loop()
{
  if (digitalRead(7) == HIGH)
  {
    textSomeone();
  }
  if (cell.ReceiveSMS())
  {
    Serial.println(cell.Message());
    cell.DeleteAllSMS();
  }
}
