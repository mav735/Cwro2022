void WaterLeftRoomNoCube(){ //work
    if (right_bottle){
        right_bottle = 0;
        TankTurn(-90);
        BrakeLeftRightMotor(1);
        MainManipulator('t')
        AccelerationDist(50, 0);
        Paws('c');
        delay(20);
        AccelerationDist(-60, 0);
        
        TankTurn(-100);
        AccelerationLinePID(130, 1);
        AccelerationLinePID(BetweenSensorsAndMiddle - 10, 0);
    }
    else if(left_bottle){
        left_bottle = 0;
        AccelerationDist(-20, 0);
        TankTurn(-150);
        BrakeLeftRightMotor(1);
        MainManipulator('t')
        AccelerationDist(50, 0);
        Paws('c');
        delay(20);
        AccelerationDist(-60, 0);
        TankTurn(-35);
        AccelerationLinePID(130, 1);
        AccelerationLinePID(BetweenSensorsAndMiddle - 10, 0);
    }
}

void WaterLeftRoomWithCube(){ //work
    BrakeLeftRightMotor(1);

    Paws('c');
    BrakeLeftRightMotor(1);
    delay(200);

    AccelerationDist(-190, 0);

    TankTurn(43);

    WaterLeftRoomNoCube();
}

void BallLeftRoomWithCube(){
    BrakeLeftRightMotor(1);
    setMotorSpeed(elevatorMotor, 100);
    delay(100);

    TankTurn(49);

    AccelerationDist(50, 0);
    BrakeLeftRightMotor(1);
    delay(100);

    setMotorSpeed(grabMotor, 100);
    delay(100);

    Paws('c');

    TankTurn(80);

    AccelerationDist(150);
    BrakeLeftRightMotor(1);

    setMotorSpeed(grabMotor, -100);
    delay(50);

    Paws('c');

    AccelerationDist(-25, 0);
    TankTurn(105);
    AccelerationDist(160, 1);
}

void BallLeftRoomNoCube(){ //work Stable
    BrakeLeftRightMotor(0);
    setMotorSpeed(elevatorMotor, 100);
    delay(500);

    RightWheelTurn(-33)
    AccelerationDist(220);

    BrakeLeftRightMotor(1);
    delay(50);

    setMotorSpeed(grabMotor, 50);
    delay(150);

    Paws('c');

    TankTurn(102.5);
    AccelerationDist(115);
    BrakeLeftRightMotor(1);

    setMotorSpeed(grabMotor, -100);
    delay(50);

    Paws('c');

    TankTurn(117);
    AccelerationDist(170);
}