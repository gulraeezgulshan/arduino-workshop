// Project 8 - Creating a Quick-Read Thermometer
// define the pins that the LEDs are connected to:
#define HOT 6
#define NORMAL 4
#define COLD 2
float voltage = 0;
float celsius = 0;

float hotTemp = 26;
float coldTemp = 20;
float sensor = 0;
void setup()
{
  pinMode(HOT, OUTPUT);
  pinMode(NORMAL, OUTPUT);
  pinMode(COLD, OUTPUT);
}

void loop()
{
  // read the temperature sensor and convert the result to degrees Celsius
  sensor = analogRead(0);
  voltage = (sensor * 5000) / 1024; // convert raw sensor value to millivolts
  voltage = voltage - 500; // remove voltage offset
  celsius = voltage / 100; // convert millivolts to Celsius
  // act on temperature range
  if ( celsius < coldTemp )
  {
    digitalWrite(COLD, HIGH);
    delay(1000);
    digitalWrite(COLD, LOW);
  }
  else if ( celsius > coldTemp && celsius <= hotTemp )
  {
    digitalWrite(NORMAL, HIGH);
    delay(1000);
    digitalWrite(NORMAL, LOW);
  }
  else
  {
    // celsius is > hotTemp
    digitalWrite(HOT, HIGH);
    delay(1000);
    digitalWrite(HOT, LOW);
  }
}
