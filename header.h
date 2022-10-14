#include <stdbool.h>

#ifndef CONNECT4_HEADER_H
#define CONNECT4_HEADER_H

#define ROWS 6
#define COLS 7

// Iterates over the indices of the array and prints them.
int display_board (int board [COLS][ROWS]);

// Sets all the elements in the array to "-"
void setup_board (char board[COLS][ROWS]);

bool column_full (char board[COLS][ROWS], int col);

// prompts the user to enter a move, and checks that it is valid
// for the supplied board and board size
// Returns the column that the user has entered, once it is valid (1-COLS)
void get_move (char board[COLS][ROWS], char color);

// adds a token of the given value (1 or 2) to the board at the
// given column (col between 1 and COLS inclusive)
// Returns 0 if successful, -1 otherwise
void add_move (char b[COLS][ROWS], int col, char colour );

// determines if the board is completely full or not
bool board_full (char board[COLS][ROWS]);

// determines who (if anybody) has won.  Returns the player id of the
// winner, otherwise 0
int winner ( int[COLS][ROWS] ) ;

#endif //CONNECT4_HEADER_H
