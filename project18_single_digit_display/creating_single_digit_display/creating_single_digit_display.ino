// Project 18 - Creating a Single-Digit Display
#define DATA 6 // connect to pin 14 on the 74HC595
#define LATCH 8 // connect to pin 12 on the 74HC595
#define CLOCK 10 // connect to pin 11 on the 74HC595
// set up the array with the segments for 0 to 9, A to F (from Table 6-2)
int digits[] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246, 238, 62, 156,
                122, 158, 142
               };
void setup()
{
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
}
void loop()
{
  int i;
  for ( i = 0 ; i < 16 ; i++ ) // display digits 0-9, A-F
  {
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, digits[i]);
    digitalWrite(LATCH, HIGH);
    delay(250);
  }
  for ( i = 0 ; i < 16 ; i++ ) // display digits 0-9, A-F with DP
  {
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, digits[i] + 1); // +1 is to turn on the DP bit
    digitalWrite(LATCH, HIGH);
    delay(250);
  }
}
