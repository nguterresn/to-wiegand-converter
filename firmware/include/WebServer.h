#ifndef SERVER_H
#define SERVER_H

#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <ESP8266mDNS.h>
#include "HTML.h"
#include "Helper.h"

#define SSID_OF_THE_NETWORK "NameOfTheNetwork"
#define DNS_NETWORK_NAME    "wiegand"

#define REQUEST_TYPE_PARAM  "type"

void notFound(AsyncWebServerRequest *request);
void setWebServer(uint8_t &cardType, uint8_t &dataType);
void sendEvent(const char* type, int value);
void setWifi();

#endif
