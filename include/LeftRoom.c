void WaterLeftRoomNoCube(){ //work
    if (right_bottle){
        right_bottle = 0;
        TankTurn(-90);
        BrakeLeftRightMotor(1);
        MainManipulator('t')
        AccelerationDist(40, 0);
        Paws('c');
        delay(20);
        AccelerationDist(-40, 0);
        TankTurn(-90);
        AccelerationLinePID(100, 1);
        AccelerationLinePID(BetweenSensorsAndMiddle - 10, 0);
    }
    else if(left_bottle){
        left_bottle = 0;
        AccelerationDist(-20, 0);
        TankTurn(-150);
        BrakeLeftRightMotor(1);
        MainManipulator('t')
        AccelerationDist(40, 0);
        Paws('c');
        delay(20);
        AccelerationDist(-40, 0);
        TankTurn(-30);
        AccelerationLinePID(100, 1);
        AccelerationLinePID(BetweenSensorsAndMiddle - 10, 0);
    }
}

void WaterLeftRoomWithCube(){ //work
    Paws('c');
    BrakeLeftRightMotor(1);
    delay(200);

    AccelerationDist(-190, 0);
    TankTurn(50);
    AccelerationDist(20, 0);
    WaterLeftRoomNoCube();
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
    TankTurn(114);
    AccelerationDist(170, 1);
}

void BallLeftRoomNoCube(){ //work Stable
    setMotorSpeed(elevatorMotor, 100);
    AccelerationDist(-50);
    delay(50);
    BrakeLeftRightMotor(1);
    TankTurn(-92);
    PointTurn(190, 0, 95, 1);
    AccelerationDist(14);
    BrakeLeftRightMotor(1);
    delay(50);
    setMotorSpeed(grabMotor, 50);
    delay(70);
    Paws('c');
    TankTurn(65);
    BrakeLeftRightMotor(1);
    delay(50);
    AccelerationDist(210);
    BrakeLeftRightMotor(1);
    setMotorSpeed(grabMotor, -100);
    delay(50);
    AccelerationDist(-20);
    TankTurn(115);
    AccelerationDist(170);
}