#include "lcd.h"
LiquidCrystal_I2C lcd(0x20, 16, 2); // Endereço do LCD para uma tela de 16 caracteres e 2 linhas

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

void lcdMotorStatus() {
    char *bufferMotorState;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Motor State");
    lcd.setCursor(0, 1);
    bufferMotorState = (motorState) ? "On":"Off";
    lcd.print(bufferMotorState);
    delay(500);
}



