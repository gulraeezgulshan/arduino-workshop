// Project 31 – Creating a Stopwatch
unsigned long start, finished, elapsed;
void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT); // the start button
  pinMode(3, INPUT); // the stop button
  Serial.println("Press 1 for Start/reset, 2 for elapsed time");
}
void displayResult()
{
  float h, m, s, ms;
  unsigned long over;
  elapsed = finished - start;
  h = int(elapsed / 3600000);
  over = elapsed % 3600000;

  m = int(over / 60000);
  over = over % 60000;
  s = int(over / 1000);
  ms = over % 1000;
  Serial.print("Raw elapsed time: ");
  Serial.println(elapsed);
  Serial.print("Elapsed time: ");
  Serial.print(h, 0);
  Serial.print("h ");
  Serial.print(m, 0);
  Serial.print("m ");
  Serial.print(s, 0);
  Serial.print("s ");
  Serial.print(ms, 0);
  Serial.println("ms");
  Serial.println();
}

void loop()
{
  if (digitalRead(2) == HIGH)
  {
    start = millis();
    delay(200); // for debounce
    Serial.println("Started...");
  }
  if (digitalRead(3) == HIGH)
  {
    finished = millis();
    delay(200); // for debounce
    displayResult();
  }
}
