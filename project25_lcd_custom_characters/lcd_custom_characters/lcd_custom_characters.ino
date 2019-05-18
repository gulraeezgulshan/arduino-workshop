// Project 25 - Defining Custom Characters
#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 5, 6, 7, 8, 9); // pins for RS, E, DB4, DB5, DB6, DB7
byte a[8] = { B00000,
              B01010,
              B01010,
              B00000,
              B00100,
              B10001,
              B01110,
              B00000
            };
void setup()
{
  lcd.begin(16, 2);
  lcd.createChar(0, a);
}
void loop()
{
  lcd.write(0); // write the custom character 0 to the next cursor position
}
