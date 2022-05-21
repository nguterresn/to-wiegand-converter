#ifndef SERVER_H
#define SERVER_H

#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <ESP8266mDNS.h>

#define SSID_OF_THE_NETWORK "NameOfTheNetwork"
#define DNS_NETWORK_NAME "esp8266"

void setWifi();
void setWebServer();
void notFound(AsyncWebServerRequest *request);

#endif
