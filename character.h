//автор: Леонид Ксинопуло 9 "В"

//LIBRARY_-_Character

#include <TXLib.h>
#ifndef _character_
#define _character_

//Class
typedef class Zombie zomb_t; ///<-CLASS Персонаж
class Zombie{
private:
    int xpic;   ///<-координата верхнего левого угла персонажа x
    int ypic;   ///<-координата верхнего левого угла персонажа y
    int wide;   ///<-ширина персонажа
    int high;   ///<-высота персонажа
    int Vx;     ///<-скорость персонажа относительно холста  x
    int Vy;     ///<-скорость персонажа относительно холста y
    HDC zombie; ///<-дискриптор спрайта персонажа
    int x;      ///<-координата персонажа x
    int y;      ///<-координата персонажа y
    int Chet;   ///<-подсчёт количества собранных бонусов (монеток ресурсов и т.п.)
    int level;  ///<- номер уровня (персонаж)
    int surf;
    int keychest;
    int harpoon;
    int lose;
    int win;

public:

    Zombie();           ///<- конструктор класса Zombie
    ~Zombie();          ///<- деструктор класса Zombie
    Zombie(const Zombie &zombie);
    Zombie& operator = (Zombie);
    void init();        ///<-функция для инициализации персонажа
    void draw();        ///<-функция рисования персонажа
    void move_up();     ///<-движение вверх
    void move_down();   ///<-движение вниз
    void move_left();   ///<-движение влево
    void move_right();  ///<-движение вправо
    void Check_Keys();  ///<-проверка клавиш
    void delete_DC();   ///<-функция для удаления всех картинок из памяти
    void boundaries();  ///<-функция для проверки положения персонажа

    //////////////////////////////////////////
    //передача значений приватных переменных//
    int get_x(){
        return x;}
    int get_y(){
        return y;}
    int get_Chet(){
        return Chet;}
    int get_level(){
        return level;}
    int get_surf(){
        return surf;}
    int get_Vy(){
        return Vy;}
    int get_keychest(){
        return keychest;}
    int get_harpoon(){
        return harpoon;}
    int get_lose(){
        return lose;}
    int get_win(){
        return win;}
    int get_xpic(){
        return xpic;}
    int get_ypic(){
        return ypic;}


    ///////////////////////////////////////////
    //изменение значений приватных переменных//
    void set_x();
    void set_y();
    void set_Chet_0();
    void set_Chet_p();
    void set_level();
    void set_level_0();
    void set_surf_1();
    void set_surf_0();
    void set_y_mm();
    void set_Vy_1();
    void set_Vy_4();
    void set_keychest_0();
    void set_keychest_1();
    void set_harpoon_0();
    void set_harpoon_1();
    void set_lose_0();
    void set_lose_1();
    void set_win_0();
    void set_win_1();
    void invisible();
    void visible();
    void winning();
};

//Конструктор

Zombie::Zombie() : xpic(0),ypic(0),wide(80),high(80),Vx(1),Vy(1),zombie(0),x(1),y(1),Chet(0),level(1),surf(0),keychest(0),harpoon(0),lose(0),win(0)
{
    x=1;
    y=1;
    xpic=0;
    ypic=0;
    wide=80;
    high=80;
    Vx=1;
    Vy=1;
    Chet=0;
    level=1;
    surf=0;
    harpoon=0;
    zombie = txLoadImage ("zombie.bmp");
    if(!zombie)
    {
        txMessageBox("Нужный файл не найден! Требуется проверка места нахождения файла. Без него запустить программу, увы, не получится. Проверьте место нахождения файла и попробуйте снова!", "Ошибка!");
        return;
    }
}

//Оператор присваивания

Zombie& Zombie::operator = (Zombie z)
{
    x=z.x;
    y=z.y;
    xpic=z.xpic;
    ypic=z.ypic;
    wide=z.wide;
    high=z.high;
    Vx=z.Vx;
    Vy=z.Vy;
    Chet=z.Chet;
    level=z.level;
    surf=z.surf;
    harpoon=z.harpoon;
    zombie = nullptr;
    return *this;
}

//Деструктор

Zombie::~Zombie()
{
    delete_DC();
}

//Zombie functions

void Zombie::init()
{
    x=1;
    y=1;
    xpic=0;
    ypic=0;
    wide=80;
    high=80;
    Vx=1;
    Vy=1;
    Chet=0;
    level=1;
    zombie = txLoadImage ("zombie.bmp");
    if(!zombie)
    {
        txMessageBox("Нужный файл не найден! Требуется проверка места нахождения файла. Без него запустить программу, увы, не получится. Проверьте место нахождения файла и попробуйте снова!", "Ошибка!");
        return;
    }
}

void Zombie::draw()
{
        Win32::TransparentBlt(txDC(), x*wide, y*high,wide,high, zombie,xpic,ypic,170, 270, TX_WHITE);
}

//UP

void Zombie::move_up()
{

    if(surf==0)
    {
        if(Chet==68&&level==1)
        {
            ypic = 1370;
            xpic += 190;
            if(xpic > 450)
                xpic = 0;
            y-=Vy;
        }
        else
        {
            ypic = 270;
            xpic += 190;
            if(xpic > 450)
                xpic = 0;
            y-=Vy;
        }
    }
    if(surf==1)
    {
        if(harpoon==0)
        {
            ypic = 550;
            xpic = 750;
            y-=Vy;
        }
        if(harpoon==1)
        {
            ypic = 1130;
            xpic = 750;
            y-=Vy;
        }
        if(lose==1)
        {
            xpic=600;
            ypic=2000;
            Vx=0;
            Vy=0;
        }
    }
    if(win==1)
    {
        xpic=860;
        ypic=1720;
        Vx=0;
        Vy=0;
        x=15;
        y=2;
    }
}

//DOWN

void Zombie::move_down()
{
    if(surf==0)
    {
        if(Chet==68&&level==1)
        {
            ypic = 1100;
            xpic += 190;
            if(xpic > 450)
                xpic = 0;
            y+=Vy;
        }
        else
        {
            ypic = 0;
            xpic += 190;
            if(xpic > 450)
                xpic = 0;
            y+=Vy;
        }
    }
    if(surf==1)
    {
        if(harpoon==0)
        {
            ypic = 550;
            xpic = 580;
            y+=Vy;
        }
        if(harpoon==1)
        {
            ypic = 1130;
            xpic = 580;
            y+=Vy;
        }
        if(lose==1)
        {
            xpic=600;
            ypic=2000;
            Vx=0;
            Vy=0;
        }
    }
    if(win==1)
    {
        xpic=860;
        ypic=1720;
        Vx=0;
        Vy=0;
        x=16;
        y=2;
    }

}

//LEFT

void Zombie::move_left()
{
    if(surf==0)
    {
        if(Chet==68&&level==1)
        {
            ypic = 1900;
            xpic += 150;
            if(xpic > 400)
                xpic = 0;
            x-=Vx;
        }
        else
        {
            ypic = 800;
            xpic += 150;
            if(xpic > 400)
                xpic = 0;
            x-=Vx;
        }
    }
    if(surf==1)
    {
        if(harpoon==0)
        {
            ypic = 840;
            xpic = 750;
            x-=Vx;
        }
        if(harpoon==1)
        {
            ypic = 1410;
            xpic = 750;
            x-=Vx;
        }
        if(lose==1)
        {
            xpic=600;
            ypic=2000;
            Vx=0;
            Vy=0;
        }
    }
    if(win==1)
    {
        xpic=860;
        ypic=1720;
        Vx=0;
        Vy=0;
        x=16;
        y=2;
    }

}

//RIGHT

void Zombie::move_right()
{
    if(surf==0)
    {
        if(Chet==68&&level==1)
        {
            ypic = 1650;
            xpic += 150;
            if(xpic > 400)
                xpic = 0;
            x+=Vx;
        }
        else
        {
            ypic = 550;
            xpic += 150;
            if(xpic > 400)
                xpic = 0;
            x+=Vx;
        }
    }
    if(surf==1)
    {
        if(harpoon==0)
        {
            ypic = 840;
            xpic = 580;
            x+=Vx;
        }
        if(harpoon==1)
        {
            ypic = 1410;
            xpic = 580;
            x+=Vx;
        }
        if(lose==1)
        {
            xpic=600;
            ypic=2000;
            Vx=0;
            Vy=0;
        }
    }
    if(win==1)
    {
        xpic=860;
        ypic=1720;
        Vx=0;
        Vy=0;
        x=16;
        y=2;
    }

}

void Zombie::delete_DC()
{
    txDeleteDC(zombie);
}

void Zombie::boundaries()
{
    if(x*80>1280)
    {
        x=16;
    }
    if(x*80<0)
    {
        x=0;
    }
    if(y*80>720)
    {
        y=9;
    }
    if(y*80<0)
    {
        y=0;
    }
}

//Zombie private set():

void Zombie::set_x()
{
    x=1;
}
void Zombie::set_y()
{
    y=1;
}
void Zombie::set_Chet_0()
{
    Chet=0;
}
void Zombie::set_Chet_p()
{
    Chet++;
}
void Zombie::set_level()
{
    level++;
}
void Zombie::set_surf_1()
{
    surf=1;
}
void Zombie::set_surf_0()
{
    surf=0;
}
void Zombie::set_level_0()
{
    level=1;
}
void Zombie::set_y_mm()
{
    y++;
}
void Zombie::set_Vy_1()
{
    Vy=1;
}
void Zombie::set_Vy_4()
{
    Vy=2;
}
void Zombie::set_harpoon_0()
{
    harpoon=0;
}
void Zombie::set_harpoon_1()
{
    harpoon=1;
}
void Zombie::set_lose_0()
{
    lose=0;
}
void Zombie::set_lose_1()
{
    lose=1;
}
void Zombie::set_win_0()
{
    win=0;
}
void Zombie::set_win_1()
{
    win=1;
}
void Zombie::invisible()
{
    xpic=600;
    ypic=2000;
    Vx=0;
    Vy=0;
}
void Zombie::visible()
{
    xpic=0;
    ypic=0;
    Vx=1;
    Vy=1;
}
void Zombie::winning()
{
    xpic=860;
    ypic=1720;
    Vx=0;
    Vy=0;
    x=16;
    y=2;
}
void Zombie::set_keychest_0()
{
    keychest=0;
}
void Zombie::set_keychest_1()
{
    keychest=1;
}

#endif
