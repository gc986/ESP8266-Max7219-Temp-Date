#include <ArduinoJson.h>
#include "display/display.h"
#include "internet/internet.h"
#include "routes/date/DateRout.h"
#include "routes/weather/WeatherRout.h"

String helloString = "Hello from Yekat!";
String tempNowMessage = "Temp now ";

String ssid = "your_wifi";
String pass = "wifi_pass";

Display display;
Internet internet;
DateRout dateRout;
WeatherRout weatherRout;

void setup(void){
    Serial.begin(115200);
    
    internet.setupInternet(ssid, pass);
    display.setupDisplay();

    display.handleTicker(helloString);
}

void loop(void){
    if (internet.checkInternet())
        display.handleTicker(dateRout.getTime());
    else 
        display.handleTicker("No WiFi connection...");
    if (internet.checkInternet())
        display.handleTicker(tempNowMessage + weatherRout.getWeather());
    else 
        display.handleTicker("No WiFi connection...");
}