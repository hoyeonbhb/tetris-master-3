#include <stdio.h>
#include <ncurses.h>
#include <locale.h>

#define LEFT 68
#define RIGHT 67
#define UP 65
#define DOWN 66
#define ARROW 27
#define ARROW2 91

void MoveMaze()
{

    if (getchar() == ARROW && getchar() == ARROW2)
    {
        int nkey = getchar();
        switch (nkey)
        {
        case UP:
            printw("위 ");
            break; 

        case DOWN:
            printw("아래 ");
            break;

        case LEFT:
            printw("왼쪽 ");
            break;

        case RIGHT:
            printw("오른쪽 ");
            break;
        } 
        
        refresh();
    }
}

int main(void)
{
    setlocale(LC_ALL, "");
	initscr();
    
    while (1)
    {
        // MoveMaze();
        printw("%d \n", getchar());
        refresh();
    }
    endwin();
}