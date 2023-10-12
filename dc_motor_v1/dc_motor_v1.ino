#include "variables.h"
#include "lcd.h"
#include "button.h"
#include "log.h"

void setup() {
  Serial.begin(9600);
  lcdSetup();
  // init_sd(); # TODO: Still doesn't work as expected
  init_log();
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