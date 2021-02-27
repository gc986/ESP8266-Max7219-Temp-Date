#include "internet.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

void Internet::setupInternet(String ssid, String pass){
    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
    }
}

bool Internet::checkInternet(){
    return WiFi.status() == WL_CONNECTED;
}

String Internet::getDataFromUrl(String url){
    HTTPClient http;  //Object of class HTTPClient
    http.begin(url);
    http.GET();
    String data = http.getString();
    http.end();
    return data;
}