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
    TankTurn(-114);
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