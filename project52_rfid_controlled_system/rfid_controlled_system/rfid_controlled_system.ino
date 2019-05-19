// Project 52 – Creating a Simple RFID Control System
int data1 = 0;
int ok = -1;
// use Listing 16-1 to find your tag numbers
int tag1[14] = {x, x, x, x, x, x, x, x, x, x, x, x, x, x};
int tag2[14] = {x, x, x, x, x, x, x, x, x, x, x, x, x, x};
int newtag[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // used for read comparisons
void setup()
{
  Serial.flush(); // need to flush serial buffer,
  // otherwise first read may not be correct
  Serial.begin(9600);
}
boolean comparetag(int aa[14], int bb[14])
{
  boolean ff = false;
  int fg = 0;
  for (int cc = 0 ; cc < 14 ; cc++)
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
void checkmytags() // compares each tag against the tag just read
{
  ok = 0; // this variable helps decision-making,
  // if it is 1 we have a match, zero is a read but no match,
  // -1 is no read attempt made
  if (comparetag(newtag, tag1) == true)
  {
    ok++;
  }
  if (comparetag(newtag, tag2) == true)
  {
    ok++;
  }
}
void loop()
{
  ok = -1;
  if (Serial.available() > 0) // if a read has been attempted
  {
    // read the incoming number on serial RX
    delay(100); // needed to allow time for the data
    // to come in from the serial buffer.
    for (int z = 0 ; z < 14 ; z++) // read the rest of the tag
    {
      data1 = Serial.read();
      newtag[z] = data1;
    }
    Serial.flush(); // stops multiple reads
    // now to match tags up
    checkmytags();
  }
  //now do something based on tag type
  if (ok > 0) // if we had a match
  {
    Serial.println("Accepted");
    ok = -1;
  }
  else if (ok == 0) // if we didn't have a match
  {
    Serial.println("Rejected");
    ok = -1;
  }
}
