#ifndef _LCD_H
#define _LCD_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
extern uint8_t motorState;
void lcdMotorStatus();
void lcdSetup(); 

#endif