#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <dirent.h>
#include <string.h>

void print_poke(void){
    int i;
    int arrayp[100] = {219,223, 223,220,32,32,32,32,32,32,32,32,32,32,32,32,220,223,223,219,10,32,219,32,32,32,223,220};
    for (i=0 ; i<28 ; i++){
        printf("%c" , arrayp[i]);
    }
}

void dir2(void) {
    struct dirent *de;  // Pointer for directory entry
    DIR *dr = opendir(".");
    if (dr == NULL){
        printf("Could not open current directory" );
    }
    while ((de = readdir(dr)) != NULL)
        if (strstr(de->d_name , "map")){
            printf("%s\n", de->d_name);
        }
    closedir(dr);
}

