// Project 11 - Creating a Quick-Read Thermometer That Blinks the Temperature
#define LED 13
int blinks = 0;
void setup()
{
  pinMode(LED, OUTPUT);
}
int checkTemp()
{
  float voltage = 0;
  float celsius = 0;
  float hotTemp = 26;
  float coldTemp = 20;
  float sensor = 0;
  int result;
  // read the temperature sensor and convert the result to degrees Celsius
  sensor = analogRead(0);
  voltage = (sensor * 5000) / 1024; // convert raw sensor value to millivolts
  voltage = voltage - 500; // remove voltage offset
  celsius = voltage / 10; // convert millivolts to Celsius
  // act on temperature range
  if (celsius < coldTemp)
  {
    result = 2;
  }
  else if (celsius >= coldTemp && celsius <= hotTemp)
  {
    result = 4;
  }
  else
  {
    result = 6; // (celsius > hotTemp)
  }
  return result;
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
  blinks = checkTemp();
  blinkLED(blinks, 500);
  delay(2000);
}
