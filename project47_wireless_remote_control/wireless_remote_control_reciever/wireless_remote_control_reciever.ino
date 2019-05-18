// Project 47 - Creating a Wireless Remote Control, Receiver Sketch
#include <VirtualWire.h>
uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;
void setup()
{
  vw_set_ptt_inverted(true); // Required for RF link modules
  vw_setup(300);
  vw_set_rx_pin(8);
  vw_rx_start();
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}
void loop()
{
  if (vw_get_message(buf, &buflen))
  {
    switch (buf[0])
    {
      case 'a':
        digitalWrite(6, HIGH);
        break;
      case 'b':
        digitalWrite(6, LOW);
        break;
      case 'c':
        digitalWrite(7, HIGH);
        break;
      case 'd':
        digitalWrite(7, LOW);
        break;
    }
  }
}
