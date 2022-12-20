#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "consul.h"
#include "moving_character.h"
float score=0;
char key=0;
char cpy=0;
int game_over=0;
int pause = 0;
int abs(int a){
    if (a>=0){
        return a;
    }
    else{
        return -a;
    }
}

void move1(int flag){


    if (kbhit()){
        key = getch();

        if (key == exit_t){
            clrscr();
            printf("\n\n\t\t Are you sure you want to exit? \n\n\t\t\t ( Y / N ) ");
            char c;
            scanf("%c" , &c);
            getchar();
            if ( c == 'y'){
                exit_in_game = 1;
            }
        }
        if ( pause == 0 && key == 32){
            //printf("hiiiiiiiiii");
            key = 0;
            pause = 1;
        }
        if ( pause ==1 && key == 32 ){
            key = 0;
            pause = 0;
        }
        if (key==put.keyboard && put.counter>=1){
            map_arr[where_is_character-1] = put.death;
            put.counter--;
        }
        if (key==72){ // attack arrow key up
            int i=0;
            for (i=0 ; i < attack ; i++){

                if (map_arr[where_is_character - i*width]==solidblock){
                    break;
                }
                if (map_arr[where_is_character - i*width]==deathblock){
                    map_arr[where_is_character - i*width] = ' ';
                }
                if (map_arr[where_is_character - i*width]==opp.shape){
                    map_arr[where_is_character - i*width] = ' ';
                    delete_opp(where_is_character - i*width);


                }
            }
        }
        if (key==80){ // attack arrow key down
            int i=0;
            for (i=0 ; i < attack ; i++){
                if (map_arr[where_is_character + i*width]==solidblock){
                    break;
                }
                if (map_arr[where_is_character + i*width]==deathblock){
                    map_arr[where_is_character] = ' ';
                }
                if (map_arr[where_is_character + i*width]==opp.shape){
                    map_arr[where_is_character + i*width] = ' ';
                    delete_opp(where_is_character + i*width) ;
                }
            }
        }
        if (key==75){ // attack arrow key left
            int i=0;
            for (i=0 ; i < attack ; i++){
                if (map_arr[where_is_character - i]==solidblock){
                    break;
                }
                if (map_arr[where_is_character - i]==deathblock){
                    map_arr[where_is_character - i] = ' ';
                }
                if (map_arr[where_is_character - i]==opp.shape){
                    map_arr[where_is_character - i] = ' ';
                    delete_opp(where_is_character - i);

                }
            }
        }
        if (key==72){ // attack arrow key up
            int i=0;
            for (i=0 ; i < attack ; i++){
                if (map_arr[where_is_character + i]==solidblock){
                    break;
                }
                if (map_arr[where_is_character + i]==deathblock){
                    map_arr[where_is_character +i] = ' ';
                }
                if (map_arr[where_is_character +i]==opp.shape){
                    map_arr[where_is_character + i] = ' ';
                    delete_opp(where_is_character + i);

                }
            }
        }
        if (key==up){
            character_to_up();
            cpy=key;
            return;
        }
        if (key==down){
            character_to_down();
            cpy=key;
            return;
        }
        if (key==right){
            character_to_right();
            cpy=key;
            return;
        }
        if (key==left){
            character_to_left();
            cpy=key;
            return;
        }
    }
    if (!kbhit() && cpy==up && !game_over && flag==1){
        character_to_up();
    }
    if (!kbhit() && cpy==down && !game_over && flag==1){
        character_to_down();
    }
    if (!kbhit() && cpy==left && !game_over && flag==1){
        character_to_left();
    }
    if (!kbhit() && cpy==right && !game_over && flag==1){
        character_to_right();
    }
}

void character_to_up(void){
    int wh = width * height ;
    if (map_arr[where_is_character - width] == ' '){ // normal move
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character - width;
        map_arr[where_is_character] = character ;
    }
    if (map_arr[where_is_character - width] == rpoint.shape){ // facing a point
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character -width;
        map_arr[where_is_character] = character ;
        score += rpoint.point;
        int dot = 1;
        while (dot != 0){
            int r = rand()%wh; //// width * height
            if ( map_arr[r] == ' '){
                map_arr[r] = rpoint.shape;
                dot = 0;
            }
        }
    }

    if (map_arr[where_is_character - width] == deathblock){ // facing a death block
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character - width;
        map_arr[where_is_character-2] = 'B';
        map_arr[where_is_character-1] = 'O';
        map_arr[where_is_character] = 'O';
        map_arr[where_is_character+1] = 'M';
        map_arr[where_is_character+2] = '!';
        game_over = 1;
    }
    if (map_arr[where_is_character - width] == moveblock && map_arr[where_is_character - 2*width]==' '){ // move block
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character - width;
        map_arr[where_is_character] = character ;
        map_arr[where_is_character - width] = moveblock;
    }
    if (map_arr[where_is_character - width] == moveblock && map_arr[where_is_character - 2*width]==target){ // move block
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character - width;
        map_arr[where_is_character] = character ;
        map_arr[where_is_character - width] = 177;
    }
    if (character==object && map_arr[where_is_character-width]==target){
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character - width ;
        map_arr[where_is_character ] = 177;
    }
}

void character_to_down(void){
    int wh = width * height ;
    if (map_arr[where_is_character + width] == ' '){
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character + width;
        map_arr[where_is_character] = character ;
    }
    if (map_arr[where_is_character + width] == rpoint.shape){
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character +width;
        map_arr[where_is_character] = character ;
        score += rpoint.point;
        int dot = 1;
        while (dot != 0){
            int r = rand()%wh; //// width * height
            if ( map_arr[r] == ' '){
                map_arr[r] = rpoint.shape;
                dot = 0;
            }
        }
    }
    if (map_arr[where_is_character + width] == deathblock){ // facing a death block
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character + width;
        map_arr[where_is_character-2] = 'B';
        map_arr[where_is_character-1] = 'O';
        map_arr[where_is_character] = 'O';
        map_arr[where_is_character+1] = 'M';
        map_arr[where_is_character+2] = '!';
        game_over = 1;
    }
    if (map_arr[where_is_character + width] == moveblock && map_arr[where_is_character + 2*width]==' '){ // move block
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character + width;
        map_arr[where_is_character] = character ;
        map_arr[where_is_character + width] = moveblock;
    }
    if (map_arr[where_is_character + width] == moveblock && map_arr[where_is_character + 2*width]==target){ // move block
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character + width;
        map_arr[where_is_character] = character ;
        map_arr[where_is_character + width] = 177;
    }
    if (character==object && map_arr[where_is_character+width]==target){
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character + width ;
        map_arr[where_is_character ] = 177;
    }
}

void character_to_right(void){
    int wh = width * height ;
    if (map_arr[where_is_character + 1] == ' '){
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character + 1;
        map_arr[where_is_character] = character ;
    }
    if (map_arr[where_is_character + 1] == rpoint.shape){
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character +1;
        map_arr[where_is_character] = character ;
        score += rpoint.point;
        int dot = 1;
        while (dot != 0){
            int r = rand()%wh; //// width * height
            if ( map_arr[r] == ' '){
                map_arr[r] = rpoint.shape;
                dot = 0;
            }
        }
    }

    if (map_arr[where_is_character +1] == deathblock){ // facing a death block
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character +1;
        map_arr[where_is_character-2] = 'B';
        map_arr[where_is_character-1] = 'O';
        map_arr[where_is_character] = 'O';
        map_arr[where_is_character+1] = 'M';
        map_arr[where_is_character+2] = '!';
        game_over = 1;
    }
    if (map_arr[where_is_character +1 ] == moveblock && map_arr[where_is_character +2]==' '){ // move block
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character +1 ;
        map_arr[where_is_character] = character ;
        map_arr[where_is_character +1 ] = moveblock;
    }
    if (map_arr[where_is_character +1 ] == moveblock && map_arr[where_is_character +2]==target){ // move block
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character +1 ;
        map_arr[where_is_character] = character ;
        map_arr[where_is_character +1 ] = 177;
    }
    if (character==object && map_arr[where_is_character+1]==target){
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character + 1 ;
        map_arr[where_is_character ] = 177;
    }
}

void character_to_left(void){
    int wh = width * height ;
    if (map_arr[where_is_character - 1] == ' '){
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character - 1;
        map_arr[where_is_character] = character ;
    }
    if (map_arr[where_is_character -1] == rpoint.shape){
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character -1;
        map_arr[where_is_character] = character ;
        score += rpoint.point;
        int dot = 1;
        while (dot != 0){
            int r = rand()%wh; //// width * height
            if ( map_arr[r] == ' '){
                map_arr[r] = rpoint.shape;
                dot = 0;
            }
        }
    }
    if (map_arr[where_is_character - 1] == deathblock){ // facing a death block
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character - 1;
        map_arr[where_is_character-2] = 'B';
        map_arr[where_is_character-1] = 'O';
        map_arr[where_is_character] = 'O';
        map_arr[where_is_character+1] = 'M';
        map_arr[where_is_character+2] = '!';
        game_over = 1;
    }
    if (map_arr[where_is_character - 1] == moveblock && map_arr[where_is_character - 2 ]==' '){ // move block
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character - 1;
        map_arr[where_is_character] = character ;
        map_arr[where_is_character - 1] = moveblock;
    }
    if (map_arr[where_is_character - 1] == moveblock && map_arr[where_is_character - 2 ]==target){ // move block
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character - 1;
        map_arr[where_is_character] = character ;
        map_arr[where_is_character - 1] = 177;
    }
    if (character==object && map_arr[where_is_character-1]==target){
        map_arr[where_is_character] = ' ';
        where_is_character = where_is_character - 1 ;
        map_arr[where_is_character ] = 177;
    }
}

void call_opp(void){
    int i;
    for (i=0 ; i<opp_counter ; i++){
        opp_move(i);
    }

}



void opp_move(int which_opp){
    int dif = where_is_character - where_is_opp[which_opp] ;
    if ( (where_is_character/width != where_is_opp[which_opp]/width)  && dif<0){  // up
        if (map_arr[where_is_opp[which_opp]-width]==' '){
            map_arr[where_is_opp[which_opp]] = ' ';
            where_is_opp[which_opp] = where_is_opp[which_opp] - width;
            map_arr[where_is_opp[which_opp]] = opp.shape ;
        }
        if (map_arr[where_is_opp[which_opp]-width]==character){
            map_arr[where_is_character-2] = 'B';
            map_arr[where_is_character-1] = 'O';
            map_arr[where_is_character] = 'O';
            map_arr[where_is_character+1] = 'M';
            map_arr[where_is_character+2] = '!';
            game_over = 1;
        }
        if (map_arr[where_is_opp[which_opp]-width]==put.death){
            map_arr[where_is_opp[which_opp]-width]=' ';
            delete_opp(where_is_opp[which_opp]);
        }
        if (map_arr[where_is_opp[which_opp] - width] == solidblock || map_arr[where_is_opp[which_opp] - width] == rpoint.shape || map_arr[where_is_opp[which_opp] - width] ==opp.shape ){
            if (map_arr[where_is_opp[which_opp]+1]==' '){
                map_arr[where_is_opp[which_opp]] = ' ';
                where_is_opp[which_opp] = where_is_opp[which_opp] + 1;
                map_arr[where_is_opp[which_opp]] = opp.shape ;
            }
        }


    }
    if ((where_is_character/width != where_is_opp[which_opp]/width)  && dif>0){ // down
        if (map_arr[where_is_opp[which_opp]+width]==' '){
            map_arr[where_is_opp[which_opp]] = ' ';
            where_is_opp[which_opp] = where_is_opp[which_opp] + width;
            map_arr[where_is_opp[which_opp]] = opp.shape ;
            return;
        }
        if (map_arr[where_is_opp[which_opp]+width]==character){
            map_arr[where_is_character-2] = 'B';
            map_arr[where_is_character-1] = 'O';
            map_arr[where_is_character] = 'O';
            map_arr[where_is_character+1] = 'M';
            map_arr[where_is_character+2] = '!';
            game_over = 1;
        }
        if (map_arr[where_is_opp[which_opp] + width]==put.death){
            map_arr[where_is_opp[which_opp] + width]=' ';
            delete_opp(where_is_opp[which_opp]);
        }
        if (map_arr[where_is_opp[which_opp] + width] == solidblock || map_arr[where_is_opp[which_opp] + width] == rpoint.shape || map_arr[where_is_opp[which_opp] +width] ==opp.shape){
            if (map_arr[where_is_opp[which_opp]-1]==' '){
                map_arr[where_is_opp[which_opp]] = ' ';
                where_is_opp[which_opp] = where_is_opp[which_opp] - 1;
                map_arr[where_is_opp[which_opp]] = opp.shape ;
            }
        }

    }
    if ((where_is_character/width == where_is_opp[which_opp]/width)  && dif<0){ // left
        if (map_arr[where_is_opp[which_opp]-1]==' '){
            map_arr[where_is_opp[which_opp]] = ' ';
            where_is_opp[which_opp] = where_is_opp[which_opp] - 1;
            map_arr[where_is_opp[which_opp]] = opp.shape ;
        }
        if (map_arr[where_is_opp[which_opp]-1]==character){
            map_arr[where_is_character-2] = 'B';
            map_arr[where_is_character-1] = 'O';
            map_arr[where_is_character] = 'O';
            map_arr[where_is_character+1] = 'M';
            map_arr[where_is_character+2] = '!';
            game_over = 1;
        }
        if (map_arr[where_is_opp[which_opp]-1]==put.death){
            map_arr[where_is_opp[which_opp]-1]=' ';
            delete_opp(where_is_opp[which_opp]);
        }
        if (map_arr[where_is_opp[which_opp] - 1] == solidblock || map_arr[where_is_opp[which_opp] - 1] == rpoint.shape || map_arr[where_is_opp[which_opp] - 1] ==opp.shape){
            if (map_arr[where_is_opp[which_opp]-width]==' '){
                map_arr[where_is_opp[which_opp]] = ' ';
                where_is_opp[which_opp] = where_is_opp[which_opp] - width;
                map_arr[where_is_opp[which_opp]] = opp.shape ;
            }
        }
    }
    if ((where_is_character/width == where_is_opp[which_opp]/width)  && dif>0){ // right
        if (map_arr[where_is_opp[which_opp]+1]==' '){
            map_arr[where_is_opp[which_opp]] = ' ';
            where_is_opp[which_opp] = where_is_opp[which_opp] + 1;
            map_arr[where_is_opp[which_opp]] = opp.shape ;
        }
        if (map_arr[where_is_opp[which_opp]+1]==character){
            map_arr[where_is_character-2] = 'B';
            map_arr[where_is_character-1] = 'O';
            map_arr[where_is_character] = 'O';
            map_arr[where_is_character+1] = 'M';
            map_arr[where_is_character+2] = '!';
            game_over = 1;
        }
        if (map_arr[where_is_opp[which_opp]+1]==put.death){
            map_arr[where_is_opp[which_opp]+1]=' ';
            delete_opp(which_opp);
        }
        if (map_arr[where_is_opp[which_opp]+1]==deathblock){
            map_arr[where_is_opp[which_opp]+1]=' ';
            delete_opp(where_is_opp[which_opp]);
        }
        if (map_arr[where_is_opp[which_opp] +1 ] == solidblock || map_arr[where_is_opp[which_opp] +1] == rpoint.shape || map_arr[where_is_opp[which_opp] +1] ==opp.shape){
            if (map_arr[where_is_opp[which_opp]+width]==' '){
                map_arr[where_is_opp[which_opp]] = ' ';
                where_is_opp[which_opp] = where_is_opp[which_opp] +width;
                map_arr[where_is_opp[which_opp]] = opp.shape ;
            }
        }
    }
}

void delete_opp(int op){
    int i=0;
    int flag = 0;
    map_arr[op]=' ';
    while(i<opp_counter){
        if (where_is_opp[i]==op){
                flag=1;

            break;
        }
        i++;
    }
    while (flag && i< opp_counter){
        where_is_opp[i] = where_is_opp[i+1];
        i++;
    }
    if (flag==1){
        opp_counter--;
    }

}




