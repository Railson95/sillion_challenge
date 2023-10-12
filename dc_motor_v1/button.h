#ifndef _BUTTON_H
#define _BUTTON_H

#include <Arduino.h>
#include "lcd.h"

class Button {
private:
    int buttonState;
    int lastButtonState;
    unsigned long lastDebounceTime;
    unsigned long debounceDelay;
public:
    Button();
    void debounceButton(int reading, int &motorState, Lcd l);
};
#endif