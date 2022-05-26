const float Kp_slow = 0.165;
const float Ki_slow = 0;
const float Kd_slow = 3.3;

const float Kp_norm = 0.155;
const float Ki_norm = 0;
const float Kd_norm = 4.3;

const float Kp_tacho = 0.485;
const float Ki_tacho = 0.20;
const float Kd_tacho = 16;

const float axleTrack = 175.5;
const float wheelDiameter = 80;
const float BetweenSensorsAndMiddle = 75;

const float left_min_sensor = 2332;
const float right_min_sensor = 2400;

const float left_max_sensor = 1616;
const float right_max_sensor = 1748;

const float max_speed_const = 80;
const float min_speed_const = 19;

const float acceleration_slow = 0.01; // speed_points/ms^2
const float acceleration = 0.05; // speed_points/ms^2

const float acceleration_turnNorm = 0.07;
const float acceleration_turnFast = 0.09;
const float acceleration_turnSuperPizdecFast = 0.12;

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
	MarkerInfoRawLeft.red_max = 174;
	MarkerInfoRawLeft.green_max = 254;
	MarkerInfoRawLeft.blue_max = 159;

	MarkerInfoRawLeft.red_min = 16;
	MarkerInfoRawLeft.green_min = 33;
	MarkerInfoRawLeft.blue_min = 25;

	MarkerInfoRawRight.red_max = 60;
	MarkerInfoRawRight.green_max = 55;
	MarkerInfoRawRight.blue_max = 54;

	MarkerInfoRawRight.red_min = 1;
	MarkerInfoRawRight.green_min = 2;
	MarkerInfoRawRight.blue_min = 2;
}

void InitWashCallibrationRaw (){
	WashInfoRawLeft.red_max = 43;
	WashInfoRawLeft.green_max = 73;
	WashInfoRawLeft.blue_max = 52;

	WashInfoRawLeft.red_min = 21;
	WashInfoRawLeft.green_min = 42;
	WashInfoRawLeft.blue_min = 32;
}