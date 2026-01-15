#include <stdio.h>
#include <conio.h>

#define cols 10
#define rows 10

char board[rows * cols];

void fill_board(){
    for(int y = 0; y < rows; y++){
        for(int x = 0; x < cols; x++){
            if(y == 0 || x == 0 || x == cols - 1 || y == rows - 1){
                board[y*cols + x] = '#';
            }else{
                board[y*cols + x] = ' ';
            }   
        }
    }
}

int snake_x = 5;
int snake_y = 5;

void draw_snake(){
    board[snake_y * cols + snake_x] = '@';
}

void move_snake(int del_y, int del_x){
    snake_y += del_y;
    snake_x += del_x;
}


void read_keyboard(){
    char c = getch();
    switch(c){
        case 'w': {
            move_snake(-1, 0);
            break;
        }
        case 's':{
            move_snake(1, 0);
            break;
        }
        case 'a':{
            move_snake(0, -1);
            break;
        }
        case 'd':{
            move_snake(0, 1);
            break;
        }
    }
}

void print_board(){
    for(int y = 0; y < rows; y++){
        for(int x = 0; x < cols; x++){
            putch(board[y*cols + x]);
        }
        putch('\n');
    }
}

int is_game_over = 0;

int main(int argc, char **argv){
    while(!is_game_over){
        fill_board();
        draw_snake();
        print_board();
        read_keyboard();
    }
    return 0;
}
