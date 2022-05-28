void yellow_room(){
    AbsTurn(360);
    AccelerationLinePID(192 - BetweenSensorsAndMiddle, 0);
    AccelerationDist(75, 0);
    BrakeLeftRightMotor(1);
    ReadRightWash(33, 20);
    BrakeLeftRightMotor(1);

    if (cube != 'N'){
        AccelerationDist(-20, 0);
        TankTurn(50);
        BrakeLeftRightMotor(1);

        if (right_indicator == 'G'){
            setMotorSpeed(elevatorMotor, 100);
        }
        else{
            Paws('o');
        }

        AccelerationDist(210, 0);
        BrakeLeftRightMotor(1);

        if (right_indicator == 'G'){
            BallRightRoomWithCube();
            short now_speed = fabs(getMotorSpeed(leftMotor));
            AccelerationLinePID(190 - BetweenSensorsAndMiddle, 1);
            AccelerationLinePID(BetweenSensorsAndMiddle, 0);
        }
        else{
            WaterRightRoomWithCube()
        }
    }
    else{
        if (right_indicator == 'G'){
            BallRightRoomNoCube();
            AccelerationLinePID(190 - BetweenSensorsAndMiddle, 1);
            AccelerationLinePID(BetweenSensorsAndMiddle, 0);
        }
        else{
            WaterRightRoomNoCube()
        }
    }
    BrakeLeftRightMotor(0);
    if (right_indicator == 'W'){
        setMotorSpeed(elevatorMotor, 100);
        delay(35)
        setMotorSpeed(elevatorMotor, 0);
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
        TankTurn(-50);
        BrakeLeftRightMotor(1);

        if (left_indicator == 'G'){
            setMotorSpeed(elevatorMotor, 100);
        }
        else{
            Paws('o');
        }

        AccelerationDist(210, 0);
        BrakeLeftRightMotor(1);

        if (left_indicator == 'G'){
            BallLeftRoomWithCube();
            short now_speed = fabs(getMotorSpeed(leftMotor));
            AccelerationLinePID(180 - BetweenSensorsAndMiddle, 1);
            AccelerationLinePID(BetweenSensorsAndMiddle, 0);
        }
        else{
            WaterLeftRoomWithCube()
        }
    }
    else{
        if (left_indicator == 'G'){
            BallLeftRoomNoCube();
            AccelerationLinePID(190 - BetweenSensorsAndMiddle, 1);
            AccelerationLinePID(BetweenSensorsAndMiddle, 0);
        }
        else{
            WaterLeftRoomNoCube()
        }
    }
    BrakeLeftRightMotor(0);
    if (left_indicator == 'W'){
        setMotorSpeed(elevatorMotor, 100);
        delay(35)
        setMotorSpeed(elevatorMotor, 0);
    }
}
