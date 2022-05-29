#include "WebServer.h"

AsyncWebServer server(80);
AsyncEventSource events("/events");

void setWifi() {
  WiFi.softAP(SSID_OF_THE_NETWORK);
  MDNS.begin(DNS_NETWORK_NAME); // Start mDNS with name `esp8266`.
  MDNS.addService("http", DNS_NETWORK_NAME, 80);
}

void setWebServer(uint8_t &cardType) {

  server.addHandler(&events);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", homePage);
  });

  server.on("/save", HTTP_GET, [&cardType](AsyncWebServerRequest *request){
    if (request->hasParam(REQUEST_SAVE_PARAM)) {
      String requestSaveParam = request->getParam(REQUEST_SAVE_PARAM)->value();
      cardType = requestSaveParam.toInt();
      request->send(200, "text/plain", "OK");
    }
  });

  server.onNotFound(notFound);
  server.begin();
}

void sendEvent(const char* type, const char* data) {
  events.send(data, "myevent", millis());
}

void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}
