#ifndef DISPLAY_H
#define DISPLAY_H

#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

class Display
{
    private:
        Max72xxPanel matrix = Max72xxPanel(D8, 4, 1);
        int spacer = 1;
        int width = 5 + spacer;

    public:
        void setupDisplay();
        void handleTicker(String text);

};
#endif