short bottle0 = 0;
short bottle1 = 0;

Array arr_objectsInRobot;
int objectsInRobot[5];

void InitCubes()
{
    arr_objectsInRobot.pointer = &objectsInRobot;
    arr_objectsInRobot.len = 5;

    arr_fill(arr_objectsInRobot, -228);
}

task openGrabers()
{
    moveMotor(grabMotor, -1037, -100, 1);
    moveMotor(grabMotor, 1833, 100, 1);
}

void takeCube(short cubeCol)
{
    // записать кубик
    arr_push_back(arr_objectsInRobot, cubeCol);


    // захват кубика
    moveMotor(grabMotor, -800, -70, 0);
}

int throwCube()
{
    // бросить кубик
    setMotorSpeed(waterMotor, -50);
    sleep(600);
    setMotorSpeed(waterMotor, 100);
    sleep(500);

    // выписать кубик
    arr_cutFirst(arr_objectsInRobot);
    return 0;
}

long getFirstCube()
{
    //BrakeLeftRightMotor(1);
    //displayCenteredTextLine(8, "%d %d %d", arr_objectsInRobot.pointer[0], arr_objectsInRobot.pointer[1], arr_objectsInRobot.pointer[2]);
    //sleep(40000);
    return arr_objectsInRobot.pointer[0];
}

void putWaterOnTable(char type)
{
    if (type == 0)
    {
        moveMotor(waterMotor, -305, -30, 1);
    }
    else
    {
        // правая вода
        moveMotor(waterMotor, -265, -28, 1);
    }
    // sleep(150);
}

task waterUp()
{
    setMotorSpeed(waterMotor, 15);
    sleep(200);
    setMotorSpeed(waterMotor, 60);
    sleep(150);
    brakeWaterMotor(1);
    setMotorSpeed(waterMotor, 30);
    sleep(600);
    brakeWaterMotor(1);
}

task waterUpStart()
{
    setMotorSpeed(waterMotor, 20);
    sleep(500);
    setMotorSpeed(waterMotor, 4);
    sleep(1700)
    setMotorSpeed(waterMotor, 40);
    sleep(900);
    setMotorSpeed(waterMotor, 60);
    sleep(300);
    brakeWaterMotor(1);
    setMotorSpeed(waterMotor, 30);
    sleep(600);
    brakeWaterMotor(1);
}

task grabStart(){
    moveMotor(grabMotor, 1730, 100, 1);
}

task grabFinish(){
    moveMotor(grabMotor, -1730, -100, 1);
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
    moveMotor(grabMotor, 1200, -100, 1);
}

task takeBall_task(){
    moveMotor(grabMotor, 70, -100, 1);
}

void throwBall_firstPart()
{
    moveMotor(grabMotor, 750, 100, 1);
    moveMotor(grabMotor, 950, -100, 1);
}

task throwBall_secondPart()
{
    moveMotor(grabMotor, 1470, 100, 1);
}

task waterFullDown(){
    setMotorSpeed(waterMotor, -15);
    sleep(200);
    setMotorSpeed(waterMotor, -60);
    sleep(1000);
    brakeWaterMotor(1);
    setMotorSpeed(waterMotor, -30);
    sleep(600);
    brakeWaterMotor(1);
}
