#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <dirent.h>
#include "menu.h"
#include "consul.h"


char availabe_g[1000];
int arrow_key = 1;

void veri_first_page(void){
    printf("\n\n\n  \n\n\n") ;
    printf("\t\t%c     %c\t%c%c%c%c%c\t%c%c     %c%c  %c%c%c%c%c      %c",254,254,254,254,254,254,254,254 ,254 ,254 , 254 , 254 , 254 , 254 ,254 , 254 , 254) ;
    printf("\n\t\t %c   %c\t%c\t%c %c   %c %c    %c       %c %c" ,254,254,254,254,254 ,254,254 , 254,254,254) ;
    printf("\n\t\t  %c %c\t%c\t%c  %c %c  %c    %c      %c   %c" ,254,254,254,254,254,254 , 254 , 254 , 254) ;
    printf("\n\t\t   %c\t%c%c%c%c%c\t%c   %c   %c    %c     %c%c%c%c%c%c%c",254,254,254,254 ,254 ,254 ,254 ,254 ,254 , 254,254 , 254) ;
    printf("\n\t\t   %c\t%c\t%c\t%c    %c       %c %c" ,254 ,254,254,254 ,254 ,254) ;
    printf("\n\t\t   %c\t%c\t%c\t%c    %c      %c   %c",254,254,254,254 ,254,254 , 254) ;
    printf("\n\t\t   %c\t%c%c%c%c%c\t%c\t%c  %c%c%c%c%c   %c     %c",254,254,254,254,254,254,254,254 ,254 ,254 ,254,254 ,254 ,254 ,254 ) ;
    printf("\n\n\n\n\n\t\t\t Press any key to continue ...");
    getch();

}

void about(void){
    arrow_key = 1;
    char ch;
    printf("\n <-Esc \n\n\n  This console is the result of cooperation of two computer engineers \n Yekta Kamaneh & Mina Nayernia.\n " );
    printf("\n  This gaming console is the term project of P.O.P (principles of programming).\n");
    printf("\n  YEMIA is a simple gaming console programmed by C.\n");
    printf(" YEMIA supports two kinds of games. Those that we programmed with a standard \n that established by a group of students in Shiraz University .\n");
    printf(" And the other games are totally created by ourselves and don't obey those \n standards.");
    printf("\n\n  The games that works with standards are : \n PACMAN \n FLIGHT \n MAZE \n RALLY-X \n PULL-BOX \n");
    printf("\n We worked on this project for three months \n  It was finished on July second 2019 . ");
    printf("\n\n\n\n   Contact us : \n");
    printf("\n\t ykamaneh@gmail.com\t minanayernia@gmail.com\n\n\t");
    while ( ch!= 27){
        ch = getch();
    }
    main_menu();
}


void clrscr(void){
    system("@cls||clear");
}
void find_the_sign(void){
    int i;
    for (i=0 ; availabe_g[i] != '\0' ; i++ ){
        if (availabe_g[i]=='>'){
            availabe_g[i] = ' ';
            break;
        }
    }
    availabe_g[3] = '>';
}

void change_theme(void){
    arrow_key = 1;
    int static_key = 1;
    int key=0;
    char themes[1000] = "\t> Kiwi       \n\t  Ocean      \n\t  Scarlet    \n\t  Navy       \n\t  The Matrix \n\t  Violet   ";

    while (key != 13 && key != 27){
        if (kbhit()){
            key = getch();
            if (key == 80 && static_key <= 75 ){ //
                themes[static_key] = ' ';
                static_key += 15;
                themes[static_key] = '>';
            }
            if (key == 72 && static_key > 3){
                themes[static_key] = ' ';
                static_key -= 15;
                themes[static_key] = '>';
            }
        }
        printf("\n <-Esc \n\n\n\tCHANGE THEME \n\n%s" , themes);
        delay(0.1);
        clrscr();
    }
    if (key == 27){
        main_menu();
    }
    if (static_key == 1 && key == 13){ // kiwi
        system("color 6E");
        system("start kiwi.mp3");
        change_theme();
    }
    if (static_key == 16 && key == 13){ // ocean
        system("color 3B");
        system("start ocean.mp3");
        change_theme();
    }
    if (static_key == 31 && key==13){ // scarlet
        system("color 4F");
        system("start scarlet.mp3");
        change_theme();
    }
    if (static_key == 46 && key==13){ // navy
        system("color 81");
        system("start navy.mp3");
        change_theme();
    }
    if (static_key == 61 && key==13){ //matrix
        system("color 0A");
        system("start matrix.mp3");
        change_theme();
    }
    if (static_key == 76 && key==13){  // violet
        system("color 5D");
        system("start violet.mp3");
        change_theme();
    }
}

void load(){
    int r,c,q;
    int tmp_character = str_index(game_setting , "character");
    int tmp_opp = str_index(game_setting , "opp");
    int tmp_up = str_index(game_setting , "up");
    int tmp_deathblock = str_index(game_setting , "deathblock");
    int tmp_down = str_index(game_setting , "down");
    int tmp_left = str_index(game_setting , "left");
    int tmp_right = str_index(game_setting , "right");
    get_character();
    get_opp();
    get_up();
    get_deathblock();
    get_down();
    get_right();
    get_left();
    if (tmp_character!=-1){
        printf("\n\t\t\t    Character : %c\n" , character);
    }
    if (tmp_opp!=-1){
        printf("\n\t\t\t      Enemy   : %c\n" , opp.shape);
    }
    if (tmp_deathblock != -1){
        printf("\n\t\t\t  Death Block : %c\n\n" , deathblock);
    }
    if (tmp_up != -1){
        printf("\n\n\t\t\t          %c\n\t\t\t          ^" , up);

    }
    if (tmp_left != -1){
        printf("\n\t\t\t     %c <" , left);
    }
    if (tmp_right != -1){
        printf("     > %c" , right);
    }
    if (tmp_down != -1){
        printf("\n\t\t\t          v\n\t\t\t          %c" , down);
    }

    printf("\n\n\n\n\n\t\t\t      loading...\n\n\t\t\t");
    for(r=1;r<=20;r++){
        for(q=0;q<=100000000;q++);//to display the character slowly
        printf("%c",177);
    }
    getch();
}

char *shrink_filename(char *filename , int size_line){
    char *res = (char *)malloc((size_line+2)*sizeof(char));
    int small_size = strlen(filename);
    int i=0;
    int difference = size_line - small_size;
    while (*filename!= '-'){
        filename++;
    }
    filename++;
    while (i<small_size){
        if (*(filename+i) == '.'){
            break;
        }
        *(res + i) = *(filename + i);
        i++;
    }
    while (difference!=0){
        *(res + i) = ' ';
        i++;
        difference--;
    }
    *(res + i) = '\0';
    return res;
}

int line_counter(char arr[]){
    int lines = 0;
    int i=0;
    while ( arr[i]!= '\0' ){
        if ( arr[i] == '\n'){
            lines++;
        }
        i++;
    }
    return lines;
}

void new_acc(void ){
    arrow_key =1;
    clrscr();
    printf("\n <- Esc\n\n\t Enter your name : \n\n\t\t");
    scanf("%s" , player_name);
    getchar();  // because of scanf's bug :(
    printf("\n\t your records will be saved with this name since now!\n");
    int ch=0;
    while ( ch!= 27){
        ch = getch();
    }
    main_menu();
}

void records(void){
    arrow_key = 1;
    char result[10000];
    FILE * file = fopen("records.txt" , "r");
    int i=0;
    char ch;
    while(ch!=EOF){
        ch = getc(file);
        result[i] = ch;
        i++;
    }
    result[i] = '\0';
    fclose(file);
    printf("\n <- Esc \n\n%s" , result);
    while ( ch!= 27){
        ch = getch();
    }
    main_menu();
}


void default_games(void){
    arrow_key =1;
    int key = 0;
    int static_arrow_key = 2;
    char static_arr[100] = "\t >  Hang Man\n\t    R-Race ";
    while (key != 13 && key != 27){
        if (kbhit()){
            key = getch();
            if (key == 80 && static_arrow_key <= 15 ){ //
                static_arr[static_arrow_key] = ' ';
                static_arrow_key += 14;
                static_arr[static_arrow_key] = '>';
            }
            if (key == 72 && static_arrow_key > 3){
                static_arr[static_arrow_key] = ' ';
                static_arrow_key -= 14;
                static_arr[static_arrow_key] = '>';
            }
        }
    printf("\n <- Esc\n\n\n\t GAMES LIST  \n\n%s" , static_arr);
    delay(0.1);
    clrscr();
    }
    if (key == 27){
        main_menu();
    }
    if (key == 13 && static_arrow_key == 2){
        hangman_lists();
    }
    if (key == 13 && static_arrow_key == 16){
        car_race();
    }
}

void availabe_games(void){
    arrow_key = 1;
    find_the_sign();
    int key = 0;
    int static_arrowkey =3;
    int len = strlen(availabe_g);
    int last_line = line_counter(availabe_g) - 2;
    while (key != 13 && key != 27){
    clrscr();
        if (kbhit()){
            key = getch();
            if (key == 80 && static_arrowkey <= 27*last_line ){ //
                availabe_g[static_arrowkey] = ' ';
                static_arrowkey += 27;
                availabe_g[static_arrowkey] = '>';
            }
            if (key == 72 && static_arrowkey > 3){
                availabe_g[static_arrowkey] = ' ';
                static_arrowkey -= 27;
                availabe_g[static_arrowkey] = '>';
            }
        }
    printf("\n <- Esc\n\n\n\t GAMES LIST  \n\n%s" , availabe_g);
    delay(0.1);
    }
    if (key==13){
        clrscr();
        static_arrowkey+=3;
        chosen_map[0]='\0';
        chosen_game[0]='\0';
        strcat(chosen_map , "map-");
        strcat(chosen_game , "game-");
        int j=4;
        int k=5;
        while(availabe_g[static_arrowkey]!= ' '){
            chosen_map[j] = availabe_g[static_arrowkey];
            chosen_game[k] = availabe_g[static_arrowkey];
            j++;
            k++;
            static_arrowkey++;
        }
        chosen_map[j]='\0';
        chosen_game[k]='\0';
        strcat(chosen_map , ".txt");
        strcat(chosen_game , ".txt");
        map_reader(chosen_map);
        game_reader(chosen_game);
        load();
        clrscr();
        playing_game();
    }
    if (key == 27){
        main_menu();
    }

}

void exitt(){
    arrow_key = 1;
    clrscr();
    printf("\n\n\t\tAre you sure you want to exit?  \n\n\t\t\t Y or N ? ");
    int c=0;
    int flag = 0;
    while ((c=getchar())!= '\n'){
        if (c=='y' || c=='Y'){
            clrscr();
            printf("\n\n\t\tYou exit successfully :) \n\n\n\n\n\n\n");
        }
        if (c=='n' || c=='N' ){
            flag = 1;
        }
    }
    if (flag == 1){
        main_menu();
    }
}

void delay(float number_of_seconds){
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}
void main_menu(void){
    printf("\n\n\twelcome to the C1 gaming console. press any key to enter");
    int key;
    clrscr();
    char arr[200] = " >  New Account            \n    console's default games\n    Available games        \n    Records                \n    Change Theme           \n    About                  \n    Exit                   \n"; //max width = 28
    while (key != 13){  // key != '\n'
        if (kbhit()){
            key =getch();
            if (key == 80 && arrow_key <= 150 ){ //
                arr[arrow_key] = ' ';
                arrow_key += 28;
                arr[arrow_key] = '>';
            }
            if (key == 72 && arrow_key > 1){
                arr[arrow_key] = ' ';
                arrow_key -= 28;
                arr[arrow_key] = '>';
            }

        }
    printf("\n MAIN MANU \n\n%s" , arr);
    delay(0.1);
    clrscr();
    }
    if (arrow_key == 1){
        new_acc();
    }
    if (arrow_key == 29){
        default_games();
    }
    if (arrow_key == 57){
        availabe_games();
    }
    if (arrow_key == 85){
        records();
    }
    if (arrow_key == 113){
        change_theme();
    }
    if (arrow_key == 141){
        about();
    }
    if (arrow_key == 169){
        exitt();
    }
}

void dir(char *filename){
    struct dirent *de;  // Pointer for directory entry
    DIR *dr = opendir(".");
    if (dr == NULL){
        printf("Could not open current directory" );
    }
    strcat(availabe_g , "\n\t >  ");
    while ((de = readdir(dr)) != NULL)
        if (strstr(de->d_name , filename)){
            char *fn = shrink_filename(de->d_name , 30);
            strcat(availabe_g , fn);
            strcat(availabe_g , "\n\t    ");
        }
    strcat(availabe_g , "\0");
    closedir(dr);
}

void hangman_lists(void){
    struct node * animal_list = NULL;
    struct node * fruit_list = NULL;
    struct node * tool_list = NULL;
    struct node * country_list = NULL;
    struct node * sport_list = NULL;
    struct node * car_list = NULL;
    animal_list = add(animal_list , "elephant");
    animal_list = add(animal_list , "penguin");
    animal_list = add(animal_list , "ostrich");
    animal_list = add(animal_list , "raccoon");
    animal_list = add(animal_list , "lizard");
    animal_list = add(animal_list , "owl");
    animal_list = add(animal_list , "dog");
    animal_list = add(animal_list , "wolf");
    animal_list = add(animal_list , "shark");
    animal_list = add(animal_list , "snake");  //10
    animal_list = add(animal_list , "bear");
    animal_list = add(animal_list , "monkey");
    animal_list = add(animal_list , "horse");
    animal_list = add(animal_list , "giraffe");
    animal_list = add(animal_list , "squirrel");
    animal_list = add(animal_list , "kangaroo");
    animal_list = add(animal_list , "turtle");
    animal_list = add(animal_list , "sheep");
    animal_list = add(animal_list , "leopard");
    animal_list = add(animal_list , "rabbit");

    fruit_list = add(fruit_list , "apple");
    fruit_list = add(fruit_list , "banana");
    fruit_list = add(fruit_list , "grape");
    fruit_list = add(fruit_list , "orange");
    fruit_list = add(fruit_list , "cherry");
    fruit_list = add(fruit_list , "pineapple");
    fruit_list = add(fruit_list , "strawberry");
    fruit_list = add(fruit_list , "watermelon");
    fruit_list = add(fruit_list , "papaya");
    fruit_list = add(fruit_list , "peach"); //10
    fruit_list = add(fruit_list , "pomegranate");
    fruit_list = add(fruit_list , "avocado");
    fruit_list = add(fruit_list , "melon");
    fruit_list = add(fruit_list , "kiwi");
    fruit_list = add(fruit_list , "berries");
    fruit_list = add(fruit_list , "mango");
    fruit_list = add(fruit_list , "lemon");
    fruit_list = add(fruit_list , "plum");
    fruit_list = add(fruit_list , "apricot");
    fruit_list = add(fruit_list , "grapefruit");

    tool_list = add(tool_list , "hammer");
    tool_list = add(tool_list , "saw");
    tool_list = add(tool_list , "ladder");
    tool_list = add(tool_list , "scissors");
    tool_list = add(tool_list , "drill");
    tool_list = add(tool_list , "bolt");
    tool_list = add(tool_list , "nail");
    tool_list = add(tool_list , "knife");
    tool_list = add(tool_list , "tape");
    tool_list = add(tool_list , "wrench");

    country_list = add(country_list , "argentina");
    country_list = add(country_list , "norway");
    country_list = add(country_list , "denmark");
    country_list = add(country_list , "korea");
    country_list = add(country_list , "china");
    country_list = add(country_list , "germany");
    country_list = add(country_list , "japan");
    country_list = add(country_list , "nepal");
    country_list = add(country_list , "morocco");
    country_list = add(country_list , "england");
    country_list = add(country_list , "finland");
    country_list = add(country_list , "spain");
    country_list = add(country_list , "france");
    country_list = add(country_list , "emirate");
    country_list = add(country_list , "russia");
    country_list = add(country_list , "canada");
    country_list = add(country_list , "greece");
    country_list = add(country_list , "senegal");
    country_list = add(country_list , "ireland");
    country_list = add(country_list , "mexico");

    sport_list = add(sport_list , "soccer");
    sport_list = add(sport_list , "basketball");
    sport_list = add(sport_list , "volleyball");
    sport_list = add(sport_list , "wrestling");
    sport_list = add(sport_list , "swimming");
    sport_list = add(sport_list , "tennis");
    sport_list = add(sport_list , "gymnastics");
    sport_list = add(sport_list , "baseball");
    sport_list = add(sport_list , "boxing");
    sport_list = add(sport_list , "running");

    car_list = add(car_list , "ford");
    car_list = add(car_list , "lamborghini");
    car_list = add(car_list , "ferrari");
    car_list = add(car_list , "chevrolet");
    car_list = add(car_list , "bmw");
    car_list = add(car_list , "audi");
    car_list = add(car_list , "datsun");
    car_list = add(car_list , "honda");
    car_list = add(car_list , "mercedes");
    car_list = add(car_list , "nissan");
    car_list = add(car_list , "porsche");
    car_list = add(car_list , "rolls-royce");
    car_list = add(car_list , "toyota");
    car_list = add(car_list , "dodge");
    car_list = add(car_list , "bugatti");
    car_list = add(car_list , "lexus");
    car_list = add(car_list , "hyundai");
    car_list = add(car_list , "mazda");
    car_list = add(car_list , "jeep");
    car_list = add(car_list , "jac");

    int static_arrowkey =1;
    char cat[100] = "\t>  Animals     \n\t   Fruits      \n\t   Tools       \n\t   Countries   \n\t   Sports      \n\t   Cars  \n";
    int key = 0 ;
    while (key != 13 && key != 27){
        if (kbhit()){
            key = getch();
            if (key == 80 && static_arrowkey <= 80 ){
                cat[static_arrowkey] = ' ';
                static_arrowkey += 17;
                cat[static_arrowkey] = '>';
            }
            if (key == 72 && static_arrowkey > 3){
                cat[static_arrowkey] = ' ';
                static_arrowkey -= 17;
                cat[static_arrowkey] = '>';
            }
        }
    printf("\n <- Esc \n\n\n\t   HANG MAN\n\n\tChoose a category : \n\n%s" , cat);
    delay(0.1);
    clrscr();
    }
    if (key == 27){
        default_games();
    }
    if (key == 13 && static_arrowkey == 1){
        int r = rand()%20;
        animal_list = find(animal_list , r);
        hangman(animal_list->data);
    }
    if (key == 13 && static_arrowkey == 18){
        int r = rand()%20;
        fruit_list = find(fruit_list , r);
        hangman(fruit_list->data);
    }
    if (key == 13 && static_arrowkey == 35){
        int r = rand()%10;
        tool_list = find(tool_list , r);
        hangman(tool_list->data);
    }
    if (key == 13 && static_arrowkey == 52){
        int r = rand()%20;
        country_list = find(country_list , r);
        hangman(country_list->data);
    }
    if (key == 13 && static_arrowkey == 69){
        int r = rand()%10;
        sport_list = find(sport_list , r);
        hangman(sport_list->data);
    }
    if (key == 13 && static_arrowkey == 86){
        int r = rand()%20;
        car_list = find(car_list , r);
        hangman(car_list->data);
    }
}

void hangman( char * word){
    //char word[20];			//Used to store the user word. Most words are less than 20 characters so the default size is 20.
    char stars[20];			//A string full of * that are replaced upon the user entering the right letter of the word.
    int counter = 0;			//A counter to use in the for loops.
    int len;				//len is the length of the word entered.
    char ch;				//ch is a temporary character variable.
    int strikes=0;			//strikes counts how many wrong characters the user has guessed.
    int trigger = 0;			//The trigger variable serves as a flag in the for loops bellow.
    int wincounter=0;			//wincounter keeps track of the number of correct guesses.
    int i;
    len = strlen(word);

    clrscr();						//To clear the screen, if function doesn't work properly, use the commented line bellow instead.
    //Fill the stars string with * according to the input word length (len)
    for(counter=0; counter<len; counter++){
        stars[counter]='-';
    }
    stars[len]='\0';					//Insert the terminating string character at the end of the stars string.
    //Enter main program loop where guessing and checking happens. 26 is for 20 maximum characters + 6 strike characters.
    for(counter = 0; counter<26; counter++){
        if(wincounter==len){			    	//If the number of correct guesses matches the length of the word it means that the user won.{
            printf("\n\nThe word was: %s\n", word);
            printf("\nYou win!\n");
            break;
        }
        hangman_draw(strikes);			    	//Print the hangman ascii art according to how many wrong guesses the user has made.
        if(strikes==6){
            printf("\n\nThe word was: %s\n", word);
            printf("\n\nYou lose.\n");
            break;
        }
        printf("\n\n\n\n The word : %s", stars);			//Print the stars string (i.e: h*ll* for hello).
	printf("\n\nGuess a letter:");			//Have the user guess a letter.
        scanf(" %c",&ch);
        getchar();
        for(i=0; i<len; i++){
            if(word[i]==ch){
                stars[i]=ch;		    		//If the guess is correct, replace it in the stars string.
                trigger++;			   	//If a character the user entered matches one of the initial word, change the trigger to a non zero value.
                wincounter++;		    		//Increase the number of correct guesses.
            }
        }
        if(trigger==0){
            strikes++;				    	//If the trigger is not a non zero value, increase the strikes counter because that means that the user input character didn't match any character of the word.
        }
        trigger = 0;				    	//Set the trigger to 0 again so the user can guess a new character.
    }
    printf("\nPress any key ...");
        while (!kbhit()){};
        getchar();
        clrscr();
        hangman_lists();


}

void hangman_draw(int i){			//A function that prints the hanged man ascii art according to how many wrong guesses the user has made.
        clrscr();           		//Command to clear screen, if it doesn't work, use the commented line bellow.
        //printf(" \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n");
        switch (i){
        case 0:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| | | / \n| |/ \n| | \n| | | \n| | \n| | \n| | | \n| | \n| | \n| | | \n| | \n|=========|_`-' `-' |===| \n|=|=======\ \       '=|=| \n| |        \ \        | | \n: :         \ \       : : \n. .          `'       . . \n");
            break;
        case 1:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| | | /        ||.-''. \n| |/         |/  _  \ \n| |          ||  `/,| \n| |          (\\`_.' \n| | | \n| | \n| | \n| | \n| | \n| | \n| | \n| | \n| | \n|=========|_`-' `-' |===| \n|=|=======\ \       '=|=| \n| |        \ \        | | \n: :         \ \       : : \n. .          `'       . . \n");
            break;
        case 2:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| |/ /       || \n| | /        ||.-''. \n| |/         |/  _  \ \n| |          ||  `/,| \n| |          (\\`_.' \n| |         .-`--'. \n| |           . .    \n| |          |   |    \n| |          | . |     \n| |          |   |      \n| | \n| | \n| | \n| | \n| | \n|=========|_`-' `-' |===| \n|=|=======\ \       '=|=| \n| |        \ \        | | \n: :         \ \       : : \n. .          `'       . . \n");
            break;
        case 3:
            printf("___________.._______ \n| .__________))______| \n| | / /      || \n| |/ /       || \n| | /        ||.-''. \n| |/         |/  _  \ \n| |          ||  `/,| \n| |          (\\`_.' \n| |         .-`--'. \n| |        /Y . .    \n| |       // |   |    \n| |      //  | . |     \n| |     ')   |   |      \n| | \n| | \n| | \n| | \n| | \n|=========|_`-' `-' |===| \n|=|=======\ \       '=|=| \n| |        \ \        | | \n: :         \ \       : : \n. .          `'       . . \n");
            break;
        case 4:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| |/ /       || \n| | /        ||.-''. \n| |/         |/  _  \ \n| |          ||  `/,| \n| |          (\\`_.' \n| |         .-`--'. \n| |        /Y . . Y\ \n| |       // |   | \\ \n| |      //  | . |  \\ \n| |     ')   |   |   (` \n| | \n| | \n| | \n| | \n| | \n|=========|_`-' `-' |===| \n|=|=======\ \       '=|=| \n| |        \ \        | | \n: :         \ \       : : \n. .          `'       . . \n");
            break;
        case 5:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| |/ /       || \n| | /        ||.-''. \n| |/         |/  _  \ \n| |          ||  `/,| \n| |          (\\`_.' \n| |         .-`--'. \n| |        /Y . . Y\ \n| |       // |   | \\ \n| |      //  | . |  \\ \n| |     ')   |   |   (` \n| |          ||    \n| |          ||    \n| |          ||    \n| |          ||    \n| |         / |    \n==========|_`-' `-' |===| \n|=|=======\ \       '=|=| \n| |        \ \        | | \n: :         \ \       : : \n. .          `'       . . \n");
            break;
        case 6:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| |/ /       || \n| | /        ||.-''. \n| |/         |/  _  \ \n| |          ||  `/,| \n| |          (\\`_.' \n| |         .-`--'. \n| |        /Y . . Y\ \n| |       // |   | \\ \n| |      //  | . |  \\ \n| |     ')   |   |   (` \n| |          || || \n| |          || || \n| |          || || \n| |          || || \n| |         / | | \\ \n==========|_`-' `-' |===| \n|=|=======\ \       '=|=| \n| |        \ \        | | \n: :         \ \       : : \n. .          `'       . . \n");
            break;
}       }

struct node * add(struct node * head , char * data){
    struct node * new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
};

struct node * find(struct node * head , int i){
    int counter=0;
    while (head!=NULL){
        if (counter==i){
            return head;
        }
        head=head->next;
        counter++;
    }
};

void print_ll(struct node * head ){
    while(head!=NULL){
        printf(" %s " , head->data);
        head = head->next;
    }
}



