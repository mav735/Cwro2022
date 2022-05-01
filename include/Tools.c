void LCDWriteInfoHitech(tHTCS2Ptr htcs2Ptr, CalibrationPtr data)
{
  eraseDisplay();
  while (true)
  {
    readSensor(htcs2Ptr, data);
    displayCenteredTextLine(6, "R: %d G: %d B: %d", htcs2Ptr->red, htcs2Ptr->green, htcs2Ptr->blue);
    displayCenteredTextLine(8, "R_c: %d G_c: %d B_c: %d", htcs2Ptr->red_calibrated, htcs2Ptr->green_calibrated, htcs2Ptr->blue_calibrated);
    displayCenteredTextLine(10, "H: %d S: %d V: %d", htcs2Ptr->hue, htcs2Ptr->saturation, htcs2Ptr->value);
    displayCenteredTextLine(12, "H_c: %d S_c: %d V_c: %d", htcs2Ptr->hue_calibrated, htcs2Ptr->saturation_calibrated, htcs2Ptr->value_calibrated);
    sleep(2);
  }
}

void LCDWriteInfoHitechRaw(tHTCS2Ptr htcs2Ptr, CalibrationPtr data)
{
  eraseDisplay();
  while (true)
  {
    readSensorRaw(htcs2Ptr, data);
    displayCenteredTextLine(6, "R: %d G: %d B: %d W: %d", htcs2Ptr->red, htcs2Ptr->green, htcs2Ptr->blue, htcs2Ptr->white);
    displayCenteredTextLine(8, "R_c: %d G_c: %d B_c: %d", htcs2Ptr->red_calibrated, htcs2Ptr->green_calibrated, htcs2Ptr->blue_calibrated);
    displayCenteredTextLine(12, "H_c: %d S_c: %d V_c: %d", htcs2Ptr->hue_calibrated, htcs2Ptr->saturation_calibrated, htcs2Ptr->value_calibrated);
    sleep(2);
  }
}

void LCDWriteInfoNXTSen()
{
  eraseDisplay();
  while (true)
  {
    results_sensors = SensorsToPercent();
    displayCenteredTextLine(6, "sen1: %d sen2: %d", SensorRaw[leftSensor], SensorRaw[rightSensor]);
  }
}

void swap(long *ptr1, long *ptr2){
  long buffer = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = buffer;
}

typedef struct
{
  long *pointer;
  long len;
} Array;

void arr_fill(Array arr, int val)
{
  for (int i = 0; i < arr.len; i++)
  {
    arr.pointer[i] = val;
  }
}

int arr_push_back(Array arr, int val)
{
  for (int i = 0; i < arr.len; i++)
  {
    if (arr.pointer[i] == -228)
    {
      arr.pointer[i] = val;
      return 1;
    }
  }
  return 0;
}

int arr_cutFirst(Array arr)
{
  int val = arr.pointer[0];
  arr.pointer[0] = -228;

  for (int i = 1; i < arr.len; i++)
  {
    swap(&arr.pointer[i - 1], &arr.pointer[i]);
  }

  return val;
}