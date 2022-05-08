void Move_1_7(){
    AbsTurn(180);
    AccelerationLinePID(170, 0);
    PointTurn(176, 0, 90, 1);
    AccelerationLinePID(213 - BetweenSensorsAndMiddle, 1);
    AccelerationDist(BetweenSensorsAndMiddle);
    EditAngle(270);
}

void Move_1_13(){
    AbsTurn(180);
    AccelerationLinePID(170, 0);
    PointTurn(176, 0, 90, 1);
    AccelerationLinePID(530 - BetweenSensorsAndMiddle, 1);
    AccelerationDist(BetweenSensorsAndMiddle);
    EditAngle(270);
}

void Move_1_13_sensor_on_line(){
    AbsTurn(180);
    AccelerationLinePID(190, 0);
    PointTurn(176, 0, 90, 1);
    AccelerationLinePID(530 - BetweenSensorsAndMiddle, 1);
    EditAngle(270);
}

void Move_1_19(){
    AbsTurn(180);
    AccelerationLinePID(190, 0);
    PointTurn(176, 0, 90, 1);
    AccelerationLinePID(717 - BetweenSensorsAndMiddle, 1);
    AccelerationDist(BetweenSensorsAndMiddle);
    EditAngle(270);
}

void Move_1_19_with_reading(){
    AbsTurn(180);
    AccelerationLinePID(160, 0, 1);
    short now_speed = fabs(getMotorSpeed(leftMotor));
    PointTurn(176, 0, 90, 1, 0.8, now_speed);

    now_speed = fabs(getMotorSpeed(leftMotor));
    AccelerationLinePID(530 - BetweenSensorsAndMiddle, 0, 0, now_speed);
    BrakeLeftRightMotor(0);

    ReadIndicator(50, 50);

    AccelerationLinePID(147 - BetweenSensorsAndMiddle, 1, 0, now_speed);
    AccelerationLinePID(BetweenSensorsAndMiddle - 10, 0, 0);
    BrakeLeftRightMotor(1);

    if (ht_results[0] > 300){
		left_indicator = 'W';
	}
	else{
		left_indicator = 'G';
	}
	
	if (ht_results[1] > 300){
		right_indicator = 'W';
	}
	else{
		right_indicator = 'G';
	}
    EditAngle(270);
}

void Move_1_3(){
    AbsTurn(180);
    AccelerationLinePID(170, 0);
    PointTurn(-176, 0, -90, 1);
    AccelerationLinePID(213 - BetweenSensorsAndMiddle, 1);
    AccelerationDist(BetweenSensorsAndMiddle);
    EditAngle(90);
}

void Move_1_10(){
    AbsTurn(180);
    AccelerationLinePID(170, 0);
    PointTurn(-176, 0, -90, 1);
    AccelerationLinePID(530 - BetweenSensorsAndMiddle, 1);
    AccelerationDist(BetweenSensorsAndMiddle);
    EditAngle(90);
}

void Move_1_16(){
    AbsTurn(180);
    AccelerationLinePID(170, 0);
    PointTurn(-176, 0, -90, 1);
    AccelerationLinePID(717 - BetweenSensorsAndMiddle, 1);
    AccelerationDist(BetweenSensorsAndMiddle);
    EditAngle(90);
}

void Take_bottles(){
    TankTurn(45);
    BrakeLeftRightMotor(1);
    delay(100);
    setMotorSpeed(elevatorMotor, -80);
    AccelerationDist(-390, 0.4);
    BrakeLeftRightMotor(1);
    setMotorSpeed(elevatorMotor, 80);
    delay(100);
    setMotorSpeed(elevatorMotor, 0);
    delay(20);
    startTask(ZeroMotorPaw, 7);
    EditAngle(180);
}

void bottles(){
    if (cube != 'N'){
        TankTurn(-35);
        Paws('o');
        AccelerationDist(BetweenSensorsAndMiddle);
        BrakeLeftRightMotor(1);
        Paws('c');
        TankTurn(-55);
        BrakeLeftRightMotor(1);
    }
}

void blue_room(){
    AbsTurn(180);
    AccelerationLinePID(187 - BetweenSensorsAndMiddle, 0);
    AccelerationDist(95);
    BrakeLeftRightMotor(1);
    waitForButtonPress();
    ReadLeftWash(33, 20);
    BrakeLeftRightMotor(1);
    if (cube != 'N'){
        if (left_indicator == 'G'){
            setMotorSpeed(elevatorMotor, 100);
        }
        else{
            Paws('o');
        }
        TankTurn(-60);
        AccelerationDist(160, 0);
    }
    playSound(soundFastUpwardTones);
    BrakeLeftRightMotor(1);
    waitForButtonPress();
    if (left_indicator == 'G'){
        LeftWheelTurn(50);
    }
    else{
        TankTurn(-40);
    }
}

void yellow_room(){
    AbsTurn(360);
    AccelerationLinePID(192 - BetweenSensorsAndMiddle, 0);
    AccelerationDist(75);
    BrakeLeftRightMotor(1);
    ReadRightWash(33, 20);
    
    if (cube != 'N'){
        if (right_indicator == 'G'){
            setMotorSpeed(elevatorMotor, 100);
        }
        else{
            Paws('o');
        }
        TankTurn(60);
        AccelerationDist(160, 0);
        if (right_indicator != 'G'){
            Paws('c');
        }
    }
    BrakeLeftRightMotor(1);
    if (right_indicator == 'G'){
        LeftWheelTurn(33);
        BrakeLeftRightMotor(1);
        GrabManipulator('b');
        Paws('c');
        TankTurn(-92);
        BrakeLeftRightMotor(1);
        AccelerationDist(220, 0);
        BrakeLeftRightMotor(1);
        delay(50);
        setMotorSpeed(grabMotor, -100);
        delay(100);
        TankTurn(-110);
    }
    else{
        TankTurn(-40);
    }
}