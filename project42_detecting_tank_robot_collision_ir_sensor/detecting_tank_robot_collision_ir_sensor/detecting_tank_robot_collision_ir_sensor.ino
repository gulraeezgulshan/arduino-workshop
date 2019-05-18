// Project 42 - Detecting Tank Bot Collisions with IR Distance Sensor
int m1speed = 6; // digital pins for speed control
int m2speed = 5;
int m1direction = 7; // digital pins for direction control
int m2direction = 4;
boolean crash = false;
void setup()
{
  pinMode(m1direction, OUTPUT);
  pinMode(m2direction, OUTPUT);
  delay(5000);
}
void backUp()
{
  digitalWrite(m1direction, LOW); // reverse
  digitalWrite(m2direction, LOW); // reverse
  analogWrite(m1speed, 200);// speed
  analogWrite(m2speed, 200);
  delay(2000);
  analogWrite(m1speed, 0);// speed
  analogWrite(m2speed, 0);
}
void checkDistance()
{
  if (analogRead(0) > 460)
  {
    crash = true;
  }
}
void goForward(int duration, int pwm)
{
  long a, b;
  boolean move = true;
  a = millis();
  do
  {
    checkDistance();
    if (crash == false)
    {
      digitalWrite(m1direction, HIGH); // forward
      digitalWrite(m2direction, HIGH); // forward
      analogWrite(m1speed, pwm); // speed
      analogWrite(m2speed, pwm);
    }
    if (crash == true)
    {
      backUp();

      crash = false;
    }
    b = millis() - a;
    if (b >= duration)
    {
      move = false;
    }
  } while (move != false);
  // stop motors
  analogWrite(m1speed, 0);
  analogWrite(m2speed, 0);
}
void loop()
{
  goForward(5000, 255);
  delay(2000);
}
