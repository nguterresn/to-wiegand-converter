#ifndef SERVER_H
#define SERVER_H

#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <ESP8266mDNS.h>
#include "HTML.h"

#define SSID_OF_THE_NETWORK "NameOfTheNetwork"
#define DNS_NETWORK_NAME    "esp8266"

#define REQUEST_SAVE_PARAM  "type"

void notFound(AsyncWebServerRequest *request);
void setWebServer(uint8_t &cardType);
void sendEvent(const char* type, const char* data);
void setWifi();
void updatePage();

#endif
