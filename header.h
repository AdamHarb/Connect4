#ifndef CONNECT4_HEADER_H
#define CONNECT4_HEADER_H

#define ROWS 6
#define COLS 7

// displays the board to the screen
int display_board ( int[COLS][ROWS] ) ;

// sets up the board to an empty state
int setup_board ( int[COLS][ROWS] ) ;

// Returns TRUE if the specified column in the board is completely full
// FALSE otherwise
// col should be between 1 and COLS
int column_full ( int[COLS][ROWS], int col ) ;

// prompts the user to enter a move, and checks that it is valid
// for the supplied board and board size
// Returns the column that the user has entered, once it is valid (1-COLS)
int get_move ( int[COLS][ROWS] ) ;

// adds a token of the given value (1 or 2) to the board at the
// given column (col between 1 and COLS inclusive)
// Returns 0 if successful, -1 otherwise
int add_move ( int b[COLS][ROWS], int col, int colour ) ;

// determines if the board is completely full or not
int board_full ( int[COLS][ROWS] ) ;

// determines who (if anybody) has won.  Returns the player id of the
// winner, otherwise 0
int winner ( int[COLS][ROWS] ) ;

#endif //CONNECT4_HEADER_H
