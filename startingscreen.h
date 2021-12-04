//автор: Леонид Ксинопуло 9 "В"

//LIBRARY_-_Starting Screen

#include <TXLib.h>
#ifndef _startingscreen_
#define _startingscreen_

//Class
typedef class ScreenSt screen_t;
class ScreenSt{
private:
    int t;
    int a;
    int b;
    int xTXT;
    int yTXT;
    int xpicSC;
    int ypicSC;
    int xpicTXT;
    int ypicTXT;
    int wTXT;
    int hTXT;
    HDC screen;
    HDC text;
    RECT area1;
    RECT area2;
    RECT area3;
    RECT area4;
public:
    ScreenSt();
    ~ScreenSt();
    ScreenSt(const ScreenSt &screen);
    ScreenSt& operator = (ScreenSt);
    void screen_out_draw();
    void starting_text_out();
    void Set_all();
    void delete_DC();

    //Sound effects
    void click_button_effect();
    void opened_window_effect();
    void winning_game_effect();
    void losing_game_effect();
    void bomb_effect();
    void blade_effect();

    //////////////////////////////////////////
    //передача значений приватных переменных//
    int get_t(){
        return t;}

    ///////////////////////////////////////////
    //изменение значений приватных переменных//
    void set_t_1();
    void set_t_4();
    void set_t_5();
};

//Конструктор

ScreenSt::ScreenSt() : t(0),a(400),b(140),xTXT(240),yTXT(340),xpicSC(0),ypicSC(0),xpicTXT(0),ypicTXT(0),wTXT(200),hTXT(70),screen(0),text(0),area1({ 540, 340, 740, 410 }),area2({ 540, 400, 600, 430 }),area3({ 700, 400, 760, 430 }),area4({ 580, 400, 660, 450 })
{
    t=0;
    a=400;
    b=140;
    xTXT=540;
    yTXT=340;
    xpicSC=0;
    ypicSC=0;
    xpicTXT=0;
    ypicTXT=0;
    wTXT=200;
    hTXT=70;
    screen = txLoadImage ("starting_screen.bmp");
    text = txLoadImage ("starting_text_animation.bmp");
    area1 = { 540, 340, 740, 410 };
    area2 = { 540, 400, 600, 430 };
    area3 = { 700, 400, 760, 430 };
    area4 = { 580, 400, 660, 450 };
    if(!screen)
    {
        txMessageBox("Нужный файл не найден! Требуется проверка места нахождения файла. Без него запустить программу, увы, не получится. Проверьте место нахождения файла и попробуйте снова!", "Ошибка!");
        return;
    }
    if(!text)
    {
        txMessageBox("Нужный файл не найден! Требуется проверка места нахождения файла. Без него запустить программу, увы, не получится. Проверьте место нахождения файла и попробуйте снова!", "Ошибка!");
        return;
    }
}

//Оператор присваивания

ScreenSt& ScreenSt::operator = (ScreenSt s)
{
    t=s.t;
    a=s.a;
    b=s.b;
    xTXT=s.xTXT;
    yTXT=s.yTXT;
    xpicSC=s.xpicSC;
    ypicSC=s.ypicSC;
    xpicTXT=s.xpicTXT;
    ypicTXT=s.ypicTXT;
    wTXT=s.wTXT;
    hTXT=s.hTXT;
    screen = nullptr;
    text = nullptr;
    return *this;
}

//Деструктор

ScreenSt::~ScreenSt()
{
    delete_DC();
}

void ScreenSt::delete_DC()
{
    txDeleteDC(screen);
    txDeleteDC(text);
}

void ScreenSt::screen_out_draw()
{
    Win32::TransparentBlt(txDC(),0,0,1280,720, screen,xpicSC,ypicSC,1280, 720, TX_GREEN);
}
void ScreenSt::starting_text_out()
{
    if(t==0)
    {
        system("cls");
        Win32::TransparentBlt(txDC(),xTXT,yTXT,wTXT,hTXT, text ,xpicTXT+400,ypicTXT+260,400, 130, RGB(0,255,0));
        if(In (txMousePos(), area1))
        {
            Win32::TransparentBlt(txDC(),xTXT,yTXT,wTXT,hTXT, text ,xpicTXT+800,ypicTXT+260,400, 130, RGB(0,255,0));
            system("cls");
        }
    }
    if((GetAsyncKeyState(VK_LCONTROL))||(GetAsyncKeyState(VK_RCONTROL)))
    {
        t=3;
        opened_window_effect();
    }
    else if(t==3)
    {
        Win32::TransparentBlt(txDC(),480,300,373,210, text ,xpicTXT,ypicTXT+590,745, 480, RGB(0,255,0));
        Win32::TransparentBlt(txDC(),540,400,60,30, text ,xpicTXT+790,ypicTXT+590,120,60, RGB(0,255,0));
        Win32::TransparentBlt(txDC(),700,400,60,30, text ,xpicTXT+940,ypicTXT+590,120,60, RGB(0,255,0));
        if(In (txMousePos(), area2))
        {
            system("cls");
            Win32::TransparentBlt(txDC(),540,430,60,10, text ,xpicTXT+1060,ypicTXT+640,120,20, RGB(0,255,0));
            if(txMouseButtons() == 1)
            {
                t=2;
                click_button_effect();
                system("cls");
            }
        }
        if(In (txMousePos(), area3))
        {
            system("cls");
            Win32::TransparentBlt(txDC(),700,430,60,10, text ,xpicTXT+1060,ypicTXT+640,120,20, RGB(0,255,0));
            if(txMouseButtons() == 1)
            {
                t=1;
                click_button_effect();
                system("cls");
            }
        }
    }
    else if(t==4)
    {
        Win32::TransparentBlt(txDC(),310,166,660,387, text ,xpicTXT+1600,ypicTXT+285,1320, 775, RGB(0,255,0));
        Win32::TransparentBlt(txDC(),580,400,120,50, text ,xpicTXT+790,ypicTXT+760,240,100, RGB(0,255,0));
        if(In (txMousePos(), area4))
        {
            system("cls");
            Win32::TransparentBlt(txDC(),580,440,120,10, text ,xpicTXT+1060,ypicTXT+780,240,20, RGB(0,255,0));
            if(txMouseButtons() == 1)
            {
                t=2;
                click_button_effect();
                system("cls");
            }
        }
    }
    else if(t==5)
    {
        Win32::TransparentBlt(txDC(),310,166,660,387, text ,xpicTXT+2960,ypicTXT+285,1320, 775, RGB(0,255,0));
        Win32::TransparentBlt(txDC(),580,400,120,50, text ,xpicTXT+790,ypicTXT+760,240,100, RGB(0,255,0));
        if(In (txMousePos(), area4))
        {
            system("cls");
            Win32::TransparentBlt(txDC(),580,440,120,10, text ,xpicTXT+1060,ypicTXT+780,240,20, RGB(0,255,0));
            if(txMouseButtons() == 1)
            {
                t=2;
                click_button_effect();
                system("cls");
            }
        }
    }
}

void ScreenSt::Set_all()
{
        while(t==0&&!GetAsyncKeyState(VK_ESCAPE))
        {
            txClear();
            if(t==0)
            {
                screen_out_draw();
                starting_text_out();
            }
            if((txMouseButtons() == 1)&&(In (txMousePos(), area1)))
            {
                t=1;
                click_button_effect();
                system("cls");
            }
            txSleep(100);
        }
        if(t!=0)
        {
            starting_text_out();
        }
}

void ScreenSt::click_button_effect()
{
    txPlaySound("click_button.wav");
}
void ScreenSt::opened_window_effect()
{
    txPlaySound("window_opening.wav");
}
void ScreenSt::winning_game_effect()
{
    txPlaySound("win_game_effect.wav");
}
void ScreenSt::losing_game_effect()
{
    txPlaySound("lose_game_effect.wav");
}
void ScreenSt::bomb_effect()
{
    txPlaySound("bomb_effect.wav");
}
void ScreenSt::blade_effect()
{
    txPlaySound("blade_effect.wav");
}

//StartingScreen private set():

void ScreenSt::set_t_1()
{
    t=1;
}
void ScreenSt::set_t_4()
{
    t=4;
}
void ScreenSt::set_t_5()
{
    t=5;
}

#endif
