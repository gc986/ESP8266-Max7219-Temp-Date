#include "DateRout.h"
#include <StringSplitter.h>

String DateRout::parseTimeJson(String input){
    StaticJsonDocument<512> doc;
    DeserializationError error = deserializeJson(doc, input);
 
    if (error) {
        return "time parse err";
        Serial.println("Error JSON parse");
    } 

    return doc["datetime"];
}

String DateRout::getTime(){
    String data = internet.getDataFromUrl(timeServerUrl);
    String dateTimeString = parseTimeJson(data);
    StringSplitter *splitter = new StringSplitter(dateTimeString, 'T', 2);
    String date = splitter->getItemAtIndex(0);
    String time = splitter->getItemAtIndex(1);
    StringSplitter *splitter2 = new StringSplitter(time, '.', 2);
    time = splitter2->getItemAtIndex(0);
    
    return date + " " + time;
}