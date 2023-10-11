#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define MOTOR_PIN 13
#define BUTTON_PIN 12

LiquidCrystal_I2C lcd(0x20, 16, 2); // Endereço do LCD para uma tela de 16 caracteres e 2 linhas

int motorState = LOW;
char *bufferMotorState;
int buttonState = LOW;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
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

void lcdSetup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Desafio Sillion!");
  lcd.setCursor(0, 1);
  lcd.print("Motor DC");
  delay(500);
  lcdMotorStatus();
}

void debounceButton(int reading) {
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if (millis() - lastDebounceTime > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        motorState = !motorState;
        lcdMotorStatus();
      }
    }
  }
  lastButtonState = reading;
}

void lcdMotorStatus(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Motor State");
  lcd.setCursor(0, 1);
  bufferMotorState = (motorState) ? "On":"Off";
  lcd.print(bufferMotorState);
  delay(500);
}

void controlMotor() {
  digitalWrite(MOTOR_PIN, motorState);
}