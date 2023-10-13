#include "Arduino.h"
#include "log.h"
DataLogger datalogger;
File dataFile;

void initLog(){
  datalogger.line = 0;
}

void writeLog(){
  dataFile = SD.open("myfile.txt", FILE_WRITE);
  // if the file opened okay, write to it:
  if (dataFile) {
    dataFile.print(datalogger.line++);
    dataFile.print("Motor Status: ");
    dataFile.print(motorState);
    dataFile.println();
    dataFile.close();
  }
  // if the file didn't open, print an error:
  else
    Serial.println("error opening myfile.txt");
    while (1);
}

void initSd(){
  Serial.print("Initializing SD card...");
  if (!SD.begin()) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
}

