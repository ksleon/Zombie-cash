//автор: Леонид Ксинопуло 9 "В"

//*_MAIN CODE_*

#include <TXLib.h>
#include "character.h"          //library of Character
#include "background.h"         //library of Background
#include "startingscreen.h"     //library of Starting Screen
#include "functions.h"          //library of Functions

///////////////////////////////////////////////

int main()
{
    txCreateWindow(1280,720);
    zomb_t zomb;
    ground_t ground;
    screen_t screen;
    txBegin();
    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        txClear();
        ground.draw();
        zomb.draw();
        Starting_Screen(&screen,&zomb,&ground);
        Check_Keys(&zomb,&ground);
        interaction(&zomb,&ground,&screen);
        txSleep(100);
    }
    txEnd();
    return 0;
}
