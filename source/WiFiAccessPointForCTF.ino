

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
extern "C" {
  #include "user_interface.h"
}


#ifndef APSSID
#define APSSID "Asteroid #80211"
#define APPSK "thereisnospoon"
#define FLAG "ATHACKCTF{Alien_Go_LMAO_Not_So_Hidden}" 
#endif

/* Set these to your desired credentials. */
const char *ssid = APSSID;
const char *password = APPSK;

// ATHACKCTF{Alien_Go_LMAO_Not_So_Hidden}
uint8_t my_oui[3] = {0xDE, 0xAD, 0xBE}; 
uint8_t flag[]    = {
  0x41,0x54,0x48,0x41,0x43,0x4b,0x43,0x54,
  0x46,0x7b,0x41,0x6c,0x69,0x65,0x6e,0x5f,
  0x47,0x6f,0x5f,0x4c,0x4d,0x41,0x4f,0x5f,
  0x4e,0x6f,0x74,0x5f,0x53,0x6f,0x5f,0x48,
  0x69,0x64,0x64,0x65,0x6e,0x7d};

ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", "<h1>HowDidYouGetHere? Talk to Enrique </h1>");
}

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  WiFi.softAP(ssid, password, 1, 0);

  delay(100);

  // 2. Disable first using the correct Enum: USER_IE_BEACON (0)
  wifi_set_user_ie(false, my_oui, USER_IE_BEACON, flag, sizeof(flag));

  // 3. Enable using the correct Enum
  bool success = wifi_set_user_ie(true, my_oui, USER_IE_BEACON, flag, sizeof(flag));
  
  if (success) {
    Serial.println("Beacon IE Injection Successful");
  } else {
    Serial.println("Beacon IE Injection Failed");
  }


  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
