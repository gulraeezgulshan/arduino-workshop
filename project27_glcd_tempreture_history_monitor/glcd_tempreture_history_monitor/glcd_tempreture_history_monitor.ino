// Project 27 - Creating a Temperature History Monitor
#include <glcd.h> // include the graphics LCD library
#include <fonts/SystemFont5x7.h> // include the standard character fonts for it
int tcurrent;
int tempArray[100];
void setup()
{
  GLCD.Init(NON_INVERTED); // configure GLCD
  GLCD.ClearScreen(); // turn off all GLCD pixels
  GLCD.SelectFont(System5x7);
}
void getTemp() // function to read temperature from TMP36
{
  float sum = 0;
  float voltage = 0;
  float sensor = 0;
  float celsius;
  // read the temperature sensor and convert the result to degrees C
  sensor = analogRead(5);
  voltage = (sensor * 5000) / 1024;
  voltage = voltage - 500;
  celsius = voltage / 10;
  tcurrent = int(celsius);
  // insert the new temperature at the start of the array of past temperatures
  for (int a = 99 ; a >= 0 ; --a )
  {
    tempArray[a] = tempArray[a - 1];
  }
  tempArray[0] = tcurrent;
}
void drawScreen() // generate GLCD display effects
{
  int q;
  GLCD.ClearScreen();
  GLCD.CursorTo(5, 0);
  GLCD.Puts("Current:");
  GLCD.PrintNumber(tcurrent);
  GLCD.CursorTo(0, 1);
  GLCD.PrintNumber(40);
  GLCD.CursorTo(0, 2);
  GLCD.PrintNumber(32);
  GLCD.CursorTo(0, 3);
  GLCD.PrintNumber(24);
  GLCD.CursorTo(0, 4);
  GLCD.PrintNumber(16);
  GLCD.CursorTo(1, 5);
  GLCD.PrintNumber(8);
  GLCD.CursorTo(1, 6);
  GLCD.PrintNumber(0);
  for (int a = 28 ; a < 127 ; a++)
  {
    q = (55 - tempArray[a - 28]);
    GLCD.SetDot(a, q, BLACK);
  }
}
void loop()
{
  getTemp();
  drawScreen();
  for (int a = 0 ; a < 20 ; a++) // wait 20 minutes until the next reading
  {
    delay(60000); // wait 1 minute
  }
}
