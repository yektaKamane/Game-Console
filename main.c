#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include "menu.h"
#include "consul.h"
#include "moving_character.h"
#include "race.h"

int main()
{

    srand(time(NULL));
    player_name[0]='\0';
    system("color 4F");
    dir("game-");
    veri_first_page();
    main_menu();


    return 0;
}
