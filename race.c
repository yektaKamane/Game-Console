#include "race.h"
#include "consul.h"
#include "menu.h"
#include "moving_character.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int road = 37;
int game_so_over = 0;

void car_race(void){
    FILE * fp = fopen("car_map.txt" , "r");
    int i=0;
    char ch;
    while (ch != EOF){
        ch = getc(fp);
        car_map[i] = ch;
        i++;
    }
    car_map[i-1] = '\0';
    fclose(fp);
    int len = 37*20;
    int key =0;
    float my_score = 0;
    game_so_over = 0;
    clrscr();
    while (!game_so_over){
        shift_append(37);
        rubb_check();
        if (kbhit()){
            key = getch();
            if (key == '6'){
                move_right();
            }
            if (key == '4'){
                move_left();
            }
        }
        printf("\n\n%.*s\n", len, car_map);
        printf("\n\t Score : %.0f" , my_score);
        stay_stayble();
        delay(0.2);
        my_score += 0.2;
        clrscr();
    }
        printf("\n <- Esc\t\tRestart : Enter\n\n%.*s\n", len, car_map);
        printf("\n\t Score : %.0f\t WRECK!" , my_score);

        if (player_name[0]!='\0'){
            FILE * fp = fopen("records.txt" , "a");
            char * game_name = shrink_filename(chosen_game , 20);
            fprintf(fp , "\n\tPlayer :%8s     Game : R-Race       Score : %.0f \n" , player_name  , my_score);
            fclose(fp);
        }
        int c;
        while((c=getch())!= 27 && c!= 13){
            if (c==27 || c==13){
                break;
            }
        }
        if (c==27){
            default_games();
        }
        if (c==13){
            car_race();
        }

}

void rubb_check(void){
    int i;
    for (i=0 ; car_map[i]!= '\0' ; i++){
        if (car_map[i] == '@'){
            break;
        }
    }
    if (car_map[i+road]!=' ' || car_map[i+road+1]!=' ' || car_map[i+road+2]!=' ' || car_map[i+road+3]!=' '){
        game_so_over = 1;
    }
}

void move_left(void){
    int i;
    for (i=0 ; car_map[i]!= '\0' ; i++){
        if (car_map[i] == '@'){
            break;
        }
    }
    if (car_map[i-1]=='!'){
        return;
    }
    if (car_map[i-1]!=' '||car_map[i - road - 1]!=' ' || car_map[i - 2*road - 1]!=' ' || car_map[i- 3*road -1]!=' ' || car_map[i - 4*road ]!=' '){
            printf("hiiiiiii");
        game_so_over = 1;
    }
    car_map[i-1] = '@';
    car_map[i] = '-';
    car_map[i+1] = '-';
    car_map[i+2] = '@';
    car_map[i+3] = ' ';

    car_map[i-road-1] = '|';
    car_map[i-road] = ' ';
    car_map[i -road + 1] = ' ';
    car_map[i-road + 2] = '|';
    car_map[i-road + 3] = ' ';

    car_map[i-2*road-1] = '|';
    car_map[i-2*road] = ' ';
    car_map[i-2*road+1] = ' ';
    car_map[i-2*road+2] = '|';
    car_map[i-2*road+3] = ' ';

    car_map[i - 3*road -1] = '/';
    car_map[i - 3*road ] = ' ';
    car_map[i - 3*road + 1] = ' ';
    car_map[i - 3*road + 2] = 92;
    car_map[i - 3*road + 3] = ' ';

    //car_map[i - 4*road -1 ] = ' ';
    car_map[i - 4*road ] = '_';
    car_map[i - 4*road + 1] = '_';
    car_map[i - 4*road + 2] = ' ';
    car_map[i - 4*road + 3] = ' ';

    //car_map[i - 5*road  + 2] = ' ';
    //car_map[i - 5*road  + 3] = ' ';

}

void move_right(void){
    int i;
    for (i=0 ; car_map[i]!= '\0' ; i++){
        if (car_map[i] == '@'){
            break;
        }
    }
    if (car_map[i+4]=='!'){
        return;
    }
    if (car_map[i+4]!=' '||car_map[i - road + 4]!=' ' || car_map[i - 2*road + 4 ]!=' ' || car_map[i- 3*road + 4 ]!=' ' || car_map[i - 4*road + 4 ]!=' '){
        game_so_over = 1;
    }
    car_map[i] = ' ';
    car_map[i+1] = '@';
    car_map[i+2] = '-';
    car_map[i+3] = '-';
    car_map[i+4] = '@';

    car_map[i-road] = ' ';
    car_map[i-road+1] = '|';
    car_map[i -road + 2] = ' ';
    car_map[i-road +3] = ' ';
    car_map[i-road+4] = '|';

    car_map[i-2*road] = ' ';
    car_map[i-2*road+1] = '|';
    car_map[i-2*road+2] = ' ';
    car_map[i-2*road+3] = ' ';
    car_map[i-2*road+4] = '|';

    car_map[i - 3*road ] = ' ';
    car_map[i - 3*road + 1] = '/';
    car_map[i - 3*road + 2] = ' ';
    car_map[i - 3*road + 3] = ' ';
    car_map[i - 3*road + 4] = 92;

    //car_map[i - 4*road  ] = ' ';
    car_map[i - 4*road + 1 ] = ' ';
    car_map[i - 4*road + 2] = '_';
    car_map[i - 4*road + 3] = '_';
    car_map[i - 4*road + 4] = ' ';

    //car_map[i - 5*road  + 2] = ' ';
    //car_map[i - 5*road  + 3] = ' ';

}

void stay_stayble(void){
    int i;
    for (i=0 ; car_map[i]!= '\0' ; i++){
        if (car_map[i] == '@'){
            break;
        }
    }
    car_map[i+road] = '@';
    car_map[i+road+1] = '-';
    car_map[i+road+2] = '-';
    car_map[i+road+3] = '@';

    car_map[i] = '|';
    car_map[i+1] = ' ';
    car_map[i+2] = ' ';
    car_map[i+3] = '|';

    car_map[i-road] = '|';
    car_map[i-road+1] = ' ';
    car_map[i-road + 2] = ' ';
    car_map[i-road + 3] = '|';

    car_map[i - 2*road ] = '/';
    car_map[i - 2*road + 1 ] = ' ';
    car_map[i - 2*road  + 2] = ' ';
    car_map[i - 2*road  + 3] = 92;

    car_map[i - 3*road  ] = ' ';
    car_map[i - 3*road  + 1] = '_';
    car_map[i - 3*road  + 2] = '_';
    car_map[i - 3*road  + 3] = ' ';

    car_map[i - 4*road  + 1] = ' ';
    car_map[i - 4*road  + 2] = ' ';


}

void shift_append(int n){
    char temp[n];
    int i,j,k;
    int len = strlen(car_map);
    for (i=0 ; i<n ; i++){
        temp [i] = car_map[i];
    }

    for (i=0 ; i<len-n ; i++){
        car_map[i] = car_map[i+n];
    }
    for ( j=0; j<n ; i++ , j++){
        car_map[i] = temp[j];
    }
    car_map[i] = '\0';
}



