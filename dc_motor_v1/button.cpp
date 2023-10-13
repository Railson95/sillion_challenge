#include "button.h"
#include "log.h"
#define startLastDebounceTime 0
#define startDebounceDelay 50

Button button;

void initButton(){
  button.buttonState = LOW;
  button.lastButtonState = LOW;
  button.lastDebounceTime = startLastDebounceTime;
  button.debounceDelay = startDebounceDelay;
}

void debounceButton(int reading) {
  assert(reading >= 0 && reading <= 1);

  if (reading != button.lastButtonState) {
      button.lastDebounceTime = millis();
  }
  if (millis() - button.lastDebounceTime > button.debounceDelay) {
    if (reading != button.buttonState) {
      button.buttonState = reading;
      if (button.buttonState == HIGH) {
        motorState = !motorState;
        lcdMotorStatus();
        // writeLog(); TODO: Still doesn't work as expected
      }
    }
  }
  button.lastButtonState = reading;
}

