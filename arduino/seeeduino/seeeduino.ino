void setup() {
  Serial.begin(115200); // to monitor
  Serial1.begin(115200); // to ESP
}

void loop() {
  // analogReadResolution(10);
  // int aVal = analogRead(A0);
  // Serial.println("read");
  // Serial.print(aVal);
  // Serial.println("");
  Serial1.write("yo");
  Serial.write("yo");
  delay(5000);
}