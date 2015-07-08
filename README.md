# RestClient for ESP8266 Arduino

HTTP Request library for the ESP8266 using the Arduino development environment.

Forked from the original library which was for a regular Arduino plus Ethernet shield. This only required very minimal changes, to get it working with the ESP8266, thanks [CSquared](https://github.com/csquared)!.

For details on how to get started with the ESP8266 using the Arduino IDE take a look at [Adafruit's tutorial](https://learn.adafruit.com/adafruit-huzzah-esp8266-breakout/using-arduino-ide).

# Install

Clone (or download and unzip) the repository to `~/Documents/Arduino/libraries`
where `~/Documents/Arduino` is your sketchbook directory.

    > cd ~/Documents/Arduino
    > mkdir libraries
    > cd libraries
    > git clone https://github.com/alexmordue/arduino-restclient.git RestClient

# Usage

### Include

Just include it and the ESP8266 library.

```c++
#include <ESP8266.h>
#include "RestClient.h"
```

## Setup

You should setup the WiFi connection before making a request, look at the included examples for more details (if needed).
```c++
const char* ssid     = "yourSSID";
const char* password = "yourPassword";

void setup(){
  Serial.begin(115200);
  delay(10);

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

```

### RestClient(host/ip, [port])

Constructor to create an RestClient object to make requests against.

Use domain name and default to port 80:
```c++
RestClient client = RestClient("arduino-http-lib-test.herokuapp.com");
```

Use a local IP and an explicit port:
```c++
RestClient client = RestClient("192.168.1.50",5000);
```

## RESTful methods

All methods return an HTTP status code or 0 if there was an error.

### `get(const char* path)`
### `get(const char* path, String* response)`

Start making requests!

```c++
int statusCode = client.get("/"));
```

Pass in a string *by reference* for the response:
```
String response = "";
int statusCode = client.get("/", &response);
```

### post(const char* path, const char* body)
### post(const char* path, String* response)
### post(const char* path, const char* body, String* response)

```
String response = "";
int statusCode = client.post("/", &response);
statusCode = client.post("/", "foo=bar");
response = "";
statusCode = client.post("/", "foo=bar", &response);
```

### put(const char* path, const char* body)
### put(const char* path, String* response)
### put(const char* path, const char* body, String* response)

```
String response = "";
int statusCode = client.put("/", &response);
statusCode = client.put("/", "foo=bar");
response = "";
statusCode = client.put("/", "foo=bar", &response);
```

### del(const char* path)
### del(const char* path, const char* body)
### del(const char* path, String* response)
### del(const char* path, const char* body, String* response)

```
String response = "";
int statusCode = client.del("/", &response);
```

## Full Example

I test every way of calling the library (against a public heroku app)[https://github.com/csquared/arduino-http-test].

You can find the file in File->Examples->RestClient->full_test_suite

## Debug Mode

If you're having trouble, you can always open `RestClient.cpp` and throw at the top:

```c++
#define HTTP_DEBUG
```

Everything happening in the client will get printed to the Serial port.

# Thanks

[csquared](https://github.com/csquared) For all his work creating this library!
