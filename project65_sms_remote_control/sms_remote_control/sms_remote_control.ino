// Project 65 - Setting Up an SMS Remote Control
#include <SoftwareSerial.h>
SoftwareSerial cell(2, 3);
char inchar;
void setup()
{
  // set up digital output pins to control
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  digitalWrite(10, LOW); // default state for I/O pins at power-up or reset,
  digitalWrite(11, LOW); // change as you wish.
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  //Initialize the GSM module serial port for communication.
  cell.begin(9600);
  delay(30000);
  cell.println("AT+CMGF=1");
  delay(200);
  cell.println("AT+CNMI=3,3,0,0");
  delay(200);
}
void loop()
{
  // If a character comes in from the cellular module...
  if (cell.available() > 0)
  {
    inchar = cell.read();
    if (inchar == '#') // the start of our command
    {
      delay(10);
      inchar = cell.read();
      if (inchar == 'a')
      {
        delay(10);
        inchar = cell.read();
        if (inchar == '0')
        {
          digitalWrite(10, LOW);
        }
        else if (inchar == '1')
        {
          digitalWrite(10, HIGH);
        }
        delay(10);
        inchar = cell.read();
        if (inchar == 'b')
        {
          inchar = cell.read();
          if (inchar == '0')
          {
            digitalWrite(11, LOW);
          }
          else if (inchar == '1')
          {
            digitalWrite(11, HIGH);
          }
          delay(10);
          inchar = cell.read();
          if (inchar == 'c')
          {
            inchar = cell.read();
            if (inchar == '0')
            {
              digitalWrite(12, LOW);
            }
            else if (inchar == '1')
            {
              digitalWrite(12, HIGH);
            }
            delay(10);
            inchar = cell.read();
            if (inchar == 'd')
            {
              delay(10);
              inchar = cell.read();
              if (inchar == '0')
              {
                digitalWrite(13, LOW);
              }
              else if (inchar == '1')
              {
                digitalWrite(13, HIGH);
              }
              delay(10);
            }
          }
          cell.println("AT+CMGD=1,4"); // delete all SMS
        }
      }
    }
  }
}
