// Project 54 - Using an External EEPROM
#include <Wire.h>
#define chip1 0x50
unsigned int pointer;
byte d = 0;
void setup()
{
  Serial.begin(9600);
  Wire.begin();
}
void writeData(int device, unsigned int address, byte data)
// writes a byte of data 'data' to the EEPROM at I2C address 'device'
// in memory location 'address'
{
  Wire.beginTransmission(device);
  Wire.write((byte)(address >> 8)); // left part of pointer address
  Wire.write((byte)(address & 0xFF)); // and the right
  Wire.write(data);
  Wire.endTransmission();
  delay(10);
}
byte readData(int device, unsigned int address)
// reads a byte of data from memory location 'address'
// in chip at I2C address 'device'
{
  byte result; // returned value
  Wire.beginTransmission(device);
  Wire.write((byte)(address >> 8)); // left part of pointer address
  Wire.write((byte)(address & 0xFF)); // and the right
  Wire.endTransmission();
  Wire.requestFrom(device, 1);
  result = Wire.read();
  return result; // and return it as a result of the function readData
}
void loop()
{
  Serial.println("Writing data...");
  for (int a = 0; a < 20; a++)
  {
    writeData(chip1, a, a);
  }

  Serial.println("Reading data...");
  for (int a = 0; a < 20; a++)
  {
    Serial.print("EEPROM position ");
    Serial.print(a);
    Serial.print(" holds ");
    d = readData(chip1, a);
    Serial.println(d, DEC);
  }
}
