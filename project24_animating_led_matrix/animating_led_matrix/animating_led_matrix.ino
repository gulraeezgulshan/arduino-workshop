// Project 24 - Animating an LED Matrix
#define DATA 6 // connect to pin 14 on the 74HC595
#define LATCH 8 // connect to pin 12 on the 74HC595
#define CLOCK 10 // connect to pin 11 on the 74HC595

byte smile[] = {B00000000, B00000110, B01000110, B00000000, B00011000,
                B00000000, B11000011, B01111110
               };
int binary[] = {1, 2, 4, 8, 16, 32, 64, 128};
void setup()
{
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
}

void loop()
{
  int a, hold, shift;
  for ( shift = 0 ; shift < 9 ; shift++ )
  {
    for ( hold = 0 ; hold < 25 ; hold++ )
    {
      for ( a = 0 ; a < 8 ; a++ )
      {
        digitalWrite(LATCH, LOW);
        shiftOut(DATA, CLOCK, MSBFIRST, ~smile[a] >> shift); // columns
        shiftOut(DATA, CLOCK, LSBFIRST, binary[a]); // rows
        digitalWrite(LATCH, HIGH);
        delay(1);
      }
    }
  }
}
