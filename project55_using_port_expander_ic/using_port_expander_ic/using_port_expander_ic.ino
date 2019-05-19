// Project 55 - Using a Port Expander IC
#include "Wire.h"
#define mcp23017 0x20
void setup()
{
  Wire.begin(); // activate I2C bus
  // setup MCP23017
  // set I/O pins to outputs
  Wire.beginTransmission(mcp23017);
  Wire.write(0x00); // IODIRA register
  Wire.write(0x00); // set all of bank A to outputs
  Wire.write(0x00); // set all of bank B to outputs
  Wire.endTransmission();
}
void loop()
{
  Wire.beginTransmission(mcp23017);
  Wire.write(0x12);
  Wire.write(255); // bank A
  Wire.write(255); // bank B
  Wire.endTransmission();
  delay(1000);
  Wire.beginTransmission(mcp23017);
  Wire.write(0x12);
  Wire.write(0); // bank A
  Wire.write(0); // bank B
  Wire.endTransmission();
  delay(1000);
}
