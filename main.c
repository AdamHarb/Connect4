#include <stdio.h>
#include "header.h"


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
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            printf("|%d", board[i][j]);
        }
        printf("|\n");
    }
    printf("---------------\n");
    return 0;
}

void setup_board(char board[COLS][ROWS]) {
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            board[i][j] = '-';
        }
    }
}

bool column_full(char board[COLS][ROWS], int col) {
    for (int i = 0; i < ROWS; i++) {
        if (board[col][i] == '-')
            return false;
    }
    return true;
}

    bool board_full(char board[COLS][ROWS]) {
        for (int i = 0; i < COLS; i++) {
            if (!column_full(board, i)) {
                return false;
            }
        }
        return true;
    }

    void get_move(char board[COLS][ROWS], char color) {
        int n;

        printf("Enter a move: \n");

        scanf("%d", &n);

        if (n > 0 && n < COLS) { // Move valid (so far)
            if (!column_full(board[COLS][ROWS], n)) // Move valid (fully)
                add_move(board, n, color);
            else
                printf("Invalid move.");

        }
    }

    void add_move(char b[COLS][ROWS], int col, char colour) {
        col--; // So the user doesn't have to input columns on a zero based index basis
        if (col >= COLS) {
            printf("Column out of bounds, please try again.");
        } else {
            for (int i = ROWS - 1; i > 0; i--) {
                if (b[col][i] == '-') {
                    b[col][i] = colour;
                    break;
                } else if (i == 1) {
                    printf("Column full, please try again.");
                }
            }
        }
    }

int main() {
    char k[ROWS][COLS];
    setup_board(k);
    int* pointer = &k;
    display_board(pointer);

}