// the wiring between the Seeeduino and ESP-01 is based on the page below
// https://www.instructables.com/Serial-Communication-Between-Arduino-and-ESP-01/

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const String wiFiSsid = "";
const String wiFiPass = "";
const String httpEndpoint = "http://your-endpoint/soil-moisture";

void setup()
{
  Serial.begin(115200);
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
  if (Serial.available() > 0)
  {
    String serialMsg = Serial.readString();
    if (serialMsg.length() > 0)
    {
      txStrByWiFi(serialMsg);
      clearSerialBuffer();
    }
  }
  delay(5000);
}