#include "WeatherRout.h"

String WeatherRout::parseWeatherJson(String input){
    StaticJsonDocument<1024> doc;
    DeserializationError error = deserializeJson(doc, input);
 
    if (error) {
        return "temp parse err";
        Serial.println("Error JSON parse");
    } 

    return doc["main"]["temp"];
}

String WeatherRout::getWeather(){
    String data = internet.getDataFromUrl(weatherServerUrl);
    String temp = parseWeatherJson(data);
            
    return "Temp now " + temp;
}