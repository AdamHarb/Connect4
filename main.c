#include <stdio.h>
#include "header.h"

int main() {
    char k[ROWS][COLS];
}

// determines who (if anybody) has won.  Returns the player id of the
// winner (1 for the first, 2 for the second), and 0 if there is a tie
//there is 3 cases: vertical, horizontal, and diagonal(downwards and upwards)
int winner(int board[COLS][ROWS]) {
    //checks vertical wins
    for (int i = 0; i < 3; i++) {
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
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == '-') { //checks if the cell at i and j is not empty
                continue;
            }
            if (board[i][j] == board[i][j + 1] && board[i][j + 2] == board[i][j + 3] &&
                board[i][j + 1] == board[i][j + 2]) {
                return board[i][j] = 'x' ? 1 : 2;
            }
        }
    }

    //checks diagonal-ascending cells
    for (int i = 0; i < 3; i++) {
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
    for (int i = 0; i < 3; i++) {
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

int display_board(int board[COLS][ROWS]) {
    printf("---------------\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("|%d", board[i][j]);
        }
        printf("|\n");
    }
    printf("---------------\n");
    return 0;
}

int setup_board(int board[COLS][ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
    return board;
}

int column_full(int board[COLS][ROWS], int col) {
    for (int j = 1; j < COLS; j++) {
        if (j == col) {
            for (int i = 0; i < ROWS; i++) {
                if (board[col][i] == 0) return 0; // 0 means its false ( teh board is not completely full)

            }
            return 1; // 1 means its true the board is completely full
        }
    }
}

bool column_full2(int board[COLS][ROWS], int col) {
    for (int j = 1; j < COLS; j++) {
        if (j == col) {
            for (int i = 0; i < ROWS; i++) {
                if (board[col][i] == 0) return false; // 0 means its false ( teh board is not completely full)

            }
            return true; // 1 means its true the board is completely full
        }
    }
}

int board_full(int board[COLS][ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0) return 1; // if 1 that means the board is not full yet
        }
    }
}

int get_move(int board[COLS][ROWS]) {
    int n;
    printf("enter a move\n");
    scanf("%c", &n);
    if (n > 0 && n < COLS) { // move valid
        if (column_full(board[COLS][ROWS], n) == 0) { // the col is not full
            return n;
        } else return -1; // move invalid
    }
}

void add_move(char b[COLS][ROWS], int col, char colour) {
    col--;
    if (col > COLS) {
        printf("Column out of bounds, please try again.");
    } else {
                for (int i = ROWS; i > 0; i--) {
                    if (b[i][col] == '-') {
                        b[i][col] = colour;
                    }
                    else if (i == 1) {
                        printf("Column full, please try again.");
                    }
                }
    }
}