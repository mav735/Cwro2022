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
    AccelerationLinePID(530 - BetweenSensorsAndMiddle, 0, 0.7, now_speed);
    BrakeLeftRightMotor(0);

    ReadIndicator(50, 60);

    AccelerationLinePID(147 - BetweenSensorsAndMiddle, 1, 0, 60);
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

void BallRightRoomWithCube(){
    setMotorSpeed(elevatorMotor, 100);
    TankTurn(-49);

    AccelerationDist(54, 0);
    BrakeLeftRightMotor(1);

    setMotorSpeed(grabMotor, 100);
    delay(50);

    Paws('c');
    TankTurn(-77.5);
    AccelerationDist(165);
    BrakeLeftRightMotor(1);
    setMotorSpeed(grabMotor, -100);
    delay(50);
    AccelerationDist(-15, 0);
    TankTurn(-112);
    AccelerationDist(170, 1);
}

void BallLeftRoomWithCube(){
    setMotorSpeed(elevatorMotor, 100);
    TankTurn(49);

    AccelerationDist(54, 0);
    BrakeLeftRightMotor(1);

    setMotorSpeed(grabMotor, 100);
    delay(50);

    Paws('c');
    TankTurn(77.5);
    AccelerationDist(165);
    BrakeLeftRightMotor(1);
    setMotorSpeed(grabMotor, -100);
    delay(50);
    AccelerationDist(-15, 0);
    TankTurn(112);
    AccelerationDist(170, 1);
}

void BallRightRoomNoCube(){
    setMotorSpeed(elevatorMotor, 100);
    AccelerationDist(-20);
    delay(50);
    BrakeLeftRightMotor(1);
    TankTurn(30);
    AccelerationDist(220);
    BrakeLeftRightMotor(1);
    setMotorSpeed(grabMotor, 50);
    delay(70);
    Paws('c');
    TankTurn(-102.5);
    AccelerationDist(110);
    BrakeLeftRightMotor(1);
    setMotorSpeed(grabMotor, -100);
    delay(50);
    TankTurn(-110);
    AccelerationDist(170);
}

void WaterRightRoomWithCube(){
    Paws('c');
    delay(100);
    if (left_bottle){
        left_bottle = 0;
        TankTurn(40);
        PointTurn(200, 0, -40, 1);
        BrakeLeftRightMotor(1);
        MainManipulator('t')
        AccelerationDist(40, 0);
        Paws('c');
        BrakeLeftRightMotor(1);
        TankTurn(158);
        PointTurn(-280, 0, -20, 1);
        AccelerationLinePID(30, 1);
        AccelerationLinePID(BetweenSensorsAndMiddle - 10, 0);
    }
    else if(right_bottle){
        right_bottle = 0;
        TankTurn(20);
        PointTurn(-200, 0, 40, 1);
        BrakeLeftRightMotor(1);
        MainManipulator('t')
        AccelerationDist(40, 0);
        Paws('c');
        BrakeLeftRightMotor(1);
        TankTurn(93);
        PointTurn(-450, 0, -20, 1);
        AccelerationLinePID(30, 1);
        AccelerationLinePID(BetweenSensorsAndMiddle - 10, 0);
    }
}

void WaterLeftRoomWithCube(){
    Paws('c');
    delay(100);
    left_bottle = 0;
    if (left_bottle){
        Paws('c');
        delay(200);
        left_bottle = 0;
        TankTurn(-35);
        PointTurn(500, 0, -15, 1);
        BrakeLeftRightMotor(1);
        MainManipulator('t')
        AccelerationDist(40, 0);
        Paws('c');
        BrakeLeftRightMotor(1);
        TankTurn(-110);
        PointTurn(250, 0, 25, 1, 1);
        AccelerationLinePID(160, 1);
        AccelerationLinePID(BetweenSensorsAndMiddle - 10, 0);
    }
    else if(right_bottle){
        Paws('c');
        right_bottle = 0;
        TankTurn(-35);
        PointTurn(-280, 0, 25, 1);
        BrakeLeftRightMotor(1);
        MainManipulator('t')
        AccelerationDist(40, 0);
        Paws('c');
        BrakeLeftRightMotor(1);
        TankTurn(-158);
        PointTurn(300, 0, 20, 1);
        AccelerationLinePID(80, 1);
        AccelerationLinePID(BetweenSensorsAndMiddle - 10, 0);
    }
}

void WaterRightRoomNoCube(){
    if (left_bottle){
        left_bottle = 0;
        TankTurn(90);
        BrakeLeftRightMotor(1);
        MainManipulator('t')
        AccelerationDist(40, 0);
        Paws('c');
        TankTurn(120);
        PointTurn(-390, 0, -20, 1);
        AccelerationLinePID(10, 1);
        AccelerationLinePID(BetweenSensorsAndMiddle - 10, 0);
    }
    else if(right_bottle){
        right_bottle = 0;
        AccelerationDist(120, 0);
        TankTurn(90);
        BrakeLeftRightMotor(1);
        MainManipulator('t')
        AccelerationDist(40, 0);
        Paws('c');
        TankTurn(120);
        PointTurn(-400, 0, -20, 1);
        AccelerationLinePID(100, 1);
        AccelerationLinePID(BetweenSensorsAndMiddle - 10, 0);
    }
}

void yellow_room(){
    AbsTurn(360);
    AccelerationLinePID(192 - BetweenSensorsAndMiddle, 0);
    AccelerationDist(75, 0);
    BrakeLeftRightMotor(1);
    ReadRightWash(33, 20);
    BrakeLeftRightMotor(1);

    if (cube != 'N'){
        AccelerationDist(-20, 0);
        TankTurn(60);
        BrakeLeftRightMotor(1);

        if (right_indicator == 'G'){
            setMotorSpeed(elevatorMotor, 100);
        }
        else{
            Paws('o');
        }

        AccelerationDist(190, 0);
        BrakeLeftRightMotor(1);

        if (right_indicator == 'G'){
            BallRightRoomWithCube();
            short now_speed = fabs(getMotorSpeed(leftMotor));
            AccelerationLinePID(190 - BetweenSensorsAndMiddle, 1, 0.6, now_speed);
            AccelerationLinePID(BetweenSensorsAndMiddle, 0);
        }
        else{
            WaterRightRoomWithCube()
        }
    }
    else{
        if (right_indicator == 'G'){
            BallRightRoomNoCube()
            AccelerationLinePID(190 - BetweenSensorsAndMiddle, 1);
            AccelerationLinePID(BetweenSensorsAndMiddle, 0);
        }
        else{
            WaterRightRoomNoCube()
        }
    }
}

void blue_room(){
    AbsTurn(180);
    AccelerationLinePID(187 - BetweenSensorsAndMiddle, 0);
    AccelerationDist(75, 0);
    BrakeLeftRightMotor(1);
    ReadLeftWash(33, 20);
    BrakeLeftRightMotor(1);

    if (cube != 'N'){
        AccelerationDist(-20, 0);
        TankTurn(-58);
        BrakeLeftRightMotor(1);

        if (right_indicator == 'G'){
            setMotorSpeed(elevatorMotor, 100);
        }
        else{
            Paws('o');
        }

        AccelerationDist(190, 0);
        BrakeLeftRightMotor(1);

        if (right_indicator == 'G'){
            BallLeftRoomWithCube();
            short now_speed = fabs(getMotorSpeed(leftMotor));
            AccelerationLinePID(180 - BetweenSensorsAndMiddle, 1, 0.6, now_speed);
            AccelerationLinePID(BetweenSensorsAndMiddle, 0);
        }
        else{
            WaterLeftRoomWithCube()
        }
    }
    else{
        if (right_indicator == 'G'){
            BallRightRoomNoCube()
            AccelerationLinePID(190 - BetweenSensorsAndMiddle, 1);
            AccelerationLinePID(BetweenSensorsAndMiddle, 0);
        }
        else{
            WaterRightRoomNoCube()
        }
    }
}