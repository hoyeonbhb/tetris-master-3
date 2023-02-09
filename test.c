#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h> 
#include <time.h>

#include "func.h"
#include "data.h"

void draw_mainboard_test() {
        for (int i = 0;i < MAIN_Y; i++){
            for (int j = 0;j < MAIN_X; j++){
                if(main_org[i][j] == EMPTY){
                    GotoXY(MAIN_Y_ADJ + j, MAIN_X_ADJ + i);
                    printw(" ");
                }
                if(main_org[i][j] == CEILLING){
                    GotoXY(MAIN_Y_ADJ + j, MAIN_X_ADJ + i);
                    printw("-");
                }
                if(main_org[i][j] == WALL){
                    GotoXY(MAIN_Y_ADJ + j, MAIN_X_ADJ + i);
                    printw("☒");
                }
            }
        }
    refresh();
}

int main(){
    setlocale(LC_ALL, "");
    initscr();
    load_master_data();
    GotoXY(2,4);
    draw_mainboard_test();
    getch();
    endwin();
    return 0;
}