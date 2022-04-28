#ifndef __HTCS2_H__
#define __HTCS2_H__

#pragma systemFile

#ifndef __LIGHT_COMMON_H__
#include "common-light.h"
#endif

#define HTCS2_I2C_ADDR        0x02      /*!< HTCS2 I2C device address */
#define HTCS2_CMD_REG         0x41      /*!< Command register */
#define HTCS2_OFFSET          0x42      /*!< Offset for data registers */

// Values contained by registers in active mode
#define HTCS2_COLNUM_REG      0x00      /*!< Color number */
#define HTCS2_RED_REG         0x01      /*!< Red reading */
#define HTCS2_GREEN_REG       0x02      /*!< Green reading */
#define HTCS2_BLUE_REG        0x03      /*!< Blue reading */
#define HTCS2_WHITE_REG       0x04      /*!< White channel reading */
#define HTCS2_COL_INDEX_REG   0x05      /*!< Color index number */
#define HTCS2_RED_NORM_REG    0x06      /*!< Normalised red reading */
#define HTCS2_GREEN_NORM_REG  0x07      /*!< Normalised green reading */
#define HTCS2_BLUE_NORM_REG   0x08      /*!< Normalised blue reading */

// Different modes
#define HTCS2_MODE_ACTIVE     0x00      /*!< Use ambient light cancellation */
#define HTCS2_MODE_PASSIVE    0x01      /*!< Disable ambient light cancellation */
#define HTCS2_MODE_RAW        0x03      /*!< Raw data from light sensor */
#define HTCS2_MODE_50HZ       0x35      /*!< Set sensor to 50Hz cancellation mode */
#define HTCS2_MODE_60HZ       0x36      /*!< Set sensor to 60Hz cancellation mode */

typedef struct
{
  tI2CData I2CData;
  short color;
  short red;
  short green;
  short blue;
  short white;
  float hue;
  float saturation;
  float value;
  ubyte _cmd;
} tHTCS2, *tHTCS2Ptr;


bool _sensorSendCommand(tHTCS2Ptr htcs2Ptr);

bool initSensor(tHTCS2Ptr htcs2Ptr, tSensors port, ubyte mode = HTCS2_MODE_ACTIVE)
{
  memset(htcs2Ptr, 0, sizeof(tHTCS2Ptr));
  htcs2Ptr->I2CData.address = HTCS2_I2C_ADDR;
  htcs2Ptr->I2CData.port = port;
  htcs2Ptr->I2CData.type = sensorI2CCustom;
  htcs2Ptr->_cmd = mode;

  if (SensorType[htcs2Ptr->I2CData.port] != htcs2Ptr->I2CData.type)
    SensorType[htcs2Ptr->I2CData.port] = htcs2Ptr->I2CData.type;

  return _sensorSendCommand(htcs2Ptr);
}

void SetModeHitech(tHTCS2Ptr htcs2Ptr, ubyte mode = HTCS2_MODE_ACTIVE){
  htcs2Ptr -> _cmd = mode;
  _sensorSendCommand(htcs2Ptr);
}

bool readSensor(tHTCS2Ptr htcs2Ptr)
{
  memset(htcs2Ptr->I2CData.request, 0, sizeof(htcs2Ptr->I2CData.request));

  htcs2Ptr->I2CData.request[0] = 2;                         // Message size
  htcs2Ptr->I2CData.request[1] = htcs2Ptr->I2CData.address; // I2C Address
  htcs2Ptr->I2CData.request[2] = HTCS2_OFFSET + HTCS2_COLNUM_REG;
  htcs2Ptr->I2CData.replyLen = 4;
  htcs2Ptr->I2CData.requestLen = 2;

  if (!writeI2C(&htcs2Ptr->I2CData))
    return false;

  htcs2Ptr->color = htcs2Ptr->I2CData.reply[0];
  htcs2Ptr->red 	= (short)htcs2Ptr->I2CData.reply[1];
  htcs2Ptr->green = (short)htcs2Ptr->I2CData.reply[2];
  htcs2Ptr->blue	= (short)htcs2Ptr->I2CData.reply[3];
  RGBtoHSV(htcs2Ptr->red, htcs2Ptr->green, htcs2Ptr->blue, &htcs2Ptr->hue, &htcs2Ptr->saturation, &htcs2Ptr->value);

  return true;
}

bool readSensorRaw(tHTCS2Ptr htcs2Ptr)
{
  memset(htcs2Ptr->I2CData.request, 0, sizeof(htcs2Ptr->I2CData.request));

  htcs2Ptr->I2CData.request[0] = 2;                         // Message size
  htcs2Ptr->I2CData.request[1] = htcs2Ptr->I2CData.address; // I2C Address
  htcs2Ptr->I2CData.request[2] = HTCS2_OFFSET + HTCS2_COLNUM_REG;
  htcs2Ptr->I2CData.replyLen = 8;
  htcs2Ptr->I2CData.requestLen = 2;

  if (!writeI2C(&htcs2Ptr->I2CData))
    return false;

  htcs2Ptr->red 	= (short)htcs2Ptr->I2CData.reply[1];
  htcs2Ptr->green = (short)htcs2Ptr->I2CData.reply[3];
  htcs2Ptr->blue	= (short)htcs2Ptr->I2CData.reply[5];
  htcs2Ptr->white	= (short)htcs2Ptr->I2CData.reply[7];

  RGBtoHSV(htcs2Ptr->red, htcs2Ptr->green, htcs2Ptr->blue, &htcs2Ptr->hue, &htcs2Ptr->saturation, &htcs2Ptr->value);

  return true;
}


bool _sensorSendCommand(tHTCS2Ptr htcs2Ptr) {
  bool retVal = false;

  memset(htcs2Ptr->I2CData.request, 0, sizeof(htcs2Ptr->I2CData.request));

  htcs2Ptr->I2CData.request[0] = 3;              // Message size
  htcs2Ptr->I2CData.request[1] = HTCS2_I2C_ADDR; // I2C Address
  htcs2Ptr->I2CData.request[2] = HTCS2_CMD_REG;  // Command register
  htcs2Ptr->I2CData.request[3] = htcs2Ptr->_cmd; // Command to be sent

  retVal = writeI2C(&htcs2Ptr->I2CData);
  htcs2Ptr->_cmd = HTCS2_MODE_ACTIVE;

  return retVal;
}

#endif
