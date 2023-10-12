#ifndef _LCD_H
#define _LCD_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class Lcd {
public:
    Lcd();
    void lcdMotorStatus(int motorState);
    void lcdSetup(int motorState);   
};

#endif