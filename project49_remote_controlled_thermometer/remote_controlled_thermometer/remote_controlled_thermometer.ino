// Project 49 - Building a Remote Control Thermometer
char a;
float voltage = 0;
float sensor = 0;
float celsius = 0;
float fahrenheit = 0;
float photocell = 0;
void setup()
{
  Serial.begin(9600);
}
void sendC()
{
  sensor = analogRead(0);
  voltage = ((sensor * 5000) / 1024);
  voltage = voltage - 500;
  celsius = voltage / 10;
  fahrenheit = ((celsius * 1.8) + 32);
  Serial.print("Temperature: ");
  Serial.print(celsius, 2);
  Serial.println(" degrees C");
}
void sendF()
{
  sensor = analogRead(0);
  voltage = ((sensor * 5000) / 1024);
  voltage = voltage - 500;
  celsius = voltage / 10;
  fahrenheit = ((celsius * 1.8) + 32);
  Serial.print("Temperature: ");
  Serial.print(fahrenheit, 2);
  Serial.println(" degrees F");
}
void getCommand()
{
  Serial.flush();
  while (Serial.available() == 0)
  {
    // do nothing until data arrives from XBee
  }
  while (Serial.available() > 0)
  {
    a = Serial.read(); // read the number in the serial buffer
  }
}
void loop()
{
  getCommand();// listen for command from PC
  switch (a)
  {
    case 'c':
      // send temperature in Celsius
      sendC();
      break;
    case 'f':
      // send temperature in Fahrenheit
      sendF();
      break;
  }
}
