// Project 22 - Creating Images on an LED Matrix
#define DATA 6 // connect to pin 14 on the 74HC595
#define LATCH 8 // connect to pin 12 on the 74HC595
#define CLOCK 10 // connect to pin 11 on the 74HC595
void setup()
{
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
  randomSeed(analogRead(0));
}

int binary[] = {1, 2, 4, 8, 16, 32, 64, 128};
int r, c = 0;

void setLED(int row, int column, int del)
{
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, ~binary[column]); // columns
  shiftOut(DATA, CLOCK, MSBFIRST, binary[row]); // rows
  digitalWrite(LATCH, HIGH);
  delay(del);
}
void loop()
{
  r = random(8);
  c = random(8);
  setLED(r, c, 1); // set a random row and column on for 1 millisecond
}
