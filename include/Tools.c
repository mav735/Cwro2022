void LCDWriteInfoHitech(tHTCS2Ptr htcs2Ptr, CalibrationPtr data){
    eraseDisplay();
    while (true){
      readSensor(htcs2Ptr, data);
      displayCenteredTextLine(6,  "R: %d G: %d B: %d",       htcs2Ptr->red,            htcs2Ptr->green,                 htcs2Ptr->blue);
      displayCenteredTextLine(8,  "R_c: %d G_c: %d B_c: %d", htcs2Ptr->red_calibrated, htcs2Ptr->green_calibrated,      htcs2Ptr->blue_calibrated);
      displayCenteredTextLine(10, "H: %d S: %d V: %d",       htcs2Ptr->hue,            htcs2Ptr->saturation,            htcs2Ptr->value);
      displayCenteredTextLine(12, "H_c: %d S_c: %d V_c: %d", htcs2Ptr->hue_calibrated, htcs2Ptr->saturation_calibrated, htcs2Ptr->value_calibrated);
      sleep(2);
  }
}

void LCDWriteInfoHitechRaw(tHTCS2Ptr htcs2Ptr, CalibrationPtr data){
    eraseDisplay();
    while (true){
      readSensorRaw(htcs2Ptr, data);
      displayCenteredTextLine(6,  "R: %d G: %d B: %d W: %d", htcs2Ptr->red,            htcs2Ptr->green,                 htcs2Ptr->blue,           htcs2Ptr->white);
      displayCenteredTextLine(8,  "R_c: %d G_c: %d B_c: %d", htcs2Ptr->red_calibrated, htcs2Ptr->green_calibrated,      htcs2Ptr->blue_calibrated);
      displayCenteredTextLine(12, "H_c: %d S_c: %d V_c: %d", htcs2Ptr->hue_calibrated, htcs2Ptr->saturation_calibrated, htcs2Ptr->value_calibrated);
      sleep(2);
  }
}
