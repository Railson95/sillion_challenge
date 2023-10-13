#ifndef _LOG_H
#define _LOG_H

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

typedef struct{
  int line;
}DataLogger;

extern uint8_t motorState;
void writeLog();
void initSd();
void initLog();

#endif