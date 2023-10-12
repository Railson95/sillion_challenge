#ifndef _BUTTON_H
#define _BUTTON_H

#include <Arduino.h>
#include <assert.h>
typedef struct{
    int buttonState;
    int lastButtonState;
    unsigned long lastDebounceTime;
    unsigned long debounceDelay;
}Button;
extern int motorState;
extern void lcdMotorStatus();
void debounceButton(int reading);
void initButton();
#endif