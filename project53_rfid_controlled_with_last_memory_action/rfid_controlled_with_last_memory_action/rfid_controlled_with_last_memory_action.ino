// Project 53 – Creating an RFID Control with "Last Action" Memory
#include <EEPROM.h>
int data1 = 0;
int ok = -1;
int lockStatus = 0;
// use Listing 16-1 to find your tag numbers
int tag1[14] = {x, x, x, x, x, x, x, x, x, x, x, x, x, x};
int tag2[14] = {x, x, x, x, x, x, x, x, x, x, x, x, x, x};
int newtag[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // used for read comparisons
void setup()
{
  Serial.flush();
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  checkLock();
}
// comparetag compares two arrays and returns true if identical
// this is good for comparing tags
boolean comparetag(int aa[14], int bb[14])
{
  boolean ff = false;
  int fg = 0;
  for (int cc = 0; cc < 14; cc++)
  {
    if (aa[cc] == bb[cc])
    {
      fg++;
    }
  }
  if (fg == 14)
  {
    ff = true;
  }
  return ff;
}
void checkmytags()
// compares each tag against the tag just read
{
  ok = 0;
  if (comparetag(newtag, tag1) == true)
  {
    ok++;
  }
  if (comparetag(newtag, tag2) == true)
  {
    ok++;
  }
}
void checkLock()
{
  Serial.print("System Status after restart ");
  lockStatus = EEPROM.read(0);
  if (lockStatus == 1)
  {
    Serial.println("- locked");
    digitalWrite(13, HIGH);
  }
  if (lockStatus == 0)
  {
    Serial.println("- unlocked");
    digitalWrite(13, LOW);
  }
  if ((lockStatus != 1) && (lockStatus != 0))
  {
    Serial.println("EEPROM fault - Replace Arduino hardware");
  }
}
void loop()
{
  ok = -1;
  if (Serial.available() > 0) // if a read has been attempted
  {
    // read the incoming number on serial RX
    delay(100);
    for (int z = 0; z < 14; z++) // read the rest of the tag
    {
      data1 = Serial.read();
      newtag[z] = data1;
    }
    Serial.flush(); // prevents multiple reads
    // now to match tags up
    checkmytags();
  }
  if (ok > 0) // if we had a match
  {
    lockStatus = EEPROM.read(0);
    if (lockStatus == 1) // if locked, unlock it
    {
      Serial.println("Status - unlocked");
      digitalWrite(13, LOW);
      EEPROM.write(0, 0);
    }
    if (lockStatus == 0)
    {
      Serial.println("Status - locked");
      digitalWrite(13, HIGH);
      EEPROM.write(0, 1);
    }

    void checkLock()
    {
      Serial.print("System Status after restart ");
      lockStatus = EEPROM.read(0);
      if (lockStatus == 1)
      {
        Serial.println("- locked");
        digitalWrite(13, HIGH);
      }
      if (lockStatus == 0)
      {
        Serial.println("- unlocked");
        digitalWrite(13, LOW);
      }
      if ((lockStatus != 1) && (lockStatus != 0))
      {
        Serial.println("EEPROM fault - Replace Arduino hardware");
      }
    }
    void loop()
    {
      ok = -1;
      if (Serial.available() > 0) // if a read has been attempted
      {
        // read the incoming number on serial RX
        delay(100);
        for (int z = 0; z < 14; z++) // read the rest of the tag
        {
          data1 = Serial.read();
          newtag[z] = data1;
        }
        Serial.flush(); // prevents multiple reads
        // now to match tags up
        checkmytags();
      }
      if (ok > 0) // if we had a match
      {
        lockStatus = EEPROM.read(0);
        if (lockStatus == 1) // if locked, unlock it
        {
          Serial.println("Status - unlocked");
          digitalWrite(13, LOW);
          EEPROM.write(0, 0);
        }
        if (lockStatus == 0)
        {
          Serial.println("Status - locked");
          digitalWrite(13, HIGH);
          EEPROM.write(0, 1);
        }
