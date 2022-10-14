#include <stdbool.h>

#ifndef CONNECT4_HEADER_H
#define CONNECT4_HEADER_H

#define ROWS 6
#define COLS 7


int display_board (int board [COLS][ROWS]);

int setup_board (int board[COLS][ROWS]);

// Returns TRUE if the specified column in the board is completely full
// FALSE otherwise
// col should be between 1 and COLS
int column_full (int board[COLS][ROWS], int col);

// hone alulna eno badun boolean true or false fa hone 3mletla copy w hatet true w false
bool column_full2 ( int board[COLS][ROWS], int col );

// prompts the user to enter a move, and checks that it is valid
// for the supplied board and board size
// Returns the column that the user has entered, once it is valid (1-COLS)
int get_move ( int board[COLS][ROWS] );

// adds a token of the given value (1 or 2) to the board at the
// given column (col between 1 and COLS inclusive)
// Returns 0 if successful, -1 otherwise
void add_move (char b[COLS][ROWS], int col, char colour );

// determines if the board is completely full or not
int board_full (int board[COLS][ROWS]);

// determines who (if anybody) has won.  Returns the player id of the
// winner, otherwise 0
int winner ( int[COLS][ROWS] ) ;

#endif //CONNECT4_HEADER_H
