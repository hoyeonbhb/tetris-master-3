#include <stdio.h>
#include <ncurses.h>
#include <locale.h>

#define LEFT 68
#define RIGHT 67
#define UP 65
#define DOWN 66
#define ARROW 27
#define ARROW2 91
void arrow_convert (){
    int Key[3];
    for(int i = 0;i <= 3; i++){
           Key[i] = getchar();
    }
    printw("%d",Key[0]);
}

int main(void){   
setlocale(LC_ALL, "");
    initscr();
    arrow_convert();
    refresh();
    endwin();
    return 0;
}