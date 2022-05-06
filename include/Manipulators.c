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
    moveMotor(grabMotor, -1335, -100, 1);
    moveMotor(grabMotor, 1307, 100, 1);

    // записать кубик
    arr_push_back(arr_objectsInRobot, cubeCol);
}

int throwCube()
{
    // бросить кубик
    moveMotor(waterMotor, -300, -50, 1);
    moveMotor(waterMotor, 295, 50, 0);

    // выписать кубик
    //return arr_cutFirst(arr_objectsInRobot);
    return 0;
}

long getFirstCube()
{
    return arr_objectsInRobot.pointer[0];
}

void putWaterOnTable()
{
    moveMotor(waterMotor, -180, -45, 1);
}

task waterUp()
{
    setMotorSpeed(waterMotor, 100);
    sleep(1500);
    brakeWaterMotor();
    sleep(200);
    brakeWaterMotor(1);
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
    moveMotor(grabMotor, 50, 50, 1);
}

void throwBall_firstPart()
{
    moveMotor(grabMotor, 400, 50, 1);
}

task throwBall_secondPart()
{
    moveMotor(grabMotor, 200, 50, 1);
}
