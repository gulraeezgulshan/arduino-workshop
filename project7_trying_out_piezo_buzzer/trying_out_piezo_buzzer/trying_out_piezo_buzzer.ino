// Project 7 - Trying Out a Piezo Buzzer

#define PIEZO 3 // pin 3 is capable of PWM output to drive tones
int del = 500;
void setup()
{
  pinMode(PIEZO, OUTPUT);
}
void loop()
{
  analogWrite(PIEZO, 128); // 50 percent duty cycle tone to the piezo
  delay(del);
  digitalWrite(PIEZO, LOW); // turn the piezo off
  delay(del);
}
