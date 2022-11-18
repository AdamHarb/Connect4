#include <stdbool.h>

#ifndef CONNECT4_HEADER_H
#define CONNECT4_HEADER_H

#define ROWS 6
#define COLS 7

#define red 1
#define yellow 2

// Iterates over the indices of the array and prints them.
void display_board(int board [ROWS][COLS]);

// Sets all the elements in the array to "-"
void setup_board (int board[ROWS][COLS]);

bool column_full (int board[ROWS][COLS], int col);

// prompts the user to enter a move, and checks that it is valid
// for the supplied board and board size
// Returns the column that the user has entered, once it is valid (1-COLS)
int get_move (int board[ROWS][COLS], int color);

// adds a token of the given value (1 or 2) to the board at the
// given column (col between 1 and COLS inclusive)
// Returns 0 if successful, -1 otherwise
void add_move (int b[ROWS][COLS], int col, int colour );

// determines if the board is completely full or not
bool board_full (int board[ROWS][COLS]);

// determines who (if anybody) has won.  Returns the player id of the
// winner, otherwise 0
int winner (int[ROWS][COLS]) ;

#endif //CONNECT4_HEADER_H
