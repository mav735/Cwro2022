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

void leftRoom(short markerLeft)
{
    // заезд в комнату
    AccelerationLinePID(110);
    AccelerationDist(190);
    BrakeLeftRightMotor(1);

    // считывание белья
    short washLeftRoom = 0;

    // движения в комнате
    // если вода
    if (markerLeft == 6)
    {
        // доворот до белья и воды
        AccelerationDist(100);
        RightWheelTurn(-90);
        BrakeLeftRightMotor(1);

        // если белье есть
        if (washLeftRoom != 0)
        {
            takeCube(washLeftRoom);
        }

        // если левая вода есть
        if (getBottleVal(0) != 0)
        {
            // выкладывание левой воды
            LeftWheelTurn(20);
            BrakeLeftRightMotor(1);
            putWaterOnTable();

            //выписка воды
            setBottle(0, 0);

            //отъезд назад
            AccelerationDist(-100);
            BrakeLeftRightMotor(1);
            startTask(waterUp);
            TankTurn(60);
            BrakeLeftRightMotor(1);

            // возврат на линию
            AccelerationDist(200);
            AccelerationLinePID(100, 1);
            MoveBeforeTurn();
        }
        else
        {
            // выкладывание правой воды
            RightWheelTurn(20);
            BrakeLeftRightMotor(1);
            putWaterOnTable();

            //выписка воды
            setBottle(1, 0);

            //отъезд назад
            AccelerationDist(-100);
            BrakeLeftRightMotor(1);
            startTask(waterUp);
            TankTurn(70);
            BrakeLeftRightMotor(1);

            // возврат на линию
            AccelerationDist(200);
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
            AccelerationDist(100);
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
            // доезда до шарика
            TankTurn(120);
            AccelerationDist(-100);

            // взять шарик
            takeBall();

            // доехать до лунки и скинуть шарик
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
}

void Rooms()
{
    // движение до линии с маркерами
    AccelerationLinePID(160, 1);

    // где-то тут считывание маркеров
    short markerLeft = 0;
    short markerRight = 0;

    // движение к комнате
    AccelerationLinePID(120, 1);
    MoveBeforeTurn();
    AbsTurn(360);

    // leftRoom
    leftRoom(markerLeft);
}
