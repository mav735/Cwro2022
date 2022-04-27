task ZeroMotorPaw(){
    float speed = -20;
    if (getMotorEncoder(elevatorMotor) < 0){
        float speed = 20;
    }

    setMotorSpeed(elevatorMotor, speed);
    while (fabs(getMotorEncoder(elevatorMotor)) > 3){
    }
    setMotorSpeed(elevatorMotor, 0);
}

void Paws(char action){
    if (action == 'o'){
        moveMotorTarget(elevatorMotor, 130, 100);
    }
    else if (action == 'c'){
        startTask(ZeroMotorPaw, 7);
    }
}

void MainManipulator(char action){
    if (action == 'b'){ //ball
        setMotorSpeed(elevatorMotor, 100);
        delay(680);
        setMotorSpeed(elevatorMotor, 0);
    }
    else if (action == 'w'){ //water
        setMotorSpeed(elevatorMotor, -100);
        delay(500);
        setMotorSpeed(elevatorMotor, 0);
    }
    else if (action == 't'){ //water
        setMotorSpeed(elevatorMotor, -100);
        delay(270);
        setMotorSpeed(elevatorMotor, 0);
    }
    else if (action == 'c'){ //in stock pos
        startTask(ZeroMotorPaw, 7);
    }
}

void GrabManipulator(char action){
    if (action == 'b'){ //ball
        setMotorSpeed(elevatorMotor, 100);
        delay(680);
        setMotorSpeed(elevatorMotor, 0);
    }
    else if (action == 'w'){ //water
        setMotorSpeed(elevatorMotor, -100);
        delay(500);
        setMotorSpeed(elevatorMotor, 0);
    }
    else if (action == 't'){ //water
        setMotorSpeed(elevatorMotor, -100);
        delay(270);
        setMotorSpeed(elevatorMotor, 0);
    }
    else if (action == 'c'){ //in stock pos
        startTask(ZeroMotorPaw, 7);
    }
}