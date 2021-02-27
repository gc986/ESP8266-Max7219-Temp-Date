#ifndef INTERNET_H
#define INTERNET_H

#include <ArduinoJson.h>

class Internet
{
    public:
        void setupInternet(String ssi, String pass);
        bool checkInternet();
        String getDataFromUrl(String url);
};

#endif