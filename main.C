#include <stdio.h>
#include <conio.h>

#define cols 30
#define rows 30

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

void print_board(){
    for(int y = 0; y < rows; y++){
        for(int x = 0; x < cols; x++){
            putch(board[y*cols + x]);
        }
        putch('\n');
    }
}

int main(int argc, char **argv){
    fill_board();
    print_board();
}
