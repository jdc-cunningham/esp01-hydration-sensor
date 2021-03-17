void setup() {
  // Serial.begin(115200); // to monitor // also sends
  Serial1.begin(115200); // to ESP // also works
  analogReadResolution(10);
}

void loop() {

  pinMode(0, OUTPUT);
  digitalWrite(0, HIGH);
  delay(5000);
  int aVal = analogRead(A1);
  digitalWrite(0, LOW);
  Serial1.println(aVal);
  delay(600000);
}