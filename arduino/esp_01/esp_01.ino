// this code requires 1 modification to the ESP-01
// you have to solder the XPD-DCDC pin on the chip to the reset pin

// code mostly from https://techtutorialsx.com/2016/07/21/esp8266-post-requests/
// deep sleep from https://randomnerdtutorials.com/esp8266-deep-sleep-with-arduino-ide/
// note the endpoint eg. "http.begin", this matches your endpoint that's receiving the POST request as text

// GPIO out sourced here
// https://simple-circuit.com/arduino-esp-01-esp8266-programming/

// the wiring between the Seeeduino and ESP-01 is based on the page below
// https://www.instructables.com/Serial-Communication-Between-Arduino-and-ESP-01/

#define LED 2 // LED to GPIO2

#include "env.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

int sleepDelay = 5000; // 86.4e3 full day in seconds

void setup()
{
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void connectToWiFi()
{
  WiFi.begin(wiFiSsid, wiFiPass);
  int connectionAttempts = 0;

  while (WiFi.status() != WL_CONNECTED and connectionAttempts < 20)
  {
    delay(250);
    connectionAttempts += 1;
  }
}

void txStrByWiFi(String strPayload)
{
  connectToWiFi();
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;
    http.begin(httpEndpoint);
    http.addHeader("Content-Type", "text/plain");
    int httpCode = http.POST(strPayload);
    String resp = http.getString();
    http.end();
  }
}

// from https://forum.arduino.cc/index.php?topic=234151.0
void clearSerialBuffer()
{
  while(Serial.available() > 0)
  {
    char t = Serial.read();
  }
}

void loop()
{
  // turn big circuit on to power Seeeduino
  digitalWrite(LED, HIGH);
  if (Serial.available() > 0)
  {
    String serialMsg = Serial.readString();
    if (serialMsg.length() > 0)
    {
      txStrByWiFi(serialMsg);
      clearSerialBuffer();
      digitalWrite(LED, LOW);
      delay(5000);
    }
  }
  delay(sleepDelay);
}