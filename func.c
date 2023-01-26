#include <ncurses.h>
#include <stdio.h>

#include "func.h"

void GotoXY(int x, int y) {
	move(y,x);
}
