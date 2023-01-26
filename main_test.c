#define __MAIN_C__
#include <stdio.h> 
#include <string.h>
// #include <ncurses.h> 
#include <stdlib.h> 
#include <sys/time.h> 

#include "data.h"
#include "loader.h"
// #include "func.h"

// gcc -o test main.c loader.c func.c

int main() {
    // initscr();

    char path[100]; 
    strcpy(path, "./resources/block_data.txt");
    load_block_data(path); 
    strcpy(path, "./resources/mainboard_data.txt");
    load_mainboard_data(path); 

    

    printf("main org %p\n", main_org); 

    for (int i = 0; i < MAIN_Y; i++) {
        for (int j = 0; j < MAIN_X; j++) {
            printf("%c ", main_org[i][j]); 
            
        }
        printf("\n"); 
    }

    // addstr("\npress any key to exit...");
    // refresh();
    // getch();

    // endwin();
    return 0; 
}