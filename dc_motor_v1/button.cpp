#include "button.h"
#include "lcd.h"

Button::Button(){
  this->buttonState = LOW;
  this->lastButtonState = LOW;
  this->lastDebounceTime = 0;
  this->debounceDelay = 50;
}

void Button::debounceButton(int reading, int &motorState, Lcd l) {
  if (reading != this->lastButtonState) {
      this->lastDebounceTime = millis();
  }
  if (millis() - this->lastDebounceTime > this->debounceDelay) {
    if (reading != this->buttonState) {
      this->buttonState = reading;
      if (this->buttonState == HIGH) {
        motorState = !motorState;
        l.lcdMotorStatus(motorState);
      }
    }
  }
  this->lastButtonState = reading;
}

