#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "func.h"
#include"data.h"
#include"loader.h"

void GotoXY(int x, int y) {
	move(y,x);
}

int kbhit() {
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return True;
    } else {
        return False;
    }
}

void load_master_data() {
    load_block_data(path_block_data); 
    load_mainboard_data(path_mainboard_data); 
}

void draw_main() {
        GotoXY(MAIN_Y_ADJ, MAIN_X_ADJ);
        for (int i = 0;i <= MAIN_Y; i++){
            for (int j = 0;j <= MAIN_X; j++){
                if(main_org[i][j] == EMPTY){
                    printw(" ");
                }
                if(main_org[i][j] == CEILLING){
                    printw("-");
                }
                if(main_org[i][j] == WALL){
                    printw("|");
                }
            }
        }

}

void draw_map() {
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

void reset() {
	FILE * file = fopen("score.dat", "rt");  

    if (file == 0) { 
		best_score = 0;
	} 
    else {
        fscanf(file,"%d", &best_score); 
        fclose(file); 
    }
        
    level = 1; 
    score = 0;
    level_goal = 1000;
    key = 0;
    crush_on = 0;
    cnt = 0;
    speed = 10000;
	
	system("clear"); 

    draw_map(); 
    draw_main(); 
 
    // b_type_next = rand() % 7; 
    // new_block(); 

}

void drop_block (){
    
}


