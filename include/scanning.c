void ReadIndicator(short len_millimeters, short speed){
	BrakeLeftRightMotor(0);
	float enc_left_motor = getMotorEncoder(leftMotor);
	float enc_right_motor = getMotorEncoder(rightMotor);

	float moved_motors = 0;
	float now_millimeters = 0;

	int sum_rl = 0;
	int sum_gl = 0;
	int sum_bl = 0;

	int sum_rr = 0;
	int sum_gr = 0;
	int sum_br = 0;

	pr_error_tacho = 0;
	SyncedMotorsPair turn_pair;

	turn_pair.max_motor_element = rightMotor;
	turn_pair.min_motor_element = leftMotor;

	turn_pair.speed_cof = -1;

	turn_pair.max_motor_enc = enc_right_motor;
	turn_pair.min_motor_enc = enc_left_motor;

	while(now_millimeters < len_millimeters) {
		readSensorRaw(&colorLeftSensor,  &MarkerInfoRawLeft);
		readSensorRaw(&colorRightSensor, &MarkerInfoRawRight);

		sum_rl += colorLeftSensor.red_calibrated;
		sum_gl += colorLeftSensor.green_calibrated;
		sum_bl += colorLeftSensor.blue_calibrated;

		sum_rr += colorRightSensor.red_calibrated;
		sum_gr += colorRightSensor.green_calibrated;
		sum_br += colorRightSensor.blue_calibrated;

		moved_motors = MotorsAbsMovedDegreesLR(enc_left_motor, enc_right_motor);
		now_millimeters = DegreesToMillimeters(moved_motors);
		DrivePIDTacho(speed, turn_pair);
	}

	ht_results[0] = sum_rl + sum_gl + sum_bl;
	ht_results[1] = sum_rr + sum_gr + sum_br;
}

void ReadLeftWash(short len_millimeters, short speed){
	BrakeLeftRightMotor(0);

	float enc_left_motor = getMotorEncoder(leftMotor);
	float enc_right_motor = getMotorEncoder(rightMotor);

	float moved_motors = 0;
	float now_millimeters = 0;

	int sum_rl = 0;
	int sum_gl = 0;
	int sum_bl = 0;

	pr_error_tacho = 0;
	results_sensors -> firstSensor = 0;
	results_sensors -> secondSensor = 0;

	SyncedMotorsPair turn_pair;

	turn_pair.max_motor_element = rightMotor;
	turn_pair.min_motor_element = leftMotor;

	turn_pair.speed_cof = -1;

	turn_pair.max_motor_enc = enc_right_motor;
	turn_pair.min_motor_enc = enc_left_motor;

	while(now_millimeters < len_millimeters) {
		readSensorRaw(&colorLeftSensor,  &WashInfoRawLeft);

		sum_rl += colorLeftSensor.red_calibrated;
		sum_gl += colorLeftSensor.green_calibrated;
		sum_bl += colorLeftSensor.blue_calibrated;

		moved_motors = MotorsAbsMovedDegreesLR(enc_left_motor, enc_right_motor);
		now_millimeters = DegreesToMillimeters(moved_motors);
		DrivePIDTacho(speed, turn_pair);
	}

	ht_results[0] = sum_rl + sum_gl + sum_bl;
}

void ReadRightWash(short len_millimeters, short speed){
	BrakeLeftRightMotor(0);

	float enc_left_motor = getMotorEncoder(leftMotor);
	float enc_right_motor = getMotorEncoder(rightMotor);

	float moved_motors = 0;
	float now_millimeters = 0;

	int sum_rr = 0;
	int sum_gr = 0;
	int sum_br = 0;

	pr_error_tacho = 0;

	SyncedMotorsPair turn_pair;

	turn_pair.max_motor_element = rightMotor;
	turn_pair.min_motor_element = leftMotor;

	turn_pair.speed_cof = -1;

	turn_pair.max_motor_enc = enc_right_motor;
	turn_pair.min_motor_enc = enc_left_motor;

	while(now_millimeters < len_millimeters) {
		readSensorRaw(&colorRightSensor,  &WashInfoRawRight);

		sum_rr += colorRightSensor.red_calibrated;
		sum_gr += colorRightSensor.green_calibrated;
		sum_br += colorRightSensor.blue_calibrated;

		moved_motors = MotorsAbsMovedDegreesLR(enc_left_motor, enc_right_motor);
		now_millimeters = DegreesToMillimeters(moved_motors);
		DrivePIDTacho(speed, turn_pair);
	}

	ht_results[1] = sum_rr + sum_gr + sum_br;
}