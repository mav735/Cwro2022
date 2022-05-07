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


