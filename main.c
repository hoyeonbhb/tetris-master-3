#include <stdio.h> 
#include <string.h>
#include <ncurses.h> 
#include <stdlib.h> 
#include <sys/time.h> 

#include "data.h"
#include "loader.h"
#include "func.h"

//  gcc -o test main.c data.c loader.c func.c -lncurses

int main() {
    initscr();

    char path[100]; 
    strcpy(path, "./resources/block_data.txt");
    load_block_data(path); 
    strcpy(path, "./resources/mainboard_data.txt");
    load_mainboard_data(path); 

    GotoXY(40, 5);
    // printw("Hello, World!\n\n");
	// refresh();

    // for (int i = 0; i < MAIN_Y; i++) {
    //     for (int j = 0; j < MAIN_X; j++) {
    //         printw("%c", main_org[i][j]); 
    //         refresh(); 
    //     }
        // printw("\n"); 
        // refresh(); 
    // }

    // addstr("\npress any key to exit...");
    // refresh();
    getch();

    endwin();
    return 0; 
}