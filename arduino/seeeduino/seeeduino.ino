void setup() {
  // Serial.begin(115200); // to monitor // also sends
  Serial1.begin(115200); // to ESP // also works
  analogReadResolution(10);
  pinMode(0, OUTPUT);
}

void loop() {
  digitalWrite(0, HIGH);
  delay(5000);
  int aVal = analogRead(A1);
  digitalWrite(0, LOW);
  // Serial.println("done measuring"); // comment out if monitor not connected
  Serial1.println(aVal);
  delay(10000); // this shouldn't turn on again for a while
}