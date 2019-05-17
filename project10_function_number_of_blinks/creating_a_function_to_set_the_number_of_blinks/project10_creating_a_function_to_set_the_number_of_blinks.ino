// Project 10 - Creating a Function to Set the Number of Blinks
#define LED 13
void setup()
{
  pinMode(LED, OUTPUT);
}
void blinkLED(int cycles, int del)
{
  for ( int z = 0 ; z < cycles ; z++ )
  {
    digitalWrite(LED, HIGH);
    delay(del);
    digitalWrite(LED, LOW);
    delay(del);
  }
}
void loop()
{
  blinkLED(12, 100);
  delay(1000);
}
