/*
 * By Gavin Monroe
 */
#include <stdio.h>
#include <stdlib.h>
#define ROWS 5
#define COLS 5

int colMove[] = { 1, 2,  2,  1, -1, -2, -2, -1, 1 };
int rowMove[] = { 2, 1, -1, -2, -2, -1,  1,  2 , 2 };
int counter = 0;
int validMove(int row, int col){
    if (col < 0 || row < 0 || row >= ROWS || col >= COLS){
        return 0;
    }
    return 1;
}

void tour(int board[ROWS][COLS], int _row, int _col, int _pos){

    board[_row][_col] = _pos;
    int max = (ROWS*COLS);
    int col = 0;
    int row = 0;
    int index = 0;

    if (_pos >= max) {

        for (row = 0; row < ROWS; row++){
            for (col = 0; col < COLS; col++){
                printf("%d, ", board[row][col]);
            }
        }

        printf("\n");
        counter++;
        board[_row][_col] = 0;
    }

    for (index = 0; index < 8; index++){
        int newX = _row + rowMove[index];
        int newY = _col + colMove[index];

        if (validMove(newX, newY) == 1 && !board[newX][newY]){
                tour(board, newX, newY, _pos + 1);
        }
    }
    board[_row][_col] = 0;
}

int main(){
    int board[ROWS][COLS];//Declares
    int pos = 1;
    int row = 0;
    int col = 0;

    //Reset
    counter = 0;
    memset(board, 0, sizeof(board));

    //Tour
    for (row = 0; row < ROWS; row++){//Loop through all Spots of the Board
            for (col = 0; col < COLS; col++){
                    tour(board, row, col, pos);
            }
    }
    printf("\nThe total number of Tours found was: %d", counter);
    return 0;
}
