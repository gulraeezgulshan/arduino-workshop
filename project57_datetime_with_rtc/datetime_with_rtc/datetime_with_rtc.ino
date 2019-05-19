// Project 57 - Adding and Displaying Time and Date with an RTC
#include "Wire.h"
#define DS3232_I2C_ADDRESS 0x68
// Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val)
{
  return ( (val / 10 * 16) + (val % 10) );
}
// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
  return ( (val / 16 * 10) + (val % 16) );
}
void setup()
{
  Wire.begin();
  Serial.begin(9600);
  // set the initial time here:
  // DS3232 seconds, minutes, hours, day, date, month, year
  setDS3232time(0, 56, 23, 3, 30, 10, 12);
}
void setDS3232time(byte second, byte minute, byte hour, byte dayOfWeek, byte
                   dayOfMonth, byte month, byte year)
{
  // sets time and date data to DS3232
  Wire.beginTransmission(DS3232_I2C_ADDRESS);
  Wire.write(0); // set next input to start at the seconds register
  Wire.write(decToBcd(second)); // set seconds
  Wire.write(decToBcd(minute)); // set minutes
  Wire.write(decToBcd(hour)); // set hours
  Wire.write(decToBcd(dayOfWeek)); // set day of week (1=Sunday, 7=Saturday)
  Wire.write(decToBcd(dayOfMonth)); // set date (1 to 31)
  Wire.write(decToBcd(month)); // set month
  Wire.write(decToBcd(year)); // set year (0 to 99)
  Wire.endTransmission();
}
void readDS3232time(byte *second,
                    byte *minute,
                    byte *hour,
