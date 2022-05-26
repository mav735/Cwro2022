/*
    COLORS:
    0 - NULL
    1 - r
    2 - g
    3 - b
    4 - yellow
    5 - black
    6 - white
*/

short leftRoom(short markerLeft)
{
    // заезд в комнату
    AccelerationLinePID(130);

    // считывание белья
    short washLeftRoom = 2;
    AccelerationDist(200);

    // движения в комнате
    // если вода
    if (markerLeft == 6)
    {
        // доворот до белья и воды
        AccelerationDist(75);
        LeftWheelTurn(-90);
        BrakeLeftRightMotor(1);

        // если белье есть
        if (washLeftRoom != 0)
        {
            takeCube(washLeftRoom);
            startTask(openGrabers);
            sleep(200);
        }
        AccelerationDist(20);

        // если правая вода есть
        if (getBottleVal(1) != 0)
        {
            // выкладывание правой воды
            AccelerationDist(5);
            LeftWheelTurn(28);
            BrakeLeftRightMotor(1);
            putWaterOnTable(1);

            //выписка воды
            setBottle(1, 0);

            //отъезд назад
            AccelerationDist(-35);
            startTask(waterUp);
            BrakeLeftRightMotor(1);
            sleep(100);
            AccelerationDist(39.8);
            TankTurn(125);
            BrakeLeftRightMotor(1);

            // возврат на линию
            AccelerationDist(150);
            AccelerationLinePID(100, 1);
            MoveBeforeTurn(0);
        }
        else
        {
            // выкладывание левой воды
            RightWheelTurn(50);
            BrakeLeftRightMotor(1);
            putWaterOnTable(0);

            //выписка воды
            setBottle(0, 0);

            //отъезд назад
            AccelerationDist(-40);
            startTask(waterUp);
            BrakeLeftRightMotor(1);
            sleep(200);
            AccelerationDist(37);
            BrakeLeftRightMotor(1);
            TankTurn(48);
            BrakeLeftRightMotor(1);

            // возврат на линию
            AccelerationDist(150);
            AccelerationLinePID(100, 1);
            MoveBeforeTurn(0);
        }
    }
    // если мячик
    else
    {
        // если белье есть
        if (washLeftRoom != 0)
        {
            // доворот до белья
            AccelerationDist(75);
            LeftWheelTurn(-77);
            BrakeLeftRightMotor(1);

            // взять белье
            takeCube(washLeftRoom);
            startTask(openGrabers);

            // шарик
            AccelerationDistSlow(-80)
            BrakeLeftRightMotor(1);
            sleep(2000);
            TankTurn(100, 0, 12);
            BrakeLeftRightMotor(1);
            sleep(300);
            moveDriveSync(-48, -10.5, 1);
            takeBall();
            startTask(takeBall_task);
            AccelerationDist(8.5);
            BrakeLeftRightMotor(1);

            // скинуть шарик
            LeftWheelTurn(-82);
            AccelerationDist(-79);
            BrakeLeftRightMotor(1);
            throwBall_firstPart();

            // возврат на линию
            AccelerationDist(16);
            TankTurnFast(-82);
            startTask(throwBall_secondPart);
            AccelerationDist(205);
            AccelerationLinePID(100, 1);
            MoveBeforeTurn(0);
        }
        // если белья нет
        else
        {
            // доезд до шарика
            AccelerationDist(63);
            TankTurn(125, 0, 15);
            BrakeLeftRightMotor(1);
            moveDriveSync(-64, -11, 1);

            // взять шарик
            takeBall();
            startTask(takeBall_task);

            // доехать до лунки и скинуть шарикx
            moveDriveSync(64, 20, 1);
            AccelerationDist(12);
            TankTurnFast(132);
            BrakeLeftRightMotor(1);
            AccelerationDist(-19);
            BrakeLeftRightMotor(1);
            throwBall_firstPart();

            // возврат на линию
            AccelerationDist(20.6);
            BrakeLeftRightMotor(1);
            TankTurn(-70);
            BrakeLeftRightMotor(1);
            AccelerationDist(200);
            startTask(throwBall_secondPart);
            AccelerationLinePID(120, 1);
            MoveBeforeTurn(0);
        }
    }

    // комната заканчивается там же, где и начинается, но с противоположным градусом поворота робота
    return washLeftRoom;
}

short rightRoom(short markerRight)
{
    // заезд в комнату
    AccelerationLinePID(130);

    // считывание белья
    short washRightRoom = 2;
    AccelerationDist(200);

    // движения в комнате
    // если вода
    if (markerRight == 6)
    {
        // доворот до белья и воды
        AccelerationDist(75);
        RightWheelTurn(-90);
        BrakeLeftRightMotor(1);

        // если белье есть
        if (washRightRoom != 0)
        {
            takeCube(washRightRoom);
            startTask(openGrabers);
            sleep(200);
        }
        AccelerationDist(20);

        // если левая вода есть
        if (getBottleVal(1) == 0)
        {
            // выкладывание левой воды
            AccelerationDist(5);
            RightWheelTurn(28);
            BrakeLeftRightMotor(1);
            putWaterOnTable(1);

            //выписка воды
            setBottle(0, 0);

            //отъезд назад
            AccelerationDist(-35);
            startTask(waterUp);
            BrakeLeftRightMotor(1);
            sleep(100);
            AccelerationDist(39.8);
            TankTurn(-117);
            BrakeLeftRightMotor(1);

            // возврат на линию
            AccelerationDist(150);
            AccelerationLinePID(80, 1);
            MoveBeforeTurn();
        }
        else
        {
            // выкладывание правой воды
            LeftWheelTurn(50);
            BrakeLeftRightMotor(1);
            putWaterOnTable(0);

            //выписка воды
            setBottle(1, 0);

            //отъезд назад
            AccelerationDist(-40);
            startTask(waterUp);
            BrakeLeftRightMotor(1);
            sleep(200);
            AccelerationDist(37);
            BrakeLeftRightMotor(1);
            TankTurn(-48);
            BrakeLeftRightMotor(1);

            // возврат на линию
            AccelerationDist(150);
            AccelerationLinePID(80, 1);
            MoveBeforeTurn();
        }
    }
    // если мячик
    else
    {
        // если белье есть
        if (washRightRoom != 0)
        {
            // доворот до белья
            AccelerationDist(75);
            RightWheelTurn(-77);
            BrakeLeftRightMotor(1);

            // взять белье
            takeCube(washRightRoom);
            startTask(openGrabers);

            // шарик
            AccelerationDistSlow(-80)
            BrakeLeftRightMotor(1);
            sleep(2000);
            TankTurn(-100, 0, 12);
            BrakeLeftRightMotor(1);
            sleep(300);
            moveDriveSync(-57, -10.5, 1);
            takeBall();
            startTask(takeBall_task);
            AccelerationDist(9.6);
            BrakeLeftRightMotor(1);

            // скинуть шарик
            RightWheelTurn(-82);
            AccelerationDist(-80);
            BrakeLeftRightMotor(1);
            throwBall_firstPart();

            // возврат на линию
            AccelerationDist(17);
            TankTurnFast(83);
            startTask(throwBall_secondPart);
            AccelerationDist(205);
            AccelerationLinePID(100, 1);
            MoveBeforeTurn();
        }
        // если белья нет
        else
        {
            // доезд до шарика
            AccelerationDist(61);
            TankTurn(-129, 0, 15);
            BrakeLeftRightMotor(1);
            moveDriveSync(-81, -11, 1);

            // взять шарик
            takeBall();
            startTask(takeBall_task);

            // доехать до лунки и скинуть шарикx
            moveDriveSync(81, 20, 1);
            TankTurn(-127);
            BrakeLeftRightMotor(1);
            AccelerationDist(-16);
            BrakeLeftRightMotor(1);
            throwBall_firstPart();

            // возврат на линию
            AccelerationDist(22);
            BrakeLeftRightMotor(1);
            TankTurn(70);
            BrakeLeftRightMotor(1);
            AccelerationDist(200);
            startTask(throwBall_secondPart);
            AccelerationLinePID(120, 1);
            MoveBeforeTurn();
        }

        // комната заканчивается там же, где и начинается, но с противоположным градусом поворота робота
        return washRightRoom;
    }
}

void start(){
    AccelerationDist(10);
    TankTurn(45);
    startTask(waterFullDown);
    AccelerationDist(20);
    AccelerationLinePID(100, 1);
    MoveBeforeTurn();
    startTask(waterUp);
}

void Rooms()
{
    // движение до линии с маркерами
    AccelerationLinePID(50, 1);

    // где-то тут считывание маркеров
    short markerLeft = 6;
    short markerRight = 6;

    // движение к комнате
    MoveBeforeTurn();
    TankTurnFast(-90);

    // leftRoom
    short washLeftRoom = leftRoom(markerLeft);
    short washRightRoom = rightRoom(markerRight);
}
