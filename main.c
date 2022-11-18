#include <stdio.h>
#include <time.h>
#include "header.h"

// determines who (if anybody) has won.  Returns the player id of the
// winner (1 for the first, 2 for the second), and 0 if there is a tie
//there is 3 cases: vertical, horizontal, and diagonal(downwards and upwards)
// Determines who, if anyone, has won. Returns 1 for red, 2 for yellow, and 0 for a tie.


//Requires : an int [] [] that represents a board of certain dimensions however in our case it is a 6 x 7
//Effects: Returns the id of the winner if exists; 1 if Red is the winner, 2 if yellow is the winner,
//         and 0 if there is still no winner (there is a tie)

int winnerF(int board[ROWS][COLS]) {
    // Checks for vertical wins
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0) { //checks if the cell at i and j is not empty, 0 stands for empty cell
                continue;
            }
            if (board[i][j] == board[i + 1][j] && board[i + 2][j] == board[i + 3][j] &&
                board[i + 1][j] == board[i + 2][j]) {
                return (board[i][j] = 'x') ? 1 : 2;
            }
        }
    }
    // Checks for horizontal wins
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) { //checks if the cell at i and j is not empty
                continue;
            }
            if (board[i][j] == board[i][j + 1] && board[i][j + 2] == board[i][j + 3] &&
                board[i][j + 1] == board[i][j + 2]) {
                return (board[i][j] = 'x') ? 1 : 2;
            }
        }
    }

    // Checks for diagonally ascending wins (ascending to the right)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) { //checks if the cell at i and j is not empty
                continue;
            }
            if (board[i][j] == board[i + 1][j + 1] && board[i + 2][j + 2] == board[i + 3][j + 3] &&
                board[i + 1][j + 1] == board[i + 2][j + 2]) {
                return (board[i][j] = 'x') ? 1 : 2;
            }
        }
    }

    // Checks for diagonally descending wins (descending to the right)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i + 3][j] == 0) { //checks if the cell at i and j is not empty
                continue;
            }
            if (board[i + 3][j] == board[i + 2][j + 1] && board[i + 1][j + 2] == board[i][j + 3] &&
                board[i + 2][j + 1] == board[i + 1][j + 2]) {
                return (board[i][j] = 'x') ? 1 : 2;
            }
        }
    }

    return 0; // Returns 0 if there is a tie
}

//Requires: an int [] [] that represents a board of certain dimensions however in our case it is a 6 x 7
//Effects: Prints the board in a grid layout where 0 represents an empty cell, 1 represents a red piece, and 2 represents a yellow piece.
void display_board(int board[ROWS][COLS]) { // int[x][y] int[y][x]
    printf("---------------\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("|%d", board[i][j]);
        }
        printf("|\n");
    }
    printf("---------------\n");
}

//Requires : an int [] [] that represents a board of certain dimensions however in our case it is a 6 x 7
//Effects: Sets all the elements of the array to "0".
void setup_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
}
//Requires : an int [] [] that represents a board of certain dimensions however in our case it is a 6 x 7
//Effects: Determines whether a given column is full.
bool column_full(int board[ROWS][COLS], int col) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][col] == 0)
            return false;
    }
    return true;
}
//Requires : an int[][] that represents a board of certain dimensions however in our case it is a 6 x 7
//Effects: Determines whether the board is completely full.
bool board_full(int b[ROWS][COLS]) {
    for (int i = 0; i < COLS; i++) {
        if (!column_full(b, i)) {
            return false;
        }
    }
    return true;
}

//Requires : an int [] [] that represents a board of certain dimensions however in our case it is a 6 x 7
//           and n : the index of the column and color : the color of the token I want to insert ( yellow or red)
//Effects: it adds the token to the required column if the column is not full.
//         However, it will not add the token if the column is full or if the move is invalid
//         and will print the corresponding message
int check_move(int b[ROWS][COLS], int n, int color) {
    if (n >= 0 && n < COLS) { // Move valid (so far)
        if (!column_full(b, n)) {
            add_move(b, n, color);
            return 1;
        } // Move valid (fully)
        else {
            printf("Column is full.");
            return 0;
        }
    } else
        printf("Invalid move.\n");
    return 0;
}

// Prompts the player to enter a column into which to place a piece.
// If the move is valid, makes the move and returns 1.
// If the move is invalid due to the column being full, prints "Column is full." and returns 0.
// If the move is invalid due to being out of bounds, prints "Invalid move." and returns 0.
//Requires : an int [] [] that represents a board of certain dimensions however in our case it is a 6 x 7
//          and n : the index of the column and color : the color of the token I want to insert ( yellow or red)
//Effects:  Prompts the player to enter a column into which to place a piece.
//          If the move is valid, makes the move and returns 1.
//          If the move is invalid due to the column being full, prints "Column is full." and returns 0.
//          If the move is invalid due to being out of bounds, prints "Invalid move." and returns 0.
int get_move(int b[ROWS][COLS], int color) {
    int n;
    int *point = (int *) &b;

    printf("Enter a move: ");

    scanf("%d", &n);

    return check_move(point, n, color);
}

// Adds a piece of the appropriate color (1 or 2, corresponding to red and yellow, respectively)
// to the chosen column of the board if the column is not full.
// Otherwise, does nothing.

//Requires : an int [] [] that represents a board of certain dimensions however in our case it is a 6 x 7
//           and n : the index of the column and color : the color of the token I want to insert ( yellow or red)
//Effects:  Adds a piece of the appropriate color (1 or 2, corresponding to red and yellow, respectively)
//          to the chosen column of the board if the column is not full.
//          Otherwise, does nothing.
void add_move(int b[ROWS][COLS], int col, int colour) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (b[i][col] == 0) {
            b[i][col] = colour;
            break;
        }

    }
}

//Requires : an int [] [] that represents a board of certain dimensions however in our case it is a 6 x 7
//Effects: generates the bots move
int genMove(int board[ROWS][COLS], int currentSide) {

    // Checks for vertical wins
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] = 0) { //checks if the cell at i and j is not empty, 0 stands for empty cell
                continue;
            } else {
                if ((board[i][j] == board[i + 1][j]) && (board[i][j] == board[i + 2][j])) {
                    if (!((i + 3 >= ROWS) || (board[i + 3][j] != 0))) {
                        return j;
                    }
                }
            }
        }
    }

    // Checks for horizontal wins
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] = 0) { //checks if the cell at i and j is not empty
                continue;
            } else {
                if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2]) {
                    // add a piece either to the left or the right
                    if (!((j - 1 < 0) || (board[i][j - 1] != 0))) && ((i-1 < 0)  || board[i-1][j-1] != 0) {
                        return (j - 1);
                    } else if (!((j + 3 >= COLS) || (board[i][j + 3] != 0))) && (board[i-1][j+4] != 0) {
                        return (j + 3);
                    }
                }
            }
        }
    }

    // Checks for diagonally ascending wins (ascending to the right)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] = 0) { //checks if the cell at i and j is not empty
                continue;
            } else {
                if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2]) {
                    // add a piece that's to the right and 1 up
                    if (!((i - 1 < 0) || (j - 1 < 0) || (board[i - 1][j - 1] != 0))) && (((i-2 < 0) && !(i-1 < 0)) || board[i-2][j-1] != 0) {
                        return (j - 1);
                    } else if (!((i + 3 >= ROWS) || (j + 3 >= COLS) || (board[i + 3][j + 3] != 0))) && (board[i+2][j+3] != 0) {
                        return (j + 3);
                    }
                }
            }
        }
    }

    // Checks for diagonally descending wins (descending to the right)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] = 0) { //checks if the cell at i and j is not empty
                continue;
            } else {
                if (board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2]) {
                    if (!((i + 1 >= ROWS) || (j - 1 < 0) || (board[i + 1][j - 1] != 0))) && (board[i][j-1] != 0) {
                        return (j - 1);
                    } else if (!((i - 3 < ROWS) || (j + 3 >= COLS) || (board[i - 3][j + 3] != 0))) && (board[i][j-1] != 0){
                        return (j + 3);
                    }
                }
            }
        }
    }

    // Checks for vertical 2's
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] = 0) { //checks if the cell at i and j is not empty, 0 stands for empty cell
                continue;
            } else {
                if ((board[i][j] == board[i + 1][j]) && (board[i][j] == currentSide)) {
                    if (!((i + 2 >= ROWS) || (board[i + 2][j] != 0))) {
                        return j;
                    }
                }
            }
        }
    }

    // Checks for horizontal 2's
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] = 0) { //checks if the cell at i and j is not empty
                continue;
            } else {
                if ((board[i][j] == board[i][j + 1]) && (board[i][j] == currentSide)) {
                    // add a piece either to the left or the right
                    if (!((j - 1 < 0) || (board[i][j - 1] != 0))) && ((i-1 < 0)|| board[i-1][j-1] != 0) {
                        return (j - 1);
                    } else if (!((j + 2 >= COLS) || (board[i][j + 2] != 0))) && (board[i-1][j+2] != 0) {
                        return (j + 2);
                    }
                }
            }
        }
    }

    // Checks for diagonally ascending 2's (ascending to the right)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] = 0) { //checks if the cell at i and j is not empty
                continue;
            } else {
                if ((board[i][j] == board[i + 1][j + 1]) && (board[i][j] == currentSide)) {
                    // add a piece that's to the right and 1 up
                    if (!((i - 1 < 0) || (j - 1 < 0) || (board[i - 1][j - 1] != 0))) && (((i-2 < 0) && !(i-1 < 0)) || board[i-2][j-1] != 0) {
                        return (j - 1);
                    } else if (!((i + 2 >= ROWS) || (j + 2 >= COLS) || (board[i + 2][j + 2] != 0))) && (board[i+1][j+2] != 0) {
                        return (j + 2);
                    }
                }
            }
        }
    }

    // Checks for diagonally descending 2's (descending to the right)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] = 0) { //checks if the cell at i and j is not empty
                continue;
            } else {
                if ((board[i][j] == board[i - 1][j + 1]) && (board[i][j] == currentSide)) {
                    if (!((i + 1 >= ROWS) || (j - 1 < 0) || (board[i + 1][j - 1] != 0))) && (board[i][j-1] != 0) {
                        return (j - 1);
                    } else if (!((i - 2 < ROWS) || (j + 2 >= COLS) || (board[i - 2][j + 2] != 0))) && (((i-3 < 0) && !(i-2 < 0)) || board[i-3][j+2] != 0) {
                        return (j + 2);
                    }
                }
            }
        }
    }

    // Checks for vertical 1's
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] = 0) { //checks if the cell at i and j is not empty, 0 stands for empty cell
                continue;
            } else {
                if (board[i][j] == currentSide) {
                    if (!((i + 1 >= ROWS) || (board[i + 1][j] != 0))) && (board[i][j-1] != 0) {
                        return j;
                    }
                }
            }
        }
    }

    // Checks for horizontal 1's
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] = 0) { //checks if the cell at i and j is not empty
                continue;
            } else {
                if (board[i][j] == currentSide) {
                    // add a piece either to the left or the right
                    if (!((j - 1 < 0) || (board[i][j - 1] != 0))) && ((i-1 < 0) || board[i-1][j-1] != 0){
                        return (j - 1);
                    } else if (!((j + 1 >= COLS) || (board[i][j + 1] != 0))) && ((i-1 < 0) || board[i-1][j+1] != 0) {
                        return (j + 1);
                    }
                }
            }
        }
    }

    // Checks for diagonally ascending 1's (ascending to the right)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] = 0) { //checks if the cell at i and j is not empty
                continue;
            } else {
                if (board[i][j] == currentSide) {
                    // add a piece that's to the right and 1 up
                    if (!((i - 1 < 0) || (j - 1 < 0) || (board[i - 1][j - 1] != 0))) && (((i-2 < 0) && !(i-1 < 0)) || board[i-2][j-1] != 0) {
                        return (j - 1);
                    } else if (!((i + 1 >= ROWS) || (j + 1 >= COLS) || (board[i + 1][j + 1] != 0))) && (board[i][j+1] != 0) {
                        return (j + 1);
                    }
                }
            }
        }
    }

    // Checks for diagonally descending 1's (descending to the right)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] = 0) { //checks if the cell at i and j is not empty
                continue;
            } else {
                if ((board[i][j] == board[i - 1][j + 1]) && (board[i][j] == currentSide)) {
                    if (!((i + 1 >= ROWS) || (j - 1 < 0) || (board[i + 1][j - 1] != 0))) && (board[i][j-1] != 0) {
                        return (j - 1);
                    } else if (!((i - 1 < ROWS) || (j + 1 >= COLS) || (board[i - 1][j + 1] != 0))) && (((i-2 < 0) && !(i-1 < 0)) || board[i-2][j+1] != 0) {
                        return (j + 1);
                    }
                }
            }
        }
    }

    return 0; // Returns 0 if there is a tie
}



int main() {
    char name[20];
    char decision;

    int winner = 0, currentSide = red, totalTime1 = 0, totalTime2 = 0, status = 0;
    int mainBoard[ROWS][COLS]; // Board declaration
    setup_board(mainBoard); // Board initialization

    printf("Welcome! Good luck!\n---------------\n");
    printf("What is your name?\n");

    scanf("%s", name);

    printf("Would you like play against an AI? (Y/N)\n");

    scanf("%s", decision);

    // Main driver loop, which alternates turns until someone wins or the board becomes completely full.
    do {
        // Turn indicator message
        if (currentSide == red) {
            printf("Red's turn.\n");
        } else {
            printf("Yellow's turn.\n");
        }

        clock_t start, end; // Variables for storing the start and end times of each turn to measure the time taken by each player.
        start = clock(); // start is set to current time.

        if (decision == 'Y' || currentSide == red != 0) {
            status = check_move(mainBoard, genMove(mainBoard, currentSide), currentSide);
        } else {
            status = get_move(mainBoard, currentSide);
        }


        // Repeatedly calls get_move until the player enters a valid move.
        while (status != 1) {
            status = get_move(mainBoard, currentSide);
        }
        end = clock(); // end is set to current time.

        display_board(mainBoard);
        winner = winnerF(mainBoard);

        // The player's total time taken is incremented by the time they took to play the last turn.
        if (currentSide == red) {
            currentSide = yellow;
            totalTime1 += (end - start) / CLOCKS_PER_SEC;
        } else {
            currentSide = red;
            totalTime2 += (end - start) / CLOCKS_PER_SEC;
        }
        status = 0;
    } while (winner == 0 && !board_full(mainBoard));

    if (winner == 1) {
        printf("Red wins!");
    } else if (winner == 2) {
        printf("Yellow wins!");
    } else {
        printf("%s wins!", totalTime2 > totalTime1 ? "Red"
                                                   : "Yellow"); // Breaks ties by giving the win to the player who took less time.
    }
    return 0;
}