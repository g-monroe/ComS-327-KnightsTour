#include <stdio.h>
#include <stdlib.h>

#define COLS 5
#define ROWS 5

//Drawing;
#define T "-------"
#define W "|\r|\r|"
int position[2] = {3,1};
int lastMove[2] = {0,0};
int failedMove[2] = {-1,-1};
int line[COLS*ROWS];
int board[COLS][ROWS];
int track[COLS][ROWS];
int lines[1000][COLS*ROWS];
int movesX[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int movesY[8] = {1 ,2, 2, 1, -1, -2, -2, -1};
int cntr = 0;
int freeze = 0;
//0 = Taken, 1 = Open
//int been[COLS][ROWS];
int main (){
    move();
}
int incr = 0;
int isValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= ROWS || y >= COLS){
        return 0;
    }
    return 1;
}
void move(){
    //printf("Possible Moves Info:\n");

    int _new = 0;
    int _old = 0;

    int newX[8];
    int newY[8];

    int oldX[8];
    int oldY[8];

    int move[2];

    for(int idx = 0; idx < 8; idx++){//Loop through Knights Moves

        int possibleMove[2] = {movesX[idx], movesY[idx]};
        move[0] = position[0] + movesX[idx];
        move[1] = position[1] + movesY[idx];

        if (isValid(move[0], move[1])){
            if (!track[move[0]][move[1]]){
                //printf("New Move:(%2d,%2d) -> Position:(%2d,%2d) -> Been:%d \n", possibleMove[0],possibleMove[1], move[0], move[1], track[move[0]][move[1]]);
                newX[_new] = move[0];
                newY[_new] = move[1];
                _new++;
            }else{
               // printf("Old Move:(%2d,%2d) -> Position:(%2d,%2d) -> Been:%d \n", possibleMove[0],possibleMove[1], move[0], move[1], track[move[0]][move[1]]);
                oldX[_old] = move[0];
                oldY[_old] = move[1];
                _old++;
            }
        }//End Of Parameter Checking
    }//End of Loop
    if (_new == 1){
        lastMove[0] = position[0];
        lastMove[1] = position[1];
        track[position[0]][position[1]] = 1;
        position[0] = newX[0];
        position[1] = newY[0];
        line[incr] = ((newY[0]+1)* 5) + newX[0]+1;
        //printf("%d\n", getPlace(newX[0], newY[0]));
        incr++;

    }else if(_new > 1){
        lastMove[0] = position[0];
        lastMove[1] = position[1];

        int rNum = rand()%((_new)-1) + 1;
        track[position[0]][position[1]] = 1;
        //line[incr] = getPlace(newX[rNum], newY[rNum]);
        line[incr] = ((newX[rNum]+1)* 5) + newY[rNum];
         //printf("%d\n", getPlace(newX[0], newY[0]));
        incr++;
        position[0] = newX[rNum];
        position[1] = newY[rNum];
    }else if (_new == 0){//Old Moves
        if (_old == 1){
            lastMove[0] = position[0];
            lastMove[1] = position[1];
            position[0] = oldX[0];
            position[1] = oldY[0];
        }else if(_old > 1){
            lastMove[0] = position[0];
            lastMove[1] = position[1];

            int rNum = rand()%((_old)-1) + 1;
            track[position[0]][position[1]] = 1;
            position[0] = oldX[rNum];
            position[1] = oldY[rNum];
        }
    }
    cont();
}
int linesCounter = 0;
void cont(){
    cntr++;
    int trackCounter = 0;
    for (int col = 0; col < COLS; col++){
            for (int row = 0; row < ROWS; row++){
                if (track[col][row] == 0){
                    trackCounter++;
                }
            }
    }
    if (trackCounter > 0){
        move();
    }else if (trackCounter == 0){
            for(int idx2=0; idx2<incr; idx2++){
                printf("%d, ", line[idx2]);
            }
            printf("\n");
            linesCounter++;
            memset(line,0,sizeof line);
            memset(track, 0, sizeof line);
            incr =0;
            move();
        }
}
int getPlace(int _col, int _row){
    int cnt= 0;
    for (int col = 0; col < COLS; col++){
        for (int row = 0; row < ROWS; row++){
                cnt++;
              if (_row == row && _col == col){
                return cnt;
              }
        }
    }
    return cnt;
}
