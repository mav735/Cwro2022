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
    short washLeftRoom = 0;
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
        }
        AccelerationDist(20);

        // если правая вода есть
        if (getBottleVal(1) != 0)
        {
            // выкладывание правой воды
            LeftWheelTurn(34);
            BrakeLeftRightMotor(1);
            putWaterOnTable(1);

            //выписка воды
            setBottle(1, 0);

            //отъезд назад
            AccelerationDist(-32);
            startTask(waterUp);
            BrakeLeftRightMotor(1);
            sleep(100);
            AccelerationDist(36.5);
            TankTurn(132);
            BrakeLeftRightMotor(1);

            // возврат на линию
            AccelerationDist(150);
            AccelerationLinePID(100, 1);
            MoveBeforeTurn();
        }
        else
        {
            // выкладывание левой воды
            RightWheelTurn(45);
            BrakeLeftRightMotor(1);
            putWaterOnTable(0);

            //выписка воды
            setBottle(0, 0);

            //отъезд назад
            AccelerationDist(-32);
            startTask(waterUp);
            BrakeLeftRightMotor(1);
            sleep(100);
            AccelerationDist(30);
            TankTurn(59);
            BrakeLeftRightMotor(1);

            // возврат на линию
            AccelerationDist(150);
            AccelerationLinePID(100, 1);
            MoveBeforeTurn();
        }
    }
    // если мячик
    else
    {
        // если белье есть
        if (washLeftRoom != 0)
        {
            // доворот до белья
            RightWheelTurn(-90);
            BrakeLeftRightMotor(1);

            // взять белье
            takeCube(washLeftRoom);

            // шарик
            RightWheelTurn(-90);
            AccelerationDist(-150);
            BrakeLeftRightMotor(1);
            takeBall();

            // скинуть шарик
            RightWheelTurn(-87);
            AccelerationDist(-150);
            BrakeLeftRightMotor(1);
            throwBall_firstPart();

            // возврат на линию
            AccelerationDist(150);
            TankTurn(-100);
            AccelerationDist(300);
            AccelerationLinePID(100, 1);
            MoveBeforeTurn();
        }
        // если белья нет
        else
        {
            // доезд до шарика
            AccelerationDist(75.4);
            TankTurn(123);
            AccelerationDist(-43.6, 0.001, 10);
            BrakeLeftRightMotor(1);
            waitForButtonPress();

            // взять шарик
            takeBall();

            // доехать до лунки и скинуть шарикx
            flushButtonMessages();
            waitForButtonPress();
            AccelerationDist(100);
            TankTurn(60);
            AccelerationDist(-100);
            BrakeLeftRightMotor(1);
            throwBall_firstPart();

            // возврат на линию
            AccelerationDist(150);
            startTask(throwBall_secondPart);
            setMotorBrakeMode(leftMotor, motorBrake);
            RightWheelTurn(30);
            AccelerationDist(300);
            AccelerationLinePID(100, 1);
            MoveBeforeTurn();
        }
    }

    // комната заканчивается там же, где и начинается, но с противоположным градусом поворота робота
    return washLeftRoom;
}

void Rooms()
{
    // движение до линии с маркерами
    AccelerationLinePID(405, 1);

    // где-то тут считывание маркеров
    short markerLeft = 0;
    short markerRight = 0;

    // движение к комнате
    MoveBeforeTurn();
    AbsTurn(360);

    // leftRoom
    short washLeftRoom = leftRoom(markerLeft);
}
