#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define cols 30
#define rows 30
#define MAX_SNAKE_SIZE 256

char board[rows * cols];

struct Snake_Part{
    int x;
    int y;
};

struct Snake{
    int length;
    struct Snake_Part part[MAX_SNAKE_SIZE];
};

struct Snake snake;

struct Food_Pos{
    int x;
    int y;
    int consumed;
};

struct Food{
    int length;
    struct Food_Pos food[MAX_SNAKE_SIZE];
};

struct Food food;

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
    for(int i = 0; i < food.length; i++){
        board[food.food[i].y*cols + food.food[i].x] = '+';
    }
}

void clear_screen(){
    system("cls");
}

void food_pos(){
    for(int i = 0; i < food.length; i++){
        food.food[i].x = 1 + rand() % (cols - 2);
        food.food[i].y = 1 + rand() % (cols - 2);
        food.food[i].consumed = 0;
    }
}

// int snake_x = 5;
// int snake_y = 5;


void move_snake(int del_y, int del_x){
    
    for(int i = snake.length - 1; i > 0; i--){
        snake.part[i] = snake.part[i - 1];
    }

    snake.part[0].y += del_y;
    snake.part[0].x += del_x;
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


void draw_snake(){

    board[snake.part[0].y*cols + snake.part[0].x] = '@'; 

    for(int i = snake.length - 1; i > 0; i--){
        board[snake.part[i].y * cols + snake.part[i].x] = '*';
    }

     
}

void print_board(){
    clear_screen();
    for(int y = 0; y < rows; y++){
        for(int x = 0; x < cols; x++){
            putch(board[y*cols + x]);
        }
        putch('\n');
    }
    
}

int is_game_over = 0;

int main(int argc, char **argv){


    snake.length = 3;
    snake.part[0].x = 5; 
    snake.part[0].y = 5;
    snake.part[1].x = 5;
    snake.part[1].y = 4;
    snake.part[2].x = 5;
    snake.part[2].y = 3;

    srand(time(NULL));

    food.length = 10;

    food_pos();

    while(!is_game_over){
        fill_board();
        draw_snake();
        print_board();
        read_keyboard();
    }
    return 0;
}
