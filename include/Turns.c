void PointTurn(float point_x, float point_y, float w_degrees, char type_move, float speed_up_part = 0.5, float speed = min_speed_const) {
	//point coords are relative from robot middle wheel base
	//type y (1 - turn; 2 - move (forward/backward))
	
	float right_w_radius = 0;
	float left_w_radius = 0;
	float start_speed = speed - 5;
	float w_cof = 1;
	float tank_cof = 1;

	pr_error_tacho = 0;

	if (point_x >= axleTrack / 2) {
		right_w_radius = point_x - axleTrack / 2;
		left_w_radius = point_x + axleTrack / 2;
		w_cof = 1;
	}
	else if (point_x == 0) {
		right_w_radius = axleTrack / 2;
		left_w_radius = -1 * axleTrack / 2;
		tank_cof = -1;	
	}
	else if(point_x <= -1 * (axleTrack / 2)) {
		right_w_radius = fabs(point_x) + axleTrack / 2;
		left_w_radius = point_x + axleTrack / 2;
		w_cof = -1;
	}
	else {
		playSound(soundBeepBeep);
	}

	float speeds_way = 1;

	if (w_degrees < 0) {
		speeds_way = -1;
	}

	float len_left_w_mm = PI * fabs(left_w_radius) * 2 / 360 * fabs(w_degrees);
	float len_right_w_mm = PI * fabs(right_w_radius) * 2 / 360 * fabs(w_degrees);

	tMotor max_motor = leftMotor;
	tMotor min_motor = rightMotor;
	float start_enc_max = getMotorEncoder(leftMotor);
	float start_enc_min = getMotorEncoder(rightMotor);
	float max_radius = len_left_w_mm;
	float speeds_cof = 0;

	if (len_left_w_mm == 0) {
		speeds_cof = 0;
	}
	else {
		speeds_cof = len_right_w_mm / len_left_w_mm * tank_cof;
	}

	int sign_speed = -1;

	if (right_w_radius > left_w_radius) {
		max_motor = rightMotor;
		min_motor = leftMotor;
		start_enc_max = getMotorEncoder(rightMotor);
		start_enc_min = getMotorEncoder(leftMotor);
		max_radius = len_right_w_mm;

		if (len_right_w_mm == 0) {
			speeds_cof = 0;
		}
		else {
			speeds_cof = len_left_w_mm / len_right_w_mm * tank_cof;
		}

		sign_speed = 1;
	}

	if (speeds_cof != 0){
		start_speed /= fabs(speeds_cof);
	}
	
	float moved_motor = MotorAbsMovedDegrees(max_motor, start_enc_max);
	float now_millimeters = DegreesToMillimeters(moved_motor);

	float total_cof = ((speed * (0 - sign_speed) * speeds_way * w_cof * speeds_cof) / (speed * sign_speed * speeds_way * w_cof));
	short speed_sign = sgn(speed * sign_speed * speeds_way * w_cof);

	SyncedMotorsPair turn_pair;
  
	turn_pair.max_motor_element = max_motor;
	turn_pair.min_motor_element = min_motor;

	turn_pair.speed_cof = total_cof;
	
	turn_pair.max_motor_enc = start_enc_max;
	turn_pair.min_motor_enc = start_enc_min;

	float start_time = getTimerValue(T1);
	while(now_millimeters < max_radius * speed_up_part) {
		speed = SpeedCounter(start_speed, 1, getTimerValue(T1) - start_time);

		if (speed > max_speed_const) {
			speed = max_speed_const;
		}

		DrivePIDTacho(speed * speed_sign, turn_pair);

		moved_motor = MotorAbsMovedDegrees(max_motor, start_enc_max);
		now_millimeters = DegreesToMillimeters(moved_motor);
	}

	float max_part_speed = speed;
	start_time = getTimerValue(T1);

	while(now_millimeters < max_radius) {
		speed = SpeedCounter(max_part_speed, -1, getTimerValue(T1) - start_time);

		if (speed < min_speed_const) {
			speed = min_speed_const;
		}

		DrivePIDTacho(speed * speed_sign, turn_pair);

		moved_motor = fabs(MotorAbsMovedDegrees(max_motor, start_enc_max));
		now_millimeters = DegreesToMillimeters(moved_motor);
	}

	pr_error_tacho = 0;
}

void LeftWheelTurn(float w_degrees){
	PointTurn(-1 * axleTrack / 2, 0, -1 * w_degrees, 1);
}

void RightWheelTurn(float w_degrees){
	PointTurn(axleTrack / 2, 0, w_degrees, 1);
}

void TankTurn(float w_degrees){
	PointTurn(0, 0, -1 * w_degrees, 1);
}

void AbsTurn(float need_angle){
	float w_angle = 0;
	if (need_angle - NOW_ANGLE != 0){
		if (need_angle == 360){
			if (fabs(need_angle - NOW_ANGLE) < fabs(0 - NOW_ANGLE)){
				w_angle = need_angle - NOW_ANGLE;
			}
			else {
				w_angle = 0 - NOW_ANGLE;
			}
		}
		else {
			if (NOW_ANGLE == 360){
				if (fabs(need_angle - 360) < fabs(need_angle)){
					w_angle = need_angle - 360;
				}	
				else{
					w_angle = need_angle;
				}
			}	
			else{
				w_angle = need_angle - NOW_ANGLE;
			}
		}
		TankTurn(w_angle);
	}
	NOW_ANGLE = need_angle;
}

void EditAngle(float need_angle){
	NOW_ANGLE = need_angle;
}

void MoveBeforeTurn(){
	AccelerationDist(BetweenSensorsAndMiddle);
}