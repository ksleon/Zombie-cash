//автор: Леонид Ксинопуло 9 "В"

//LIBRARY_-_Background

#include <TXLib.h>
#ifndef _background_
#define _background_

//Class
typedef class Background ground_t; ///<-CLASS Карта
class Background{
private:
    int N;      ///<- параметр размера карты N (номер строки)
    int M;      ///<- параметр размера карты M (номер столбца)
    int mx;     ///<- координата персонажа X
    int my;     ///<- координата персонажа Y
    int wide;   ///<-ширина карты
    int high;   ///<-высота карты
    int type;   ///<- тип клетки массива
    int level;  ///<- номер уровня
    HDC ground; ///<- дискриптор карты (для её отображения)

public:

    int karta[9][16];        ///<- массив N на M клеток карты
    Background();            ///<- конструктор класса Background
    ~Background();           ///<- деструктор класса Background
    Background(const Background &background);
    Background& operator = (Background);
    void init();             ///<- функция для инициализации карты - заполнение массива числами, загрузка и проверка картинок
    void draw();             ///<- функция для рисования карты - отображение на экране N на M клеток, раскрашенных текстурами в соответствии с таблицей
    void delete_DC();        ///<- функция для удаления всех картинок из памяти
    void get_cell(int x,int y);         ///<- функция для получения содержимого клетки, расположенной в точке с координатами x,y
    void set_cell();         ///<- функция для записи числа в клетку

    //////////////////////////////////////////
    //передача значений приватных переменных//
    int get_type(){
        return type;}
    int get_level(){
        return level;}
    int get_KARTA_massive(){
        return karta[9][16];}



    ///////////////////////////////////////////
    //изменение значений приватных переменных//
    void set_type();
    void set_level_p();
    void set_level_0();
    void final_picture();
    void set_KARTA_massive();
};

//Конструктор

Background::Background() : N(9),M(16),mx(1),my(1),wide(80),high(80),type(0),level(1),ground(0)
{
    N=9;
    M=16;
    mx=1;
    my=1;
    wide=80;
    high=80;
    type=0;
    level=1;
    ground = txLoadImage("map_sheet.bmp");
    int level1[9][16] = {{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
                         {2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2},
                         {2,0,0,0,3,3,3,3,3,0,0,0,0,3,3,2},
                         {2,3,3,0,3,3,0,0,4,0,3,3,0,3,3,2},
                         {2,3,3,0,3,3,0,3,3,0,3,3,0,3,3,2},
                         {2,3,3,0,3,3,0,4,0,0,3,3,0,3,3,2},
                         {2,3,3,0,0,0,0,3,3,3,3,3,0,0,0,2},
                         {2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2},
                         {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}};
    if(!ground)
    {
        txMessageBox("Нужный файл не найден! Требуется проверка места нахождения файла. Без него запустить программу, увы, не получится. Проверьте место нахождения файла и попробуйте снова!", "Ошибка!");
        return;
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            karta[i][j]=level1[i][j];
}

//Оператор присваивания

Background& Background::operator = (Background b)
{
    N=b.N;
    M=b.M;
    mx=b.mx;
    my=b.my;
    wide=b.wide;
    high=b.high;
    type=b.type;
    level=b.level;
    ground = nullptr;
    return *this;
}

//Деструктор

Background::~Background()
{
    delete_DC();
}

//Background functions

void Background::init()
{
    N=9;
    M=16;
    mx=1;
    my=1;
    wide=80;
    high=80;
    type=0;
    level=1;
    ground = txLoadImage("map_sheet.bmp");
    int level1[9][16] = {{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
                         {2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2},
                         {2,0,0,0,3,3,3,3,3,0,0,0,0,3,3,2},
                         {2,3,3,0,3,3,0,0,4,0,3,3,0,3,3,2},
                         {2,3,3,0,3,3,0,3,3,0,3,3,0,3,3,2},
                         {2,3,3,0,3,3,0,4,0,0,3,3,0,3,3,2},
                         {2,3,3,0,0,0,0,3,3,3,3,3,0,0,0,2},
                         {2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2},
                         {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}};
    if(!ground)
    {
        txMessageBox("Нужный файл не найден! Требуется проверка места нахождения файла. Без него запустить программу, увы, не получится. Проверьте место нахождения файла и попробуйте снова!", "Ошибка!");
        return;
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            karta[i][j]=level1[i][j];
}

void Background::draw()
{
    txClear();
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(karta[i][j]==1)                                                                                  ///<- Земля
            {
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,220,85,55,55,RGB(64,96,64));
            }
            else
            {
                if(karta[i][j]==2)                                                                              ///<- TNT блок
                    Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,0,580,90,86,RGB(64,96,64));
                else
                    Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,0,400,100,100,RGB(64,96,64));
            }
            if(karta[i][j]==0)                                                                                  ///<- Вода
            {
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,0,400,100,100,RGB(64,96,64));
            }
            if(karta[i][j]==3)                                                                                  ///<-Монета
            {
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,220,85,55,55,RGB(64,96,64));
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,680,480,70,70,RGB(0,0,0));
            }
            else if(karta[i][j]==4)                                                                             ///<-Лестница (целая)
            {
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,0,400,100,100,RGB(64,96,64));
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,415,320,60,60,RGB(64,96,64));
            }
            else if(karta[i][j]==5)                                                                             ///<-Лестница (сломанная)
            {
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,0,400,100,100,RGB(64,96,64));
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,510,320,60,60,RGB(64,96,64));
            }
            else if(karta[i][j]==6)                                                                             ///<-Взрыв
            {
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,220,85,55,55,RGB(64,96,64));
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,15,505,70,70,RGB(64,96,64));
            }
            else if(karta[i][j]==7)                                                                             ///<-Доска (сёрфинг)
            {
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,0,400,100,100,RGB(64,96,64));
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,0,80,80,60,RGB(64,96,64));
            }
            else if(karta[i][j]==8)                                                                             ///<-Туннель
            {
                if(karta[i][j-1]==0)
                    Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,0,400,100,100,RGB(64,96,64));
                if(karta[i][j+1]==3||karta[i][j+1]==1||karta[i][j-1]==3||karta[i][j-1]==1)
                    Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,220,85,55,55,RGB(64,96,64));
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,849,380,76,80,RGB(64,96,64));
            }
            else if(karta[i][j]==9)                                                                             ///<-Каменная стена
            {
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,0,160,100,100,RGB(64,96,64));
            }
            if(karta[i][j]==10)                                                                                  ///<-Монета на воде
            {
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,0,400,100,100,RGB(64,96,64));
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,680,480,70,70,RGB(0,0,0));
            }
            if(karta[i][j]==11)                                                                                  ///<-Небо
            {
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,1155,85,80,80,RGB(64,96,64));
            }
            if(karta[i][j]==12)                                                                                  ///<-Трава
            {
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,125,83,60,60,RGB(64,96,64));
            }
            if(karta[i][j]==13)                                                                                  ///<-Монета в воздухе
            {
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,1155,85,80,80,RGB(64,96,64));
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,680,480,70,70,RGB(0,0,0));
            }
            if(karta[i][j]==14)                                                                                  ///<-Кубок
            {
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,1155,85,80,80,RGB(64,96,64));
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,1170,190,80,80,RGB(64,96,64));
            }
            if(karta[i][j]==15)                                                                                  ///<-Сундук
            {
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,0,160,100,100,RGB(64,96,64));
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,170,490,90,60,RGB(64,96,64));
            }
            if(karta[i][j]==16)                                                                                  ///<- Открытый Сундук
            {
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,0,160,100,100,RGB(64,96,64));
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,270,480,90,60,RGB(64,96,64));
            }
            if(karta[i][j]==17)                                                                                  ///<- Плавник Акулы
            {
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,0,400,100,100,RGB(64,96,64));
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,1150,300,105,80,RGB(64,96,64));
            }
            if(karta[i][j]==18)                                                                                  ///<- Кровавый след
            {
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,0,400,100,100,RGB(64,96,64));
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,1150,370,105,100,RGB(64,96,64));
            }
            if(karta[i][j]==19)                                                                                  ///<- Акула!
            {
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,0,400,100,100,RGB(64,96,64));
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,1260,300,105,100,RGB(64,96,64));
            }
            if(karta[i][j]==20)                                                                                  ///<- Ключ от сундука
            {
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,220,85,55,55,RGB(64,96,64));
                Win32::TransparentBlt(txDC(),wide*j,high*i,wide,high, ground,380,490,60,70,RGB(0,0,0));
            }
        }

    }
}

void Background::delete_DC()
{
    txDeleteDC(ground);
}

void Background::set_cell()
{
    int level1[9][16] = {{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
                         {2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2},
                         {2,0,0,0,3,3,3,3,3,0,0,0,0,3,3,2},
                         {2,3,3,0,3,3,0,0,4,0,3,3,0,3,3,2},
                         {2,3,3,0,3,3,0,3,3,0,3,3,0,3,3,2},
                         {2,3,3,0,3,3,0,4,0,0,3,3,0,3,3,2},
                         {2,3,3,0,0,0,0,3,3,3,3,3,0,0,0,2},
                         {2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2},
                         {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}};

    int level2[9][16] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0},
                         {0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0},
                         {0,3,3,3,3,3,0,3,3,3,0,3,3,3,3,0},
                         {0,0,4,0,4,0,0,4,0,0,0,4,0,0,4,0},
                         {0,3,3,3,3,0,3,3,3,0,3,3,20,0,3,0},
                         {0,4,0,4,0,0,0,0,4,0,0,4,0,0,3,0},
                         {0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0},
                         {17,7,0,0,0,0,0,0,0,0,0,0,0,0,0,8}};

    int level3[9][16] = {{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                         {9,8,10,10,10,10,10,10,10,10,10,10,10,10,10,15},
                         {9,9,9,9,9,9,9,9,9,9,9,9,9,9,4,9},
                         {9,10,10,10,10,10,10,10,10,10,10,10,10,9,4,9},
                         {9,4,9,9,9,9,9,9,9,9,9,9,4,9,4,9},
                         {9,4,9,8,10,10,10,10,10,10,10,10,10,9,4,9},
                         {9,4,9,9,9,9,9,9,9,9,9,9,9,9,4,9},
                         {9,10,10,10,10,17,10,10,10,10,10,10,10,10,10,9},
                         {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9}};

    int level4[9][16] = {{11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11},
                         {11,11,11,11,11,11,11,11,11,13,13,11,11,13,13,14},
                         {11,11,11,11,11,11,11,11,13,12,12,11,11,12,12,12},
                         {11,11,11,13,13,13,11,13,12,11,11,11,11,11,11,11},
                         {11,11,11,12,12,12,11,12,11,11,11,11,11,11,11,11},
                         {11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11},
                         {11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11},
                         {11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11},
                         {12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12}};
    if(level==1)
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                karta[i][j]=level1[i][j];
    }
    if(level==2)
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                karta[i][j]=level2[i][j];
    }
    if(level==3)
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                karta[i][j]=level3[i][j];
    }
    if(level==4)
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                karta[i][j]=level4[i][j];
    }
}

//Background private set():

void Background::set_type()
{
    type=0;
}
void Background::set_level_p()
{
    level++;
}
void Background::final_picture()
{
    Win32::TransparentBlt(txDC(),320,360,600,150, ground,960,0,320,60,RGB(64,96,64));
}
void Background::set_level_0()
{
    level=1;
}

#endif
