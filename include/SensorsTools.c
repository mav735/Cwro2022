Arraysensors* SensorsToPercent () {
	Arraysensors *array_pointer;
	Arraysensors array;
	array.firstSensor = (float)(SensorRaw[leftSensor] - left_min_sensor) / (left_max_sensor - left_min_sensor) * 100;
	array.secondSensor = (float)(SensorRaw[rightSensor] - right_min_sensor) / (right_max_sensor - right_min_sensor) * 100;

	if (array.firstSensor > 100) {
		array.firstSensor = 100;
	}

	if (array.secondSensor > 100) {
		array.secondSensor = 100;
	}

	array_pointer = &array;

	return array_pointer;
}

void ReadIndicator(short len_millimeters, short speed){
	float start_time = getTimerValue(T1);
	float enc_left_motor = getMotorEncoder(leftMotor);
	float enc_right_motor = getMotorEncoder(rightMotor);

	float moved_motors = MotorsAbsMovedDegreesLR(enc_left_motor, enc_right_motor);
	float now_millimeters = DegreesToMillimeters(moved_motors);

	float sum_r = 0;
	float sum_g = 0;
	float sum_b = 0;

	while(now_millimeters < len_millimeters) {
		DrivePIDTacho(speed, turn_pair);
		readSensorRaw(htcs2Ptr, data);
		moved_motors = MotorsAbsMovedDegreesLR(enc_left_motor, enc_right_motor);
		now_millimeters = DegreesToMillimeters(moved_motors);
	}
}
