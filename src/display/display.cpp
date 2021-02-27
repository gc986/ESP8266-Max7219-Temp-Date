#include "display.h"
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

void Display::handleTicker(String text){
    for ( int i = 0 ; i < width * text.length() + matrix.width() - 1 - spacer; i++ ) {
        matrix.fillScreen(LOW);

        int letter = i / width;
        int x = (matrix.width() - 1) - i % width;
        int y = (matrix.height() - 8) / 2;

        while ( x + width - spacer >= 0 && letter >= 0 ) {
            if ( letter < text.length() ) {
                matrix.drawChar(x, y, text[letter], HIGH, LOW, 1);
            }
            letter--;
            x -= width;
        }

        matrix.write();
        delay(50);
    }
}

void Display::setupDisplay(){
    matrix.setIntensity(1); // яркость
    matrix.setPosition(0, 0, 0); // The first display is at <0, 0>
    matrix.setPosition(1, 1, 0); // The second display is at <1, 0>
    matrix.setPosition(2, 2, 0); // The third display is at <2, 0>
    matrix.setPosition(3, 3, 0); // And the last display is at <3, 0>

    matrix.setRotation(0, 1);    // The first display is position upside down
    matrix.setRotation(1, 1);    // The first display is position upside down
    matrix.setRotation(2, 1);    // The first display is position upside down
    matrix.setRotation(3, 1);    // The same hold for the last display
}