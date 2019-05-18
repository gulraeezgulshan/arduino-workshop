// Project 44 - Creating a Simple GPS Receiver
#include <TinyGPS.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd( 8, 9, 4, 5, 6, 7 );
// Create an instance of the TinyGPS object
TinyGPS gps;
void getgps(TinyGPS &gps);
void setup()
{
  Serial.begin(4800);
  lcd.begin(16, 2);
}
void getgps(TinyGPS &gps)
// The getgps function will display the required data on the LCD
{
  float latitude, longitude;
  //decode and display position data
  gps.f_get_position(&latitude, &longitude);
  lcd.setCursor(0, 0);
  lcd.print("Lat:");
  lcd.print(latitude, 5);
  lcd.print(" ");
  lcd.setCursor(0, 1);
  lcd.print("Long:");
  lcd.print(longitude, 5);
  lcd.print(" ");
  delay(3000); // wait for 3 seconds
  lcd.clear();
}
void loop()
{
  byte a;
  if ( Serial.available() > 0 ) // if there is data coming into the serial line
  {
    a = Serial.read(); // get the byte of data
    if (gps.encode(a)) // if there is valid GPS data...
    {
      getgps(gps); // grab the data and display it on the LCD
    }
  }
}
