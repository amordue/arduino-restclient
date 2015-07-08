/* RestClient simple GET request
 *
 * Updated for ESP8266 by Alex Mordue (alexmordue)
 * Originally by Chris Continanza (csquared)
 */

#include <ESP8266WiFi.h>
#include "RestClient.h"

const char* ssid     = "yourSSID";
const char* password = "yourPassword";

RestClient client = RestClient("arduino-http-lib-test.herokuapp.com");

// Setup function as per the Adafruit example for the esp8266
// https://learn.adafruit.com/adafruit-huzzah-esp8266-breakout/using-arduino-ide

void setup(){
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

String response;
void loop(){
  response = "";
  int statusCode = client.get("/get", &response);
  Serial.print("Status code from server: ");
  Serial.println(statusCode);
  Serial.print("Response body from server: ");
  Serial.println(response);
  delay(1000);
}
