#include "hitechnic-colour-v2.h"

task main ()
{
  // Create struct to hold sensor data
  tHTCS2 colorSensor;

  // Initialise and configure struct and port
  initSensor(&colorSensor, S4);

  eraseDisplay();
  while (true)
  {
    // Read the currently detected colour and RGB/HSV data from the sensor
    if (!readSensor(&colorSensor)) {
      displayTextLine(4, "ERROR!!");
      sleep(2000);
      stopAllTasks();
    }

    displayCenteredTextLine(0, "Color: %d", colorSensor.color);
    displayCenteredBigTextLine(1, "R  G  B");

    eraseRect(0,10, 99, 41);

    displayTextLine(7, " %3d   %3d   %3d", colorSensor.red, colorSensor.green, colorSensor.blue);
		writeDebugStreamLine("R: %d, G: %d, B: %d", colorSensor.red, colorSensor.green, colorSensor.blue);
    sleep(2);
  }
}
