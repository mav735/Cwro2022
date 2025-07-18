const float Kp = 0.3;
const float Ki = 0;
const float Kd = 7.7;

const float Kp_tacho = 0.35;
const float Ki_tacho = 0.3;
const float Kd_tacho = 5.5;

byte left_bottle = 1;
byte right_bottle = 1;

const float axleTrack = 175.5;
const float wheelDiameter = 80;
const float BetweenSensorsAndMiddle = 73;

const float left_min_sensor = 2480;
const float right_min_sensor = 2380;

const float left_max_sensor = 1804;
const float right_max_sensor = 1716;

const float max_speed_const = 80;
const float min_speed_const = 18;

const float acceleration = 0.04; // speed_points/ms^2

float NOW_ANGLE = 45;
float pr_error = 0;
float pr_error_tacho = 0;

typedef struct {
	tMotor max_motor_element;
	tMotor min_motor_element;

	float speed_cof;

	float max_motor_enc;
	float min_motor_enc;
} SyncedMotorsPair;

typedef struct {
	float firstSensor;
	float secondSensor;
} Arraysensors;

typedef struct {
	char *commands;
	byte weight;
} weights_struct;

weights_struct* InitStructWeight (char *command, byte weight) {
	weights_struct *w_pointer;
	weights_struct w;

	w.commands = command;
	w.weight = weight;
	w_pointer = &w;

	return w_pointer;
}

Arraysensors *results_sensors = NULL;
int ht_results[2];
char left_indicator = 'G';
char right_indicator = 'G';
char cube = 'N';

tHTCS2 colorRightSensor;
tHTCS2 colorLeftSensor;

CalibrationHiTechData CloseDistInfoLeft;
CalibrationHiTechData MiddleDistInfoLeft;
CalibrationHiTechData LongDistInfoLeft;

CalibrationHiTechData CloseDistInfoRawLeft;
CalibrationHiTechData MiddleDistInfoRawLeft;
CalibrationHiTechData LongDistInfoRawLeft;

CalibrationHiTechData CloseDistInfoRight;
CalibrationHiTechData MiddleDistInfoRight;
CalibrationHiTechData LongDistInfoRight;

CalibrationHiTechData CloseDistInfoRawRight;
CalibrationHiTechData MiddleDistInfoRawRight;
CalibrationHiTechData LongDistInfoRawRight;

CalibrationHiTechData MarkerInfoRawLeft;
CalibrationHiTechData MarkerInfoRawRight;

CalibrationHiTechData WashInfoRawLeft;
CalibrationHiTechData WashInfoRawRight;

void InitCalibrationNormal(){
	// LEFT
	// Close Normal
	CloseDistInfoLeft.red_max = 12;
	CloseDistInfoLeft.green_max = 12;
	CloseDistInfoLeft.blue_max = 12;

	CloseDistInfoLeft.red_min = 1;
	CloseDistInfoLeft.green_min = 1;
	CloseDistInfoLeft.blue_min = 1;
	//


	// Middle Normal
	MiddleDistInfoLeft.red_max = 12;
	MiddleDistInfoLeft.green_max = 12;
	MiddleDistInfoLeft.blue_max = 12;

	MiddleDistInfoLeft.red_min = 1;
	MiddleDistInfoLeft.green_min = 1;
	MiddleDistInfoLeft.blue_min = 1;
	//

	// Long Normal
	LongDistInfoLeft.red_max = 12;
	LongDistInfoLeft.green_max = 12;
	LongDistInfoLeft.blue_max = 12;

	LongDistInfoLeft.red_min = 1;
	LongDistInfoLeft.green_min = 1;
	LongDistInfoLeft.blue_min = 1;
	//
	// LEFT ---------------------------------------------- END 

	// Close Normal
	CloseDistInfoRight.red_max = 12;
	CloseDistInfoRight.green_max = 12;
	CloseDistInfoRight.blue_max = 12;

	CloseDistInfoRight.red_min = 1;
	CloseDistInfoRight.green_min = 1;
	CloseDistInfoRight.blue_min = 1;
	//


	// Middle Normal
	MiddleDistInfoRight.red_max = 12;
	MiddleDistInfoRight.green_max = 12;
	MiddleDistInfoRight.blue_max = 12;

	MiddleDistInfoRight.red_min = 1;
	MiddleDistInfoRight.green_min = 1;
	MiddleDistInfoRight.blue_min = 1;
	//

	// Long Normal
	LongDistInfoRight.red_max = 12;
	LongDistInfoRight.green_max = 12;
	LongDistInfoRight.blue_max = 12;

	LongDistInfoRight.red_min = 1;
	LongDistInfoRight.green_min = 1;
	LongDistInfoRight.blue_min = 1;
	//
}


void InitCalibrationRaw(){
	// Close Raw
	CloseDistInfoRawLeft.red_max = 12;
	CloseDistInfoRawLeft.green_max = 12;
	CloseDistInfoRawLeft.blue_max = 12;

	CloseDistInfoRawLeft.red_min = 1;
	CloseDistInfoRawLeft.green_min = 1;
	CloseDistInfoRawLeft.blue_min = 1;
	//


	// Middle Raw
	MiddleDistInfoRawLeft.red_max = 12;
	MiddleDistInfoRawLeft.green_max = 12;
	MiddleDistInfoRawLeft.blue_max = 12;

	MiddleDistInfoRawLeft.red_min = 1;
	MiddleDistInfoRawLeft.green_min = 1;
	MiddleDistInfoRawLeft.blue_min = 1;
	//

	// Long Raw
	LongDistInfoRawLeft.red_max = 12;
	LongDistInfoRawLeft.green_max = 12;
	LongDistInfoRawLeft.blue_max = 12;

	LongDistInfoRawLeft.red_min = 1;
	LongDistInfoRawLeft.green_min = 1;
	LongDistInfoRawLeft.blue_min = 1;
	//



	// Close Raw
	CloseDistInfoRawRight.red_max = 12;
	CloseDistInfoRawRight.green_max = 12;
	CloseDistInfoRawRight.blue_max = 12;

	CloseDistInfoRawRight.red_min = 1;
	CloseDistInfoRawRight.green_min = 1;
	CloseDistInfoRawRight.blue_min = 1;
	//


	// Middle Raw
	MiddleDistInfoRawRight.red_max = 12;
	MiddleDistInfoRawRight.green_max = 12;
	MiddleDistInfoRawRight.blue_max = 12;

	MiddleDistInfoRawRight.red_min = 1;
	MiddleDistInfoRawRight.green_min = 1;
	MiddleDistInfoRawRight.blue_min = 1;
	//

	// Long Raw
	LongDistInfoRawRight.red_max = 12;
	LongDistInfoRawRight.green_max = 12;
	LongDistInfoRawRight.blue_max = 12;

	LongDistInfoRawRight.red_min = 1;
	LongDistInfoRawRight.green_min = 1;
	LongDistInfoRawRight.blue_min = 1;
	//
}

void InitMarkerCallibrationRaw() {
	MarkerInfoRawLeft.red_max = 58;
	MarkerInfoRawLeft.green_max = 90;
	MarkerInfoRawLeft.blue_max = 58;

	MarkerInfoRawLeft.red_min = 19;
	MarkerInfoRawLeft.green_min = 37;
	MarkerInfoRawLeft.blue_min = 26;

	MarkerInfoRawRight.red_max = 44;
	MarkerInfoRawRight.green_max = 71;
	MarkerInfoRawRight.blue_max = 47;

	MarkerInfoRawRight.red_min = 15;
	MarkerInfoRawRight.green_min = 31;
	MarkerInfoRawRight.blue_min = 22;
}

void InitWashCallibrationRaw (){
	WashInfoRawLeft.red_max = 59;
	WashInfoRawLeft.green_max = 90;
	WashInfoRawLeft.blue_max = 59;

	WashInfoRawLeft.red_min = 17;
	WashInfoRawLeft.green_min = 37;
	WashInfoRawLeft.blue_min = 28;

	WashInfoRawRight.red_max = 45;
	WashInfoRawRight.green_max = 72;
	WashInfoRawRight.blue_max = 46;

	WashInfoRawRight.red_min = 15;
	WashInfoRawRight.green_min = 32;
	WashInfoRawRight.blue_min = 22;
}