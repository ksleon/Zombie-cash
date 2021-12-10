//автор: Леонид Ксинопуло 9 "В"

//LIBRARY_-_Functions

#include <TXLib.h>
#ifndef _functions_
#define _functions_

void Check_Keys(zomb_t* zomb,ground_t* ground);         ///<-функция проверки клавиш
void interaction(zomb_t* zomb,ground_t* ground,screen_t* screen);         ///<-функция осуществляющая операции взаимодействии с картой
void Starting_Screen(screen_t* screen,zomb_t* zomb,ground_t* ground);     ///<-функция отвечающая за вывод стартового изображения, диалоговых окон и заставок на экран
void Delete_ALL_PICTURES(screen_t* screen,zomb_t* zomb,ground_t* ground); ///<-функция удаления всех картинок из памяти
void anti_meow();                                                         ///<-функция стириющая все ненужные комментарии от разработчика в консоли. Коты, кыш из моего кода!

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//CHECK KEYS FUNCTION

void Check_Keys(zomb_t* zomb,ground_t* ground)
{
if(GetAsyncKeyState(VK_RIGHT)&&((ground->karta[zomb->get_y()][zomb->get_x()+1]==1)||
(ground->karta[zomb->get_y()][zomb->get_x()+1]==3)||
(ground->karta[zomb->get_y()][zomb->get_x()+1]==11)||
(ground->karta[zomb->get_y()][zomb->get_x()+1]==13)||
(ground->karta[zomb->get_y()][zomb->get_x()+1]==4)||
(ground->karta[zomb->get_y()][zomb->get_x()+1]==7)||
(ground->karta[zomb->get_y()][zomb->get_x()+1]==20)||
((ground->karta[zomb->get_y()][zomb->get_x()+1]==14)&&zomb->get_Chet()==9)||
((ground->karta[zomb->get_y()][zomb->get_x()+1]==0)&&zomb->get_surf()==1)||
((ground->karta[zomb->get_y()][zomb->get_x()+1]==17)&&zomb->get_surf()==1)||
((ground->karta[zomb->get_y()][zomb->get_x()+1]==10)&&zomb->get_surf()==1)||
((ground->karta[zomb->get_y()][zomb->get_x()+1]==8)&&zomb->get_surf()==1)))
    {
        zomb->move_right();
    }
    else if(GetAsyncKeyState(VK_LEFT)&&((ground->karta[zomb->get_y()][zomb->get_x()-1]==1)||
    (ground->karta[zomb->get_y()][zomb->get_x()-1]==3)||
    (ground->karta[zomb->get_y()][zomb->get_x()-1]==11)||
    (ground->karta[zomb->get_y()][zomb->get_x()-1]==13)||
    (ground->karta[zomb->get_y()][zomb->get_x()-1]==4)||
    (ground->karta[zomb->get_y()][zomb->get_x()-1]==7)||
    (ground->karta[zomb->get_y()][zomb->get_x()-1]==20)||
    ((ground->karta[zomb->get_y()][zomb->get_x()-1]==14)&&zomb->get_Chet()==9)||
    ((ground->karta[zomb->get_y()][zomb->get_x()-1]==0)&&zomb->get_surf()==1)||
    ((ground->karta[zomb->get_y()][zomb->get_x()-1]==17)&&zomb->get_surf()==1)||
    ((ground->karta[zomb->get_y()][zomb->get_x()-1]==10)&&zomb->get_surf()==1)||
    ((ground->karta[zomb->get_y()][zomb->get_x()-1]==8)&&zomb->get_surf()==1)))
    {
        zomb->move_left();
    }
    else if(GetAsyncKeyState(VK_UP)&&((ground->karta[zomb->get_y()-1][zomb->get_x()]==1)||
    (ground->karta[zomb->get_y()-1][zomb->get_x()]==3)||
    (ground->karta[zomb->get_y()-1][zomb->get_x()]==11)||
    (ground->karta[zomb->get_y()-1][zomb->get_x()]==13)||
    (ground->karta[zomb->get_y()-1][zomb->get_x()]==4)||
    (ground->karta[zomb->get_y()-1][zomb->get_x()]==7)||
    (ground->karta[zomb->get_y()-1][zomb->get_x()]==20)||
    ((ground->karta[zomb->get_y()-1][zomb->get_x()]==14)&&zomb->get_Chet()==9)||
    ((ground->karta[zomb->get_y()-1][zomb->get_x()]==0)&&zomb->get_surf()==1)||
    ((ground->karta[zomb->get_y()-1][zomb->get_x()]==17)&&zomb->get_surf()==1)||
    ((ground->karta[zomb->get_y()-1][zomb->get_x()]==10)&&zomb->get_surf()==1)||
    ((ground->karta[zomb->get_y()-1][zomb->get_x()]==8)&&zomb->get_surf()==1)))
    {
        zomb->move_up();
    }
    else if(GetAsyncKeyState(VK_DOWN)&&((ground->karta[zomb->get_y()+1][zomb->get_x()]==1)||
    (ground->karta[zomb->get_y()+1][zomb->get_x()]==3)||
    (ground->karta[zomb->get_y()+1][zomb->get_x()]==11)||
    (ground->karta[zomb->get_y()+1][zomb->get_x()]==13)||
    (ground->karta[zomb->get_y()+1][zomb->get_x()]==4)||
    (ground->karta[zomb->get_y()+1][zomb->get_x()]==7)||
    (ground->karta[zomb->get_y()+1][zomb->get_x()]==20)||
    ((ground->karta[zomb->get_y()+1][zomb->get_x()]==14)&&zomb->get_Chet()==9)||
    ((ground->karta[zomb->get_y()+1][zomb->get_x()]==0)&&zomb->get_surf()==1)||
    ((ground->karta[zomb->get_y()+1][zomb->get_x()]==17)&&zomb->get_surf()==1)||
    ((ground->karta[zomb->get_y()+1][zomb->get_x()]==10)&&zomb->get_surf()==1)||
    ((ground->karta[zomb->get_y()+1][zomb->get_x()]==8)&&zomb->get_surf()==1)))
    {
        zomb->move_down();
    }
}

//INTERACTION FUNCTION

void interaction(zomb_t* zomb,ground_t* ground,screen_t* screen)
{
    zomb->boundaries();
    if(ground->karta[zomb->get_y()][zomb->get_x()]==3)
    {
        ground->karta[zomb->get_y()][zomb->get_x()]=1;
        zomb->set_Chet_p();
    }
    if(ground->karta[zomb->get_y()][zomb->get_x()]==10)
    {
        ground->karta[zomb->get_y()][zomb->get_x()]=0;
        zomb->set_Chet_p();
    }
    if(ground->karta[zomb->get_y()][zomb->get_x()]==13)
    {
        ground->karta[zomb->get_y()][zomb->get_x()]=11;
        zomb->set_Chet_p();
        screen->money_collect_effect();
    }
    if(ground->karta[zomb->get_y()][zomb->get_x()]==4)
    {
        ground->karta[zomb->get_y()][zomb->get_x()]=5;
    }
    if(ground->karta[zomb->get_y()][zomb->get_x()]==7&&zomb->get_surf()==0&&zomb->get_Chet()==51)
    {
        zomb->set_surf_1();
        screen->surfboard_effect();
        ground->karta[zomb->get_y()][zomb->get_x()]=0;
    }
    if(ground->karta[zomb->get_y()][zomb->get_x()]==20)
    {
        ground->karta[zomb->get_y()][zomb->get_x()]=1;
        screen->keychest_got_effect();
        zomb->set_keychest_1();
    }
    if(((ground->karta[zomb->get_y()][zomb->get_x()]==1)||(ground->karta[zomb->get_y()][zomb->get_x()]==3)||(ground->karta[zomb->get_y()][zomb->get_x()]==4))&&zomb->get_surf()==1)
    {
        zomb->set_surf_0();
        if((ground->karta[zomb->get_y()][zomb->get_x()]==1)||(ground->karta[zomb->get_y()][zomb->get_x()]==3))
        {
            ground->karta[zomb->get_y()][zomb->get_x()]=1;
        }
        if(ground->karta[zomb->get_y()][zomb->get_x()]==4)
        {
            ground->karta[zomb->get_y()][zomb->get_x()]=5;
        }
    }
    if(zomb->get_harpoon()==0&&zomb->get_keychest()==1&&(GetAsyncKeyState(VK_LSHIFT)||GetAsyncKeyState(VK_RSHIFT))&&(ground->karta[zomb->get_y()][zomb->get_x()+1]==15))
    {
        ground->karta[zomb->get_y()][zomb->get_x()+1]=16;
        screen->chest_opening_effect();
        zomb->set_harpoon_1();
        zomb->set_keychest_0();
    }
    if(zomb->get_harpoon()==1&&(ground->karta[zomb->get_y()][zomb->get_x()]==17))
    {
        ground->karta[zomb->get_y()][zomb->get_x()]=18;
        zomb->set_harpoon_0();
        screen->blade_effect();
    }
    if(zomb->get_harpoon()==0&&(ground->karta[zomb->get_y()][zomb->get_x()]==17))
    {
        ground->karta[zomb->get_y()][zomb->get_x()]=19;
        zomb->set_lose_1();
        zomb->set_keychest_0();
        zomb->invisible();
        screen->losing_game_effect();
    }
    if(zomb->get_level()==4)
    {
        if(ground->karta[zomb->get_y()+1][zomb->get_x()]!=12)
        {
            zomb->set_y_mm();
            zomb->set_surf_0();
            zomb->set_Vy_4();
        }
    }

    if(((ground->karta[zomb->get_y()+1][zomb->get_x()]==2)||(ground->karta[zomb->get_y()-1][zomb->get_x()]==2)||(ground->karta[zomb->get_y()][zomb->get_x()+1]==2)||(ground->karta[zomb->get_y()][zomb->get_x()-1]==2))&&GetAsyncKeyState(VK_SPACE)&&zomb->get_Chet()==68&&zomb->get_level()==1)
    {
        screen->bomb_effect();
        zomb->invisible();
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<16;j++)
            {
                if(ground->karta[i][j]==2)
                {
                    ground->karta[i][j]=6;
                    ground->draw();
                }
            }
        }
        txSleep(200);
        ground->set_level_p();
        zomb->set_level();
        ground->set_cell();
        zomb->set_x();
        zomb->set_y();
        zomb->set_Chet_0();
        zomb->visible();
    }
    if(((ground->karta[zomb->get_y()][zomb->get_x()]==8)&&zomb->get_Chet()==51&&zomb->get_level()==2))
    {
        ground->set_level_p();
        zomb->set_level();
        ground->set_cell();
        zomb->set_x();
        zomb->set_y();
        zomb->set_Chet_0();
    }
    if(((ground->karta[zomb->get_y()][zomb->get_x()]==8)&&zomb->get_Chet()==47&&zomb->get_level()==3))
    {
        ground->set_level_p();
        zomb->set_level();
        ground->set_cell();
        zomb->set_x();
        zomb->set_y();
        zomb->set_Chet_0();
    }
    if(((ground->karta[zomb->get_y()][zomb->get_x()]==14)&&zomb->get_Chet()==9&&zomb->get_level()==4))
    {
        ground->karta[zomb->get_y()][zomb->get_x()]=11;
        zomb->set_win_1();
        zomb->winning();
        screen->winning_game_effect();
    }
}

//STARTING SCREEN FUNCTION

void Starting_Screen(screen_t* screen,zomb_t* zomb,ground_t* ground)
{
    screen->Set_all();
    if(screen->get_t()==2)
    {
        ground->set_level_0();
        zomb->set_level_0();
        zomb->set_Chet_0();
        ground->set_cell();
        zomb->visible();
        zomb->set_x();
        zomb->set_y();
        zomb->set_Vy_1();
        zomb->set_lose_0();
        zomb->set_harpoon_0();
        zomb->set_win_0();
        screen->set_t_1();
    }
    if(zomb->get_lose()==1)
    {
        screen->set_t_4();
    }
    if(zomb->get_win()==1)
    {
        screen->set_t_5();
    }
}

//DELETING ALL PICTURES FROM THE MEMORY FUNCTION

void Delete_ALL_PICTURES(screen_t* screen,zomb_t* zomb,ground_t* ground)
{
    ground->delete_DC();
    zomb->delete_DC();
    screen->delete_DC();
}

//DELETING "MEOW" FUNCTION

void anti_meow()
{
    txClearConsole();
}

#endif
