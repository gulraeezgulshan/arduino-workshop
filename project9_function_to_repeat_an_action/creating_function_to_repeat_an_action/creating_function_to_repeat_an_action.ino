// Project 9 - Creating a Function to Repeat an Action
#define LED 13
#define del 200
void setup()
{
  pinMode(LED, OUTPUT);
}
void blinkLED()
{
  digitalWrite(LED, HIGH);
  delay(del);
  digitalWrite(LED, LOW);
  delay(del);
  digitalWrite(LED, HIGH);
  delay(del);
  digitalWrite(LED, LOW);
  delay(del);
}
void loop()
{
  blinkLED();
  delay(1000);
}
