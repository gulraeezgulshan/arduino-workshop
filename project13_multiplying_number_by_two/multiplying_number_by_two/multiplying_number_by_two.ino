// Project 13 - Multiplying a Number by Two
int number;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  number = 0; // zero the incoming number ready for a new read
  Serial.flush(); // clear any "junk" out of the serial buffer before waiting
  while (Serial.available() == 0)
  {
    // do nothing until something enters the serial buffer
  }
  while (Serial.available() > 0)
  {
    number = Serial.read() - '0';
    // read the number in the serial buffer,
    // remove the ASCII text offset for zero: '0'
  }
  // Show me the number!
  Serial.print("You entered: ");
  Serial.println(number);
  Serial.print(number);
  Serial.print(" multiplied by two is ");
  number = number * 2;
  Serial.println(number);
}
