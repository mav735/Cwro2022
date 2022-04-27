float SteerCounterTacho(float speed, SyncedMotorsPair MotorPair){
	float mot_max = MotorAbsMovedDegrees(MotorPair.max_motor_element, MotorPair.max_motor_enc);
	float mot_min = MotorAbsMovedDegrees(MotorPair.min_motor_element, MotorPair.min_motor_enc);
	float error;
	
	if (MotorPair.speed_cof == 0){
		error = 0;
	}
	else{
		error =  (fabs(mot_max * MotorPair.speed_cof) - mot_min) / (fabs(MotorPair.speed_cof) + 1);
	}

	float actionP = error * Kp_tacho * (speed / 60);
	float actionI = (error + pr_error_tacho) * Ki_tacho;
	float actionD = (error - pr_error_tacho) * Kd_tacho;

	float steer = actionP + actionI + actionD;

	pr_error_tacho = error;

	return steer;
}

void DrivePIDTacho(int speed, SyncedMotorsPair MotorPair) {
	float steer = SteerCounterTacho(speed, MotorPair);
	short sgn_speed = sgn(speed);

	float speed_fab_max = fabs(speed);
	float speed_fab_min = fabs(speed * MotorPair.speed_cof);

	setMotorSpeed(MotorPair.max_motor_element, (speed_fab_max - steer) * sgn_speed);
	setMotorSpeed(MotorPair.min_motor_element, (speed_fab_min + steer) * sgn_speed * sgn(MotorPair.speed_cof));

	delay(2);
}
