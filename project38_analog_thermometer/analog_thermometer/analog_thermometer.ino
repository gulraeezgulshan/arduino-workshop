// Project 38 - Building an Analog Thermometer
float voltage = 0;
float sensor = 0;
float currentC = 0;
int angle = 0;
#include <Servo.h>
Servo myservo;
void setup()
{
  myservo.attach(4);
}
int calculateservo(float temperature)
{
  float resulta;
  int resultb;
  resulta = -6 * temperature;
  resulta = resulta + 180;
  resultb = int(resulta);
  return resultb;
}
void loop()
{
  // read current temperature
  sensor = analogRead(0);
  voltage = (sensor * 5000) / 1024;
  voltage = voltage - 500;
  currentC = voltage / 10;
  // display current temperature on servo
  angle = calculateservo(currentC);
  // convert temperature to a servo position
  if (angle >= 0 && angle <= 30)
  {
    myservo.write(angle); // set servo to temperature
    delay(1000);
  }
}
