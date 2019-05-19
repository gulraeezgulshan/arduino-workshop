// Project 61 - Creating an Arduino Tweeter
#include <SPI.h>
#include <Ethernet.h>
#include <Twitter.h>
byte ip[] = { xxx, xxx, xxx, xxx };
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
Twitter twitter("token");
char msg[] = "I'm alive!"; // message to tweet
void setup()
{
  delay(30000);
  Ethernet.begin(mac, ip);
  Serial.begin(9600);
}

void loop()
{
  Serial.println("connecting ...");
  if (twitter.post(msg)) {
    int status = twitter.wait();
    if (status == 200) {
      Serial.println("OK.");
    } else {
      Serial.print("failed : code ");
      Serial.println(status);
    }
  } else {
    Serial.println("connection failed.");
  }
  do {} while (1);
}
