// Project 21 – Creating an LED Matrix
#define DATA 6 // connect to pin 14 on the 74HC595
#define LATCH 8 // connect to pin 12 on the 74HC595
#define CLOCK 10 // connect to pin 11 on the 74HC595

void setup()
{
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
}

void loop()
{
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, ~B10101010); // columns
  shiftOut(DATA, CLOCK, MSBFIRST, B10101010); // rows
  digitalWrite(LATCH, HIGH);
  do {} while (1); // do nothing
}
