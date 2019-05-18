// Project 47 - Creating a Wireless Remote Control, Transmitter Sketch
#include <VirtualWire.h>
uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;
const char *on2 = "a";
const char *off2 = "b";
const char *on3 = "c";
const char *off3 = "d";
void setup()
{
  vw_set_ptt_inverted(true); // Required for RF Link modules
  vw_setup(300); // set data speed
  vw_set_tx_pin(8);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}
void loop()
{
  if (digitalRead(2) == HIGH)
  {
    vw_send((uint8_t *)on2, strlen(on2)); // send the data out to the world
    vw_wait_tx(); // wait a moment
    delay(200);
  }
  if (digitalRead(2) == LOW)
  {
    vw_send((uint8_t *)off2, strlen(off2));
    vw_wait_tx();
    delay(200);
  }
  if (digitalRead(3) == HIGH)
  {
    vw_send((uint8_t *)on3, strlen(on3));
    vw_wait_tx();
    delay(200);
  }

  if (digitalRead(3) == LOW)
  {
    vw_send((uint8_t *)off3, strlen(off3));
    vw_wait_tx();
    delay(200);
  }
}
