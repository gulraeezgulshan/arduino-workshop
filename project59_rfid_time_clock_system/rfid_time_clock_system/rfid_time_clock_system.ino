// Project 59 - Creating an RFID Time-Clock System
#include "Wire.h" // for RTC
#define DS3232_I2C_ADDRESS 0x68
#include "SD.h" // for SD card
#include <LiquidCrystal.h>
LiquidCrystal lcd( 8, 9, 4, 5, 6, 7 );
int data1 = 0;
// Use Listing 16-1 to find your tag numbers
int Mary[14] = {
  2, 52, 48, 48, 48, 56, 54, 67, 54, 54, 66, 54, 66, 3
};
int John[14] = {
  2, 52, 48, 48, 48, 56, 54, 66, 49, 52, 70, 51, 56, 3
};
int newtag[14] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
}; // used for read comparisons
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
void setDS3232time(byte second, byte minute, byte hour, byte dayOfWeek, byte
                   dayOfMonth, byte month, byte year)
{
  // Sets time and date data to DS3232
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
                    byte *dayOfWeek,
                    byte *dayOfMonth,
                    byte *month,
                    byte *year)

{
  Wire.beginTransmission(DS3232_I2C_ADDRESS);
  Wire.write(0); // set DS3232 register pointer to 00h
  Wire.endTransmission();
  Wire.requestFrom(DS3232_I2C_ADDRESS, 7);
  // Request seven bytes of data from DS3232 starting from register 00h
  *second = bcdToDec(Wire.read() & 0x7f);
  *minute = bcdToDec(Wire.read());
  *hour = bcdToDec(Wire.read() & 0x3f);
  *dayOfWeek = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month = bcdToDec(Wire.read());
  *year = bcdToDec(Wire.read());
}
void setup()
{
  Serial.flush(); // need to flush serial buffer
  Serial.begin(9600);
  Wire.begin();
  lcd.begin(16, 2);
  // set the initial time here:
  // DS3232 seconds, minutes, hours, day, date, month, year
  //setDS3232time(0, 27, 0, 5, 15, 11, 12);
  // Check that the microSD card exists and can be used
  if (!SD.begin(8))
  {
    lcd.print("uSD card failure");
    // stop the sketch
    return;
  }
  lcd.print("uSD card OK");
  delay(1000);
  lcd.clear();
}
// Compares two arrays and returns true if identical.
// This is good for comparing tags.
boolean comparetag(int aa[14], int bb[14])
{
  boolean ff = false;
  int fg = 0;
  for (int cc = 0; cc < 14; cc++)
  {
    if (aa[cc] == bb[cc])
    {
      fg++;
    }
  }
  if (fg == 14)
  {
    ff = true; // all 14 elements in the array match each other
  }

  return ff;
}
void wipeNewTag()
{
  for (int i = 0; i <= 14; i++)
  {
    newtag[i] = 0;
  }
}
void loop()
{
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  if (Serial.available() > 0) // if a read has been attempted
  {
    // Read the incoming number on serial RX
    delay(100); // Allow time for the data to come in from the serial buffer
    for (int z = 0; z < 14; z++) // read the rest of the tag
    {
      data1 = Serial.read();
      newtag[z] = data1;
    }
    Serial.flush(); // stops multiple reads
    // retrieve data from DS3232
    readDS3232time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
                   &year);
  }
  //now do something based on the tag type
  if (comparetag(newtag, Mary) == true)
  {
    lcd.print("Hello Mary ");
    File dataFile = SD.open("DATA.TXT", FILE_WRITE);
    if (dataFile)
    {
      dataFile.print("Mary ");
      dataFile.print(hour);
      dataFile.print(":");
      if (minute < 10) {
        dataFile.print("0");
      }
      dataFile.print(minute);
      dataFile.print(":");
      if (second < 10) {
        dataFile.print("0");
      }
      dataFile.print(second);
      dataFile.print(" ");
      dataFile.print(dayOfMonth);
      dataFile.print("/");
      dataFile.print(month);
      dataFile.print("/");
      dataFile.print(year);
      dataFile.println();
      dataFile.close();
    }

    delay(1000);
    lcd.clear();
    wipeNewTag();
  }
  if (comparetag(newtag, John) == true)
  {
    lcd.print("Hello John ");
    File dataFile = SD.open("DATA.TXT", FILE_WRITE);
    if (dataFile)
    {
      dataFile.print("John ");
      dataFile.print(hour);
      dataFile.print(":");
      if (minute < 10) {
        dataFile.print("0");
      }
      dataFile.print(minute);
      dataFile.print(":");
      if (second < 10) {
        dataFile.print("0");
      }
      dataFile.print(second);
      dataFile.print(" ");
      dataFile.print(dayOfMonth);
      dataFile.print("/");
      dataFile.print(month);
      dataFile.print("/");
      dataFile.print(year);
      dataFile.println();
      dataFile.close();
    }
    delay(1000);
    lcd.clear();
    wipeNewTag();
  }
}
