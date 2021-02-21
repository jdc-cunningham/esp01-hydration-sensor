// this code requires 2 modifications to the ESP-01
// you have to solder the XPD-DCDC pin on the chip to the reset pin
// you have to solder the TOUT pin on the chip to whatever analog value you're measuring
// the analog value should not exceed 1V, I am using a voltage divider

// code mostly from https://techtutorialsx.com/2016/07/21/esp8266-post-requests/
// deep sleep from https://randomnerdtutorials.com/esp8266-deep-sleep-with-arduino-ide/
// note the endpoint eg. "http.begin", this matches your endpoint that's receiving the POST request as text

// using voltage divider 330 ohm to 100 ohm eg. 3.3V dropped to 0.748V
// max from moisture sensor is 3V so 0.698V should be max

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

void setup() {
  Serial.begin(115200);

  // set pinMode for TOUT(6) (3rd pin from deep sleep wired to reset pin)
  // https://forum.arduino.cc/index.php?topic=658062.0
  pinMode(A0, INPUT);
}

void connectWifi() {
  WiFi.begin("SSID", "WiFi Pass");

  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.println("Waiting for connection");
  }

  transmit();
}

void transmit() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("http://your-local-ip-or-domain/plant-moisture");
    http.addHeader("Content-Type", "text/plain");
    int httpCode = http.POST(String(analogRead(A0)));
    String payload = http.getString();
    Serial.println(httpCode);
    Serial.println(payload);
    http.end();  
  } else {
    Serial.println("Error in WiFi connection");
  }
}

void loop() {
  connectWifi();
  delay(5000);
  // ESP.deepSleep(1.44e+7); // sleep for 4 hours, runs 6 times a day
}