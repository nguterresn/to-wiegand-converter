#include "WebServer.h"

AsyncWebServer server(80);

void setWifi() {
  WiFi.softAP(SSID_OF_THE_NETWORK);
  // Start mDNS with name esp8266
  MDNS.begin("esp8266");
  MDNS.addService("http", DNS_NETWORK_NAME, 80);
}

void setWebServer() {

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", homePage);
  });

  // server.on("/close",  HTTP_GET, [](AsyncWebServerRequest *request){
  //   referenceState = CLOSE;
  //   request->send(200, "text/html", homePage);
  // });

  // server.on("/open", HTTP_GET, [](AsyncWebServerRequest *request){
  //   if (request->hasParam(LATITUDE) && request->hasParam(LONGITUDE)) {
  //     String latParam = request->getParam(LATITUDE)->value();
  //     String longParam = request->getParam(LONGITUDE)->value();
  //     // Read configuration !
  //     String latExpected = readMemory(LATITUDE_OFFSET, SIZEOF_COORDINATE);
  //     String longExpected = readMemory(LONGITUDE_OFFSET, SIZEOF_COORDINATE);
  //     // Compare received coordinates with the stored ones in the configuration.
  //     if (latParam.equals(latExpected) && longParam.equals(longExpected)) {
  //       referenceState = OPEN;
  //       request->send(200, "text/plain", "OK");
  //     } else {
  //       request->send(204, "text/plain", "Not equal");
  //     }
  //   }
  // });

  server.onNotFound(notFound);
  server.begin();
}

void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}
