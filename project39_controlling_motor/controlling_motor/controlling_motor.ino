// Project 39 - Controlling the Motor
void setup()
{
  pinMode(5, OUTPUT);
}
void loop()
{
  for (int a = 0; a < 256; a++)
  {
    analogWrite(5, a);
    delay(100);
  }
  delay(5000);
  for (int a = 255; a >= 0; a--)
  {
    analogWrite(5, a);
    delay(100);
  }
  delay(5000);
}
