// Project 56 - Using a Digital Rheostat
#include "SPI.h" // necessary library
int ss = 10; // using digital pin 10 for SPI slave select
int del = 200; // used for delaying the steps between LED brightness values
void setup()
{
  SPI.begin();
  pinMode(ss, OUTPUT); // we use this for the SS pin
  digitalWrite(ss, HIGH); // the SS pin is active low, so set it up high first

  SPI.setBitOrder(MSBFIRST);
  // our MCP4162 requires data to be sent MSB (most significant byte) first
}
void setValue(int value)
{
  digitalWrite(ss, LOW);
  SPI.transfer(0); // send the command byte
  SPI.transfer(value); // send the value (0 to 255)
  digitalWrite(ss, HIGH);
}
void loop()
{
  for (int a = 0; a < 256; a++)
  {
    setValue(a);
    delay(del);
  }
  for (int a = 255; a >= 0; a--)
  {
    setValue(a);
    delay(del);
  }
}
