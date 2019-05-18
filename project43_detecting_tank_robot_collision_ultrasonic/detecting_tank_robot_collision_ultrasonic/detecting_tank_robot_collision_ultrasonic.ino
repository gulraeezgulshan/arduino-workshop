// Project 43 - Detecting Tank Bot Collisions with an Ultrasonic Distance
// Sensor
int m1speed = 6; // digital pins for speed control
int m2speed = 5;
int m1direction = 7; // digital pins for direction control
int m2direction = 4;
int signal = 3;
boolean crash = false;
void setup()
{
  pinMode(m1direction, OUTPUT);
  pinMode(m2direction, OUTPUT);
  pinMode(signal, OUTPUT);
  delay(5000);
  Serial.begin(9600);
}
int getDistance()
// returns distance from Ping))) sensor in cm
{
  int distance;
  unsigned long pulseduration = 0;
  // get the raw measurement data from Ping)))
  // set pin as output so we can send a pulse
  pinMode(signal, OUTPUT);
  // set output to LOW
  digitalWrite(signal, LOW);
  delayMicroseconds(5);
  // send the 5uS pulse out to activate Ping)))
  digitalWrite(signal, HIGH);
  delayMicroseconds(5);
  digitalWrite(signal, LOW);
  // change the digital pin to input to read the incoming pulse
  pinMode(signal, INPUT);
  // measure the length of the incoming pulse
  pulseduration = pulseIn(signal, HIGH);
  // divide the pulse length in half
  pulseduration = pulseduration / 2;
  // convert to centimeters
  distance = int(pulseduration / 29);
  return distance;
}
void backUp()
{
  digitalWrite(m1direction, LOW); // go back
  digitalWrite(m2direction, LOW);
  delay(2000);
  digitalWrite(m1direction, HIGH); // go left
  digitalWrite(m2direction, LOW);
  analogWrite(m1speed, 200); // speed
  analogWrite(m2speed, 200);
  delay(2000);
  analogWrite(m1speed, 0); // speed
  analogWrite(m2speed, 0);
}
void goForward(int duration, int pwm)
{
  long a, b;
  int dist = 0;
  boolean move = true;
  a = millis();
  do
  {
    dist = getDistance();
    Serial.println(dist);
    if (dist < 10) // if less than 10cm from object
    {
      crash = true;
    }
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
  goForward(1000, 255);
}
