float SpeedCounter(float speed, int acceleration_value, int time_delta)
{
	// acceleration value - 1 || -1, speed up or speed down
	float now_speed = speed + acceleration * time_delta * acceleration_value;
	return now_speed;
}

float MotorAbsMovedDegrees(tMotor motor_name, float start_value)
{
	float moved = fabs(getMotorEncoder(motor_name) - start_value);
	return moved;
}

float MotorsAbsMovedDegreesLR(float start_degrees_left, float start_degrees_right)
{
	float moved = (MotorAbsMovedDegrees(leftMotor, start_degrees_left) + MotorAbsMovedDegrees(rightMotor, start_degrees_right)) / 2;
	return moved;
}

float DegreesToMillimeters(float degrees_input)
{
	float millimiters = degrees_input * PI * wheelDiameter / 360;
	return millimiters;
}

void BrakeLeftRightMotor(char stop_type = 0)
{
	if (stop_type)
	{
		setMotorBrakeMode(leftMotor, motorBrake);
		setMotorBrakeMode(rightMotor, motorBrake);
	}
	else
	{
		setMotorBrakeMode(leftMotor, motorCoast);
		setMotorBrakeMode(rightMotor, motorCoast);
	}
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
}

void brakeWaterMotor(char stop_type = 0)
{
	if (stop_type)
	{
		setMotorBrakeMode(waterMotor, motorBrake);
	}
	else
	{
		setMotorBrakeMode(waterMotor, motorCoast);
	}
	setMotorSpeed(waterMotor, 0);
}

void brakeGrabMotor(char stop_type = 0)
{
	if (stop_type)
	{
		setMotorBrakeMode(grabMotor, motorBrake);
	}
	else
	{
		setMotorBrakeMode(grabMotor, motorCoast);
	}
	setMotorSpeed(grabMotor, 0);
}

void stopMotor(tMotor motor_name, char stop_type = 0)
{
	if (stop_type)
	{
		setMotorBrakeMode(motor_name, motorBrake);
	}
	else
	{
		setMotorBrakeMode(motor_name, motorCoast);
	}
	setMotorSpeed(motor_name, 0);
}

void moveMotor(tMotor motor, int deg, short speed, char stop)
{
	int start_deg = getMotorEncoder(motor);
	setMotorSpeed(motor, speed);
	while (MotorAbsMovedDegrees(motor, start_deg) < fabs(deg))
	{
	};
	stopMotor(motor, stop);
}

