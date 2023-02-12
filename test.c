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
                GotoXY(MAIN_Y_ADJ + j, MAIN_X_ADJ + i);
                if(main_org[i][j] == EMPTY){
                    printw(" ");
                }
                if(main_org[i][j] == CEILLING){

                    printw("-");
                }
                if(main_org[i][j] == WALL){
                    printw("☒");
                }
            }
        }
}

void draw_map_test() {
    GotoXY(STATUS_X_ADJ, STATUS_Y_LEVEL);
    printw("LEVEL :     ");
    printw("%d", level);
    GotoXY(STATUS_X_ADJ, STATUS_Y_GOAL);
    printw("GOAL :      ");
    printw("%d", level_goal);
    GotoXY(STATUS_X_ADJ, STATUS_Y_LEVEL + 1);
    printw("+- N E X T -+");
    for (int i = 0; i < 8; i++){
        GotoXY(STATUS_X_ADJ, STATUS_Y_LEVEL + 2 + i);
        printw("|           |");
    }
    GotoXY(STATUS_X_ADJ, STATUS_Y_LEVEL + 1 + 9);
    printw("+- - - - - -+");
    GotoXY(STATUS_X_ADJ, STATUS_Y_SCORE + 6);
    printw("your score :");
    GotoXY(STATUS_X_ADJ, STATUS_Y_SCORE + 7);
    printw("           %d", score);
    GotoXY(STATUS_X_ADJ, STATUS_Y_SCORE + 9);
    printw("last score :");
    GotoXY(STATUS_X_ADJ, STATUS_Y_SCORE + 10);
    printw("           %d", last_score);
    GotoXY(STATUS_X_ADJ, STATUS_Y_SCORE + 12);
    printw("best score :");
    GotoXY(STATUS_X_ADJ, STATUS_Y_SCORE + 13);
    printw("           %d", best_score);
    GotoXY(STATUS_X_ADJ, STATUS_Y_SCORE + 15);
    printw("    ⦽   :Shift         Space : Hard Drop");
    GotoXY(STATUS_X_ADJ, STATUS_Y_SCORE + 16);
    printw("    ⬲ ⟴   :Left / Right   P : Pause");
    GotoXY(STATUS_X_ADJ, STATUS_Y_SCORE + 17);
    printw("    ↓  : soft drop         esc : Quit");
}

int main(){
    setlocale(LC_ALL, "");
    initscr();
    load_master_data();
    GotoXY(2,4);
    draw_mainboard_test();
    draw_map_test();
    refresh();
    getch();
    endwin();
    return 0;
}