#include <stdio.h>
#include <time.h>
#include "header.h"

/*
Requirements:   board: A 2D array of ints of dimensions [6][7], representing the game board.

Effects:        In the case of a winner, returns an int representing the color of the winner (1 for red, 2 for yellow).
                In the case of a tie, returns 0.
 */

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

/*
Requirements:   board: A 2D array of ints of dimensions [6][7], representing the game board.

Effects:        Prints the board in a grid layout where 0 represents an empty cell, 1 represents a red piece, and 2 represents a yellow piece.
 */
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

/*
Requirements:   board: A 2D array of ints of dimensions [6][7], representing the game board.

Effects:        Sets every element of the 2D array to 0.
 */
void setup_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
}

/*
Requirements:   board: A 2D array of ints of dimensions [6][7], representing the game board.
                col: An int representing the column to be checked.

Effects:        If the column is  full, returns true.
                Else, returns false.
 */
bool column_full(int board[ROWS][COLS], int col) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][col] == 0)
            return false;
    }
    return true;
}

/*
Requirements:   b: A 2D array of ints of dimensions [6][7], representing the game board.

Effects:        If the board is completely full, returns true.
                Else, returns false.
 */
bool board_full(int b[ROWS][COLS]) {
    for (int i = 0; i < COLS; i++) {
        if (!column_full(b, i)) {
            return false;
        }
    }
    return true;
}

/*
Requirements:   b: A 2D array of ints of dimensions [6][7], representing the game board.
                n: An int representing the column to be played.
                color: An int of value either 1 or 2, representing the color of the piece being played. Red is 1, yellow is 2.

Effects:        If the move is valid, it will be played, and the function will return 1.
                Else, the function will print the corresponding message and return 0.
 */
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

/*
Requirements:   b: A 2D array of integers of dimensions [6][7], representing the game board.
                color: An integer of value either 1 or 2, representing the color of the piece being played. Red is 1, yellow is 2.

Effects:        Prompts the player to enter a column into which to place a piece.
                If the move is valid, makes the move and returns 1.
                If the move is invalid due to the column being full, prints "Column is full." and returns 0.
                If the move is invalid due to being out of bounds, prints "Invalid move." and returns 0.

*/
int get_move(int b[ROWS][COLS], int color) {
    int n;
    int *point = (int *) &b;

    printf("Enter a move: ");

    scanf("%d", &n);

    return check_move(point, n, color);
}

/*
Requirements:   b: A 2D array of integers of dimensions [6][7], representing the game board.
                col: An int representing the column to be played.
                color: An integer of value either 1 or 2, representing the color of the piece being played. Red is 1, yellow is 2.

Effects:    Adds a piece of the appropriate color (1 for red, 2 for yellow) to the chosen column of the board
            if the column is not full. Otherwise, does nothing.
 */
void add_move(int b[ROWS][COLS], int col, int color) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (b[i][col] == 0) {
            b[i][col] = color;
            break;
        }

    }
}

/*
Requirements:   board: A 2D array of ints of dimensions [6][7], representing the game board.
                currentSide:    An int representing the color of the player currently playing.
                                Since this function will only be called during this bot's turn, it effectively represents the bot's color.
                                Red is 1, yellow is 2.

Effects:        Chooses what move the bot will make, and returns an int representing the column to be played.
 */
int genMove(int board[ROWS][COLS], int currentSide) {

    // Check's if it's playing the very first move of the entire game, and if so, plays the center column (considered an advantageous move).
    if (board[0] = [0,0,0,0,0,0,0]) {
        return 3;
    }

    // Checks for potential vertical wins (lines of 3 pieces) by either player
    for (int i = 0; i <= 2; i++) { // Checks only first 3 rows, as starting from rows above prevents creating a column of 4 pieces.
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] = 0) { // Moves on if space is empty
                continue;
            } else {
                // If the chosen space and the two above it are of the same color, places a piece above them
                // This either wins or prevents the opponent from winning
                if ((board[i][j] == board[i + 1][j]) && (board[i][j] == board[i + 2][j])) {
                    // Checks that the space where the piece will be dropped is empty and not out of bounds
                    if (!((i + 3 >= ROWS) || (board[i + 3][j] != 0))) {
                        return j;
                    }
                }
            }
        }
    }

    // Checks for potential horizontal wins (lines of 3 pieces) by either player
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= 3; j++) { // Checks only first 4 rows, as starting from columns other prevents creating a row of 4 pieces.
            if (board[i][j] = 0) { // Moves on if space is empty
                continue;
            } else {
                // If the chosen space and the two to the right of it are of the same color, places a piece either to left or right of them.
                // This either wins or prevents the opponent from winning.
                if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2]) {
                    // Tries to drop piece on left
                    // Checks that the space where the piece will be dropped is empty and not out of bounds
                    if (!((j - 1 < 0) || (board[i][j - 1] != 0)))
                        // and that the piece will be dropped in the intended spot, not below it.
                        && ((i-1 < 0)  || board[i-1][j-1] != 0) {
                        return (j - 1);
                    // Tries to drop piece on right
                    } else if (!((j + 3 >= COLS) || (board[i][j + 3] != 0))) && (board[i-1][j+4] != 0) {
                        return (j + 3);
                    }
                }
            }
        }
    }

    // Checks for potential diagonally ascending wins (lines of 3 pieces) by either player (ascending to the right)
    for (int i = 0; i <= 3; i++) { // Checks only the first 4 rows
        for (int j = 0; j <= 4; j++) { // and only the first 5 columns
            if (board[i][j] = 0) { // Moves on if space is empty
                continue;
            } else {
                // If the chosen space and the two up and to the right of it are of the same color,
                // places a piece either down and to the left or up and to the right of them.
                // This either wins or prevents the opponent from winning.
                if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2]) {
                    if (!((i - 1 < 0) || (j - 1 < 0) || (board[i - 1][j - 1] != 0)))
                        && (((i-2 < 0) && !(i-1 < 0)) || board[i-2][j-1] != 0) {
                        return (j - 1);
                    } else if (!((i + 3 >= ROWS) || (j + 3 >= COLS) || (board[i + 3][j + 3] != 0))) && (board[i+2][j+3] != 0) {
                        return (j + 3);
                    }
                }
            }
        }
    }

    // Checks for potential diagonally descending wins (lines of 3 pieces) by either player (descending to the right)
    for (int i = 2; i < ROWS; i++) { // Checks all except the first 2 rows
        for (int j = 0; j <= 4; j++) { // and checks the first 5 columns
            if (board[i][j] = 0) {
                continue;
            } else {
                // If the chosen space and the two down and to the right of it are of the same color,
                // places a piece either up and to the left or down and to the right of them.
                // This either wins or prevents the opponent from winning.
                if (board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2]) {
                    if (!((i + 1 >= ROWS) || (j - 1 < 0) || (board[i + 1][j - 1] != 0)))
                        && (board[i][j-1] != 0) {
                        return (j - 1);
                    } else if (!((i - 3 < ROWS) || (j + 3 >= COLS) || (board[i - 3][j + 3] != 0)))
                        && (board[i][j-1] != 0){
                        return (j + 3);
                    }
                }
            }
        }
    }

    // Checks for vertical 2's (only by self, not by opponent)
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] = 0) {
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

    // Checks for horizontal 2's (only by self, not by opponent)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= 3; j++) {
            if (board[i][j] = 0) {
                continue;
            } else {
                if ((board[i][j] == board[i][j + 1]) && (board[i][j] == currentSide)) {
                    // add a piece either to the left or the right
                    if (!((j - 1 < 0) || (board[i][j - 1] != 0)))
                        && ((i-1 < 0) || board[i-1][j-1] != 0) {
                        return (j - 1);
                    } else if (!((j + 2 >= COLS) || (board[i][j + 2] != 0)))
                        && (board[i-1][j+2] != 0) {
                        return (j + 2);
                    }
                }
            }
        }
    }

    // Checks for diagonally ascending 2's (ascending to the right) (only by self, not by opponent)
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 4; j++) {
            if (board[i][j] = 0) {
                continue;
            } else {
                if ((board[i][j] == board[i + 1][j + 1]) && (board[i][j] == currentSide)) {
                    if (!((i - 1 < 0) || (j - 1 < 0) || (board[i - 1][j - 1] != 0)))
                        && (((i-2 < 0) && !(i-1 < 0)) || board[i-2][j-1] != 0) {
                        return (j - 1);
                    } else if (!((i + 2 >= ROWS) || (j + 2 >= COLS) || (board[i + 2][j + 2] != 0)))
                        && (board[i+1][j+2] != 0) {
                        return (j + 2);
                    }
                }
            }
        }
    }

    // Checks for diagonally descending 2's (descending to the right) (only by self, not by opponent)
    for (int i = 2; i < ROWS; i++) {
        for (int j = 0; j <= 4; j++) {
            if (board[i][j] = 0) {
                continue;
            } else {
                if ((board[i][j] == board[i - 1][j + 1]) && (board[i][j] == currentSide)) {
                    if (!((i + 1 >= ROWS) || (j - 1 < 0) || (board[i + 1][j - 1] != 0)))
                        && (board[i][j-1] != 0) {
                        return (j - 1);
                    } else if (!((i - 2 < ROWS) || (j + 2 >= COLS) || (board[i - 2][j + 2] != 0)))
                        && (((i-3 < 0) && !(i-2 < 0)) || board[i-3][j+2] != 0) {
                        return (j + 2);
                    }
                }
            }
        }
    }

    // Checks for vertical 1's (only by self, not by opponent)
    for (int i = 0; i <= 2; i++) { // Checks only first 3 rows
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] = 0) {
                continue;
            } else {
                if (board[i][j] == currentSide) {
                    if (!((i + 1 >= ROWS) || (board[i + 1][j] != 0)))
                        && (board[i][j-1] != 0) {
                        return j;
                    }
                }
            }
        }
    }

    // Checks for horizontal 1's (only by self, not by opponent)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= 3; j++) { // Checks only first 4 columns
            if (board[i][j] = 0) {
                continue;
            } else {
                if (board[i][j] == currentSide) {
                    if (!((j - 1 < 0) || (board[i][j - 1] != 0)))
                        && ((i-1 < 0) || board[i-1][j-1] != 0){
                        return (j - 1);
                    } else if (!((j + 1 >= COLS) || (board[i][j + 1] != 0)))
                        && ((i-1 < 0) || board[i-1][j+1] != 0) {
                        return (j + 1);
                    }
                }
            }
        }
    }

    // Checks for diagonally ascending 1's (ascending to the right) (only by self, not by opponent)
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 4; j++) {
            if (board[i][j] = 0) { //checks if the cell at i and j is not empty
                continue;
            } else {
                if (board[i][j] == currentSide) {
                    if (!((i - 1 < 0) || (j - 1 < 0) || (board[i - 1][j - 1] != 0)))
                        && (((i-2 < 0) && !(i-1 < 0)) || board[i-2][j-1] != 0) {
                        return (j - 1);
                    } else if (!((i + 1 >= ROWS) || (j + 1 >= COLS) || (board[i + 1][j + 1] != 0)))
                        && (board[i][j+1] != 0) {
                        return (j + 1);
                    }
                }
            }
        }
    }

    // Checks for diagonally descending 1's (descending to the right) (only by self, not by opponent)
    for (int i = 2; i < ROWS; i++) {
        for (int j = 0; j <= 4; j++) {
            if (board[i][j] = 0) {
                continue;
            } else {
                if ((board[i][j] == board[i - 1][j + 1]) && (board[i][j] == currentSide)) {
                    if (!((i + 1 >= ROWS) || (j - 1 < 0) || (board[i + 1][j - 1] != 0)))
                        && (board[i][j-1] != 0) {
                        return (j - 1);
                    } else if (!((i - 1 < ROWS) || (j + 1 >= COLS) || (board[i - 1][j + 1] != 0)))
                        && (((i-2 < 0) && !(i-1 < 0)) || board[i-2][j+1] != 0) {
                        return (j + 1);
                    }
                }
            }
        }
    }

    // If none of the above happen, simply chooses the closest move to the center possible.
    if !(column_full(board, 3)) {return 3;}
    if !(column_full(board, 2)) {return 2;}
    if !(column_full(board, 4)) {return 4;}
    if !(column_full(board, 1)) {return 1;}
    if !(column_full(board, 5)) {return 5;}
    if !(column_full(board, 0)) {return 0;}
    if !(column_full(board, 6)) {return 6;}
}



int main() {
    char name[50];
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