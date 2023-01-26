#ifndef __DATA_H_
#define __DATA_H_

#define NUM_BLOCKS 7 

#define ARROW 27
#define ARROW2 91
#define LEFT 68
#define RIGHT 67
#define UP 65
#define DOWN 66

#define SPACE 32 //hard drop
#define p 112 //일시정지 
#define P 80 //일시정지
#define ESC 27 //게임종료 
 
#define False 0
#define True 1
 
#define ACTIVE_BLOCK '1' // 게임판배열에 저장될 블록의 상태들 
#define EMPTY '0'         // 블록이 이동할 수 없는 공간은 양수로 표현 
#define WALL '2'
#define INACTIVE_BLOCK '3' // 이동이 완료된 블록값 
#define CEILLING '4'     
 
#define MAIN_X 11 //게임판 가로크기 
#define MAIN_Y 23 //게임판 세로크기 
#define MAIN_X_ADJ 3 //게임판 위치조정 
#define MAIN_Y_ADJ 1 //게임판 위치조정 
 
#define STATUS_X_ADJ MAIN_X_ADJ + MAIN_X + 1 //게임정보표시 위치조정 
 
extern int STATUS_Y_GOAL; //GOAL 정보표시위치Y 좌표 저장 
extern int STATUS_Y_LEVEL; //LEVEL 정보표시위치Y 좌표 저장
extern int STATUS_Y_SCORE; //SCORE 정보표시위치Y 좌표 저장
 
extern int b_type; //블록 종류를 저장 
extern int b_rotation; //블록 회전값 저장 
extern int b_type_next; //다음 블록값 저장 
 
extern char main_org[MAIN_Y][MAIN_X]; //게임판의 정보를 저장하는 배열 모니터에 표시후에 main_cpy로 복사됨 
extern char main_cpy[MAIN_Y][MAIN_X]; //즉 maincpy는 게임판이 모니터에 표시되기 전의 정보를 가지고 있음 
                              //main의 전체를 계속 모니터에 표시하지 않고(이렇게 하면 모니터가 깜빡거림) 
                              //main_cpy와 배열을 비교해서 값이 달라진 곳만 모니터에 고침 

extern char blocks[7][4][4][4];

extern int bx, by; //이동중인 블록의 게임판상의 x,y좌표를 저장 
 
extern int key; //키보드로 입력받은 키값을 저장 
 
extern int speed; //게임진행속도 
extern int level; //현재 level 
extern int level_goal; //다음레벨로 넘어가기 위한 목표점수 
extern int cnt; //현재 레벨에서 제거한 줄 수를 저장 
extern int score; //현재 점수 
extern int last_score; //마지막게임점수 
extern int best_score; //최고게임점수 
 
extern int new_block_on; //새로운 블럭이 필요함을 알리는 flag 
extern int crush_on; //현재 이동중인 블록이 충돌상태인지 알려주는 flag 
extern int level_up_on; //다음레벨로 진행(현재 레벨목표가 완료되었음을) 알리는 flag 
extern int space_key_on; //hard drop상태임을 알려주는 flag 

#endif