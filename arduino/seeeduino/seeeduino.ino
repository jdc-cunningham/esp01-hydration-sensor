void setup() {
  Serial.begin(115200);
}

void loop() {
  analogReadResolution(10);
  int aVal = analogRead(A0);
  Serial.println("read");
  Serial.print(aVal);
  Serial.println("");
  delay(1000);
}