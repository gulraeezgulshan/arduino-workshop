// Project 1 - Creating a Blinking LED Wave
void setup()
{
  pinMode(2, OUTPUT); // LED 1 control pin is set up as an output
  pinMode(3, OUTPUT); // same for LED 2 to LED 5
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  digitalWrite(2, HIGH); // Turn LED 1 on
  delay(500); // wait half a second
  digitalWrite(2, LOW); // Turn LED 1 off
  digitalWrite(3, HIGH); // and repeat for LED 2 to 5
  delay(500);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(500);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(500);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(500);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  delay(500);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  delay(500);
  digitalWrite(4, LOW);
  digitalWrite(3, HIGH);
  delay(500);
  digitalWrite(3, LOW);
}
