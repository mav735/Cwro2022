void WaterLeftRoomWithCube(){ //work
    Paws('c');
    delay(100);
    if (left_bottle){
        BrakeLeftRightMotor(1);
        delay(300);
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
        BrakeLeftRightMotor(1);
        delay(300);
        right_bottle = 0;
        TankTurn(-35);

        PointTurn(-280, 0, 25, 1);
        BrakeLeftRightMotor(1);
        
        MainManipulator('t')
        AccelerationDist(40, 0);
        Paws('c');
        BrakeLeftRightMotor(1);
        TankTurn(-158);
        AccelerationLinePID(150, 1);
        AccelerationLinePID(BetweenSensorsAndMiddle - 10, 0);
    }
}

void WaterLeftRoomNoCube(){ //work
    if (right_bottle){
        right_bottle = 0;
        TankTurn(-90);
        BrakeLeftRightMotor(1);
        MainManipulator('t')
        AccelerationDist(40, 0);
        Paws('c');
        TankTurn(-120);
        PointTurn(390, 0, 20, 1);
        AccelerationLinePID(10, 1);
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
        TankTurn(-20);
        AccelerationLinePID(100, 1);
        AccelerationLinePID(BetweenSensorsAndMiddle - 10, 0);
    }
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