#include "data.h"
#include <stdio.h>

int STATUS_Y_GOAL = 3;
int STATUS_Y_LEVEL = 4; 
int STATUS_Y_SCORE = 12; 
int b_type = 0; 
int b_rotation = 0; 
int b_type_next = 0; 
char main_org[MAIN_Y][MAIN_X] = {{0,},}; 
char main_cpy[MAIN_Y][MAIN_X] = {{0,},}; 
char blocks[7][4][4][4] = {{{{0,},},},}; // [종류 t0-7][로테이트 종류][가로][세로]

int bx = 0, by = 0; 
int key = 0;

int speed = 0;
int level = 0;
int level_goal = 0; 


int cnt = 0; 
int score = 0;
int last_score = 0;
int best_score = 0; 

int new_block_on = 0;
int crush_on = 0; 
int level_up_on = 0; 
int space_key_on = 0;

char path_block_data[100] = "./resources/block_data.txt"; 
char path_mainboard_data[100] = "./resources/mainboard_data.txt";