// Project 15 - Creating an Electronic Die
void setup()
{
  randomSeed(analogRead(0)); // seed the random number generator
  for ( int z = 1 ; z < 7 ; z++ ) // LEDs on pins 1-6 are output
  {
    pinMode(z, OUTPUT);
  }
}
void randomLED(int del)
{
  int r;
  r = random(1, 7); // get a random number from 1 to 6
  digitalWrite(r, HIGH); // output to the matching LED on digital pin 1-6
  if (del > 0)
  {
    delay(del); // hold the LED on for the delay received
  }
  else if (del == 0)
  {
    do // the delay entered was zero, hold the LED on
      forever
      {}
    while (1);
  }
  digitalWrite(r, LOW); // turn off the LED
}
void loop()
{
  int a;
  // cycle the LEDs around for effect
  for ( a = 0 ; a < 100 ; a++ )
  {
    randomLED(50);
  }
  // slow down
  for ( a = 1 ; a <= 10 ; a++ )
  {
    randomLED(a * 100);
  }
  // and stop at the final random number and LED
  randomLED(0);
}
