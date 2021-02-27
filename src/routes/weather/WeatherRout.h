#ifndef WEATHERROUT_H
#define WEATHERROUT_H

#include "internet/internet.h"
#include <ArduinoJson.h>

class WeatherRout{
    private:
        String weatherServerUrl = "http://api.openweathermap.org/data/2.5/weather?q=Yekaterinburg&appid=YOUR-KEY&units=metric";
        Internet internet;
        String parseWeatherJson(String input);
    public:
        String getWeather();
};

#endif