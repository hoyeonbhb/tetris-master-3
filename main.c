#include <stdio.h> 
#include <string.h>
#include <ncurses.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <time.h> 
#include <locale.h>

#include "data.h"
#include "func.h"

//  gcc -o test main.c data.c loader.c func.c -lncurses

int main() {
    setlocale(LC_ALL, "");
    initscr();

    load_master_data();
    
    srand(time(NULL)); //난수 생성 
    curs_set(0); // 커서 없애기
    // title(); //메인타이틀 호출 
    reset(); //게임판 리셋 
    
    // while (True) {
    //     for (int i = 0; i < 5; i++) { //블록이 한칸떨어지는동안 5번 키입력받을 수 있음 
    //         check_key(); // 키입력확인 
    //         draw_main(); // 화면을 그림 
    //         usleep(speed); // 게임속도조절 

    //         if (crush_on && check_crush(bx, by + 1, b_rotation) == False) { //블록이 충돌중인경우 추가로 이동및 회전할 시간을 갖음 
    //             usleep(speed); 
    //         }                      
    //         if (space_key_on == 1) { //스페이스바를 누른경우(hard drop) 추가로 이동및 회전할수 없음 break; 
    //             space_key_on = 0;
    //             break;
    //         }
    //     }
// 
    //     drop_block(); // 블록을 한칸 내림 
    //     check_level_up(); // 레벨업을 체크 
    //     check_game_over(); //게임오버를 체크 

    //     if (new_block_on == 1) {// 뉴 블럭 flag가 있는 경우 새로운 블럭 생성 
    //         new_block(); 
    //     }
    // }

    getch();

    endwin();
    return 0; 
}