const float Kp = 0.21;
const float Ki = 0;
const float Kd = 7.6;

const float Kp_tacho = 0.2;
const float Ki_tacho = 1.5;
const float Kd_tacho = 5;

const float axleTrack = 175.5;
const float wheelDiameter = 80;
const float BetweenSensorsAndMiddle = 75;

const float left_min_sensor = 2480;
const float right_min_sensor = 2380;

const float left_max_sensor = 1804;
const float right_max_sensor = 1716;

const float max_speed_const = 80;
const float min_speed_const = 20;

const float acceleration = 0.03; // speed_points/ms^2

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