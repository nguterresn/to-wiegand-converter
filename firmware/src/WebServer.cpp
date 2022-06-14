#include "WebServer.h"

AsyncWebServer server(80);
AsyncEventSource events("/events");

void setWifi() {
  WiFi.softAP(SSID_OF_THE_NETWORK);
  MDNS.begin(DNS_NETWORK_NAME);
  MDNS.addService("http", DNS_NETWORK_NAME, 80);
}

void setWebServer(uint8_t &cardType, uint8_t &dataType) {

  server.addHandler(&events);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", homePage);
  });

  server.on("/save", HTTP_GET, [&cardType](AsyncWebServerRequest *request){
    if (request->hasParam(REQUEST_TYPE_PARAM)) {
      String requestTypeParam = request->getParam(REQUEST_TYPE_PARAM)->value();
      cardType = requestTypeParam.toInt();
      request->send(200, "text/plain", "OK");
    }
  });

  server.on("/format", HTTP_GET, [&dataType](AsyncWebServerRequest *request){
    if (request->hasParam(REQUEST_TYPE_PARAM)) {
      String requestTypeParam = request->getParam(REQUEST_TYPE_PARAM)->value();
      dataType = requestTypeParam.toInt();
      request->send(200, "text/plain", "OK");
    }
  });

  server.onNotFound(notFound);
  server.begin();
}

void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}

void sendEvent(const char* type, int value) {
  char *buffer = new char[50];
  intToConstChar(value, buffer);
  events.send(buffer, type, millis());
  delete []buffer;
}
