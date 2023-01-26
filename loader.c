#include <stdio.h> 
#include "data.h" 
#include "loader.h"

void load_block_data(char * data_path) {
    FILE * fp = fopen(data_path, "r"); 
    char buffer[MAX_LEN];
    int curr_block_type = -1; 
    int curr_rotate_type = 0; 
    int curr_i = 0;

    while (1) {
        fgets(buffer, MAX_LEN, fp); 
        
        if (feof(fp) != 0) {
            break; 
        }

        if (curr_block_type == -1 && buffer[0] == 't') {
            curr_block_type = buffer[1] - '0'; 
        } else if (curr_block_type >= 0 && buffer[0] == '\n') {
            if (curr_rotate_type == 3) {
                curr_block_type = -1; 
                curr_rotate_type = 0; 
                curr_i = 0; 
            } else {
                curr_rotate_type++; 
                curr_i = 0; 
            }
        } else {
            for (int j = 0; j < 4; j++) {
                blocks[curr_block_type][curr_rotate_type][curr_i][j] = buffer[j]; 
            }
            
            curr_i++; 
        }
    }

    fclose(fp); 
}


void load_mainboard_data(char * data_path) {
    FILE * fp = fopen(data_path, "r"); 
    char buffer[MAX_LEN];

    printf("main org %p\n", main_org); 

    for (int i = 0; i < MAIN_Y; i++) {
        fgets(buffer, MAX_LEN, fp); 
    
        for (int j = 0; j < MAIN_X; j++) {
            main_org[i][j] = buffer[j];
        }
    }
    fclose(fp); 
}