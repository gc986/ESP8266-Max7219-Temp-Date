#ifndef DATEROUT_H
#define DATEROUT_H

#include "internet/internet.h"
#include <ArduinoJson.h>

class DateRout
{
    private:
        String timeServerUrl = "http://worldtimeapi.org/api/timezone/Asia/Yekaterinburg";
        Internet internet;
        String parseTimeJson(String input);
    public:
        String getTime();
};

#endif