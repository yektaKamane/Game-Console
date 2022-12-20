#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consul.h"
#include "menu.h"
#include "moving_character.h"
#include <conio.h>
#include <time.h>



void map_reader(char filename[]) {
    char c ;
    int i = 0 ;
    FILE *fp ;
    fp =  fopen(filename , "r") ;
    fscanf(fp , "%d %c %d" , &width , &garbage, &height ) ;
    while((c=getc(fp)) != EOF){
        map_arr[i] = c;
        i++;
    }
    map_arr[i] = '\0';
    fclose(fp);
    //printf("%s" , map_arr);

}

int win_check(void){
    int i=0;
    for (i=0 ; i < height*width ; i++){
        if (map_arr[i]==target || map_arr[i]==object){
            return 0;
        }
    }
    return 1;
}

void game_reader(char filename[]){
    FILE *fp ;
    int i = 0;
    char c ;
    fp = fopen(filename  , "r") ;
    while((c=getc(fp)) != EOF){
        game_setting[i] = c;
        i++;
    }
    game_setting[i] = '\0';
    fclose(fp);
    //printf("%s" , game_setting);

}

int str_index(char *source , char *word){  // if word is found in source return the finishing index else return -1
    int i,j,k;
    for (i=0 ; i<strlen(source) ; i++){
        for (j=i ,k=0 ; *(word + k) == *(source+j) ; k++ , j++){
            ;
        }
        if (k>0 && *(word + k)=='\0'){
            return j;
        }
    }
    return -1;

}

void get_time(void){
    int a = str_index(game_setting , "time");
    if (a != -1){ //it has found the index
        int sum = 0;
        while(game_setting[a] != '\n'){
            if (game_setting[a]<'0' || game_setting[a] >'9' ){ //if it's not an integer go ahead
                a++;
                continue;
            }
            sum = (sum*10) + (game_setting[a] - '0');
            a++;
        }
        my_time = sum ;
        //printf("%d" , my_time);
    }
}

void get_deathblock(void){
    int a = str_index(game_setting , "deathblock");
    while(game_setting[a] != '\n'){
        if ( game_setting[a] == ' ' || game_setting[a] == '='){
            a++ ;
            continue ;
        }
        deathblock = game_setting[a] ;
        break ;
    }
    //printf("%c" , deathblock) ;
}


void get_solidblock(void){
    int a = str_index(game_setting , "solidblock");
    while(game_setting[a] != '\n'){
        if ( game_setting[a] == ' ' || game_setting[a] == '='){
            a++ ;
            continue ;
        }
        solidblock = game_setting[a] ;
        break ;
    }
    //printf("%c" , solidblock) ;
}

void get_wall(void){
    int a = str_index(game_setting , "wall");
    while(game_setting[a] != '\n'){
        if ( game_setting[a] == ' ' || game_setting[a] == '='){
            a++ ;
            continue ;
        }
        wall = game_setting[a] ;
        break ;
    }
    //printf("%c" , solidblock) ;
}

void get_moveblock(void){
    int a = str_index(game_setting , "moveblock");
    while(game_setting[a] != '\n'){
        if ( game_setting[a] == ' ' || game_setting[a] == '='){
            a++ ;
            continue ;
        }
        moveblock = game_setting[a] ;
        break ;
    }
    //printf("%c" , moveblock) ;
}

void get_up(void){
    int a = str_index(game_setting , "up");
    while(game_setting[a] != '\n'){
        if ( game_setting[a] == ' ' || game_setting[a] == '='){
            a++ ;
            continue ;
        }
        up = game_setting[a] ;
        break ;
    }
    //printf("%c" , up) ;
}

void get_down(void){
    int a = str_index(game_setting , "down");
    while(game_setting[a] != '\n'){
        if ( game_setting[a] == ' ' || game_setting[a] == '='){
            a++ ;
            continue ;
        }
        down = game_setting[a] ;
        break ;
    }
    //printf("%c" , down) ;
}

void get_right(void){
    int a = str_index(game_setting , "right");
    while(game_setting[a] != '\n'){
        if ( game_setting[a] == ' ' || game_setting[a] == '='){
            a++ ;
            continue ;
        }
        right = game_setting[a] ;
        break ;
    }
    //printf("%c" , right) ;
}

void get_left(void){
    int a = str_index(game_setting , "left");
    while(game_setting[a] != '\n'){
        if ( game_setting[a] == ' ' || game_setting[a] == '='){
            a++ ;
            continue ;
        }
        left = game_setting[a] ;
        break ;
    }
    //printf("%c" , left) ;
}

void get_character(void){
    int a = str_index(game_setting , "character");
    while(game_setting[a] != '\n'){
        if ( game_setting[a] == ' ' || game_setting[a] == '='){
            a++ ;
            continue ;
        }
        character = game_setting[a] ;
        break ;
    }
    //printf("%c" , character) ;
}

void get_object(void){
    int a = str_index(game_setting , "object");
    while(game_setting[a] != '\n'){
        if ( game_setting[a] == ' ' || game_setting[a] == '='){
            a++ ;
            continue ;
        }
        object = game_setting[a] ;
        break ;
    }
    //printf("%c" , object) ;
}

void get_target(void){
    int a = str_index(game_setting , "target");
    while(game_setting[a] != '\n'){
        if ( game_setting[a] == ' ' || game_setting[a] == '='){
            a++ ;
            continue ;
        }
        target = game_setting[a] ;
        break ;
    }
    //printf("%c" , target) ;
}

void get_exit(void){
    int a = str_index(game_setting , "Exit");
    while(game_setting[a] != '\n'){
        if ( game_setting[a] == ' ' || game_setting[a] == '='){
            a++ ;
            continue ;
        }
        exit_t = game_setting[a] ;
        break ;
    }
    //printf("%c" , exit_t) ;
}

void get_attack(void){
    int a = str_index(game_setting , "attack");
    int sum=0;
    while(game_setting[a] != '\n'){
        if ( game_setting[a] < '0' || game_setting[a] > '9'){
            a++ ;
            continue ;
        }
        sum = (sum *10) + (game_setting[a] - '0' ) ;
        a++;
    }
    attack = sum;
    //printf("%c" , attack) ;
}

void get_raindb(void){
    int a = str_index(game_setting , "raindb");
    int sum=0;
    while(game_setting[a] != '\n'){
        if ( game_setting[a] < '0' || game_setting[a] > '9'){
            a++ ;
            continue ;
        }
        sum = (sum *10) + (game_setting[a] - '0' ) ;
        a++;
    }
    raindb = sum;
    //printf("%d" , raindb) ;
}

void get_put(void){
    int a = str_index(game_setting , "put");
    int sum =0;
    int flag = 0;
    while (game_setting[a]!='\n'){
        if (game_setting[a]==',' && flag ==0){
            flag =1;
            put.keyboard = game_setting[a-1];
            a++;
            continue ;
        }
        if (game_setting[a]==',' && flag==1){
            flag = 2;
            put.death = game_setting[a-1];
            a++;
            continue ;
        }
        if (flag==2 ){
            if ( game_setting[a]>= '0' && game_setting[a]<= '9'){
                sum = (sum *10) + (game_setting[a] - '0');
                a++;
                continue ;
            }
        }
        a++ ;
    }
    put.counter = sum;
    //printf("put keyboard : %c\nput death : %c\nput counter : %d" , put.keyboard , put.death , put.counter);
}

void get_opp(void){
    int a = str_index(game_setting , "opp");
    int flag = 0;
    while (game_setting[a]!='\n'){
        if (game_setting[a]==',' && flag ==0){
            flag =1;
            opp.shape = game_setting[a-1];
            a++;
            continue ;
        }
        if (game_setting[a]==',' && flag==1){
            opp.target = game_setting[a-1];
            a++;
            continue ;
        }

        a++ ;
    }
}

void get_rpoint(void){
    int a = str_index(game_setting , "rpoint");
    int sum_point =0;
    int sum_number=0;
    int flag = 0;
    while (game_setting[a]!='\n'){
        if (game_setting[a]==',' && flag ==0){
            flag =1;
            rpoint.shape = game_setting[a-1];
            a++;
            continue ;
        }
         if (flag==1 ){ // char shape is finished now get the integer point
            if ( game_setting[a]>= '0' && game_setting[a]<= '9'){
                sum_point = (sum_point *10) + (game_setting[a] - '0');
                a++;
                continue ;
            }
            flag = 2;
        }
        if (flag==2 ){ // integer point is over now get the integer number
            if ( game_setting[a]>= '0' && game_setting[a]<= '9'){
                sum_number = (sum_number *10) + (game_setting[a] - '0');
                a++;
                continue ;
            }
        }
        a++ ;
    }
    rpoint.point = sum_point;
    rpoint.number = sum_number;
}

void find_character(void){
    int i=0;
    while (map_arr[i] != '\0'){
        if (map_arr[i]==character){
            break;
        }
    i++;
    }
    where_is_character = i;
}

void f_new_rain(int number){
    int i=0;
    int j;
    //srand(time(NULL));   // to make it different
    while (number > 0){
        int r = rand()%width;
        if (map_arr[r+width]!=' '){
            continue;
        }
        raindb_coord[i] = r+width;
        number--;
        i++;

    }
    for(j=0 ; j<i ; j++){
        map_arr[raindb_coord[j]] = deathblock;
    }

}


void frain(int number){
    int i;

    for (i=width*height; i>0 ; i-- ){
        if (map_arr[i]==deathblock && map_arr[i+width]==' '){
            map_arr[i] = ' ';
            map_arr[i+width] = deathblock;
        }
        if (map_arr[i]==deathblock && map_arr[i+width]==wall){
            map_arr[i]=' ';
        }
        if (map_arr[i]==deathblock && map_arr[i+width]==character){
            map_arr[where_is_character-2] = 'B';
            map_arr[where_is_character-1] = 'O';
            map_arr[where_is_character] = 'O';
            map_arr[where_is_character+1] = 'M';
            map_arr[where_is_character+2] = '!';
            game_over = 1;
        }
    }

}

void find_opp(void){
    opp_counter = 0;
    //where_is_opp = (int *)malloc(100 * sizeof(int));
    int i=0;
    while (map_arr[i] != '\0'){
        if (map_arr[i]==opp.shape){
            where_is_opp[opp_counter] = i;
            opp_counter++;
        }
    i++;
    }
}

void playing_game(void){
    get_time();
    get_character();
    get_down();
    get_left();
    get_up();
    get_right();
    get_deathblock();
    get_wall();
    get_object();
    get_opp();
    get_attack();
    get_put();
    get_raindb();
    get_solidblock();
    get_target();
    get_rpoint();
    get_exit();
    get_moveblock();
    int flag_keep_moving = 0;
    clrscr();
    printf("\n\n\tThis game contains a character that moves with keyboards.\n\t Do you want to keep moving after pressing a key?\n");
    printf("\n\t\t ( Y / N ) \n\t\t");
    char c;
    scanf("%c" , &c);
    getchar();
    if (c=='y'){
        flag_keep_moving = 1;
    }
    int time_temp = str_index(game_setting , "time") ;
    int char_temp = str_index(game_setting , "character");
    int opp_temp =  str_index(game_setting , "opp");
    int raindb_temp = str_index(game_setting , "raindb");
    int target_temp = str_index(game_setting , "target");
    int rpoint_temp = str_index(game_setting , "rpoint");
    if (rpoint_temp != -1){
        int num = rpoint.number;
        int r ;
        while(num>0){
            r = rand()%(width*height);
            if (map_arr[r]==' '){
                map_arr[r] = rpoint.shape;
                num--;
            }
        }
    }
    if (raindb_temp != -1){
        raindb_coord = (int *)malloc(raindb *sizeof(int));
    }
    if (char_temp!=-1){
        find_character(); // if the game has  character find it in the map array
    }
    if (opp_temp!=-1){
        find_opp(); //if the game has opp find it in map array
    }
    int win =0 ;
    if ( time_temp == -1 ){
        game_over=0;
        if (target_temp != -1){
            score = 1000;
        }
        else{
            score = 0;
        }
        exit_in_game=0;
        while( !game_over && !win ){
            if (pause==1){
                clrscr();
                printf("\n\n\n\t\t  Paused ");
                while(pause){
                    move1(flag_keep_moving);
                }
            }
            if (exit_in_game == 1){
                break;
            }
            if (target_temp!=-1 && win_check()){
                win = 1;
            }
            if (opp_temp!=-1 && opp_temp==0){
                break;
            }
            printf("\n Exit : %c \t Pause : space\n%s" , exit_t , map_arr);
            printf("\nScore : %.0f" , score);

            move1(flag_keep_moving);
            if (opp_temp!=-1){
                call_opp();
            }
        if (raindb_temp!=-1){
            f_new_rain(raindb);
            frain(raindb);
        }
        delay(0.2);
        if (target_temp != -1){
            score-=0.1;
        }
        else{
            score += 0.1;
        }
        clrscr();
        }
        if (exit_in_game == 1){
            availabe_games();
        }
        printf("\n<- Esc\t Restart : Enter \n%s\n\n\t " , map_arr);
        printf("\n Score : %.0f" , score);
        if (player_name[0]!='\0'){
            FILE * fp = fopen("records.txt" , "a");
            char * game_name = shrink_filename(chosen_game , 20);
            fprintf(fp , "\n\tPlayer :%8s     Game : %10s  Score : %.0f " , player_name , game_name , score);
            fclose(fp);
        }

        int c;
        while((c=getch())!= 27 && c!= 13){
            if (c==27 || c==13){
                break;
            }
        }
        if (c==27){
            main_menu();
        }
        if (c==13){
            map_reader(chosen_map);
            game_reader(chosen_game);
            playing_game();
        }

    }
    else{
        game_over = 0;
        score = 0;
        exit_in_game=0;
        float ftime = my_time;
        while( ftime >= 0  && !win){
            if (pause==1){
                clrscr();
                printf("\n\n\n\t\t  Paused \n");
                while(pause){
                    move1(flag_keep_moving);
                }
            }
            if (exit_in_game == 1){
                break;
            }
            if (opp_temp!=-1 && opp_counter==0){
                break;
            }
            if (target_temp!=-1 && win_check()){
                win = 1;
            }
            printf("\n Exit : %c \t Pause : space\n%s" , exit_t , map_arr);
            printf("\n Time : %.1f" , ftime);
            printf("\n Score : %.0f" , score);

            move1(flag_keep_moving);
            call_opp();
            ftime -= 0.2;
            delay(0.2);
            clrscr();
            if (game_over){
                break;
            }
        }
        if (exit_in_game == 1){
            availabe_games();
        }
        printf("\n<- Esc \t Restart : Enter\n%s\n\n\t " , map_arr);
        printf("\n Score : %.0f" , score);
        if (player_name[0]!='\0'){
            FILE * fp = fopen("records.txt" , "a");
            char * game_name = shrink_filename(chosen_game , 20);
            fprintf(fp , "\n\tPlayer :%8s     Game : %10s  Score : %.0f " , player_name , game_name , score);
            fclose(fp);
        }
        int c;
        while((c=getch())!= 27 && c!= 13){
            if (c==27 || c==13){
                break;
            }
        }
        if (c==27){
            main_menu();
        }
        if (c==13){
            map_reader(chosen_map);
            game_reader(chosen_game);
            playing_game();
        }
    }
}
