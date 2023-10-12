#include "lcd.h"
#include "button.h"
#include "variables.h"

Lcd l;
Button b;

int motorState = 0;

void setup() {
  l.lcdSetup(motorState);
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(MOTOR_PIN, motorState);
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);
  b.debounceButton(reading, motorState, l);
  controlMotor();
}

void controlMotor() {
  digitalWrite(MOTOR_PIN, motorState);
}