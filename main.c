#include <stdio.h>
#include "header.h"

//winner method - returns the id of the winner if exists
int winner(int board[COLS][ROWS]);

int main()
{
    printf("Hello, World!\n");
    return 0;
}

// determines who (if anybody) has won.  Returns the player id of the
// winner (1 for the first, 2 for the second), and 0 if there is a tie
//there is 3 cases: vertical, horizontal, and diagonal(downwards and upwards)
int winner(int board[COLS][ROWS]) {
    //checks vertical wins
    for(int i=0; i<3; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == '-') { //checks if the cell at i and j is not empty, '-' stands for empty cell
                continue;
            }
            if (board[i][j] == board[i + 1][j] && board[i + 2][j] == board[i + 3][j] &&
                board[i + 1][j] == board[i + 2][j]) {
                return board[i][j] = 'x' ? 1 : 2;
            }
        }
    }
    //checks horizontal wins
    for(int i=0; i<ROWS; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == '-') { //checks if the cell at i and j is not empty
                continue;
            }
            if (board[i][j] == board[i][j + 1] && board[i][j + 2] == board[i][j + 3] &&
                board[i][j + 1] == board[i][j + 2]){
                return board[i][j] = 'x' ? 1 : 2;
            }
        }
    }

    //checks diagonal-ascending cells
    for(int i=0; i<3; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == '-') { //checks if the cell at i and j is not empty
                continue;
            }
            if (board[i][j] == board[i + 1][j + 1] && board[i + 2][j + 2] == board[i + 3][j + 3] &&
                board[i + 1][j + 1] == board[i + 2][j + 2]) {
                return board[i][j] = 'x' ? 1 : 2;
            }
        }
    }

    //checks diagonal-descending cells
    for(int i=0; i<3; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i + 3][j] == '-') { //checks if the cell at i and j is not empty
                continue;
            }
            if (board[i + 3][j] == board[i + 2][j + 1] && board[i + 1][j + 2] == board[i][j + 3] &&
                board[i + 2][j + 1] == board[i + 1][j + 2]) {
                return board[i][j] = 'x' ? 1 : 2;
            }
        }
    }
    return 0; //returns 0 if there is a tie
}

