// Project 51 - Creating an IR Remote Control Tank
int receiverpin = 11; // pin 1 of IR receiver to Arduino digital pin 11
#include <IRremote.h>
IRrecv irrecv(receiverpin); // create instance of 'irrecv'
decode_results results;
int m1speed = 6; // digital pins for speed control
int m2speed = 5;
int m1direction = 7; // digital pins for direction control
int m2direction = 4;
void setup()
{
  pinMode(m1direction, OUTPUT);
  pinMode(m2direction, OUTPUT);
  irrecv.enableIRIn(); // start IR receiver
}
void goForward(int duration, int pwm)
{
  digitalWrite(m1direction, HIGH); // forward
  digitalWrite(m2direction, HIGH); // forward
  analogWrite(m1speed, pwm); // at selected speed
  analogWrite(m2speed, pwm);
  delay(duration); // and duration
  analogWrite(m1speed, 0); // then stop
  analogWrite(m2speed, 0);
}
void goBackward(int duration, int pwm)
{
  digitalWrite(m1direction, LOW); // backward
  digitalWrite(m2direction, LOW); // backward
  analogWrite(m1speed, pwm); // at selected speed
  analogWrite(m2speed, pwm);
  delay(duration);
  analogWrite(m1speed, 0); // then stop
  analogWrite(m2speed, 0);
}
void rotateRight(int duration, int pwm)
{
  digitalWrite(m1direction, HIGH); // forward
  digitalWrite(m2direction, LOW); // backward
  analogWrite(m1speed, pwm); // at selected speed
  analogWrite(m2speed, pwm);
  delay(duration); // and duration
  analogWrite(m1speed, 0); // then stop
  analogWrite(m2speed, 0);
}
void rotateLeft(int duration, int pwm)
{
  digitalWrite(m1direction, LOW); // backward
  digitalWrite(m2direction, HIGH); // forward
  analogWrite(m1speed, pwm); // at selected speed
  analogWrite(m2speed, pwm);
  delay(duration); // and duration
  analogWrite(m1speed, 0); // then stop
  analogWrite(m2speed, 0);
}
// translateIR takes action based on IR code received, uses Sony IR codes
void translateIR()
{
  switch (results.value)
  {
    case 0x810: goForward(250, 255); break; // 2
    case 0xC10: rotateLeft(250, 255); break; // 4
    case 0xA10: rotateRight(250, 255); break; // 6
    case 0xE10: goBackward(250, 255); break; // 8
  }
}

void loop()
{
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    translateIR();
    for (int z = 0 ; z < 2 ; z++) // ignore the repeated codes
    {
      irrecv.resume(); // receive the next value
    }
  }
}
