// Project 35 - Creating a Two-Zone On/Off Touch Switch
int x, y = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(10, OUTPUT);
}
void switchOn()
{
  digitalWrite(10, HIGH);
  Serial.print("Turned ON at X = ");
  Serial.print(x);
  Serial.print(" Y = ");
  Serial.println(y);
  delay(200);
}
void switchOff()
{
  digitalWrite(10, LOW);
  Serial.print("Turned OFF at X = ");
  Serial.print(x);
  Serial.print(" Y = ");
  Serial.println(y);
  delay(200);
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
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT);
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
  if (x <= 900 && x >= 500)
  {
    switchOn();
  }
  // test for OFF
  if (x < 500 && x >= 100)
  {
    switchOff();
  }
}
