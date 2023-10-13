#include "variables.h"
#include "lcd.h"
#include "button.h"
#include "log.h"
#define boudRate 9600

void setup() {
  Serial.begin(boudRate);
  lcdSetup();
  // initSd(); # TODO: Still doesn't work as expected
  initLog();
  initButton();
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