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
                GotoXY(MAIN_X_ADJ + j * 2, MAIN_Y_ADJ + i );
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
    for (int i = 0; i < 4; i++){
        GotoXY(STATUS_X_ADJ, STATUS_Y_LEVEL + 2 + i);
        printw("|           |");

    }
    GotoXY(STATUS_X_ADJ, STATUS_Y_LEVEL + 1 + 5);
    printw("+- - - - - -+");
    GotoXY(STATUS_X_ADJ, STATUS_Y_SCORE);
    printw("your score :");
    GotoXY(STATUS_X_ADJ, STATUS_Y_SCORE + 1);
    printw("           %d", score);
    GotoXY(STATUS_X_ADJ, STATUS_Y_SCORE + 2);
    printw("last score :");
    GotoXY(STATUS_X_ADJ, STATUS_Y_SCORE + 3);
    printw("           %d", last_score);
    GotoXY(STATUS_X_ADJ, STATUS_Y_SCORE + 4);
    printw("best score :");
    GotoXY(STATUS_X_ADJ, STATUS_Y_SCORE + 5);
    printw("           %d", best_score);
    GotoXY(STATUS_X_ADJ, STATUS_Y_SCORE + 7);
    printw("    ^   :Shift         Space : Hard Drop");
    GotoXY(STATUS_X_ADJ, STATUS_Y_SCORE + 8);
    printw("   < >    :Left / Right   P : Pause");
    GotoXY(STATUS_X_ADJ, STATUS_Y_SCORE + 9);
    printw("    v  : soft drop         esc : Quit");
}

void next_rand_block_test(){
    time_t tim;
    time(&tim);
    srand(tim);
    
    int rand_type = rand() % 7;
    GotoXY(STATUS_X_ADJ + 4, STATUS_Y_LEVEL + 2);
    for(int i = 0;i < 4; i++){
        for(int j = 0;j < 4; j++){
            if(blocks[rand_type][0][i][j] == EMPTY){
                printw(" ");
            }
            if(blocks[rand_type][0][i][j] == ACTIVE_BLOCK){
                printw("▉");
            }
            GotoXY(STATUS_X_ADJ + 4 + j, STATUS_Y_LEVEL + 2);
        }
        GotoXY(STATUS_X_ADJ + 4, STATUS_Y_LEVEL + 3 + i);
    }
}

int main(){
    setlocale(LC_ALL, "");
    initscr();
    load_master_data();
    GotoXY(2,4);
    draw_mainboard_test();
    load_master_data();
    draw_map_test();
    next_rand_block_test();
    refresh();
    getch();
    endwin();
    return 0;
}