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

    // draw_map(); 
    draw_main(); 
 
    // b_type_next = rand() % 7; 
    // new_block(); 

}

