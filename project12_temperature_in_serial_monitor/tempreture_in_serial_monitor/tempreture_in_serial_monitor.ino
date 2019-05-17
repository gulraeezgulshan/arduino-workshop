// Project 12 - Displaying the Temperature in the Serial Monitor
float celsius = 0;
float fahrenheit = 0;
void setup()
{
  Serial.begin(9600);
}
void findTemps()
{
  float voltage = 0;
  float sensor = 0;

  // read the temperature sensor and convert the result to degrees C and F
  sensor = analogRead(0);
  voltage = (sensor * 5000) / 1024; // convert the raw sensor value to millivolts
  voltage = voltage - 500; // remove the voltage offset
  celsius = voltage / 10; // convert millivolts to Celsius
  fahrenheit = (1.8 * celsius) + 32; // convert Celsius to Fahrenheit
}
void displayTemps()
{
  Serial.print("Temperature is ");
  Serial.print(celsius, 2);
  Serial.print(" deg. C / ");
  Serial.print(fahrenheit, 2);
  Serial.println(" deg. F");
  // use .println here so the next reading starts on a new line
}
void loop()
{
  findTemps();
  displayTemps();
  delay(1000);
}
