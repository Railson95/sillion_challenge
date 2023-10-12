#include "variables.h"
#include "lcd.h"
#include "button.h"

void setup() {
  initButton();
  lcdSetup();
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(MOTOR_PIN, motorState);
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);
  debounceButton(reading);
  controlMotor();
}

void controlMotor() {
  digitalWrite(MOTOR_PIN, motorState);
}