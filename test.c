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
    GotoXY(150, 150);
    b_type_next = rand() % 4 + rand() % 3;// 계산식이 문제 랜덤이 아니라 4만 나옴
    for(int i = 0;i < 4; i++){
        for(int j = 0;j < 4; j++){
            GotoXY(STATUS_X_ADJ + 4 + j * 2, STATUS_Y_LEVEL + 2 + i);
            if(blocks[b_type_next][0][i][j] == EMPTY){
                printw(" ");
            }
            if(blocks[b_type_next][0][i][j] == ACTIVE_BLOCK){
                printw("⚀");
            }
        }
    }
}


void drop_block_test(){
    int active_blok_position_i[4];
    int active_blok_position_j[4];
    int con = 0;
    GotoXY( X_START_POS, Y_START_POS);
    for(int i = 0;i < 4; i++){
        for(int j = 0;j < 4; j++){
            GotoXY(X_START_POS + 4 + j * 2, Y_START_POS + 2 + i);
            if(blocks[b_type_next][0][i][j] == EMPTY){
                printw(" ");
            }
            if(blocks[b_type_next][0][i][j] == ACTIVE_BLOCK){
                printw("⚀");
                    active_blok_position_i[con] = i;
                    active_blok_position_j[con] = j;
                    con++;
            }
        }
    }
    con = 0;
    while(1){
        for(int i = 0;i <= 3; i++){
            GotoXY(active_blok_position_i[i], active_blok_position_j[i]);
            printf(" ");
            sleep(1);
        }
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
    drop_block_test();
    getch();
    endwin();
    return 0;
}