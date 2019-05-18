// Project 26 - Seeing the Text Functions in Action
#include <glcd.h> // include the graphics LCD library
#include "fonts/SystemFont5x7.h" // include the standard character fonts for it

int j = 7;
void setup()
{
  GLCD.Init(NON_INVERTED);
  GLCD.ClearScreen();
  GLCD.SelectFont(System5x7);
}
void loop()
{
  GLCD.ClearScreen();
  GLCD.CursorTo(1, 1);
  GLCD.Puts("Hello, world.");
  GLCD.CursorTo(1, 2);
  GLCD.Puts("I hope you are ");
  GLCD.CursorTo(1, 3);
  GLCD.Puts("enjoying this");
  GLCD.CursorTo(1, 4);
  GLCD.Puts("book. ");
  GLCD.CursorTo(1, 5);
  GLCD.Puts("This is from ");
  GLCD.CursorTo(1, 6);
  GLCD.Puts("chapter ");
  GLCD.PrintNumber(j);
  GLCD.Puts(".");
  do {} while (1);
}
