// Project 36 - Creating a Three-Zone Touch Switch
int x, y = 0;
void setup()
{
  pinMode(3, OUTPUT);
}
void switchOn()
{
  digitalWrite(3, HIGH);
  delay(200);
}
void switchOff()
{
  digitalWrite(3, LOW);
  delay(200);
}
void setBrightness()
{
  int xx, bright;
  float br;
  xx = x - 100;
  br = (800 - xx) / 255;
  bright = int(br);
  analogWrite(3, bright);
}
int readX() // returns the value of the touchscreen's x-axis
{
  int xr = 0;
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A3, OUTPUT);
  digitalWrite(A1, LOW); // set A1 to GND
  digitalWrite(A3, HIGH); // set A3 as 5V
  delay(5);
  xr = analogRead(0);
  return xr;
}
int readY() // returns the value of the touchscreen's y-axis
{
  int yr = 0;
  pinMode(A0, OUTPUT); // A0
  pinMode(A1, INPUT); // A1
  pinMode(A2, OUTPUT); // A2
  pinMode(A3, INPUT); // A3
  digitalWrite(A0, LOW); // set A0 to GND
  digitalWrite(A2, HIGH); // set A2 as 5V
  delay(5);
  yr = analogRead(1);
  return yr;
}
void loop()
{
  x = readX();
  y = readY();
  // test for ON
  if (x <= 500 && x >= 100 && y >= 150 && y < 375)
  {
    switchOn();
  }

  // test for OFF
  if (x > 500 && x <= 900 && y >= 150 && y < 375)
  {
    switchOff();
  }
  // test for brightness
  if (y >= 375 && y <= 900)
  {
    setBrightness();
  }
}
