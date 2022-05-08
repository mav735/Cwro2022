void check_battery(){
  float volt = getBatteryVoltage();
  setSoundVolume(90); 
  if (!(volt > 8.02 && volt < 8.3)){
    playSound(soundDownwardTones);
    playSound(soundException);
    displayCenteredBigTextLine(12, "%f", volt);
  }
}

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

void swap(long *ptr1, long *ptr2)
{
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

void test_arr_operations(){
  Array my_arr;
  int arr[7];
  my_arr.pointer = &arr;
  my_arr.len = 7;
  
  arr_fill(my_arr, -228);
  for (int i = 0; i < my_arr.len; i++){
    arr_push_back(my_arr, i + 10);
  }

  displayCenteredTextLine(5, "after push_back");
  displayCenteredTextLine(10, "%d %d %d %d %d %d %d", my_arr.pointer[0], my_arr.pointer[1], my_arr.pointer[2], my_arr.pointer[3], my_arr.pointer[4], my_arr.pointer[5], my_arr.pointer[6]);
  waitForButtonPress();
  eraseDisplay();

  for (int i = 0; i < my_arr.len; i++){
    displayCenteredTextLine(5, "%d", arr_cutFirst(my_arr));
    flushButtonMessages();
    waitForButtonPress();
    eraseDisplay();
  }

  displayCenteredTextLine(5, "after cut");
  displayCenteredTextLine(10, "%d %d %d %d %d %d %d", my_arr.pointer[0], my_arr.pointer[1], my_arr.pointer[2], my_arr.pointer[3], my_arr.pointer[4], my_arr.pointer[5], my_arr.pointer[6]);
}

const float SPEEDY_BOBOT_GEARS[4] = {0, 30, 55, 101};
const float SPEEDY_BOBOT_SOUNDS_MIN = 2000;
const float SPEEDY_BOBOT_SOUNDS_MAX = 2100;

task speedyBobot()
{
  setSoundVolume(1);
  while (1 == 1)
  {
    short speedyBobot_gearNow = 0;
    // float speedyBobot_speedNow = (abs(getMotorSpeed(leftMotor)) + abs(getMotorSpeed(rightMotor))) / 2;
    float speedyBobot_speedNow = abs(getMotorSpeed(leftMotor));
    for (short speedyBobot_i = 1; speedyBobot_i < 4; speedyBobot_i++)
    {
      if (speedyBobot_speedNow < SPEEDY_BOBOT_GEARS[speedyBobot_i])
      {
        speedyBobot_gearNow = speedyBobot_i - 1;
        break;
      }
    }

    if (speedyBobot_gearNow > 0)
    {
      float speedyBobot_freq = (speedyBobot_speedNow - SPEEDY_BOBOT_GEARS[speedyBobot_gearNow]) / (SPEEDY_BOBOT_GEARS[speedyBobot_gearNow + 1] - SPEEDY_BOBOT_GEARS[speedyBobot_gearNow]) * (SPEEDY_BOBOT_SOUNDS_MAX - SPEEDY_BOBOT_SOUNDS_MIN) + SPEEDY_BOBOT_SOUNDS_MIN;
      playTone(speedyBobot_freq, 1);
    }
    sleep(10);
  }
}