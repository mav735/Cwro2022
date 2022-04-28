void LCDWriteInfoHitech(tHTCS2Ptr htcs2Ptr){
    displayCenteredBigTextLine(1, "R  G  B");
    eraseDisplay();
    while (true){
	  readSensor(htcs2Ptr);
    displayCenteredTextLine(6, "R: %d G: %d B: %d W: %d", colorRightSensor.red, colorRightSensor.green, colorRightSensor.blue, colorRightSensor.white);
    displayCenteredTextLine(9, "H: %d S: %d V: %d", colorRightSensor.hue, colorRightSensor.saturation, colorRightSensor.value);
    eraseRect(0,10, 99, 41);
    sleep(2);
  }
}

void LCDWriteInfoHitechRaw(tHTCS2Ptr htcs2Ptr){
    displayCenteredBigTextLine(1, "R  G  B");
    eraseDisplay();
    while (true){
	  readSensorRaw(htcs2Ptr);
    displayCenteredTextLine(6, "R: %d G: %d B: %d W: %d", colorRightSensor.red, colorRightSensor.green, colorRightSensor.blue, colorRightSensor.white);
    displayCenteredTextLine(9, "W: %d T: %d F: %d", colorRightSensor.hue, colorRightSensor.saturation, colorRightSensor.value);
    eraseRect(0,10, 99, 41);
    sleep(2);
  }
}