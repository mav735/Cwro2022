short bottle0 = 0;
short bottle1 = 0;

Array arr_objectsInRobot;

void InitCubes()
{
	int objectsInRobot[5];
    arr_objectsInRobot.pointer = &objectsInRobot[0];
    arr_objectsInRobot.len = sizeof(objectsInRobot) / sizeof(objectsInRobot[0]);

    arr_fill(arr_objectsInRobot, -228);
}

void takeCube(short cubeCol)
{
    // захват кубика
    moveMotorTarget(grabMotor, 1000, -80);
    waitUntilMotorStop(grabMotor);
    moveMotorTarget(grabMotor, 1000, 80);
    waitUntilMotorStop(grabMotor);

    // записать кубик
    arr_push_back(arr_objectsInRobot, cubeCol);
}

int throwCube()
{
    // бросить кубик
    moveMotorTarget(waterMotor, 300, -50);
    waitUntilMotorStop(waterMotor);
    moveMotorTarget(waterMotor, 300, 100);
    waitUntilMotorStop(waterMotor);

    // выписать кубик
    return arr_cutFirst(arr_objectsInRobot);
}

long getFirstCube()
{
    return arr_objectsInRobot.pointer[0];
}

void putWaterOnTable()
{
    moveMotorTarget(waterMotor, 300, -50);
    waitUntilMotorStop(waterMotor);
}

task waterUp()
{
    setMotorSpeed(waterMotor, 50);
    sleep(1500);
    setMotorBrakeMode(waterMotor, motorCoast);
    sleep(200);
    setMotorBrakeMode(waterMotor, motorBrake);
}

void setBottle(short bottle_num, short new_val)
{
    if (bottle_num == 0)
    {
        bottle0 = new_val;
    }
    else
    {
        bottle1 = new_val;
    }
}

short getBottleVal(short bottle_num)
{
    if (bottle_num == 0)
    {
        return bottle0;
    }
    else
    {
        return bottle1;
    }
}

void takeBall()
{
    moveMotorTarget(grabMotor, 600, -50);
    waitUntilMotorStop(grabMotor);
}

void throwBall_firstPart()
{
    moveMotorTarget(grabMotor, 400, 50);
}

task throwBall_secondPart()
{
    moveMotorTarget(grabMotor, 200, 50);
}
