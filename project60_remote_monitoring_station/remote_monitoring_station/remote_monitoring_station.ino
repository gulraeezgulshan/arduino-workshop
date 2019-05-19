/* Project 60 – Building a Remote-Monitoring Station
  created 18 Dec 2009 by David A. Mellis, modified 9 Apr 2012 by Tom Igoe
  modified 20 Mar 2013 by John Boxall
*/
#include <SPI.h>
#include <Ethernet.h>
IPAddress ip(xxx, xxx, xxx, xxx); // Replace this with your project's IP address
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
EthernetServer server(80);
void setup()
{
  // Start the Ethernet connection and server
  Ethernet.begin(mac, ip);
  server.begin();

  for (int z = 0; z < 10; z++)
  {
    pinMode(z, INPUT); // set digital pins 0 to 9 to inputs
  }
}
void loop()
{
  // listen for incoming clients (incoming web page request connections)
  EthernetClient client = server.available();
  if (client) {
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (c == '\n' && currentLineIsBlank) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          // add a meta refresh tag, so the browser pulls again every 5 sec:
          client.println("<meta http-equiv=\"refresh\" content=\"5\">");
          // output the value of each analog input pin onto the web page
          for (int analogChannel = 0; analogChannel < 6; analogChannel++) {
            int sensorReading = analogRead(analogChannel);
            client.print("analog input ");
            client.print(analogChannel);
            client.print(" is ");
            client.print(sensorReading);
            client.println("<br />");
          }
          // output the value of digital pins 0 to 9 onto the web page
          for (int digitalChannel = 0; digitalChannel < 10; digitalChannel++)
          {
            boolean pinStatus = digitalRead(digitalChannel);
            client.print("digital pin ");
            client.print(digitalChannel);
            client.print(" is ");
            client.print(pinStatus);
            client.println("<br />");
          }
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        }

        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
  }
}
