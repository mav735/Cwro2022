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

long get_colorWash_left(int rawHT)
{
    if (rawHT > 1100){
        return 4;
    }
    else if (rawHT < 1100 && rawHT > 800){
        return 1;
    }
    else if (rawHT < 800 && rawHT > 200){
        return 5;
    }
    return 0;
}

long get_colorWash_right(int rawHT)
{
    if (rawHT > 1100){
        return 4;
    }
    else if (rawHT < 1100 && rawHT > 800){
        return 1;
    }
    else if (rawHT < 800 && rawHT > 200){
        return 5;
    }
    return 0;
}

short leftRoom(short markerLeft)
{
    AccelerationLinePID(130);
    // считывание белья
    AccelerationDist(185);
    ReadLeftWash(15, 20);
    BrakeLeftRightMotor(1);
    displayCenteredBigTextLine(8, "%d", ht_results[0]);
    displayCenteredBigTextLine(12, "%d", get_colorWash_left(ht_results[0]));
    short washLeftRoom = get_colorWash_left(ht_results[0]);

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
            AccelerationDist(-45);
            BrakeLeftRightMotor(1);

            startTask(waterUp);
            sleep(400);

            AccelerationDist(49.8);
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
            AccelerationDist(-50);
            BrakeLeftRightMotor(1);

            startTask(waterUp);
            sleep(400);

            AccelerationDist(47);
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
            AccelerationDistSlow(-80);
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
            TankTurnFast(-80);
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
    AccelerationDist(185);
    ReadRightWash(15, 20);
    BrakeLeftRightMotor(1);
    displayCenteredBigTextLine(8, "%d", ht_results[1]);
    displayCenteredBigTextLine(12, "%d", get_colorWash_right(ht_results[1]));
    short washRightRoom = get_colorWash_right(ht_results[1]);

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
            AccelerationDist(-45);
            BrakeLeftRightMotor(1);

            startTask(waterUp);
            sleep(500);

            AccelerationDist(49.8);
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
            AccelerationDist(-50);
            BrakeLeftRightMotor(1);

            startTask(waterUp);
            sleep(500);

            AccelerationDist(47);
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
            AccelerationDistSlow(-75)
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
            moveDriveSync(-76, -11, 1);

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

int get_colorMarker_left(long rawHTRes)
{
    if (rawHTRes > 2000)
    {
        return 6;
    }
    else
    {
        return 2;
    }
}

int get_colorMarker_right(long rawHTRes)
{
    if (rawHTRes > 1000)
    {
        return 6;
    }
    else
    {
        return 2;
    }
}

void Rooms()
{
    // движение до линии с маркерами
    AccelerationLinePID(200, 1, 1);
    AccelerationDist(100, 1, 80);
    ReadIndicator(40, 90);
    AccelerationLinePID(50, 1, 0.1);
    MoveBeforeTurn(1);
    TankTurn(-90);
    displayCenteredBigTextLine(8, "%d", get_colorMarker_left(ht_results[0]));
    displayCenteredBigTextLine(12, "%d", get_colorMarker_right(ht_results[1]));

    // где-то тут считывание маркеров
    short markerLeft = get_colorMarker_left(ht_results[0]);
    short markerRight = get_colorMarker_right(ht_results[1]);

    // движение к комнате

    // leftRoom
    short washLeftRoom = leftRoom(markerLeft);
    short washRightRoom = rightRoom(markerRight);
}

void start()
{
    startTask(grabStart);
    AccelerationDistSlow(17);
    BrakeLeftRightMotor(1);
    sleep(300);
    TankTurn(48);
    BrakeLeftRightMotor(1);
    sleep(300);
    startTask(waterFullDown);
    AccelerationDist(30);
    AccelerationLinePID(130, 1);
    stopTask(waterFullDown);
    stopMotor(waterMotor, 0);
    AccelerationDist(BetweenSensorsAndMiddle - 14, 0.5, 11, 0.0001);
    BrakeLeftRightMotor(1);
    startTask(waterUpStart);
    // бутылки в роботе
    sleep(900);
    PointTurn(-333, -10, 90, 1);
    BrakeLeftRightMotor(1);
    sleep(300);
    TankTurn(194);
    BrakeLeftRightMotor(1);
    sleep(300);
    MoveBeforeTurn(0);
    // готов к комнате
}

void moveFromRoomToRoom()
{
    // комната окончена, едем к другой
    // вроде бы нам налево, но если что надо заредачить
    TankTurnFast(-90);
    // сделать тут fast
    AccelerationLinePID(400, 1);

    AccelerationLinePID(130);
    AccelerationDist(450);
    BrakeLeftRightMotor(1);
    sleep(200);
    TankTurn(45);
    BrakeLeftRightMotor(1);
    sleep(200);

    // здесь бибот должен по дуге обойти человека и встать под ~45 градусов (или не под 45 гладусов) на перекрестке
    PointTurn(-205, 0, -87, 1);
    BrakeLeftRightMotor(1);
    AccelerationDist(40);
    TankTurn(35);
    BrakeLeftRightMotor(1);
    // мы готовы ко второй комнате
}

void moveFromSecondPairRoomsToFrames()
{
    // закончили вторую комнату, едем к рамкам
    // вроде бы как нам направо, но я опять не уверен
    // как оказалось нет, нам налево
    TankTurnFast(-90);
    AccelerationLinePID(400, 1);
    MoveBeforeTurn(1);
    sleep(200);

    // надо бы опять объехать чела
    // повренуться вокруг себя, проехаться и повернуться на линию
    TankTurn(-25);
    AccelerationDist(450);
    TankTurn(-65);
    BrakeLeftRightMotor(1);
    sleep(200);
    AccelerationLinePID(100, 1);
    BrakeLeftRightMotor(1);
    // готов к рамкам
}

void actionFromPos_frames(int pos)
{
    playSound(soundBlip);
    // возможно стоит изменить абсолютный угол
    if (pos == 0)
    {
        // левая рамка относительно робота
        AbsTurn(60);
        throwCube();
        BrakeLeftRightMotor(1);
    }
    else if (pos == 1)
    {
        // центральная рамка
        AbsTurn(90);
        throwCube();
        BrakeLeftRightMotor(1);
    }
    else if (pos == 2)
    {
        // правая рамка относительно робота
        AbsTurn(120);
        throwCube();
        BrakeLeftRightMotor(1);
    }
    else{
        actionFromPos_frames(1);
    }
}

void frames_func()
{
    StartTask(grabFinish);
    // считывание
    // вращаться вокруг одной точки и считывать цвета рамок

    Array frames_array;
    int frames[3] = {1, 4, 5};
    frames_array.pointer = &frames;
    frames_array.len = sizeof(frames) / sizeof(frames[0]);

    // надо выставить абсолютный угол
    EditAngle(90);

    for (int i = 0; i < 3; i++)
    {
        // находим расположение нужной рамки
        int position = arr_find(frames_array, getFirstCube());
        // что-то сделали
        actionFromPos_frames(position);
    }
}

void finish()
{
    sleep(300);
    TankTurn(193);
    BrakeLeftRightMotor(1);
    sleep(300);
    AccelerationLinePID(60);
    AccelerationDist(240);
    BrakeLeftRightMotor(1);
    sleep(300);
    TankTurn(45);
    BrakeLeftRightMotor(1);
    sleep(300);
    AccelerationDistSlow(-5);
    BrakeLeftRightMotor(1);
    sleep(300);
}
